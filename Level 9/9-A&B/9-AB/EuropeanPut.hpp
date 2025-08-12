/**
*
* EuropeanPut.hpp
*
* Header file for the European Put class
*
* @author:  Kaushik Aryan R
* @date:    10-08-2025
* @version: 1.0
*
**/

#ifndef EUROPEAN_PUT_HPP
#define EUROPEAN_PUT_HPP

#include "OptionContract.hpp"
#include "EuropeanOption.hpp"
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include "NormalDistribution.hpp"

template<typename NumType = double>
class EuropeanPut : public EuropeanOption<NumType>
{
public:
	// Default constructor
	EuropeanPut() : EuropeanOption<NumType>() {}

	// Constructor with market parameters for put option setup
	EuropeanPut(NumType underlyingValue, NumType strikePrice, NumType expirationTime, NumType riskFreeRate, NumType volatility, NumType costOfCarry = 0)
		: EuropeanOption<NumType>(underlyingValue, strikePrice, expirationTime, riskFreeRate, volatility, costOfCarry) {}

	// Copy constructor
	EuropeanPut(const EuropeanPut<NumType>& existingPut) : EuropeanOption<NumType>(existingPut) {}

	// Destructor 
	virtual ~EuropeanPut() {}

	// Compute put option value using Black-Scholes pricing model
	NumType price() const override
	{
		// Extract market parameters from base class accessors
		NumType spotPrice = this->S();
		NumType strikePrice = this->K();
		NumType maturity = this->T();
		NumType riskFreeRate = this->r();
		NumType costOfCarry = this->b();

		// Compute standard normal distribution parameters
		NumType d1Value = this->d1();
		NumType d2Value = this->d2();

		// Black-Scholes put option pricing formula
		return strikePrice * exp(-riskFreeRate * maturity) * this->N(-d2Value)
			- spotPrice * exp((costOfCarry - riskFreeRate) * maturity) * this->N(-d1Value);
	}

	// Factory method to create shared pointer copy of put option
	virtual boost::shared_ptr<EuropeanOption<NumType>> clone() const override
	{
		return boost::make_shared<EuropeanPut<NumType>>(*this);
	}

	// Risk sensitivities (Greeks) - Financial derivatives for European put options

	// Delta: Sensitivity of put price to changes in underlying asset price
	NumType delta() const
	{
		NumType maturity = this->T();
		NumType costOfCarry = this->b();
		NumType riskFreeRate = this->r();
		NumType d1Value = this->d1();

		return (this->N(d1Value) - 1.0) * exp((costOfCarry - riskFreeRate) * maturity);
	}

	// Theta: Time decay sensitivity - rate of put price change with respect to time
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
			+ (costOfCarry - riskFreeRate) * spotPrice * exp((costOfCarry - riskFreeRate) * maturity)
			* this->N(-d1Value)
			+ riskFreeRate * strikePrice * exp(-riskFreeRate * maturity)
			* this->N(-d2Value);
	}
};

#endif // EUROPEAN_PUT_HPP