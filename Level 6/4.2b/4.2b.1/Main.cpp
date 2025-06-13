/**
*
* Main.cpp
* C++ program to test the Array class
*
* @author:  Kaushik Aryan R
* @date:    10-06-2025
* @version: 1.0
*
**/

#include <iostream>
#include "Array.hpp"

// Using standard namespace to simplify code
using namespace std;

/*
*
* main function - entry point of the program
*
* @return 0 on successful execution
*
*/
int main()
{
	Array<int> intArray1;
	Array<int> intArray2;
	Array<double> doubleArray;

	cout << intArray1.DefaultSize() << endl;
	cout << intArray2.DefaultSize() << endl;
	cout << doubleArray.DefaultSize() << endl;

	intArray1.DefaultSize(15);

	cout << intArray1.DefaultSize() << endl;
	cout << intArray2.DefaultSize() << endl;
	cout << doubleArray.DefaultSize() << endl;

	/*
	Output:
		10
		10
		10
		15
		15
		10

	Explanation:
		Initially the default size of all arrays is 10.
		Then, the default size of the Array<int> class is set to 15 using intArray1.DefaultSize(15)
		Since m_default_size is a static member of the Array<int> class, it is shared among all instances/objects of the Array<int> class.

		This explains why the default size of both intArray1 and intArray2 is now 15.
		Since the default size of the Array<double> class is not altered, it remains 10.
	*/

	// Return successful execution
	return 0;
}