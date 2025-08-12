#ifndef EURO_OPTION_BASE_HPP
#define EURO_OPTION_BASE_HPP

#include <cmath>
#include "NormalDistribution.hpp"
#include "OptionContract.hpp"
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

template <typename NumericType>
class EuropeanOption : public OptionContract<NumericType>
{
protected:
	// Standard normal probability density function helper
	NumericType n(NumericType value) const
	{
		return NormalDistribution<NumericType>::pdf(value);
	}

	// Standard normal cumulative distribution function helper
	NumericType N(NumericType value) const
	{
		return NormalDistribution<NumericType>::cdf(value);
	}

public:
	// Default constructor
	EuropeanOption() : OptionContract<NumericType>() {}

	// Constructor that takes option parameters as input
	EuropeanOption(NumericType spot, NumericType strike, NumericType maturity,
		NumericType risk_rate, NumericType volatility, NumericType cost_of_carry = 0)
		: OptionContract<NumericType>(spot, strike, maturity, risk_rate, volatility, cost_of_carry) {}

	// Copy constructor
	EuropeanOption(const EuropeanOption<NumericType>& other)
		: OptionContract<NumericType>(other) {}

	// Virtual destructor
	virtual ~EuropeanOption() {}

	// Abstract pricing method
	virtual NumericType price() const override = 0;

	// Black-Scholes formula helper functions
	// First Black-Scholes parameter calculation
	NumericType d1() const {
		NumericType spot = this->S();
		NumericType strike = this->K();
		NumericType maturity = this->T();
		NumericType risk_rate = this->r();
		NumericType volatility = this->sig();
		NumericType carry_cost = this->b();

		return (log(spot / strike) + (carry_cost + 0.5 * volatility * volatility) * maturity)
			/ (volatility * sqrt(maturity));
	}

	// Second Black-Scholes parameter calculation
	NumericType d2() const {
		return d1() - this->sig() * sqrt(this->T());
	}

	// Convert call option price to put option price via parity relationship
	static NumericType callToPut(const EuropeanOption<NumericType>& call_option, NumericType call_price) {
		NumericType spot = call_option.S();
		NumericType strike = call_option.K();
		NumericType maturity = call_option.T();
		NumericType risk_rate = call_option.r();

		return call_price + strike * exp(-risk_rate * maturity) - spot;
	}

	// Convert put option price to call option price via parity relationship
	static NumericType putToCall(const EuropeanOption<NumericType>& put_option, NumericType put_price) {
		NumericType spot = put_option.S();
		NumericType strike = put_option.K();
		NumericType maturity = put_option.T();
		NumericType risk_rate = put_option.r();

		return put_price - strike * exp(-risk_rate * maturity) + spot;
	}

	// Validate put-call parity relationship
	static bool putCallParityCheck(
		const EuropeanOption<NumericType>& call_option,
		const EuropeanOption<NumericType>& put_option,
		NumericType tolerance = 1e-5)
	{
		// Extract common parameters
		NumericType spot = call_option.S();
		NumericType strike = call_option.K();
		NumericType maturity = call_option.T();
		NumericType risk_rate = call_option.r();

		// Calculate option values
		NumericType call_value = call_option.price();
		NumericType put_value = put_option.price();

		// Evaluate parity equation: C + K*e^(-r*T) = P + S
		NumericType left_side = call_value + strike * exp(-risk_rate * maturity);
		NumericType right_side = put_value + spot;

		// Check if difference is within tolerance
		return fabs(left_side - right_side) < tolerance;
	}

	// Greek sensitivities - applicable to both calls and puts

	// Gamma: second-order sensitivity to underlying price changes
	NumericType calcGamma() const {
		NumericType spot = this->S();
		NumericType maturity = this->T();
		NumericType volatility = this->sig();
		NumericType carry_cost = this->b();
		NumericType risk_rate = this->r();
		NumericType d1_value = d1();

		return n(d1_value) * exp((carry_cost - risk_rate) * maturity)
			/ (spot * volatility * sqrt(maturity));
	}

	// Vega: sensitivity to volatility changes
	NumericType calcVega() const {
		NumericType spot = this->S();
		NumericType maturity = this->T();
		NumericType carry_cost = this->b();
		NumericType risk_rate = this->r();
		NumericType d1_value = d1();

		return spot * sqrt(maturity) * exp((carry_cost - risk_rate) * maturity)
			* n(d1_value);
	}

	// Numerical delta approximation using finite differences
	NumericType calcDelta_dd(NumericType step_size = 0.001) const {
		// Create option instances with perturbed underlying prices
		boost::shared_ptr<EuropeanOption<NumericType>> upward_option = this->clone();
		upward_option->S(this->S() + step_size);

		boost::shared_ptr<EuropeanOption<NumericType>> downward_option = this->clone();
		downward_option->S(this->S() - step_size);

		// Calculate option prices at perturbed points
		NumericType upward_price = upward_option->price();
		NumericType downward_price = downward_option->price();

		// Return central difference approximation
		return (upward_price - downward_price) / (2.0 * step_size);
	}

	// Numerical gamma approximation using finite differences
	NumericType calcGamma_dd(NumericType step_size = 0.001) const {
		// Create option instances with perturbed underlying prices
		boost::shared_ptr<EuropeanOption<NumericType>> base_option = this->clone();

		boost::shared_ptr<EuropeanOption<NumericType>> upward_option = this->clone();
		upward_option->S(this->S() + step_size);

		boost::shared_ptr<EuropeanOption<NumericType>> downward_option = this->clone();
		downward_option->S(this->S() - step_size);

		// Calculate option prices
		NumericType base_price = base_option->price();
		NumericType upward_price = upward_option->price();
		NumericType downward_price = downward_option->price();

		// Return second-order central difference approximation
		return (upward_price - 2.0 * base_price + downward_price) / (step_size * step_size);
	}

	// Abstract method for creating copies
	virtual boost::shared_ptr<EuropeanOption<NumericType>> clone() const = 0;
};

#endif // EURO_OPTION_BASE_HPP