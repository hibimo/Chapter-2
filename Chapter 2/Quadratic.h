#pragma once

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <cmath>

class Quadratic
{
private:
	double a;
	double b;
	double c;
	double x;

public:
	// Pre-condition:  None
	// Post-condition: Initializes a Quadratic object with a = 0, b = 0, c = 0, x = 0
	Quadratic() {
		a = 0.0;
		b = 0.0;
		c = 0.0;
		x = 0.0;
	}

	// Pre-condition:  coefficientA is a valid double
	// Post-condition: Sets coefficient a as coefficientA
	void setA(double coefficientA) {
		a = coefficientA;
	}

	// Pre-condition:  None
	// Post-condition: Returns coefficient a
	double getA() const
	{
		return a;
	}

	// Pre-condition:  coefficientB is a valid double
	// Post-condition: Sets coefficient b as coefficientB
	void setB(double coefficientB)
	{
		b = coefficientB;
	}

	// Pre-condition:  None
	// Post-condition: Returns coefficient b
	double getB() const
	{
		return b;
	}

	// Pre-condition:  coefficientC is a valid double
	// Post-condition: Sets coefficient c as coefficientC
	void setC(double coefficientC)
	{
		c = coefficientC;
	}

	// Pre-condition:  None
	// Post-condition: Returns coefficient c
	double getC() const
	{
		return c;
	}

	// Pre-condition:  variable is a valid double
	// Post-condition: Sets evaluation variable x
	void setX(double variable)
	{
		x = variable;
	}

	// Pre-condition:  None
	// Post-condition: Returns evaluation variable x
	double getX() const
	{
		return x;
	}

	// Pre-condition:  None
	// Post-condition: Displays quadratic expression in standard form (ax^2 + bx + c)
	void showFormula() const {
		std::cout << "\n\t" << a << "x^2 + " << b << "x + " << c << std::endl;
	}

	// Pre-condition:  Coefficients a, b, and c are finite values
	// Post-condition: Returns discriminant (b^2 - 4ac)
	double discriminant() const {
		// TODO: To be implemented by team
		return b * b - 4 * a * c;
	}

	// Pre-condition:  Coefficients a, b, c are finite values
	// Post-condition: Returns number of real roots: 0 (none), 1 (one), 2 (two), or 3 (infinitely many)
	int NumRealRoot() const
	{
		// TODO: To be implemented by team
		std::cout << "\n\t[Not yet implemented: NumRealRoot]\n";
		return 0;
	}

	// Pre-condition:  At least one real root exists (NumRealRoot() == 1 or 2)
	// Post-condition: Returns smaller real root value; returns 0 if no root or infinite roots
	double SmallerRoot() const
	{
		// TODO: To be implemented by team
		std::cout << "\n\t[Not yet implemented: SmallerRoot]\n";
		return 0.0;
	}

	// Pre-condition:  At least one real root exists (NumRealRoot() == 1 or 2)
	// Post-condition: Returns larger real root value; returns 0 if no root or infinite roots
	double LargerRoot() const
	{
		// TODO: To be implemented by team
		std::cout << "\n\t[Not yet implemented: LargerRoot]\n";
		return 0.0;
	}

	// Pre-condition:  x is set
	// Post-condition: Returns evaluated value: a*x^2 + b*x + c
	double quadratic() const {
		// TODO: To be implemented by team
		std::cout << "\n\t[Not yet implemented: quadratic]\n";
		return 0.0;
	}
};

// Pre-condition:  q1 and q2 are valid Quadratic objects
// Post-condition: Returns new Quadratic whose coefficients are sum of q1 and q2
inline Quadratic operator +(const Quadratic& q1, const Quadratic& q2)
{
	// TODO: To be implemented by team
	(void)q1;
	(void)q2;
	std::cout << "\n\t[Not yet implemented: operator+]\n";
	Quadratic temp;
	return temp;
}

// Pre-condition:  r is a finite double; q1 is a valid Quadratic object
// Post-condition: Returns new Quadratic whose coefficients are scaled by r
inline Quadratic operator *(double r, const Quadratic& q1)
{
	// TODO: To be implemented by team
	(void)r;
	(void)q1;
	std::cout << "\n\t[Not yet implemented: operator*]\n";
	Quadratic temp;
	return temp;
}
