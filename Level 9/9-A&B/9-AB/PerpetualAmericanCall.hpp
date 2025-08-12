/**
*
* PerpetualAmericalCall.hpp
*
* Header file for the Perpetual American Call class
*
* @author:  Kaushik Aryan R
* @date:    10-08-2025
* @version: 1.0
*
**/

#ifndef PERPETUAL_AMERICAN_CALL_HPP
#define PERPETUAL_AMERICAN_CALL_HPP

#include "OptionContract.hpp"
#include "PerpetualAmericanOption.hpp"
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <cmath>

template<typename NumType = double>
class PerpetualAmericanCall : public PerpetualAmericanOption<NumType>
{
public:
	// Default constructor
	PerpetualAmericanCall() : PerpetualAmericanOption<NumType>() {}

	// Constructor with option parameters
	PerpetualAmericanCall(NumType underlyingValue, NumType strikePrice, NumType discountRate, NumType volatility, NumType costOfCarry = 0)
		: PerpetualAmericanOption<NumType>(underlyingValue, strikePrice, discountRate, volatility, costOfCarry) {}

	// Copy constructor
	PerpetualAmericanCall(const PerpetualAmericanCall<NumType>& source) : PerpetualAmericanOption<NumType>(source) {}

	// Virtual destructor
	virtual ~PerpetualAmericanCall() {}

	// Compute perpetual American call value using closed-form analytical solution
	NumType price() const override
	{
		// Numerical tolerance for boundary condition checking
		const NumType tolerance = 1e-10;

		// Extract option parameters from base class
		NumType spotPrice = this->S();
		NumType strikePrice = this->K();
		NumType discountRate = this->r();
		NumType costOfCarry = this->b();
		NumType volatility = this->sig();

		// Calculate critical parameter y1 for perpetual option formula
		NumType y1 = 0.5 - (costOfCarry / pow(volatility, 2));
		y1 += sqrt(pow((costOfCarry / pow(volatility, 2)) - 0.5, 2)
			+ (2.0 * discountRate / pow(volatility, 2)));

		// Check if gamma parameter is near unity (special boundary case)
		if (fabs(y1 - 1.0) > tolerance)
			// Standard perpetual American call pricing formula
			return (strikePrice / (y1 - 1))
			* pow(((y1 - 1) / y1)
				* (spotPrice / strikePrice), y1);
		else
			// Boundary case when gamma approaches 1 - option value equals spot price
			return spotPrice;
	}

	// Factory method to create shared pointer copy of perpetual call
	virtual boost::shared_ptr<PerpetualAmericanOption<NumType>> clone() const override
	{
		return boost::make_shared<PerpetualAmericanCall<NumType>>(*this);
	}
};

#endif // PERPETUAL_AMERICAN_CALL_HPP