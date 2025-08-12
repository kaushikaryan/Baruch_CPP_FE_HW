#include <cmath>
#include <string>
#include <iostream>
#include "OptionContract.hpp"
#include "EuropeanOption.hpp"
#include "EuropeanPut.hpp"
#include "EuropeanCall.hpp"
#include <vector>
#include "MatrixPricer.hpp"
#include "UtilitiesDJD/ExcelDriver/ExcelDriverLite.hpp"

int main()
{
	// Define market parameters for option pricing analysis
	double minAssetPrice = 10.0;     // Lower boundary for underlying asset price range
	double maxAssetPrice = 50.0;     // Upper boundary for underlying asset price range
	double priceIncrement = 1.0;      // Step size for price grid generation
	double expirationPeriod = 0.25;   // Time to option expiration (in years)
	double strikeLevel = 35.0;        // Exercise price of the option
	double riskFreeRate = 0.08;      // Risk-free interest rate
	double volatilityParam = 0.3;     // Implied volatility of underlying asset

	// Create European call option instance for analysis
	EuropeanCall<double> callOption;

	// Generate uniform price mesh for underlying asset values
	MeshGenerator<double> priceMesh(minAssetPrice, maxAssetPrice, priceIncrement);

	// Initialize storage containers for calculation results
	std::vector<double> optionValues;
	optionValues.reserve(priceMesh.size());
	std::vector<double> underlyingPrices;
	underlyingPrices.reserve(priceMesh.size());

	// Calculate option prices across the parameter range
	for (unsigned meshIndex = 0; meshIndex < priceMesh.size(); ++meshIndex)
	{
		underlyingPrices.push_back(priceMesh[meshIndex]);
		callOption = EuropeanCall<double>::EuropeanCall(underlyingPrices[meshIndex],
			strikeLevel,
			expirationPeriod,
			riskFreeRate,
			volatilityParam);
		optionValues.push_back(callOption.price());
	}

	// Initialize Excel reporting interface
	std::string worksheetTitle("European Call Prices");
	ExcelDriver& spreadsheetInterface = ExcelDriver::Instance();
	spreadsheetInterface.MakeVisible(true);

	// Configure data labels for Excel output
	std::string rowIdentifier("row1");
	std::list<std::string> columnHeaders = { "S", "Call Price" };

	// Generate visualization chart in Excel
	spreadsheetInterface.CreateChart(underlyingPrices, optionValues,
		"Call Option Prices",
		"Stock Price",
		"Option Value");
	return 0;
}
