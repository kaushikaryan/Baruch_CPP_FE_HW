/**
*
* PerpetualAmericalOption.hpp
*
* Header file for the Perpetual American Option base class
*
* @author:  Kaushik Aryan R
* @date:    10-08-2025
* @version: 1.0
*
**/

#ifndef PERPETUAL_AMERICAN_OPTION_HPP
#define PERPETUAL_AMERICAN_OPTION_HPP

#include "OptionContract.hpp"
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

template <typename NumType>
class PerpetualAmericanOption : public OptionContract<NumType>
{
public:
    // Default constructor
    PerpetualAmericanOption() : OptionContract<NumType>() {}

    // Constructor that takes option parameters as input
    PerpetualAmericanOption(NumType underlyingValue, NumType strikePrice, NumType discountRate, NumType volatility, NumType costOfCarry = 0)
        : OptionContract<NumType>(underlyingValue, strikePrice, 0.0, discountRate, volatility, costOfCarry) {}

    // Copy constructor
    PerpetualAmericanOption(const PerpetualAmericanOption<NumType>& other) : OptionContract<NumType>(other) {}

    // Destructor
    virtual ~PerpetualAmericanOption() {}

    // Abstract method
    virtual NumType price() const override = 0;

    // Abstract cloning method for creating copies of derived class instances
    virtual boost::shared_ptr<PerpetualAmericanOption<NumType>> clone() const = 0;
};

#endif // PERPETUAL_AMERICAN_OPTION_HPP