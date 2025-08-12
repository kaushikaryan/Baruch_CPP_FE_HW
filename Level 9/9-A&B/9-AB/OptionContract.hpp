/**
*
* OptionContractbase.hpp
*
* Header file for the Option Contract Base class
*
* @author:  Kaushik Aryan R
* @date:    10-08-2025
* @version: 1.0
*
**/

#ifndef OPTION_BASE_HPP
#define OPTION_BASE_HPP
#include <stdexcept>

template<typename NumType>
class OptionContract
{
private:
	NumType underlyingValue;  // Current price of underlying asset
	NumType strikePrice;      // Strike price for option exercise
	NumType expirationTime;   // Time until option expiration
	NumType riskFreeRate;     // Risk-free interest rate
	NumType volatility;       // Implied volatility of underlying
	NumType costOfCarry;      // Cost of carry rate

public:
	// Default constructor
	OptionContract() : underlyingValue(), strikePrice(), expirationTime(),
		riskFreeRate(), volatility(), costOfCarry() {
	};

	// Copy constructor
	OptionContract(const OptionContract<NumType>& original)
		: underlyingValue(original.underlyingValue), strikePrice(original.strikePrice),
		expirationTime(original.expirationTime), riskFreeRate(original.riskFreeRate),
		volatility(original.volatility), costOfCarry(original.costOfCarry) {
	};

	// Constructor that takes option parameters as input and validates them
	OptionContract(NumType spot, NumType strike, NumType maturity,
		NumType rate, NumType vol, NumType carry)
	{
		// Input validation with descriptive error messages
		if (spot <= 0) throw std::invalid_argument("Underlying asset value must be positive");
		if (strike <= 0) throw std::invalid_argument("Strike price must be positive");
		if (maturity < 0) throw std::invalid_argument("Time to maturity must be non-negative");
		if (vol < 0) throw std::invalid_argument("Volatility parameter must be non-negative");

		// Initialize member variables
		underlyingValue = spot;
		strikePrice = strike;
		expirationTime = maturity;
		riskFreeRate = rate;
		volatility = vol;
		costOfCarry = carry;
	};

	// Virtual destructor for proper inheritance cleanup
	virtual ~OptionContract() {};

	// Pure virtual function for option pricing - implemented by derived classes
	virtual NumType price() const = 0;

	// Accessor methods for retrieving contract parameters
	NumType S() const { return underlyingValue; };
	NumType K() const { return strikePrice; };
	NumType T() const { return expirationTime; };
	NumType r() const { return riskFreeRate; };
	NumType sig() const { return volatility; };
	NumType b() const { return costOfCarry; };

	// Mutator methods with input validation
	inline void S(NumType source)
	{
		if (source <= 0)
			throw std::invalid_argument("Underlying asset price must be positive");

		underlyingValue = source;
	}

	inline void K(NumType source)
	{
		if (source <= 0)
			throw std::invalid_argument("Strike price must be positive");

		strikePrice = source;
	}

	inline void T(NumType source)
	{
		if (source < 0)
			throw std::invalid_argument("Time-to-expiry must be non-negative");

		expirationTime = source;
	}

	inline void r(NumType source)
	{
		riskFreeRate = source;
	}

	inline void sig(NumType source)
	{
		if (source < 0)
			throw std::invalid_argument("Volatility parameter must be non-negative");

		volatility = source;
	}

	inline void b(NumType source)
	{
		costOfCarry = source;
	}

	// Bulk parameter update method with validation
	inline void setParameters(NumType spot, NumType strike, NumType maturity,
		NumType rate, NumType vol, NumType carry = 0)
	{
		// Comprehensive input validation
		if (spot <= 0)
			throw std::invalid_argument("Underlying asset price must be positive");

		if (strike <= 0)
			throw std::invalid_argument("Strike price must be positive");

		if (maturity < 0)
			throw std::invalid_argument("Time to maturity must be non-negative");

		if (vol < 0)
			throw std::invalid_argument("Volatility parameter must be non-negative");

		// Update all contract parameters
		underlyingValue = spot;
		strikePrice = strike;
		expirationTime = maturity;
		riskFreeRate = rate;
		volatility = vol;
		costOfCarry = carry;
	}
};

#endif	// CONTRACT_BASE_HPP
