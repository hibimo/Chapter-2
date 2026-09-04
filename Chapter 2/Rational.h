#pragma once

#include <iostream>
#include <stdexcept>
#include <algorithm>

class Rational
{
private:
	int numerator;
	int denominator;

	// Pre-condition:  None
	// Post-condition: Returns greatest common divisor of a and b (positive integer)
	int gcd(int a, int b)
	{
		// TODO: To be implemented by team
		(void)a;
		(void)b;
		return 1;
	}

	// Pre-condition:  denominator != 0
	// Post-condition: Reduces fraction to lowest terms and ensures denominator is positive
	void simplify()
	{
		// TODO: To be implemented by team
		if (denominator == 0)
		{
			throw std::runtime_error("Denominator cannot be zero.");
		}
	}

public:
	// Pre-condition:  None
	// Post-condition: Initializes Rational number to 0/1
	Rational()
	{
		numerator = 0;
		denominator = 1;
	}

	// Pre-condition:  d != 0
	// Post-condition: Initializes Rational number to n/d in simplified form
	Rational(int n, int d)
	{
		if (d == 0)
		{
			throw std::invalid_argument("Denominator cannot be zero.");
		}
		numerator = n;
		denominator = d;
		simplify();
	}

	// Pre-condition:  None
	// Post-condition: Sets numerator and simplifies fraction
	void setNumerator(int n)
	{
		numerator = n;
		simplify();
	}

	// Pre-condition:  None
	// Post-condition: Returns numerator
	int getNumerator() const
	{
		return numerator;
	}

	// Pre-condition:  d != 0
	// Post-condition: Sets denominator and simplifies fraction; throws runtime_error if d == 0
	void setDenominator(int d)
	{
		if (d == 0)
		{
			throw std::runtime_error("Denominator cannot be zero.");
		}
		denominator = d;
		simplify();
	}

	// Pre-condition:  None
	// Post-condition: Returns denominator
	int getDenominator() const
	{
		return denominator;
	}

	// Pre-condition:  R1 and R2 are valid Rational objects
	// Post-condition: Returns true if R1 == R2, false otherwise
	friend bool operator==(const Rational& R1, const Rational& R2)
	{
		// TODO: To be implemented by team
		(void)R1;
		(void)R2;
		std::cout << "\n\t[Not yet implemented: operator==]\n";
		return false;
	}

	// Pre-condition:  R1 and R2 are valid Rational objects
	// Post-condition: Returns true if R1 < R2, false otherwise
	friend bool operator<(const Rational& R1, const Rational& R2)
	{
		// TODO: To be implemented by team
		(void)R1;
		(void)R2;
		std::cout << "\n\t[Not yet implemented: operator<]\n";
		return false;
	}
};

// Pre-condition:  R1 and R2 are valid Rational objects
// Post-condition: Returns result of R1 * R2
inline Rational operator *(const Rational& R1, const Rational& R2)
{
	// TODO: To be implemented by team
	(void)R1;
	(void)R2;
	std::cout << "\n\t[Not yet implemented: operator*]\n";
	return Rational();
}

// Pre-condition:  R2 numerator != 0
// Post-condition: Returns result of R1 / R2; throws runtime_error if R2 == 0
inline Rational operator /(const Rational& R1, const Rational& R2)
{
	// TODO: To be implemented by team
	(void)R1;
	(void)R2;
	std::cout << "\n\t[Not yet implemented: operator/]\n";
	return Rational();
}

// Pre-condition:  R1 and R2 are valid Rational objects
// Post-condition: Returns result of R1 + R2
inline Rational operator +(const Rational& R1, const Rational& R2)
{
	// TODO: To be implemented by team
	(void)R1;
	(void)R2;
	std::cout << "\n\t[Not yet implemented: operator+]\n";
	return Rational();
}

// Pre-condition:  R1 and R2 are valid Rational objects
// Post-condition: Returns result of R1 - R2
inline Rational operator -(const Rational& R1, const Rational& R2)
{
	// TODO: To be implemented by team
	(void)R1;
	(void)R2;
	std::cout << "\n\t[Not yet implemented: operator-]\n";
	return Rational();
}
