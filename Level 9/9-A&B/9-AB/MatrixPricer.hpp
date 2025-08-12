/**
*
* MatrixPricer.hpp
*
* Header file for the Matrix Pricer class
*
* @author:  Kaushik Aryan R
* @date:    10-08-2025
* @version: 1.0
*
**/

#ifndef MATRIX_PRICER_HPP
#define MATRIX_PRICER_HPP

#include <vector>
#include "OptionContract.hpp"
#include <functional>

 // Template class for generating parameter grids used in batch option pricing
template<typename NumType = double>
class MeshGenerator
{
private:
    std::vector<NumType> parameterGrid;

public:
    // Default constructor
    MeshGenerator() : parameterGrid() {}

    // Copy constructor
    MeshGenerator(const MeshGenerator& source) : parameterGrid(source.parameterGrid) {}

    // Parametric constructor
    MeshGenerator(NumType rangeStart, NumType rangeEnd, NumType step)
    {
        for (NumType currValue = rangeStart; currValue <= rangeEnd; currValue += step)
            parameterGrid.push_back(currValue);
    }

    // Destructor
    ~MeshGenerator() {}

    // Assignment operator - assigns mesh from another instance
    MeshGenerator& operator=(const MeshGenerator& source)
    {
        if (this != &source)
            parameterGrid = source.parameterGrid;
        return *this;
    }

    // Returns number of grid points
    inline size_t size() const
    {
        return parameterGrid.size();
    }

    // Array access operator for retrieving grid values
    inline NumType operator[](unsigned gridIndex) const
    {
        return parameterGrid[gridIndex];
    }

    // Constant iterator to beginning of grid
    typename std::vector<NumType>::const_iterator begin() const
    {
        return parameterGrid.begin();
    }

    // Constant iterator to end of grid
    typename std::vector<NumType>::const_iterator end() const
    {
        return parameterGrid.end();
    }

    std::vector<NumType> getGrid() const
    {
        return parameterGrid;
    }
};

class MatrixPricer
{
public:
    // Generate uniform parameter mesh between bounds with specified step size
    template<typename NumType = double>
    static std::vector<NumType> createMesh(NumType lowerBound, NumType upperBound, NumType step)
    {
        std::vector<NumType> paramMesh;
        for (NumType currPoint = lowerBound; currPoint <= upperBound; currPoint += step) {
            paramMesh.push_back(currPoint);
        }
        return paramMesh;
    }

    // Calculate option values across range of underlying prices using custom function
    template<typename OptionType, typename NumType = double>
    static std::vector<NumType> priceRange(
        const OptionType& baseOption,
        NumType minSpot,        // Minimum underlying price
        NumType maxSpot,        // Maximum underlying price  
        NumType priceStep,      // Price increment
        std::function<NumType(const OptionType&)> evaluationFunction
    )
    {
        std::vector<NumType> calculatedPrices;
        calculatedPrices.reserve(static_cast<unsigned>((maxSpot - minSpot) / priceStep) + 1);

        for (NumType underlyingPrice = minSpot; underlyingPrice <= maxSpot; underlyingPrice += priceStep) {
            OptionType modifiedOption = baseOption;     // Create a copy
            modifiedOption.S(underlyingPrice);          // Update underlying price
            calculatedPrices.push_back(evaluationFunction(modifiedOption));
        }

        return calculatedPrices;
    }

    // Generate 2D matrix of option values for parameter combinations
    template<typename OptionType, typename NumType = double>
    static std::vector<std::vector<NumType>> priceMatrix(
        const OptionType& templateOption,       // Base option for calculations
        MeshGenerator<NumType>& firstParam,     // Grid for first dimension (e.g., spot prices)
        MeshGenerator<NumType>& secondParam,    // Grid for second dimension (e.g., time to expiry)
        std::function<void(OptionType&, NumType)> firstParamSetter,   // Function to set first parameter
        std::function<void(OptionType&, NumType)> secondParamSetter,  // Function to set second parameter
        std::function<NumType(const OptionType&)> valueCalculator     // Function to calculate result
    )
    {
        // Initialize result matrix
        std::vector<std::vector<NumType>> pricingMatrix;
        pricingMatrix.reserve(firstParam.size());

        // Iterate through first parameter dimension
        for (unsigned rowIndex = 0; rowIndex < firstParam.size(); ++rowIndex) {
            // Initialize current row
            std::vector<NumType> matrixRow;
            matrixRow.reserve(secondParam.size());

            // Iterate through second parameter dimension  
            for (unsigned colIndex = 0; colIndex < secondParam.size(); ++colIndex) {
                OptionType workingOption = templateOption;                 // Create working copy
                firstParamSetter(workingOption, firstParam[rowIndex]);    // Set first parameter
                secondParamSetter(workingOption, secondParam[colIndex]);  // Set second parameter
                matrixRow.push_back(valueCalculator(workingOption));      // Calculate and store result
            }

            pricingMatrix.push_back(matrixRow);
        }

        return pricingMatrix;
    }

    // Factory methods for commonly used calculation functors
    template<typename OptionType, typename NumType = double>
    static std::function<NumType(const OptionType&)> priceFunctor()
    {
        return [](const OptionType& optionInstance) { return optionInstance.price(); };
    }

    template<typename OptionType, typename NumType = double>
    static std::function<NumType(const OptionType&)> deltaFunctor()
    {
        return [](const OptionType& optionInstance) { return optionInstance.delta(); };
    }

    template<typename OptionType, typename NumType = double>
    static std::function<NumType(const OptionType&)> gammaFunctor()
    {
        return [](const OptionType& optionInstance) { return optionInstance.calcGamma(); };
    }

    template<typename OptionType, typename NumType = double>
    static std::function<NumType(const OptionType&)> vegaFunctor()
    {
        return [](const OptionType& optionInstance) { return optionInstance.calcVega(); };
    }

    template<typename OptionType, typename NumType = double>
    static std::function<NumType(const OptionType&)> ddDeltaFunctor(NumType diffStep = 0.001)
    {
        return [diffStep](const OptionType& optionInstance) { return optionInstance.calcDelta_dd(diffStep); };
    }

    template<typename OptionType, typename NumType = double>
    static std::function<NumType(const OptionType&)> ddGammaFunctor(NumType diffStep = 0.001)
    {
        return [diffStep](const OptionType& optionInstance) { return optionInstance.calcGamma_dd(diffStep); };
    }

    // Factory methods for parameter setter functors
    template<typename OptionType, typename NumType = double>
    static std::function<void(OptionType&, NumType)> setSFunctor()
    {
        return [](OptionType& optionInstance, NumType newValue) { optionInstance.S(newValue); };
    }

    template<typename OptionType, typename NumType = double>
    static std::function<void(OptionType&, NumType)> setTFunctor()
    {
        return [](OptionType& optionInstance, NumType newValue) { optionInstance.T(newValue); };
    }

    template<typename OptionType, typename NumType = double>
    static std::function<void(OptionType&, NumType)> setKFunctor()
    {
        return [](OptionType& optionInstance, NumType newValue) { optionInstance.K(newValue); };
    }

    template<typename OptionType, typename NumType = double>
    static std::function<void(OptionType&, NumType)> setRFunctor()
    {
        return [](OptionType& optionInstance, NumType newValue) { optionInstance.r(newValue); };
    }

    template<typename OptionType, typename NumType = double>
    static std::function<void(OptionType&, NumType)> setSigFunctor()
    {
        return [](OptionType& optionInstance, NumType newValue) { optionInstance.sig(newValue); };
    }

    template<typename OptionType, typename NumType = double>
    static std::function<void(OptionType&, NumType)> setBFunctor()
    {
        return [](OptionType& optionInstance, NumType newValue) { optionInstance.b(newValue); };
    }
};

#endif // MATRIX_PRICER_HPP