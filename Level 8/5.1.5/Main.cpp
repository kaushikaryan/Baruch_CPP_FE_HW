/**
*
* Main.cpp
* C++ program to test Exponential and Poisson distributions
*
* @author:  Kaushik Aryan R
* @date:    05-07-2025
* @version: 1.0
*
**/

#include <boost/math/distributions.hpp>	// For non-member functions of distributions
#include <vector>
#include <iostream>

/*
*
* main function - entry point of the program
*
* @return 0 on successful execution
*
*/
int main()
{
	// Don't forget to tell compiler which namespace
	using namespace boost::math;

	double scaleParameter1 = 0.5;

	// Default type is 'double' 
	exponential_distribution<> exponentialDist1(scaleParameter1);
	std::cout << "Mean:" << mean(exponentialDist1)
		<< ",standard deviation: "
		<< standard_deviation(exponentialDist1) << std::endl;

	// Distributional properties
	double x = 10.25;

	std::cout << "pdf: " << pdf(exponentialDist1, x) << std::endl;
	std::cout << "cdf: " << cdf(exponentialDist1, x) << std::endl;

	float scaleParameter2 = 0.5;

	// Choose another data type
	exponential_distribution<float> exponentialDist2(scaleParameter2);

	std::cout << "Mean: " << mean(exponentialDist2) << ", standard deviation: "
		<< standard_deviation(exponentialDist2) << std::endl;
	std::cout << "pdf: " << pdf(exponentialDist2, x) << std::endl;
	std::cout << "cdf: " << cdf(exponentialDist2, x) << std::endl;

	// Choose precision
	std::cout.precision(10); // Number of values behind the comma

	// Other properties
	std::cout << "\n***exponential distribution: \n";
	std::cout << "mean: " << mean(exponentialDist1) << std::endl;
	std::cout << "variance: " << variance(exponentialDist1) << std::endl;
	std::cout << "median: " << median(exponentialDist1) << std::endl;
	std::cout << "mode: " << mode(exponentialDist1) << std::endl;
	std::cout << "kurtosis excess: " << kurtosis_excess(exponentialDist1) << std::endl;
	std::cout << "kurtosis: " << kurtosis(exponentialDist1) << std::endl;
	std::cout << "characteristic function: " << chf(exponentialDist1, x) << std::endl;
	std::cout << "hazard: " << hazard(exponentialDist1, x) << std::endl;

	// Poisson distribution
	double mean = 3.0;
	poisson_distribution<double> poissonDist(mean);

	// Set the value at which to evaluate the Poisson distribution
	double val = 13.0;

	// Output the pdf and cdf at 'val'
	std::cout << "\npdf: " << pdf(poissonDist, val) << std::endl;
	std::cout << "cdf: " << cdf(poissonDist, val) << std::endl;

	// Vectors to store pdf and cdf values over a range
	std::vector<double> pdfList;
	std::vector<double> cdfList;

	// Define the range [start, end] and number of subdivisions N
	double start = 0.0;
	double end = 10.0;
	long N = 30;        // Number of subdivisions

	// Initialize value and step size for iteration
	val = 0.0;
	double h = (end - start) / double(N);

	// Compute pdf and cdf at N+1 equally spaced points in [start, end]
	for (long j = 1; j <= N; ++j)
	{
		pdfList.push_back(pdf(poissonDist, val));
		cdfList.push_back(cdf(poissonDist, val));

		val += h;
	}

	std::cout << "\n***" << std::endl;

	// Output all computed pdf values, separated by commas
	for (long j = 0; j < pdfList.size(); ++j)
	{
		std::cout << pdfList[j] << ", ";
	}

	std::cout << "\n***" << std::endl;

	// Output all computed cdf values, separated by commas
	for (long j = 0; j < cdfList.size(); ++j)
	{
		std::cout << cdfList[j] << ", ";
	}

	std::cout << "\n***" << std::endl;

	// Return successful execution
	return 0;
}