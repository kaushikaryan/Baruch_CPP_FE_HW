#ifndef NORMAL_DISTRIBUTION_HPP
#define NORMAL_DISTRIBUTION_HPP

#include <boost/math/distributions/normal.hpp>

template<typename NT = double>
struct NormalDistribution
{
    // Calculate probability density function value for standard normal distribution
    static NT pdf(NT input_value)
    {
        // Static standard normal distribution (mean=0, std_dev=1) for efficiency
        static const boost::math::normal_distribution<NT> standard_normal(NT(0), NT(1));
        return boost::math::pdf(standard_normal, input_value);
    }

    // Calculate cumulative distribution function value for standard normal distribution
    static NT cdf(NT input_value)
    {
        // Static standard normal distribution (mean=0, std_dev=1) for efficiency  
        static const boost::math::normal_distribution<NT> standard_normal(NT(0), NT(1));
        return boost::math::cdf(standard_normal, input_value);
    }
};

#endif // NORMAL_DISTRIBUTION_HPP