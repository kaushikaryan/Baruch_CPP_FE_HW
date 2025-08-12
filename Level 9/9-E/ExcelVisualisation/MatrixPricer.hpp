#ifndef MATRIX_PRICER_HPP
#define MATRIX_PRICER_HPP

#include <vector>
#include "OptionContract.hpp"
#include <functional>

 // Template class for generating parameter grids used in batch option pricing
template<typename NT = double>
class MeshGenerator
{
private:
    std::vector<NT> parameter_grid;

public:
    // Default constructor
    MeshGenerator() : parameter_grid() {}

    // Copy constructor
    MeshGenerator(const MeshGenerator& original_mesh) : parameter_grid(original_mesh.parameter_grid) {}

    // Parametric constructor
    MeshGenerator(NT range_start, NT range_end, NT increment)
    {
        for (NT current_value = range_start; current_value <= range_end; current_value += increment)
            parameter_grid.push_back(current_value);
    }

    // Destructor
    ~MeshGenerator() {}

    // Assignment operator - assigns mesh from another instance
    MeshGenerator& operator=(const MeshGenerator& other_mesh)
    {
        if (this != &other_mesh)
            parameter_grid = other_mesh.parameter_grid;
        return *this;
    }

    // Returns number of grid points
    inline size_t size() const
    {
        return parameter_grid.size();
    }

    // Array access operator for retrieving grid values
    inline NT operator[](unsigned grid_index) const
    {
        return parameter_grid[grid_index];
    }

    // Constant iterator to beginning of grid
    typename std::vector<NT>::const_iterator begin() const
    {
        return parameter_grid.begin();
    }

    // Constant iterator to end of grid
    typename std::vector<NT>::const_iterator end() const
    {
        return parameter_grid.end();
    }
};

class MatrixPricer
{
public:
    // Generate uniform parameter mesh between bounds with specified step size
    template<typename NT = double>
    static std::vector<NT> createMesh(NT lower_bound, NT upper_bound, NT step_increment)
    {
        std::vector<NT> parameter_mesh;
        for (NT current_point = lower_bound; current_point <= upper_bound; current_point += step_increment) {
            parameter_mesh.push_back(current_point);
        }
        return parameter_mesh;
    }

    // Calculate option values across range of underlying prices using custom function
    template<typename OptionType, typename NT = double>
    static std::vector<NT> priceRange(
        const OptionType& base_option,
        NT spot_min,        // Minimum underlying price
        NT spot_max,        // Maximum underlying price  
        NT price_step,      // Price increment
        std::function<NT(const OptionType&)> evaluation_function
    ) {
        std::vector<NT> calculated_prices;
        calculated_prices.reserve(static_cast<unsigned>((spot_max - spot_min) / price_step) + 1);

        for (NT underlying_price = spot_min; underlying_price <= spot_max; underlying_price += price_step) {
            OptionType modified_option = base_option;           // Create working copy
            modified_option.S(underlying_price);            // Update underlying price
            calculated_prices.push_back(evaluation_function(modified_option));
        }

        return calculated_prices;
    }

    // Simplified version using default price() method
    template<typename OptionType, typename NT = double>
    static std::vector<NT> priceRange(
        const OptionType& base_option,
        NT spot_min,        // Minimum underlying price
        NT spot_max,        // Maximum underlying price
        NT price_step       // Price increment
    ) {
        // Define pricing function using lambda expression
        std::function<NT(const OptionType&)> pricing_function =
            [](const OptionType& option_instance) { return option_instance.price(); };

        return priceRange(base_option, spot_min, spot_max, price_step, pricing_function);
    }

    // Generate 2D matrix of option values for parameter combinations
    template<typename OptionType, typename NT = double>
    static std::vector<std::vector<NT>> priceMatrix(
        const OptionType& template_option,      // Base option for calculations
        MeshGenerator<NT>& first_parameter,     // Grid for first dimension (e.g., spot prices)
        MeshGenerator<NT>& second_parameter,    // Grid for second dimension (e.g., time to expiry)
        std::function<void(OptionType&, NT)> first_param_setter,   // Function to set first parameter
        std::function<void(OptionType&, NT)> second_param_setter,  // Function to set second parameter
        std::function<NT(const OptionType&)> value_calculator      // Function to calculate result
    ) {
        // Initialize result matrix
        std::vector<std::vector<NT>> pricing_matrix;
        pricing_matrix.reserve(first_parameter.size());

        // Iterate through first parameter dimension
        for (unsigned row_index = 0; row_index < first_parameter.size(); ++row_index) {
            // Initialize current row
            std::vector<NT> matrix_row;
            matrix_row.reserve(second_parameter.size());

            // Iterate through second parameter dimension  
            for (unsigned col_index = 0; col_index < second_parameter.size(); ++col_index) {
                OptionType working_option = template_option;                    // Create working copy
                first_param_setter(working_option, first_parameter[row_index]);   // Set first parameter
                second_param_setter(working_option, second_parameter[col_index]); // Set second parameter
                matrix_row.push_back(value_calculator(working_option));         // Calculate and store result
            }

            pricing_matrix.push_back(matrix_row);
        }

        return pricing_matrix;
    }

    // Simplified matrix pricing using default price() method
    template<typename OptionType, typename NT = double>
    static std::vector<std::vector<NT>> priceMatrix(
        const OptionType& template_option,
        MeshGenerator<NT>& first_parameter,
        MeshGenerator<NT>& second_parameter,
        std::function<void(OptionType&, NT)> first_param_setter,
        std::function<void(OptionType&, NT)> second_param_setter
    ) {
        // Define default pricing function
        std::function<NT(const OptionType&)> pricing_function =
            [](const OptionType& option_instance) { return option_instance.price(); };

        return priceMatrix(
            template_option,
            first_parameter,
            second_parameter,
            first_param_setter,
            second_param_setter,
            pricing_function
        );
    }

    // Factory methods for commonly used calculation functors
    template<typename OptionType, typename NT = double>
    static std::function<NT(const OptionType&)> priceFunctor()
    {
        return [](const OptionType& option_instance) { return option_instance.price(); };
    }

    template<typename OptionType, typename NT = double>
    static std::function<NT(const OptionType&)> deltaFunctor()
    {
        return [](const OptionType& option_instance) { return option_instance.delta(); };
    }

    template<typename OptionType, typename NT = double>
    static std::function<NT(const OptionType&)> gammaFunctor()
    {
        return [](const OptionType& option_instance) { return option_instance.calcGamma(); };
    }

    template<typename OptionType, typename NT = double>
    static std::function<NT(const OptionType&)> vegaFunctor()
    {
        return [](const OptionType& option_instance) { return option_instance.calcVega(); };
    }

    template<typename OptionType, typename NT = double>
    static std::function<NT(const OptionType&)> ddDeltaFunctor(NT finite_diff_step = 0.001)
    {
        return [finite_diff_step](const OptionType& option_instance) {
            return option_instance.calcDelta_dd(finite_diff_step);
            };
    }

    template<typename OptionType, typename NT = double>
    static std::function<NT(const OptionType&)> ddGammaFunctor(NT finite_diff_step = 0.001)
    {
        return [finite_diff_step](const OptionType& option_instance) {
            return option_instance.calcGamma_dd(finite_diff_step);
            };
    }

    // Factory methods for parameter setter functors
    template<typename OptionType, typename NT = double>
    static std::function<void(OptionType&, NT)> setSFunctor()
    {
        return [](OptionType& option_instance, NT new_value) { option_instance.S(new_value); };
    }

    template<typename OptionType, typename NT = double>
    static std::function<void(OptionType&, NT)> setTFunctor()
    {
        return [](OptionType& option_instance, NT new_value) { option_instance.T(new_value); };
    }

    template<typename OptionType, typename NT = double>
    static std::function<void(OptionType&, NT)> setKFunctor()
    {
        return [](OptionType& option_instance, NT new_value) { option_instance.K(new_value); };
    }

    template<typename OptionType, typename NT = double>
    static std::function<void(OptionType&, NT)> setRFunctor()
    {
        return [](OptionType& option_instance, NT new_value) { option_instance.r(new_value); };
    }

    template<typename OptionType, typename NT = double>
    static std::function<void(OptionType&, NT)> setSigFunctor()
    {
        return [](OptionType& option_instance, NT new_value) { option_instance.sig(new_value); };
    }

    template<typename OptionType, typename NT = double>
    static std::function<void(OptionType&, NT)> setBFunctor()
    {
        return [](OptionType& option_instance, NT new_value) { option_instance.b(new_value); };
    }
};

#endif // MATRIX_PRICER_HPP