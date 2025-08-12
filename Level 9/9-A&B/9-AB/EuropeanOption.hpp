/**
*
* EuropeanOption.hpp
*
* Header file for the European Option Base class
*
* @author:  Kaushik Aryan R
* @date:    10-08-2025
* @version: 1.0
*
**/

#ifndef EURO_OPTION_BASE_HPP
#define EURO_OPTION_BASE_HPP

#include <cmath>
#include "NormalDistribution.hpp"
#include "OptionContract.hpp"
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

template <typename NumType>
class EuropeanOption : public OptionContract<NumType>
{
protected:
	// Standard normal probability density function helper
	NumType n(NumType value) const
	{
		return NormalDistribution<NumType>::pdf(value);
	}

	// Standard normal cumulative distribution function helper
	NumType N(NumType value) const
	{
		return NormalDistribution<NumType>::cdf(value);
	}

public:
	// Default constructor
	EuropeanOption() : OptionContract<NumType>() {}

	// Constructor that takes option parameters as input
	EuropeanOption(NumType underlyingValue, NumType strikePrice, NumType expirationTime,
		NumType riskFreeRate, NumType volatility, NumType costOfCarry = 0)
		: OptionContract<NumType>(underlyingValue, strikePrice, expirationTime, riskFreeRate, volatility, costOfCarry) {}

	// Copy constructor
	EuropeanOption(const EuropeanOption<NumType>& other)
		: OptionContract<NumType>(other) {}

	// Virtual destructor
	virtual ~EuropeanOption() {}

	// Abstract pricing method
	virtual NumType price() const override = 0;

	// Black-Scholes formula helper functions
	// First Black-Scholes parameter calculation
	NumType d1() const {
		NumType spotPrice = this->S();
		NumType strikePrice = this->K();
		NumType maturity = this->T();
		NumType riskFreeRate = this->r();
		NumType volatility = this->sig();
		NumType costOfCarry = this->b();

		return (log(spotPrice / strikePrice) + (costOfCarry + 0.5 * volatility * volatility) * maturity)
			/ (volatility * sqrt(maturity));
	}

	// Second Black-Scholes parameter calculation
	NumType d2() const {
		return d1() - this->sig() * sqrt(this->T());
	}

	// Convert call option price to put option price via parity relationship
	static NumType callToPut(const EuropeanOption<NumType>& callOption, NumType callPrice) {
		NumType spotPrice = callOption.S();
		NumType strikePrice = callOption.K();
		NumType maturity = callOption.T();
		NumType riskFreeRate = callOption.r();

		return callPrice + strikePrice * exp(-riskFreeRate * maturity) - spotPrice;
	}

	// Convert put option price to call option price via parity relationship
	static NumType putToCall(const EuropeanOption<NumType>& putOption, NumType putPrice) {
		NumType spotPrice = putOption.S();
		NumType strikePrice = putOption.K();
		NumType maturity = putOption.T();
		NumType riskFreeRate = putOption.r();

		return putPrice - strikePrice * exp(-riskFreeRate * maturity) + spotPrice;
	}

	// Validate put-call parity relationship
	static bool putCallParityCheck(
		const EuropeanOption<NumType>& callOption,
		const EuropeanOption<NumType>& putOption,
		NumType tolerance = 1e-5)
	{
		// Extract common parameters
		NumType spotPrice = callOption.S();
		NumType strikePrice = callOption.K();
		NumType maturity = callOption.T();
		NumType riskFreeRate = callOption.r();

		// Calculate option values
		NumType callValue = callOption.price();
		NumType putValue = putOption.price();

		// Evaluate parity equation: C + K*e^(-r*T) = P + S
		NumType leftSide = callValue + strikePrice * exp(-riskFreeRate * maturity);
		NumType rightSide = putValue + spotPrice;

		// Check if difference is within tolerance
		return fabs(leftSide - rightSide) < tolerance;
	}

	// Greek sensitivities - applicable to both calls and puts

	// Gamma: second-order sensitivity to underlying price changes
	NumType calcGamma() const {
		NumType spotPrice = this->S();
		NumType maturity = this->T();
		NumType volatility = this->sig();
		NumType costOfCarry = this->b();
		NumType riskFreeRate = this->r();
		NumType d1Value = d1();

		return n(d1Value) * exp((costOfCarry - riskFreeRate) * maturity)
			/ (spotPrice * volatility * sqrt(maturity));
	}

	// Vega: sensitivity to volatility changes
	NumType calcVega() const {
		NumType spotPrice = this->S();
		NumType maturity = this->T();
		NumType costOfCarry = this->b();
		NumType riskFreeRate = this->r();
		NumType d1Value = d1();

		return spotPrice * sqrt(maturity) * exp((costOfCarry - riskFreeRate) * maturity)
			* n(d1Value);
	}

	// Numerical delta approximation using finite differences
	NumType calcDelta_dd(NumType step = 0.001) const {
		// Create option instances with perturbed underlying prices
		boost::shared_ptr<EuropeanOption<NumType>> upwardOption = this->clone();
		upwardOption->S(this->S() + step);

		boost::shared_ptr<EuropeanOption<NumType>> downwardOption = this->clone();
		downwardOption->S(this->S() - step);

		// Calculate option prices at perturbed points
		NumType upwardPrice = upwardOption->price();
		NumType downwardPrice = downwardOption->price();

		// Return central difference approximation
		return (upwardPrice - downwardPrice) / (2.0 * step);
	}

	// Numerical gamma approximation using finite differences
	NumType calcGamma_dd(NumType step = 0.001) const {
		// Create option instances with perturbed underlying prices
		boost::shared_ptr<EuropeanOption<NumType>> baseOption = this->clone();

		boost::shared_ptr<EuropeanOption<NumType>> upwardOption = this->clone();
		upwardOption->S(this->S() + step);

		boost::shared_ptr<EuropeanOption<NumType>> downwardOption = this->clone();
		downwardOption->S(this->S() - step);

		// Calculate option prices
		NumType basePrice = baseOption->price();
		NumType upwardPrice = upwardOption->price();
		NumType downwardPrice = downwardOption->price();

		// Return second-order central difference approximation
		return (upwardPrice - 2.0 * basePrice + downwardPrice) / (step * step);
	}

	// Abstract method for creating copies
	virtual boost::shared_ptr<EuropeanOption<NumType>> clone() const = 0;
};

#endif // EURO_OPTION_BASE_HPP