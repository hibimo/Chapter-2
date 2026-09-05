
#ifndef Rational_H
#define Rational_H
#include <iostream>
#include <stdexcept>


using namespace std;

class Rational
{
private:
	int numerator;
	int denominator;

// Precondition: denominator is not 0.
// Postcondition: the rational number is reduced to lowest terms, the denominator is positive, and 0 is stored as 0/1.
	void simplify()
	{
		if (denominator == 0)
			throw invalid_argument("Denominator cannot be zero.");

		if (numerator ==0)
		{
			denominator = 1;
			return;
		}

		int num = numerator;
		int den = denominator;

		if (num < 0)
			num = -num;

		if (den < 0)
			den = -den;

		int smaller;

		if (num < den)
			smaller = num;
		else
			smaller = den;

		int gcd = 1;

		for (int i = 1; i <= smaller; i++)
		{
			if (num % i == 0 && den % i == 0)
				gcd = i;
		}

		numerator /= gcd;
		denominator /= gcd;

		if (denominator < 0)
		{
			numerator = -numerator;
			denominator = -denominator;
		}
	}
public:
	//Precondition: denominator cannot be 0.
	//Postcondition: numerator and denominator are initialized and the rational number is normalized.
	Rational(int numerator = 0, int denominator = 1)
	{
		if (denominator == 0)
			throw invalid_argument("Denominator cannot be zero.");
			
			this->numerator = numerator;
			this->denominator = denominator;

		simplify();
	}

	//destructor
	// Precondition: None.
	// Postcondition: The Rational object is destroyed.
	~Rational()
	{
	}

	//accessor
	// Precondition: None.
	// Postcondition: Return the numerator.
	int getNumerator() const
	{
		return numerator;
	}
	// Precondition: None.
	// Postcondition: Return the denominator.
	int getDenominator() const
	{
		return denominator;
	}

	//mutator
	// Precondition: None.
	// Postcondition: Set the numerator to the given value and normalizes the rational number.
	void setNumerator(int numerator)
	{
		this->numerator = numerator;
		simplify();
	}
	// Precondition: denominator cannot be 0.
	// Postcondition: Set the denominator to the given value and normalizes the rational number.
	void setDenominator(int denominator)
	{
		if (denominator == 0)
			throw invalid_argument("Denominator cannot be zero.");
		
			this->denominator = denominator;
			simplify();
		
	}

	//arithmetic operator
	friend Rational operator*(const Rational & r1, const Rational& r2);
	friend Rational operator/(const Rational & r1, const Rational& r2);
	friend Rational operator+(const Rational& r1, const Rational& r2);
	friend Rational operator-(const Rational& r1, const Rational& r2);

	

	//comparison operator - overloading with operators!=,<=,>,>=.
	friend bool operator==(const Rational& r1, const Rational& r2);
	friend bool operator!=(const Rational& r1, const Rational& r2);
	friend bool operator<(const Rational& r1, const Rational& r2);
	friend bool operator<=(const Rational& r1, const Rational& r2);
	friend bool operator>(const Rational& r1, const Rational& r2);
	friend bool operator>=(const Rational& r1, const Rational& r2);

	//input/output operators
	// Precondition: r is a valid Rational object.
	// Postcondition: the rational number is written to the output stream in numerator/denominator format.
	friend ostream& operator<<(ostream& outs, const Rational& r)
	{
		outs << r.numerator << "/" << r.denominator;
		return outs;
	}
	// Precondition: Input contain valid integer values for numerator and denominator, and denominator not 0.
	// Postcondition: The Rational object store the entered values in normalized form.
	friend istream& operator>>(istream& ins, Rational& r)
	{
		int numerator;
		int denominator;
		char slash;

		ins >> numerator >> slash >> denominator;

		if (slash != '/')
			throw invalid_argument("Invalid rational format. Use numerator/denominator.");

		if (denominator == 0)
			throw invalid_argument("Denominator cannot be zero.");

		r.numerator = numerator;
		r.denominator = denominator;
		r.simplify();

		return ins;
	}
};

// Precondition: r1 and r2 are valid Rational objects.
	// Postcondition: Return a normalized Rational object equal to r1 * r2.
inline Rational operator*(const Rational& r1, const Rational& r2)
{
	int newNumerator = r1.numerator * r2.numerator;
	int newDenominator = r1.denominator * r2.denominator;

	return Rational(newNumerator, newDenominator);
}
// Precondition: r1 and r2 are valid Rational objects, and r2.numerator is not zero.
// Postcondition: Return a normalized Rational object equal to r1 / r2.
inline Rational operator/(const Rational& r1, const Rational& r2)
{
	if (r2.numerator == 0)
		throw runtime_error("Cannot divide by a zero rational number.");

	int newNumerator = r1.numerator * r2.denominator;
	int newDenominator = r1.denominator * r2.numerator;

	return Rational(newNumerator, newDenominator);
}
// Precondition: r1 and r2 are valid Rational objects. 
// Postcondition: Return a normalized Rational object equal to r1 + r2.
inline Rational operator+(const Rational& r1, const Rational& r2)
{
	int newNumerator = r1.numerator * r2.denominator + r1.denominator * r2.numerator;
	int newDenominator = r1.denominator * r2.denominator;

	return Rational(newNumerator, newDenominator);
}
// Precondition: r1 and r2 are valid Rational objects.
// Postcondition: Return a normalized Rational object equal to r1 - r2.
inline Rational operator-(const Rational& r1, const Rational& r2)
{
	int newNumerator = r1.numerator * r2.denominator - r1.denominator * r2.numerator;
	int newDenominator = r1.denominator * r2.denominator;

	return Rational(newNumerator, newDenominator);
}


// Precondition: r1 and r2 are valid Rational objects.
// Postcondition: Compare r1 and r2, if r1 and r2 have equal values return True, otherwise return False.
inline bool operator== (const Rational& r1, const Rational& r2)
{
	return r1.numerator * r2.denominator == r1.denominator * r2.numerator;
}
// Precondition: r1 and r2 are valid Rational objects.
// Postcondition: Compare r1 and r2, only if r1 < r2 return True, otherwise return False.
inline bool operator< (const Rational& r1, const Rational& r2)
{
	return r1.numerator * r2.denominator < r1.denominator * r2.numerator;
}
// Precondition: r1 and r2 are valid Rational objects.
// Postcondition: Compare r1 and r2, only if r1 and r2 are not equal to return True, otherwise return False.
inline bool operator!= (const Rational& r1, const Rational& r2)
{
	return !(r1 == r2); //return the opposite answer to when they are equal to
}
// Precondition: r1 and r2 are valid Rational objects.
// Postcondition: Return true if r1 is less than or equal to r2, otherwise return false.
inline bool operator<=(const Rational& r1, const Rational& r2)
{
	return (r1 < r2) || (r1 == r2);
}
// Precondition: r1 and r2 are valid Rational objects.
// Postcondition: Return true if r1 is greater than r2, otherwise return false.
inline bool operator>(const Rational& r1, const Rational& r2)
{
	return !(r1 <= r2);
}
// Precondition: r1 and r2 are valid Rational objects.
// Postcondition: Return true if r1 is greater than or equal to r2, otherwise return false.
inline bool operator>=(const Rational& r1, const Rational& r2)
{
	return !(r1 < r2);
}

#endif