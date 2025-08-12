/**
*
* NormalDistribution.hpp
*
* Header file for the Normal Distribution class
*
* @author:  Kaushik Aryan R
* @date:    10-08-2025
* @version: 1.0
*
**/

#ifndef NORMAL_DISTRIBUTION_HPP
#define NORMAL_DISTRIBUTION_HPP

#include <boost/math/distributions/normal.hpp>

template<typename NumType = double>
struct NormalDistribution
{
    // Calculate probability density function value for standard normal distribution
    static NumType pdf(NumType inputValue)
    {
        // Static standard normal distribution (mean=0, std_dev=1) for efficiency
        static const boost::math::normal_distribution<NumType> standard_normal(NumType(0), NumType(1));
        return boost::math::pdf(standard_normal, inputValue);
    }

    // Calculate cumulative distribution function value for standard normal distribution
    static NumType cdf(NumType inputValue)
    {
        // Static standard normal distribution (mean=0, std_dev=1) for efficiency  
        static const boost::math::normal_distribution<NumType> standard_normal(NumType(0), NumType(1));
        return boost::math::cdf(standard_normal, inputValue);
    }
};

#endif // NORMAL_DISTRIBUTION_HPP