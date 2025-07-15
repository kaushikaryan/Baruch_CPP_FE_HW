/**
*
* Visitor.cpp
*
* Implementation file for the Visitor class.
*
* @author:  Kaushik Aryan R
* @date:    05-07-2025
* @version: 1.0
*
**/

#include "Visitor.hpp"

// Default Constructor
Visitor::Visitor() : boost::static_visitor<void>(), m_dx(0), m_dy(0) {}

// Copy Constructor
Visitor::Visitor(const Visitor& source) : boost::static_visitor<void>(source), m_dx(source.m_dx), m_dy(source.m_dy) {}

// Constuctor that accepts x and y coordinates
Visitor::Visitor(const double x_cord, const double y_cord) : boost::static_visitor<void>(), m_dx(x_cord), m_dy(y_cord) {}

// Destructor
Visitor::~Visitor() {}

// Equality operator
Visitor& Visitor::operator=(const Visitor& source)
{
	if (this != &source)
	{
		// Call base class assignment operator
		Visitor::operator = (source);

		// Copy data members
		m_dx = source.m_dx;
		m_dy = source.m_dy;
	}

	return *this;
}

// Operator () overloading
void Visitor::operator()(Circle& circle) const
{
	Point centrePoint = circle.CentrePoint();

	// Moving the points
	centrePoint.X(centrePoint.X() + m_dx);
	centrePoint.Y(centrePoint.Y() + m_dy);

	circle.CentrePoint(centrePoint);
}

void Visitor::operator()(Line& line) const
{
	Point point1 = line.P1();
	Point point2 = line.P2();

	// Moving the points
	point1.X(point1.X() + m_dx);
	point1.Y(point1.Y() + m_dy);
	point2.X(point2.X() + m_dx);
	point2.Y(point2.Y() + m_dy);

	line.P1(point1);
	line.P2(point2);
}

void Visitor::operator()(Point& point) const
{
	// Moving the points
	point.X(point.X() + m_dx);
	point.Y(point.Y() + m_dy);
}
