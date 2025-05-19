/**
*
* Main.cpp
*
* C++ program to test the Point class.
* The program, gets x and y coordinates from the user, creates two Point objects,
* and displays their properties.
*
* @author:  Kaushik Aryan R
* @date:    17-05-2025
* @version: 1.3
*
**/

#include "Point.hpp"
#include <iostream>

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
    // Initialize variables for input coordinates
    double xCord = 0, yCord = 0;

    // Prompt the user for input
    cout << "Provide the X and Y co-ordinates for Point #1: \n";
    if (!(cin >> xCord >> yCord))
    {
        cout << "Error: Invalid arguments provided." << endl;
        return 1;
    }

    // Create a Point object using the new constructor that accepts X and Y coordinates
    Point pointOne(xCord, yCord);

    // Prompt the user for input
    cout << "Provide the X and Y co-ordinates for Point #2: \n";
    if (!(cin >> xCord >> yCord))
    {
        cout << "Error: Invalid arguments provided." << endl;
        return 1;
    }

    // Create a Point object using the new constructor that accepts X and Y coordinates
    Point pointTwo(xCord, yCord);

    // Print the distance of the point from another point p
    cout << "The distance of Point #1 from Point #2 is: " << pointOne.Distance(pointTwo) << endl;

    // Return successful execution
    return 0;

    /*
    *
    * We now see in the console, that constructors are called two times - only the constructor that accepts X and Y coordinates is called twice.
    * The copy constructor is not called, since we pass by reference to the the Distance() function.
    * The destructor is also called twice.
    * 
    * Passing the Point object as a const reference, and trying to modify it in the Distance() function results these errors:
    * 'the object has type qualifiers that are not compatible with the member function "Point::SetY"'
    * 'void Point::SetY(double &)': cannot convert 'this' pointer from 'const Point' to 'Point &'
    *
    */
}