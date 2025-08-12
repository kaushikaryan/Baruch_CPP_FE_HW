#ifndef PERPETUAL_AMERICAN_CALL_HPP
#define PERPETUAL_AMERICAN_CALL_HPP

#include "OptionContract.hpp"
#include "PerpetualAmericanOption.hpp"
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <cmath>

template<typename NT = double>
class PerpetualAmericanCall : public PerpetualAmericanOption<NT>
{
public:
	// Default constructor - creates perpetual call with base class defaults
	PerpetualAmericanCall() : PerpetualAmericanOption<NT>() {}

	// Parameterized constructor for perpetual American call initialization
	PerpetualAmericanCall(NT underlying_value, NT strike_price, NT discount_rate, NT volatility, NT cost_of_carry = 0)
		: PerpetualAmericanOption<NT>(underlying_value, strike_price, discount_rate, volatility, cost_of_carry) {}

	// Copy constructor - duplicates existing perpetual call option
	PerpetualAmericanCall(const PerpetualAmericanCall<NT>& original_call) : PerpetualAmericanOption<NT>(original_call) {}

	// Virtual destructor for proper inheritance cleanup
	virtual ~PerpetualAmericanCall() {}

	// Calculate perpetual American call option price using analytical solution
	NT price() const override
	{
		// Numerical tolerance for boundary condition checking
		const NT convergence_threshold = 1e-10;

		// Extract option parameters from base class
		NT current_price = this->S();
		NT exercise_strike = this->K();
		NT interest_rate = this->r();
		NT dividend_rate = this->b();
		NT vol_coeff = this->sig();

		// Calculate critical parameter y1 for perpetual option formula
		NT gamma_param = 0.5 - (dividend_rate / pow(vol_coeff, 2));
		gamma_param += sqrt(pow((dividend_rate / pow(vol_coeff, 2)) - 0.5, 2)
			+ (2.0 * interest_rate / pow(vol_coeff, 2)));

		// Check if gamma parameter is near unity (special boundary case)
		if (fabs(gamma_param - 1.0) > convergence_threshold)
			// Standard perpetual American call pricing formula
			return (exercise_strike / (gamma_param - 1))
			* pow(((gamma_param - 1) / gamma_param)
				* (current_price / exercise_strike), gamma_param);
		else
			// Boundary case when gamma approaches 1 - option value equals spot price
			return current_price;
	}

	// Factory method to create shared pointer copy of perpetual call
	virtual boost::shared_ptr<PerpetualAmericanOption<NT>> clone() const override
	{
		return boost::make_shared<PerpetualAmericanCall<NT>>(*this);
	}
};

#endif // PERPETUAL_AMERICAN_CALL_HPP