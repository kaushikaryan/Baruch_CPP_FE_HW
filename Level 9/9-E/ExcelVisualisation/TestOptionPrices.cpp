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
	double min_asset_price = 10.0;     // Lower boundary for underlying asset price range
	double max_asset_price = 50.0;     // Upper boundary for underlying asset price range
	double price_increment = 1.0;      // Step size for price grid generation
	double expiration_period = 0.25;   // Time to option expiration (in years)
	double strike_level = 35.0;        // Exercise price of the option
	double risk_free_rate = 0.08;      // Risk-free interest rate
	double volatility_param = 0.3;     // Implied volatility of underlying asset

	// Create European call option instance for analysis
	EuropeanCall<double> call_option;

	// Generate uniform price mesh for underlying asset values
	MeshGenerator<double> price_mesh(min_asset_price, max_asset_price, price_increment);

	// Initialize storage containers for calculation results
	std::vector<double> option_values;
	option_values.reserve(price_mesh.size());
	std::vector<double> underlying_prices;
	underlying_prices.reserve(price_mesh.size());

	// Calculate option prices across the parameter range
	for (unsigned mesh_index = 0; mesh_index < price_mesh.size(); ++mesh_index)
	{
		underlying_prices.push_back(price_mesh[mesh_index]);
		call_option = EuropeanCall<double>::EuropeanCall(underlying_prices[mesh_index],
			strike_level,
			expiration_period,
			risk_free_rate,
			volatility_param);
		option_values.push_back(call_option.price());
	}

	// Initialize Excel reporting interface
	std::string worksheet_title("European Call Prices");
	ExcelDriver& spreadsheet_interface = ExcelDriver::Instance();
	spreadsheet_interface.MakeVisible(true);

	// Configure data labels for Excel output
	std::string row_identifier("row1");
	std::list<std::string> column_headers = { "S", "Call Price" };

	// Generate visualization chart in Excel
	spreadsheet_interface.CreateChart(underlying_prices, option_values,
		"Call Option Prices",
		"Stock Price",
		"Option Value");

	return 0;
}