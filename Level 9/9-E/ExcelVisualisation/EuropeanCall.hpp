#ifndef EUROPEAN_CALL_HPP
#define EUROPEAN_CALL_HPP

#include "OptionContract.hpp"
#include "EuropeanOption.hpp"
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include "NormalDistribution.hpp"

template<typename NT = double>
class EuropeanCall : public EuropeanOption<NT>
{
public:
    // Default constructor
    EuropeanCall() : EuropeanOption<NT>() {}

    // Parameterized constructor for call option initialization
    EuropeanCall(NT underlying_price, NT strike_price, NT expiration_time, NT risk_free_rate, NT volatility, NT cost_of_carry = 0)
        : EuropeanOption<NT>(underlying_price, strike_price, expiration_time, risk_free_rate, volatility, cost_of_carry) {}

    // Copy constructor
    EuropeanCall(const EuropeanCall<NT>& original) : EuropeanOption<NT>(original) {}

    // Virtual destructor for proper cleanup
    virtual ~EuropeanCall() {}

    // Calculate call option price using Black-Scholes formula
    NT price() const override
    {
        // Retrieve option parameters from base class
        NT spot_price = this->S();
        NT strike_value = this->K();
        NT expiry_time = this->T();
        NT rate = this->r();
        NT carry_cost = this->b();

        // Calculate Black-Scholes parameters
        NT d1_parameter = this->d1();
        NT d2_parameter = this->d2();

        // Apply generalized Black-Scholes pricing formula for call
        return spot_price * exp((carry_cost - rate) * expiry_time) * this->N(d1_parameter)
            - strike_value * exp(-rate * expiry_time) * this->N(d2_parameter);
    }

    // Create a copy of this call option instance
    virtual boost::shared_ptr<EuropeanOption<NT>> clone() const override
    {
        return boost::make_shared<EuropeanCall<NT>>(*this);
    }

    // Greek sensitivities - Risk measures for European call options

    // Delta: Rate of change of option price with respect to underlying asset price
    NT delta() const
    {
        NT maturity = this->T();
        NT carry_rate = this->b();
        NT interest_rate = this->r();
        NT d1_value = this->d1();

        return this->N(d1_value) * exp((carry_rate - interest_rate) * maturity);
    }

    // Theta: Rate of change of option price with respect to time (time decay)
    NT theta() const
    {
        NT current_spot = this->S();
        NT time_remaining = this->T();
        NT implied_vol = this->sig();
        NT carry = this->b();
        NT discount_rate = this->r();
        NT exercise_price = this->K();
        NT d1_calc = this->d1();
        NT d2_calc = this->d2();

        return -((current_spot * implied_vol * exp((carry - discount_rate) * time_remaining)
            * this->n(d1_calc)) / (2.0 * sqrt(time_remaining)))
            - (carry - discount_rate) * current_spot * exp((carry - discount_rate) * time_remaining)
            * this->N(d1_calc)
            - discount_rate * exercise_price * exp(-discount_rate * time_remaining)
            * this->N(d2_calc);
    }
};

#endif // EUROPEAN_CALL_HPP