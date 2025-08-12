/**
*
* PerpetualAmericalPut.hpp
*
* Header file for the Perpetual American Put class
*
* @author:  Kaushik Aryan R
* @date:    10-08-2025
* @version: 1.0
*
**/

#ifndef PERPETUAL_AMERICAN_PUT_HPP
#define PERPETUAL_AMERICAN_PUT_HPP

#include "OptionContract.hpp"
#include "PerpetualAmericanOption.hpp"
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <cmath>

template<typename NumType = double>
class PerpetualAmericanPut : public PerpetualAmericanOption<NumType>
{
public:
	// Default constructor
	PerpetualAmericanPut() : PerpetualAmericanOption<NumType>() {}

	// Constructor with option parameters
	PerpetualAmericanPut(NumType underlyingValue, NumType strikePrice, NumType discountRate, NumType volatility, NumType costOfCarry = 0)
		: PerpetualAmericanOption<NumType>(underlyingValue, strikePrice, discountRate, volatility, costOfCarry) {}

	// Copy constructor
	PerpetualAmericanPut(const PerpetualAmericanPut<NumType>& source) : PerpetualAmericanOption<NumType>(source) {}

	// Virtual destructor 
	virtual ~PerpetualAmericanPut() {}

	// Compute perpetual American put value using closed-form analytical solution
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

		// Calculate critical parameter y2 for perpetual option formula
		NumType y2 = 0.5 - (costOfCarry / pow(volatility, 2));
		y2 -= sqrt(pow((costOfCarry / pow(volatility, 2)) - 0.5, 2)
			+ (2.0 * discountRate / pow(volatility, 2)));

		// Evaluate boundary condition when beta parameter approaches unity
		if (fabs(y2 - 1.0) > tolerance)
			// Standard perpetual American put pricing formula
			return (strikePrice / (1 - y2))
			* pow(((y2 - 1) / y2)
				* (spotPrice / strikePrice), y2);
		else
			// Special boundary case when beta approaches 1 - return spot price
			return spotPrice;
	}

	// Factory method to generate shared pointer copy of perpetual put
	virtual boost::shared_ptr<PerpetualAmericanOption<NumType>> clone() const override
	{
		return boost::make_shared<PerpetualAmericanPut<NumType>>(*this);
	}
};

#endif // PERPETUAL_AMERICAN_PUT_HPP