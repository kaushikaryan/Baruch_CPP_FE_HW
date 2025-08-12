#ifndef PERPETUAL_AMERICAN_PUT_HPP
#define PERPETUAL_AMERICAN_PUT_HPP

#include "OptionContract.hpp"
#include "PerpetualAmericanOption.hpp"
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <cmath>

template<typename NT = double>
class PerpetualAmericanPut : public PerpetualAmericanOption<NT>
{
public:
	// Default constructor
	PerpetualAmericanPut() : PerpetualAmericanOption<NT>() {}

	// Constructor with market parameters for perpetual American put setup
	PerpetualAmericanPut(NT underlying_value, NT strike_price, NT discount_rate, NT volatility, NT cost_of_carry = 0)
		: PerpetualAmericanOption<NT>(underlying_value, strike_price, discount_rate, volatility, cost_of_carry) {}

	// Copy constructor - creates duplicate perpetual put from existing instance
	PerpetualAmericanPut(const PerpetualAmericanPut<NT>& existing_put) : PerpetualAmericanOption<NT>(existing_put) {}

	// Virtual destructor ensures proper resource management
	virtual ~PerpetualAmericanPut() {}

	// Compute perpetual American put value using closed-form analytical solution
	NT price() const override
	{
		// Numerical precision threshold for boundary condition evaluation
		const NT tolerance_limit = 1e-10;

		// Retrieve option characteristics from base class accessors
		NT spot_price = this->S();
		NT strike_level = this->K();
		NT interest_rate = this->r();
		NT dividend_yield = this->b();
		NT volatility_coeff = this->sig();

		// Calculate critical root parameter y2 for perpetual put pricing
		NT beta_coefficient = 0.5 - (dividend_yield / pow(volatility_coeff, 2));
		beta_coefficient -= sqrt(pow((dividend_yield / pow(volatility_coeff, 2)) - 0.5, 2)
			+ (2.0 * interest_rate / pow(volatility_coeff, 2)));

		// Evaluate boundary condition when beta parameter approaches unity
		if (fabs(beta_coefficient - 1.0) > tolerance_limit)
			// Standard perpetual American put pricing formula
			return (strike_level / (1 - beta_coefficient))
			* pow(((beta_coefficient - 1) / beta_coefficient)
				* (spot_price / strike_level), beta_coefficient);
		else
			// Special boundary case when beta approaches 1 - return spot price
			return spot_price;
	}

	// Factory method to generate shared pointer copy of perpetual put
	virtual boost::shared_ptr<PerpetualAmericanOption<NT>> clone() const override
	{
		return boost::make_shared<PerpetualAmericanPut<NT>>(*this);
	}
};

#endif // PERPETUAL_AMERICAN_PUT_HPP