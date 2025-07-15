/**
*
* Visitor.hpp
*
* Header file for the Visitor class.
*
* @author:  Kaushik Aryan R
* @date:    05-07-2025
* @version: 1.0
*
**/

#ifndef VISITOR_H
#define VISITOR_H

#include <boost/variant/static_visitor.hpp>
#include "Circle.hpp"
#include "Line.hpp"
#include "Point.hpp"

/*
*
* Visitor class
*
*/
class Visitor : public boost::static_visitor<void>
{
private:
	double m_dx;	// x-coordinate
	double m_dy;	// y-coordinate

public:

	// Constructors and Destructor
	Visitor();											// Default constructor
	Visitor(const Visitor& source);						// Copy constructor
	Visitor(const double x_cord, const double y_cord);	// Constuctor that accepts x and y coordinates
	~Visitor();											// Destructor

	// Operator overloading
	Visitor& operator = (const Visitor& source);	// Assignment operator
	// () operator
	void operator() (Circle& circle) const;
	void operator() (Line& line) const;
	void operator() (Point& point) const;
};

#endif // VISITOR_H