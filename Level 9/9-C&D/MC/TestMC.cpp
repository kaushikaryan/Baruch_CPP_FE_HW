// HardCoded.cpp
//
// C++ code to price an option, essential algorithms.
//
// We take CEV model with a choice of the elaticity parameter
// and the Euler method. We give option price and number of times
// S hits the origin.
//
// (C) Datasim Education BC 2008-2011
//

#include "OptionData.hpp" 
#include "UtilitiesDJD/RNG/NormalGenerator.hpp"
#include "UtilitiesDJD/Geometry/Range.cpp"
#include <cmath>
#include <iostream>
#include <iomanip>

template <class T>void print(const std::vector<T>& myList)
{  // A generic print function for vectors

	std::cout << std::endl << "Size of vector is " << l.size() << "\n[";

	// We must use a const iterator here, otherwise we get a compiler error.
	std::vector<T>::const_iterator i;
	for (i = myList.begin(); i != myList.end(); ++i)
	{
		std::cout << *i << ",";
	}

	std::cout << "]\n";
}

namespace SDEDefinition
{ // Defines drift + diffusion + data

	OptionData* data;				// The data for the option MC

	double drift(double t, double X)
	{ // Drift term

		return (data->r) * X; // r - D
	}


	double diffusion(double t, double X)
	{ // Diffusion term

		double betaCEV = 1.0;
		return data->sig * pow(X, betaCEV);

	}

	double diffusionDerivative(double t, double X)
	{ // Diffusion term, needed for the Milstein method

		double betaCEV = 1.0;
		return 0.5 * (data->sig) * (betaCEV)* pow(X, 2.0 * betaCEV - 1.0);
	}
} // End of namespace

// Function to compute standard deviation
template<typename NumType>
NumType computeSD(vector<NumType> draws, NumType r, NumType T)
{
	// This function computes the standard deviation of the Monte Carlo 
	//	pricing algorithm based on a vector of draws, the risk-free rate,
	//	and time-to-expiry.
	// 
	// Extract drawCount
	unsigned drawCount = draws.size();

	// Compute sum_C := \sum_j C_{T,j}, and sum_sq_C := \sum_j C_{T,j}^2
	NumType sumDraws = 0;
	NumType sumDrawsSquared = 0;
	for (unsigned i = 0; i < drawCount; ++i)
	{
		sumDraws += draws[i];
		sumDrawsSquared += pow(draws[i], 2);
	}

	return sqrt((sumDrawsSquared - (pow(sumDraws, 2) / drawCount)) / (drawCount - 1)) * exp(-r * T);
}

// Function to compute standard error
template<typename NumType>
NumType computeSE(vector<NumType> draws, NumType r, NumType T)
{
	// This function computes the standard error of the Monte Carlo 
	//	pricing algorithm based on a vector of draws, the risk-free rate,
	//	and time-to-expiry.

	// Extract drawCount
	unsigned drawCount = draws.size();

	// Compute standard deviation
	NumType stdDev = computeSD(draws, r, T);

	return stdDev / sqrt(drawCount);
}

int main()
{
	// Option parameters initialization
	OptionData myOption;
	myOption.K = 65.0;
	myOption.T = 0.25;
	myOption.r = 0.08;
	myOption.sig = 0.3;
	myOption.type = 1; // Call -> (+1), Put -> (-1)
	double S_0 = 60.0;
	double grnd_truth = 2.13337;


	// Define ranges for NT (time grid points) and NSIM (number of simulations)
	vector<long> NTvalues = {2, 5, 10, 100, 500, 1000};
	vector<long> NSIMvalues = {100, 1000, 10000, 100000, 1000000};

	// Random number generator
	NormalGenerator* myNormal = new BoostNormal();

	using namespace SDEDefinition;
	SDEDefinition::data = &myOption;

	// Output headers
	std::cout << setw(10) << "NT" << setw(15) << "NSIM" << setw(15) << "Abs. Err.";
	std::cout << setw(20) << "Std. Deviation" << setw(20) << "Std. Error\n";

	for (long NT : NTvalues) {
		double k = myOption.T / double(NT);
		double sqrk = sqrt(k);

		Range<double> range(0.0, myOption.T);
		vector<double> x = range.mesh(NT);

		for (long NSIM : NSIMvalues) {

			double price = 0.0;
			vector<double> cVector;
			cVector.reserve(NSIM);

			// Main Monte Carlo simulation loop
			for (long i = 0; i < NSIM; ++i) {
				double VOld = S_0, VNew;

				for (size_t index = 1; index < x.size(); ++index) {
					double dW = myNormal->getNormal();

					VNew = VOld + (k * drift(x[index - 1], VOld))
						+ (sqrk * diffusion(x[index - 1], VOld) * dW);

					VOld = VNew;
				}

				double payoff = myOption.myPayOffFunction(VNew);	// Compute C_{T,j}
				cVector.push_back(payoff);							// Store in vector
				price += payoff;
			}

			price = (price / double(NSIM)) * exp(-myOption.r * myOption.T);

			// Compute standard deviation and standard error
			double std_dev = computeSD(cVector, myOption.r, myOption.T);
			double std_err = computeSE(cVector, myOption.r, myOption.T);

			// Output results
			std::cout << setw(10) << NT << setw(15) << NSIM << scientific
				<< setw(15) << setprecision(6) << fabs(price - grnd_truth)
				<< setw(20) << std_dev
				<< setw(20) << std_err << endl;
		}
		std::cout << "----------------------------------------------------------------------------------\n";
	}

	delete myNormal;

	return 0;
}
