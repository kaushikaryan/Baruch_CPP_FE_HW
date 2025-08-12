/**
*
* Main.cpp
*
* Main file to test the various option classes
*
* @author:  Kaushik Aryan R
* @date:    10-08-2025
* @version: 1.0
*
**/

#include <cmath>
#include <string>
#include <iostream>
#include "OptionContract.hpp"
#include "EuropeanOption.hpp"
#include "EuropeanPut.hpp"
#include "EuropeanCall.hpp"
#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_io.hpp>
#include <vector>
#include "MatrixPricer.hpp"
#include "PerpetualAmericanOption.hpp"
#include "PerpetualAmericanCall.hpp"
#include "PerpetualAmericanPut.hpp"

// Options Pricing and Analysis Framework

// Precision threshold used to check if put-call parity is satisfied,
// as equality comparator cannot be used due to floating point innacuracies
const double PRECISION_THRESHOLD = 0.0001;

int main()
{
	std::cout << "================================================\n";
	std::cout << "    Section A1: European Call/Put Validation    \n";
	std::cout << "================================================\n\n";

	// Define parameter structure for test scenarios
	using Batch = boost::tuple<double, double, double, double, double, double, double>;

	// Test data: (Time to expiry, strike price, volatility, risk free rate, spot, expectedCall, expectedPut)
	std::vector<Batch> testBatch = {
		boost::make_tuple(0.25, 65.0, 0.30, 0.08, 60.0, 2.13337, 5.84628),
		boost::make_tuple(1.0, 100.0, 0.2, 0.0, 100.0, 7.96557, 7.96557),
		boost::make_tuple(1.0, 10.0, 0.50, 0.12, 5.0, 0.204058, 4.07326),
		boost::make_tuple(30.0, 100.0, 0.30, 0.08, 100.0, 92.17570, 1.24750)
	};

	// Process validation for each scenario
	Batch currentBatch;
	double maturity, strike, vol, rate, spot, expectedCall, expectedPut, computedCall, computedPut;
	EuropeanPut<double> euroPut;
	EuropeanCall<double> euroCall;

	for (unsigned batchID = 0; batchID < 4; ++batchID)
	{
		currentBatch = testBatch[batchID];

		// Extract scenario parameters
		maturity = boost::get<0>(currentBatch);
		strike = boost::get<1>(currentBatch);
		vol = boost::get<2>(currentBatch);
		rate = boost::get<3>(currentBatch);
		spot = boost::get<4>(currentBatch);
		expectedCall = boost::get<5>(currentBatch);
		expectedPut = boost::get<6>(currentBatch);

		// Initialize option objects
		euroPut = EuropeanPut<double>::EuropeanPut(spot, strike, maturity, rate, vol, rate);
		euroCall = EuropeanCall<double>::EuropeanCall(spot, strike, maturity, rate, vol, rate);

		// Display validation results
		std::cout.precision(4);
		std::cout << "================================================\n";
		std::cout << "Batch: " << batchID + 1 << "\n";
		std::cout << "================================================\n";
		std::cout << "Reference Put Price:    " << expectedPut << "\n";
		std::cout << "Calculated Put Price:   " << euroPut.price() << "\n";
		std::cout << "Put Price Match:        " << ((fabs(expectedPut - euroPut.price()) < PRECISION_THRESHOLD)
			? "PASS" : "FAIL") << "\n";
		std::cout << "Reference Call Price:   " << expectedCall << "\n";
		std::cout << "Calculated Call Price:  " << euroCall.price() << "\n";
		std::cout << "Call Price Match:       ";
		std::cout << ((fabs(expectedCall - euroCall.price()) < PRECISION_THRESHOLD) ? "PASS" : "FAIL") << "\n";

		// Verify put-call parity relationships
		computedCall = EuropeanOption<double>::putToCall(euroPut, euroPut.price());
		computedPut = EuropeanOption<double>::callToPut(euroCall, euroCall.price());
		std::cout << "Put-to-Call Conversion: " << computedCall << "\n";
		std::cout << "Conversion Match:       ";
		std::cout << ((fabs(expectedCall - computedCall) < PRECISION_THRESHOLD) ? "PASS" : "FAIL") << "\n";
		std::cout << "Call-to-Put Conversion: " << computedPut << "\n";
		std::cout << "Conversion Match:       ";
		std::cout << ((fabs(expectedPut - computedPut) < PRECISION_THRESHOLD) ? "PASS" : "FAIL") << "\n";
		std::cout << "Parity Check Status:    ";
		std::cout << (EuropeanOption<double>::putCallParityCheck(euroCall, euroPut, PRECISION_THRESHOLD)
			? "PASS" : "FAIL") << "\n";
		std::cout << "================================================\n\n";
	}

	// Demonstrate mesh generation functionality
	double startPrice = 1.0;
	double endPrice = 20.0;
	double stepSize = 1.0;
	MeshGenerator<double> priceGrid(startPrice, endPrice, stepSize);

	std::cout << "================================================\n";
	std::cout << "           Mesh Generation Testing             \n";
	std::cout << "================================================\n\n";
	std::cout << "Generated price mesh from " << startPrice << " to " << endPrice << " with step " << stepSize << ":\n";

	// Print mesh
	std::vector<double> grid = priceGrid.getGrid();
	for (double i = 0; i< grid.size(); i++)
		std::cout << grid[i] << std::endl;
	std::cout << "\nTotal mesh points: " << priceGrid.size() << "\n";
	std::cout << "================================================\n\n";

	std::vector<double>::const_iterator meshIter;

	// Test static mesh creation
	/*currentBatch = testBatch[0];
	std::vector<double> staticMesh = MatrixPricer::createMesh(startPrice, endPrice, stepSize);
	std::cout << "Static mesh creation: ";
	for (meshIter = staticMesh.begin(); meshIter != staticMesh.end(); ++meshIter)
		std::cout << *meshIter << " ";
	std::cout << "\n================================================\n";*/

	// Test matrix pricing with S and T grids
	std::cout << "================================================\n";
	std::cout << "           Matrix Pricing Testing              \n";
	std::cout << "================================================\n\n";

	startPrice = 91; endPrice = 100;
	double startTime = 1, endTime = 10;
	MeshGenerator<double> spotGrid(startPrice, endPrice, stepSize);
	MeshGenerator<double> timeGrid(startTime, endTime, stepSize);

	// Print matrix for European Put Option
	std::vector<std::vector<double>> optionMatrix = MatrixPricer::priceMatrix(
		euroPut, spotGrid, timeGrid,
		MatrixPricer::setSFunctor<EuropeanPut<double>>(),
		MatrixPricer::setTFunctor<EuropeanPut<double>>(),
		MatrixPricer::priceFunctor<EuropeanPut<double>>()
	);

	std::cout << "European Put Option Price Matrix (rows represent spot prices, columns represent time to maturity):\n\n";

	// Print first row of Time values
	std::cout << "\t";
	for (double timeValue : timeGrid)
		std::cout << timeValue << "\t";
	std::cout << std::endl;

	for (std::size_t rowIndex = 0; rowIndex < optionMatrix.size(); ++rowIndex) {
		// Print first column of Spot prices
		std::cout << spotGrid[rowIndex] << "\t";
		for (std::size_t colIndex = 0; colIndex < optionMatrix[rowIndex].size(); ++colIndex)
			std::cout << optionMatrix[rowIndex][colIndex] << "\t";
		std::cout << "\n";
	}

	// Print matrix for European Call Option
	optionMatrix = MatrixPricer::priceMatrix(
		euroCall, spotGrid, timeGrid,
		MatrixPricer::setSFunctor<EuropeanCall<double>>(),
		MatrixPricer::setTFunctor<EuropeanCall<double>>(),
		MatrixPricer::priceFunctor<EuropeanCall<double>>()
	);

	std::cout << "\n----------------------------------------------------------------------------------------------\n";

	std::cout << "European Call Option Price Matrix (rows represent spot prices, columns represent time to maturity):\n\n";

	// Print first row of Time values
	std::cout << "\t";
	for (double timeValue : timeGrid)
		std::cout << timeValue << "\t";
	std::cout << std::endl;

	for (std::size_t rowIndex = 0; rowIndex < optionMatrix.size(); ++rowIndex) {
		// Print first column of Spot prices
		std::cout << spotGrid[rowIndex] << "\t";
		for (std::size_t colIndex = 0; colIndex < optionMatrix[rowIndex].size(); ++colIndex)
			std::cout << optionMatrix[rowIndex][colIndex] << "\t";
		std::cout << "\n";
	}

	std::cout << "\n==============================================================================================\n\n";





	std::cout << "================================================\n";
	std::cout << "      Section A2: Greeks Calculation           \n";
	std::cout << "================================================\n\n";
	std::cout << "Calculating Greeks for European futures call and put options:\n";

	// 2.a
	// Set parameters for Greeks calculation
	strike = 100.0;
	spot = 105.0;
	maturity = 0.5;
	double costOfCarry = 0.0;
	vol = 0.36;
	rate = 0.1;

	// Create futures option objects
	EuropeanPut<double> futurePut = EuropeanPut<double>::EuropeanPut(spot, strike, maturity, rate, vol, costOfCarry);
	EuropeanCall<double> futureCall = EuropeanCall<double>::EuropeanCall(spot, strike, maturity, rate, vol, costOfCarry);

	// Calculate Greeks using analytical formulas
	double calculatedPutGamma = futurePut.calcGamma();
	double calculatedPutDelta = futurePut.delta();
	double calculatedPutTheta = futurePut.theta();
	double calculatedPutVega = futurePut.calcVega();
	double calculatedCallGamma = futureCall.calcGamma();
	double calculatedCallDelta = futureCall.delta();
	double calculatedCallTheta = futureCall.theta();
	double calculatedCallVega = futureCall.calcVega();
	std::string separator = "\t|\t";

	std::cout << separator << "Greek Type" << separator << "Put Value" << separator << "Call Value" << "    |\n";
	std::cout << "=============================================================================================\n\n";
	std::cout << separator << "Gamma     " << separator << calculatedPutGamma << separator << calculatedCallGamma << "    |\n";
	std::cout << separator << "Delta     " << separator << calculatedPutDelta << separator << calculatedCallDelta << "    |\n";
	std::cout << separator << "Theta     " << separator << calculatedPutTheta << separator << calculatedCallTheta << "    |\n";
	std::cout << separator << "Vega      " << separator << calculatedPutVega << separator << calculatedCallVega << "    |\n";

	// Validate calculated Deltas
	double expectedPutDelta = -0.3566, expectedCallDelta = 0.5946;
	bool validateDelta = (fabs(calculatedPutDelta - expectedPutDelta) <= PRECISION_THRESHOLD) && (fabs(calculatedCallDelta - expectedCallDelta) <= PRECISION_THRESHOLD);
	std::cout << "Delta validation result: " << (validateDelta ? "PASS" : "FAIL") << "\n\n";

	


	// 2.b
	// Compute Call Delta for monotonically increasing range of Spot
	std::cout << "Computing call option Delta for spot prices from 10 to 50:\n";
	std::vector<double> deltaRange;
	deltaRange = MatrixPricer::priceRange(futureCall, 10.0, 50.0, 1.0, MatrixPricer::deltaFunctor<EuropeanCall<double>>());

	std::cout << "|  Spot Price\t|     Delta Value\t|\n";
	std::cout << "=========================================\n";
	for (int idx = 0; idx < deltaRange.size(); ++idx)
		std::cout << "|\t" << 10.0 + idx << "\t|\t" << deltaRange[idx] << "\t|\n";
	std::cout << "=========================================\n\n";

	// Compute Call Gamma for monotonically increasing range of Spot
	std::cout << "Computing call option Gamma for spot prices from 10 to 50:\n";
	std::vector<double> gammaRange;
	gammaRange = MatrixPricer::priceRange(futureCall, 10.0, 50.0, 1.0, MatrixPricer::gammaFunctor<EuropeanCall<double>>());

	std::cout << "|  Spot Price\t|    Gamma Value\t|\n";
	std::cout << "=========================================\n";
	for (int idx = 0; idx < gammaRange.size(); ++idx)
		std::cout << "|\t" << 10.0 + idx << "\t|\t" << gammaRange[idx] << "\t|\n";





	// 2.c
	// Compute Call Delta Matrix for varying Spot and Strike values
	std::cout << "\n\nGenerating matrix of Delta values across spot prices 90-100 and strike prices 100-110: \n\n";
	MeshGenerator<double> spotMesh = MeshGenerator<double>(90.0, 100.0, 1.0);
	MeshGenerator<double> strikeMesh = MeshGenerator<double>(100.0, 110.0, 1.0);
	std::vector<std::vector<double>> deltaMatrix;
	deltaMatrix = MatrixPricer::priceMatrix(futureCall, spotMesh, strikeMesh,
		MatrixPricer::setSFunctor<EuropeanCall<double>>(),
		MatrixPricer::setKFunctor<EuropeanCall<double>>(),
		MatrixPricer::deltaFunctor<EuropeanCall<double>>());

	std::cout << "Delta Surface Matrix (rows represent spot prices, columns represent strike prices):\n\n";

	// Print first row of Spot prices
	std::cout << "\t";
	for (double spotPrice : spotMesh)
		std::cout << spotPrice << "\t";
	std::cout << std::endl;

	for (std::size_t rowIndex = 0; rowIndex < deltaMatrix.size(); ++rowIndex) {
		// Print first column of Strike prices
		std::cout << strikeMesh[rowIndex] << "\t";
		for (std::size_t colIndex = 0; colIndex < deltaMatrix[rowIndex].size(); ++colIndex)
			std::cout << deltaMatrix[rowIndex][colIndex] << "\t";
		std::cout << "\n";
	}
	std::cout << "\n================================================================================================\n\n";


	
	// 2.d
	std::cout << "Computing Delta and Gamma using divided difference approximations...\n\n";

	// Calculate Greeks using divided differences
	double ddPutGamma = futurePut.calcGamma_dd();
	double ddPutDelta = futurePut.calcDelta_dd();
	double ddCallGamma = futureCall.calcGamma_dd();
	double ddCallDelta = futureCall.calcDelta_dd();

	std::cout << separator << "Greek Type" << separator << "Put Value" << separator << "Call Value" << "    |\n";
	std::cout << "================================================================================================================\n\n";
	std::cout << separator << "Gamma     " << separator << ddPutGamma << separator << ddCallGamma << "    |\n";
	std::cout << separator << "Delta     " << separator << ddPutDelta << separator << ddCallDelta << "    |\n";
	std::cout << separator << "Theta     " << separator << calculatedPutTheta << separator << calculatedCallTheta << "    |\n";
	std::cout << separator << "Vega      " << separator << calculatedPutVega << separator << calculatedCallVega << "    |\n";
	validateDelta = (fabs(ddPutDelta - expectedPutDelta) <= PRECISION_THRESHOLD) && (fabs(ddCallDelta - expectedCallDelta) <= PRECISION_THRESHOLD);
	std::cout << "Delta validation result: " << (validateDelta ? "PASS" : "FAIL") << "\n\n";

	std::cout << "Analyzing absolute error for step sizes from h = 10^-16 to h = 10^-1 for Delta and Gamma calculations.\n";

	// Initialize error analysis variables
	double putDeltaError, putgammaError, callDeltaError, callGammaError;
	stepSize = std::pow(10.0, -16.0);
	std::vector<double> averageErrors(16);

	for (unsigned stepIndex = 0; stepIndex < 16; ++stepIndex)
	{
		// Calculate divided difference Greeks with current step size
		ddPutDelta = futurePut.calcDelta_dd(stepSize);
		ddPutGamma = futurePut.calcGamma_dd(stepSize);
		ddCallDelta = futureCall.calcDelta_dd(stepSize);
		ddCallGamma = futureCall.calcGamma_dd(stepSize);

		// Calculate absolute errors
		putDeltaError = fabs(ddPutDelta - calculatedPutDelta);
		putgammaError = fabs(ddPutGamma - calculatedPutGamma);
		callDeltaError = fabs(ddCallDelta - calculatedCallDelta);
		callGammaError = fabs(ddCallGamma - calculatedCallGamma);

		// Display error analysis results
		std::cout << "================================\n";
		std::cout << "Step size h: 1e-" << 16 - stepIndex << "\n";
		std::cout << "Call delta absolute error: " << callDeltaError << "\n";
		std::cout << "Put delta absolute error:  " << putDeltaError << "\n";
		std::cout << "Call gamma absolute error: " << callGammaError << "\n";
		std::cout << "Put gamma absolute error:  " << putgammaError << "\n";
		averageErrors[stepIndex] = putDeltaError + putgammaError + callDeltaError;
		averageErrors[stepIndex] += callGammaError;
		averageErrors[stepIndex] /= 4.0;
		std::cout << "Average absolute error:    " << averageErrors[stepIndex] << "\n";
		std::cout << "================================\n\n";

		// Update step size for next iteration
		stepSize *= 10.0;
	}

	// Commentary on numerical results
	std::cout << "Numerical Analysis Notes:\n";
	std::cout << "The divided difference method for gamma calculations using divided differences exhibits sensitivity to roundoff errors which get\n";
	std::cout << "amplified by the h^2 term in the denominator.\n";
	std::cout << "Optimal step size appears to be approximately 1e-3.\n\n";

	std::cout << "Recomputing range-based delta calculations with error analysis...\n\n";

	// Calculate divided difference deltas for the range
	std::vector<double> ddDeltaRange;
	ddDeltaRange = MatrixPricer::priceRange(futureCall, 10.0, 50.0, 1.0, MatrixPricer::ddDeltaFunctor<EuropeanCall<double>>());

	std::vector<double> errorAnalysis(ddDeltaRange.size());
	std::cout << "================================ Delta Comparison Results ================================\n";
	std::cout << "| Spot |   Analytical   | Divided Diff | Absolute Error |\n";
	std::cout << "========================================================================================\n";
	double totalError = 0.0;
	double currentError;
	for (int idx = 0; idx < deltaRange.size(); ++idx)
	{
		currentError = fabs(ddDeltaRange[idx] - deltaRange[idx]);
		totalError += currentError;
		std::cout << "|  " << 10.0 + idx << " |    " << deltaRange[idx] << "    |   ";
		std::cout << ddDeltaRange[idx] << "   |   " << currentError << "   |\n";
	}
	totalError /= ddDeltaRange.size();
	std::cout << "================ Mean absolute error: " << totalError;
	std::cout << " ================\n\n";

	std::cout << "Performing comprehensive step size analysis from h = 1e-16 to h = 1e-1\n";
	std::cout << "computing mean absolute error for delta and gamma across all spot prices.\n\n";

	// Matrix to store mean absolute errors for delta and gamma
	std::vector<std::vector<double>> errorMatrix(16, std::vector<double>(2));
	std::vector<double> ddGammaRange(ddDeltaRange.size());
	double maeGamma = 0.0;
	double maeDelta = 0.0;
	stepSize = pow(10, -16);

	for (unsigned index = 0; index < 16; ++index)
	{
		// Reset error accumulators
		maeGamma = 0.0;
		maeDelta = 0.0;

		// Calculate divided difference deltas for current step size
		ddDeltaRange = MatrixPricer::priceRange(
			futureCall, 10.0, 50.0, 1.0, MatrixPricer::ddDeltaFunctor<EuropeanCall<double>>(stepSize)
		);

		// Calculate divided difference gammas for current step size
		ddGammaRange = MatrixPricer::priceRange(
			futureCall, 10.0, 50.0, 1.0, MatrixPricer::ddGammaFunctor<EuropeanCall<double>>(stepSize)
		);

		// Compute mean absolute errors
		for (unsigned index = 0; index < ddDeltaRange.size(); ++index)
		{
			maeDelta += fabs(ddDeltaRange[index] - deltaRange[index]);
			maeGamma += fabs(ddGammaRange[index] - gammaRange[index]);
		}

		maeDelta /= ddDeltaRange.size();
		maeGamma /= ddGammaRange.size();

		// Store results
		errorMatrix[index][0] = maeDelta;
		errorMatrix[index][1] = maeGamma;

		// Display results for current step size
		//std::cout << "Step size h = " << stepSize << ":\tDelta MAE = " << maeDelta << ",\tGamma MAE = " << maeGamma << std::endl;

		// Update step size
		stepSize *= 10.0;
	}

	// Display comprehensive error analysis summary
	std::cout << "\nComprehensive Mean Absolute Error Analysis:\n";
	std::cout << "===========================================\n";
	std::cout << "| Step Size h  |  Delta MAE  |  Gamma MAE  |\n";
	std::cout << "===========================================\n";

	// Reset step size for summary display
	stepSize = pow(10, -16);
	for (unsigned idx = 0; idx < 16; ++idx) {
		std::cout << "| 1e" << std::setw(3) << log10(stepSize) << "      | "
			<< std::setw(11) << std::scientific << std::setprecision(3) << errorMatrix[idx][0] << " | "
			<< std::setw(11) << std::scientific << std::setprecision(3) << errorMatrix[idx][1] << " |\n";
		stepSize *= 10.0;
	}
	std::cout << "===========================================\n";

	std::cout << "================================================\n";
	std::cout << "  Section B: Perpetual American Options        \n";
	std::cout << "================================================\n\n";

	std::cout << "Testing perpetual American options with parameters:\n";
	std::cout << "K = 100, sigma = 0.1, r = 0.1, b = 0.02, S = 110\n";

	PerpetualAmericanCall<double> perpetualCall;
	PerpetualAmericanPut<double> perpetualPut;
	perpetualCall =
		PerpetualAmericanCall<double>::PerpetualAmericanCall(
			110.0,  // S
			100.0,  // K
			0.1,    // r
			0.1,    // sig
			0.02    // b
		);
	perpetualPut =
		PerpetualAmericanPut<double>::PerpetualAmericanPut(
			110.0,  // S
			100.0,  // K
			0.1,    // r
			0.1,    // sig
			0.02    // b
		);

	std::cout << "Calculated Put Price:  " << perpetualPut.price() << ".\n";
	std::cout << "Expected Put Price:    " << 3.03106 << ".\n";
	std::cout << "Calculated Call Price: " << perpetualCall.price() << ".\n";
	std::cout << "Expected Call Price:   " << 18.5035 << ".\n";
	std::cout << "========================================\n\n";

	std::cout << "Computing perpetual put prices for spot prices from 10 to 50.\n\n";
	startPrice = 10.0;
	endPrice = 50.0;
	stepSize = 1.0;

	std::vector<double> prices = MatrixPricer::priceRange(
		perpetualPut, startPrice, endPrice, stepSize,
		MatrixPricer::priceFunctor<PerpetualAmericanPut<double>>()
	);
	std::cout << "Perpetual Put Prices:\n";
	int spotCounter = 10;
	for (meshIter = prices.begin(); meshIter != prices.end(); ++meshIter)
	{
		std::cout << "Spot = " << spotCounter << ":\tPrice " << *meshIter << "\n";
		spotCounter++;
	}
	std::cout << "\n";

	prices = MatrixPricer::priceRange(
		perpetualCall, startPrice, endPrice, stepSize,
		MatrixPricer::priceFunctor<PerpetualAmericanCall<double>>()
	);
	std::cout << "Perpetual Call Prices:\n";
	spotCounter = 10;
	for (meshIter = prices.begin(); meshIter != prices.end(); ++meshIter)
	{
		std::cout << "Spot = " << spotCounter << ":\tPrice " << *meshIter << "\n";
		spotCounter++;
	}
	std::cout << "\n";

	std::cout << "Computing perpetual put price matrix for spot grid 1-10 and strike grid 1-10.\n\n";
	startPrice = 1; endPrice = 10;
	double startStrike = 1, endStrike = 10;

	spotGrid = MeshGenerator<double>::MeshGenerator(startPrice, endPrice, stepSize);
	MeshGenerator<double> strikeGrid(startStrike, endStrike, stepSize);

	optionMatrix = MatrixPricer::priceMatrix(
		perpetualPut, spotGrid, strikeGrid,
		MatrixPricer::setSFunctor<PerpetualAmericanPut<double>>(),
		MatrixPricer::setKFunctor<PerpetualAmericanPut<double>>(),
		MatrixPricer::priceFunctor<PerpetualAmericanPut<double>>()
	);
	std::cout << "Perpetual Put Price Matrix (rows represent spot prices, columns represent strike prices):\n\n";

	// Print first row of Strike prices
	std::cout << "\t\t";
	for (double spotPrice : spotGrid)
		std::cout << spotPrice << "\t";
	std::cout << std::endl;

	for (std::size_t rowIndex = 0; rowIndex < optionMatrix.size(); ++rowIndex) {
		// Print the first column of Spot prices
		std::cout << strikeGrid[rowIndex] << "\t";
		for (std::size_t colIndex = 0; colIndex < optionMatrix[rowIndex].size(); ++colIndex)
			std::cout << optionMatrix[rowIndex][colIndex] << "\t";
		std::cout << "\n";
	}

	std::cout << "Computing perpetual call price matrix for spot grid 1-10 and strike grid 1-10.\n\n";
	optionMatrix = MatrixPricer::priceMatrix(
		perpetualCall, spotGrid, strikeGrid,
		MatrixPricer::setSFunctor<PerpetualAmericanCall<double>>(),
		MatrixPricer::setKFunctor<PerpetualAmericanCall<double>>(),
		MatrixPricer::priceFunctor<PerpetualAmericanCall<double>>()
	);
	std::cout << "Perpetual Call Price Matrix (rows represent spot prices, columns represent strike prices):\n\n";

	// Print first row of Strike prices
	std::cout << "\t\t";
	for (double spotPrice : spotGrid)
		std::cout << spotPrice << "\t";
	std::cout << std::endl;

	for (std::size_t rowIndex = 0; rowIndex < optionMatrix.size(); ++rowIndex) {
		// Print the first column of Spot prices
		std::cout << strikeGrid[rowIndex] << "\t";
		for (std::size_t colIndex = 0; colIndex < optionMatrix[rowIndex].size(); ++colIndex)
			std::cout << optionMatrix[rowIndex][colIndex] << "\t";
		std::cout << "\n";
	}

	return 0;
}
