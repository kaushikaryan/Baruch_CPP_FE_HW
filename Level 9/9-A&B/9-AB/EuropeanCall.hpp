/**
*
* EuropeanCall.hpp
*
* Header file for the European Call class
*
* @author:  Kaushik Aryan R
* @date:    10-08-2025
* @version: 1.0
*
**/

#ifndef EUROPEAN_CALL_HPP
#define EUROPEAN_CALL_HPP

#include "OptionContract.hpp"
#include "EuropeanOption.hpp"
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include "NormalDistribution.hpp"

template<typename NumType = double>
class EuropeanCall : public EuropeanOption<NumType>
{
public:
    // Default constructor
    EuropeanCall() : EuropeanOption<NumType>() {}

    // Parameterized constructor for call option initialization
    EuropeanCall(NumType underlyingValue, NumType strikePrice, NumType expirationTime, NumType riskFreeRate, NumType volatility, NumType costOfCarry = 0)
        : EuropeanOption<NumType>(underlyingValue, strikePrice, expirationTime, riskFreeRate, volatility, costOfCarry) {}

    // Copy constructor
    EuropeanCall(const EuropeanCall<NumType>& original) : EuropeanOption<NumType>(original) {}

    // Virtual destructor for proper cleanup
    virtual ~EuropeanCall() {}

    // Calculate call option price using Black-Scholes formula
    NumType price() const override
    {
        // Retrieve option parameters from base class
        NumType spotPrice = this->S();
        NumType strikePrice = this->K();
        NumType maturity = this->T();
        NumType riskFreeRate = this->r();
        NumType costOfCarry = this->b();

        // Calculate Black-Scholes parameters
        NumType d1Value = this->d1();
        NumType d2Value = this->d2();

        // Apply generalized Black-Scholes pricing formula for call
        return spotPrice * exp((costOfCarry - riskFreeRate) * maturity) * this->N(d1Value)
            - strikePrice * exp(-riskFreeRate * maturity) * this->N(d2Value);
    }

    // Create a copy of this call option instance
    virtual boost::shared_ptr<EuropeanOption<NumType>> clone() const override
    {
        return boost::make_shared<EuropeanCall<NumType>>(*this);
    }

    // Greek sensitivities - Risk measures for European call options

    // Delta: Rate of change of option price with respect to underlying asset price
    NumType delta() const
    {
        NumType maturity = this->T();
        NumType riskFreeRate = this->r();
        NumType costOfCarry = this->b();
        NumType d1Value = this->d1();

        return this->N(d1Value) * exp((costOfCarry - riskFreeRate) * maturity);
    }

    // Theta: Rate of change of option price with respect to time (time decay)
    NumType theta() const
    {
        NumType spotPrice = this->S();
        NumType strikePrice = this->K();
        NumType maturity = this->T();
        NumType riskFreeRate = this->r();
        NumType volatility = this->sig();
        NumType costOfCarry = this->b();
        NumType d1Value = this->d1();
        NumType d2Value = this->d2();

        return -((spotPrice * volatility * exp((costOfCarry - riskFreeRate) * maturity)
            * this->n(d1Value)) / (2.0 * sqrt(maturity)))
            - (costOfCarry - riskFreeRate) * spotPrice * exp((costOfCarry - riskFreeRate) * maturity)
            * this->N(d1Value)
            - riskFreeRate * strikePrice * exp(-riskFreeRate * maturity)
            * this->N(d2Value);
    }
};

#endif // EUROPEAN_CALL_HPP