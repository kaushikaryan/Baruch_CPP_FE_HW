#ifndef OPTION_BASE_HPP
#define OPTION_BASE_HPP
#include <stdexcept>

template<typename NumericType>
class OptionContract
{
private:
	NumericType underlying_price;    // Current price of underlying asset
	NumericType exercise_price;      // Strike price for option exercise
	NumericType time_remaining;      // Time until option expiration
	NumericType interest_rate;       // Risk-free interest rate
	NumericType volatility;          // Implied volatility of underlying
	NumericType carry_rate;          // Cost of carry rate

public:
	// Default constructor
	OptionContract() : underlying_price(), exercise_price(), time_remaining(),
		interest_rate(), volatility(), carry_rate() {
	};

	// Copy constructor
	OptionContract(const OptionContract<NumericType>& original)
		: underlying_price(original.underlying_price), exercise_price(original.exercise_price),
		time_remaining(original.time_remaining), interest_rate(original.interest_rate),
		volatility(original.volatility), carry_rate(original.carry_rate) {
	};

	// Constructor that takes option parameters as input and validates them
	OptionContract(NumericType spot, NumericType strike, NumericType maturity,
		NumericType rate, NumericType vol, NumericType carry)
	{
		// Input validation with descriptive error messages
		if (spot <= 0) throw std::invalid_argument("Underlying asset price must be positive");
		if (strike <= 0) throw std::invalid_argument("Strike price must be positive");
		if (maturity < 0) throw std::invalid_argument("Time to maturity must be non-negative");
		if (vol < 0) throw std::invalid_argument("Volatility parameter must be non-negative");

		// Initialize member variables
		underlying_price = spot;
		exercise_price = strike;
		time_remaining = maturity;
		interest_rate = rate;
		volatility = vol;
		carry_rate = carry;
	};

	// Virtual destructor for proper inheritance cleanup
	virtual ~OptionContract() {};

	// Pure virtual function for option pricing - implemented by derived classes
	virtual NumericType price() const = 0;

	// Accessor methods for retrieving contract parameters
	NumericType S() const { return underlying_price; };
	NumericType K() const { return exercise_price; };
	NumericType T() const { return time_remaining; };
	NumericType r() const { return interest_rate; };
	NumericType sig() const { return volatility; };
	NumericType b() const { return carry_rate; };

	// Mutator methods with input validation
	inline void S(NumericType new_value)
	{
		if (new_value <= 0) throw std::invalid_argument("Underlying asset price must be positive");
		underlying_price = new_value;
	}

	inline void K(NumericType new_value)
	{
		if (new_value <= 0) throw std::invalid_argument("Strike price must be positive");
		exercise_price = new_value;
	}

	inline void T(NumericType new_value)
	{
		if (new_value < 0) throw std::invalid_argument("Time-to-expiry must be non-negative");
		time_remaining = new_value;
	}

	inline void r(NumericType new_value) { interest_rate = new_value; }

	inline void sig(NumericType new_value)
	{
		if (new_value < 0)
			throw std::invalid_argument("Volatility parameter must be non-negative");

		volatility = new_value;
	}

	inline void b(NumericType new_value) { carry_rate = new_value; }

	// Bulk parameter update method with validation
	inline void setParameters(NumericType spot, NumericType strike, NumericType maturity,
		NumericType rate, NumericType vol, NumericType carry = 0)
	{
		// Comprehensive input validation
		if (spot <= 0) throw std::invalid_argument("Underlying asset price must be positive");
		if (strike <= 0) throw std::invalid_argument("Strike price must be positive");
		if (maturity < 0) throw std::invalid_argument("Time to maturity must be non-negative");
		if (vol < 0) throw std::invalid_argument("Volatility parameter must be non-negative");

		// Update all contract parameters
		underlying_price = spot;
		exercise_price = strike;
		time_remaining = maturity;
		interest_rate = rate;
		volatility = vol;
		carry_rate = carry;
	}
};

#endif	// CONTRACT_BASE_HPP
