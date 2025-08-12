#ifndef PERPETUAL_AMERICAN_OPTION_HPP
#define PERPETUAL_AMERICAN_OPTION_HPP

#include "OptionContract.hpp"
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

template <typename NT>
class PerpetualAmericanOption : public OptionContract<NT>
{
public:
    // Default constructor
    PerpetualAmericanOption() : OptionContract<NT>() {}

    // Constructor that takes option parameters as input
    PerpetualAmericanOption(NT underlying_value, NT strike_price, NT discount_rate, NT volatility, NT cost_of_carry = 0)
        : OptionContract<NT>(underlying_value, strike_price, 0.0, discount_rate, volatility, cost_of_carry) {}

    // Copy constructor
    PerpetualAmericanOption(const PerpetualAmericanOption<NT>& other) : OptionContract<NT>(other) {}

    // Destructor
    virtual ~PerpetualAmericanOption() {}

    // Abstract method
    virtual NT price() const override = 0;

    // Abstract cloning method for creating copies of derived class instances
    virtual boost::shared_ptr<PerpetualAmericanOption<NT>> clone() const = 0;
};

#endif // PERPETUAL_AMERICAN_OPTION_HPP