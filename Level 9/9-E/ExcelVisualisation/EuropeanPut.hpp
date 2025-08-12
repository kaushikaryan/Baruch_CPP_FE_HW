#ifndef EUROPEAN_PUT_HPP
#define EUROPEAN_PUT_HPP

#include "OptionContract.hpp"
#include "EuropeanOption.hpp"
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include "NormalDistribution.hpp"

template<typename NT = double>
class EuropeanPut : public EuropeanOption<NT>
{
public:
    // Default constructor
    EuropeanPut() : EuropeanOption<NT>() {}

    // Constructor with market parameters for put option setup
    EuropeanPut(NT underlying_value, NT strike_price, NT expiration_time, NT risk_free_rate, NT volatility, NT cost_of_carry = 0)
        : EuropeanOption<NT>(underlying_value, strike_price, expiration_time, risk_free_rate, volatility, cost_of_carry) {}

    // Copy constructor
    EuropeanPut(const EuropeanPut<NT>& existing_put) : EuropeanOption<NT>(existing_put) {}

    // Destructor 
    virtual ~EuropeanPut() {}

    // Compute put option value using Black-Scholes pricing model
    NT price() const override
    {
        // Extract market parameters from base class accessors
        NT underlying_asset = this->S();
        NT exercise_level = this->K();
        NT time_to_maturity = this->T();
        NT riskfree_rate = this->r();
        NT cost_carry = this->b();

        // Compute standard normal distribution parameters
        NT d_one = this->d1();
        NT d_two = this->d2();

        // Black-Scholes put option pricing formula
        return exercise_level * exp(-riskfree_rate * time_to_maturity) * this->N(-d_two)
            - underlying_asset * exp((cost_carry - riskfree_rate) * time_to_maturity) * this->N(-d_one);
    }

    // Factory method to create shared pointer copy of put option
    virtual boost::shared_ptr<EuropeanOption<NT>> clone() const override
    {
        return boost::make_shared<EuropeanPut<NT>>(*this);
    }

    // Risk sensitivities (Greeks) - Financial derivatives for European put options

    // Delta: Sensitivity of put price to changes in underlying asset price
    NT delta() const
    {
        NT maturity_period = this->T();
        NT carry_rate = this->b();
        NT rate_riskfree = this->r();
        NT d1_computation = this->d1();

        return (this->N(d1_computation) - 1.0) * exp((carry_rate - rate_riskfree) * maturity_period);
    }

    // Theta: Time decay sensitivity - rate of put price change with respect to time
    NT theta() const
    {
        NT spot_value = this->S();
        NT remaining_time = this->T();
        NT volatility_param = this->sig();
        NT carry_cost_rate = this->b();
        NT risk_free_return = this->r();
        NT strike_price_level = this->K();
        NT d1_result = this->d1();
        NT d2_result = this->d2();

        return -((spot_value * volatility_param * exp((carry_cost_rate - risk_free_return) * remaining_time)
            * this->n(d1_result)) / (2.0 * sqrt(remaining_time)))
            + (carry_cost_rate - risk_free_return) * spot_value * exp((carry_cost_rate - risk_free_return) * remaining_time)
            * this->N(-d1_result)
            + risk_free_return * strike_price_level * exp(-risk_free_return * remaining_time)
            * this->N(-d2_result);
    }
};

#endif // EUROPEAN_PUT_HPP