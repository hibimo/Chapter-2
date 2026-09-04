#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include "input.h"
#include "Statistician.h"
#include "Quadratic.h"
#include "Rational.h"
#include "Pseudorandom.h"

using namespace std;

void mainMenu();
void StatisticianFunction();
void QuadraticFunction();
void RationalFunction();
void PseudorandomFunction();

void StatMenu();
void QuadraticMenu();
void RationalMenu();
void PseudorandomMenu();

int main()
{
	do
	{
		system("cls");
		mainMenu();
		char option = toupper(inputChar("\n\tOption: "));

		switch (option)
		{
		case '1':
			StatisticianFunction();
			break;
		case '2':
			QuadraticFunction();
			break;
		case '3':
			PseudorandomFunction();
			break;
		case '4':
			RationalFunction();
			break;
		case 'X':
			exit(0);
		default:
			cout << "\n\tERROR: Invalid Input.\n";
			break;
		}

		cout << "\n\n\t";
		system("pause");

	} while (true);

	return EXIT_SUCCESS;
}

void mainMenu()
{
	cout << "\n\tCMPR131 Chapter 2 - ADT Assignments ";
	cout << "\n\t" << string(80, char(205));
	cout << "\n\t\t1> Statistician";
	cout << "\n\t\t2> Quadratic Expression";
	cout << "\n\t\t3> Pseudorandom";
	cout << "\n\t\t4> Rational number";
	cout << "\n\t" << string(80, char(196));
	cout << "\n\t\tX. Exit";
	cout << "\n\t" << string(80, char(205)) << "\n";
}

// ============================================================================
// 1. Statistician
// ============================================================================

void StatMenu()
{
	cout << "\n\t1> Statistician Menu";
	cout << "\n\t" << string(80, char(205));
	cout << "\n\t\tA. Insert a number";
	cout << "\n\t\tB. Size of sequence";
	cout << "\n\t\tC. Last number of sequence";
	cout << "\n\t\tD. Sum of sequence";
	cout << "\n\t\tE. Mean of sequence";
	cout << "\n\t\tF. Smallest number of sequence";
	cout << "\n\t\tG. Largest number of sequence";
	cout << "\n\t\tH. Reset sequence";
	cout << "\n\t\tI. Combine with another sequence";
	cout << "\n\t" << string(80, char(196));
	cout << "\n\t\tR. Return";
	cout << "\n\t" << string(80, char(205)) << "\n";
}

void StatisticianFunction()
{
	Statistician s;

	do
	{
		system("cls");
		StatMenu();

		try
		{
			char opt = toupper(inputChar("\n\tOption: "));
			switch (opt)
			{
			case 'A':
			{
				double number = inputDouble("\n\tEnter a double number: ");
				s.next_number(number);
				cout << "\n\tNumber " << number << " added to sequence.\n";
				break;
			}
			case 'B':
				cout << "\n\tThe size of the sequence is: \t" << s.length() << "\n";
				break;
			case 'C':
				cout << "\n\tThe last number of the sequence is: \t" << s.last() << "\n";
				break;
			case 'D':
				cout << "\n\tThe Sum of the sequence is: \t" << s.sum() << "\n";
				break;
			case 'E':
				cout << "\n\tThe Mean of the sequence is: \t" << s.mean() << "\n";
				break;
			case 'F':
				cout << "\n\tThe smallest number of the sequence is: \t" << s.minimum() << "\n";
				break;
			case 'G':
				cout << "\n\tThe largest number of the sequence is: \t" << s.maximum() << "\n";
				break;
			case 'H':
				s.reset();
				cout << "\n\tSequence has been reset.\n";
				break;
			case 'I':
			{
				Statistician s1;
				int n = inputInteger("\n\tHow many numbers to insert into second sequence: ", 1, 100);
				for (int i = 0; i < n; i++)
				{
					double val = inputDouble("\tEnter number: ");
					s1.next_number(val);
				}
				s = s + s1;
				cout << "\n\tSequences combined successfully.\n";
				break;
			}
			case 'R':
				return;
			default:
				cout << "\n\tERROR: Invalid Input.\n";
				break;
			}
		}
		catch (const exception& e)
		{
			cout << "\n\tERROR: " << e.what() << "\n";
		}

		cout << "\n\n\t";
		system("pause");

	} while (true);
}

// ============================================================================
// 2. Quadratic Expression
// ============================================================================

void QuadraticMenu()
{
	cout << "\n\t2> Quadratic Menu";
	cout << "\n\t" << string(80, char(205));
	cout << "\n\t\tD. Display the expression";
	cout << "\n\t\tA. Set coefficient (a)";
	cout << "\n\t\tB. Set coefficient (b)";
	cout << "\n\t\tC. Set coefficient (c)";
	cout << "\n\t\tE. Get evaluation (x)";
	cout << "\n\t\tN. Get the number of real roots";
	cout << "\n\t\tG. Get real root(s)";
	cout << "\n\t\tH. Add another quadratic expression";
	cout << "\n\t\tI. Scale expression by a constant";
	cout << "\n\t" << string(80, char(196));
	cout << "\n\t\tR. Return";
	cout << "\n\t" << string(80, char(205)) << "\n";
}

void QuadraticFunction()
{
	Quadratic q;

	do
	{
		system("cls");
		QuadraticMenu();
		int num = q.NumRealRoot();

		try
		{
			char opt = toupper(inputChar("\n\tOption: "));
			switch (opt)
			{
			case 'D':
				cout << "\n\tCurrent Expression: ";
				q.showFormula();
				break;
			case 'A':
			{
				double a = inputDouble("\n\tEnter coefficient (a): ");
				q.setA(a);
				cout << "\n\tSet a = " << q.getA() << "\n";
				break;
			}
			case 'B':
			{
				double b = inputDouble("\n\tEnter coefficient (b): ");
				q.setB(b);
				cout << "\n\tSet b = " << q.getB() << "\n";
				break;
			}
			case 'C':
			{
				double c = inputDouble("\n\tEnter coefficient (c): ");
				q.setC(c);
				cout << "\n\tSet c = " << q.getC() << "\n";
				break;
			}
			case 'E':
			{
				double x = inputDouble("\n\tEnter value of x: ");
				q.setX(x);
				cout << "\n\tEvaluation result: " << q.quadratic() << "\n";
				break;
			}
			case 'N':
			{
				if (num == 3)
				{
					cout << "\n\tNumber of real roots: Infinity (all x are roots)\n";
				}
				else
				{
					cout << "\n\tNumber of real roots: " << num << "\n";
				}
				break;
			}
			case 'G':
			{
				if (num == 3)
				{
					cout << "\n\tEvery value of x is a real root.\n";
				}
				else if (num == 0)
				{
					cout << "\n\tNo real roots.\n";
				}
				else if (num == 1)
				{
					cout << "\n\tOne real root: " << q.SmallerRoot() << "\n";
				}
				else
				{
					cout << "\n\tTwo real roots:";
					cout << "\n\tSmaller root = " << q.SmallerRoot();
					cout << "\n\tLarger  root = " << q.LargerRoot() << "\n";
				}
				break;
			}
			case 'H':
			{
				Quadratic q1;
				cout << "\n\tPlease enter coefficients for second expression:\n";
				q1.setA(inputDouble("\tEnter coefficient (a): "));
				q1.setB(inputDouble("\tEnter coefficient (b): "));
				q1.setC(inputDouble("\tEnter coefficient (c): "));

				Quadratic sumQ = q + q1;
				cout << "\n\tSum of expressions: ";
				sumQ.showFormula();

				char choice = toupper(inputChar("\n\tStore this sum as the current expression? (Y/N): ", 'Y', 'N'));
				if (choice == 'Y')
				{
					q = sumQ;
					cout << "\n\tSaved. Current expression updated.\n";
				}
				break;
			}
			case 'I':
			{
				double r = inputDouble("\n\tEnter scale factor r: ");
				cout << "\n\tBefore scaling: ";
				q.showFormula();

				q = r * q;
				cout << "\n\tAfter scaling: ";
				q.showFormula();
				break;
			}
			case 'R':
				return;
			default:
				cout << "\n\tERROR: Invalid Input.\n";
				break;
			}
		}
		catch (const exception& e)
		{
			cout << "\n\tERROR: " << e.what() << "\n";
		}

		cout << "\n\n\t";
		system("pause");

	} while (true);
}

// ============================================================================
// 3. Pseudorandom
// ============================================================================

void PseudorandomMenu()
{
	cout << "\n\t3> Pseudorandom Menu";
	cout << "\n\t" << string(80, char(205));
	cout << "\n\t\tA. Get seed";
	cout << "\n\t\tB. Set seed";
	cout << "\n\t\tC. Get multiplier";
	cout << "\n\t\tD. Set multiplier";
	cout << "\n\t\tE. Get modulus";
	cout << "\n\t\tF. Set modulus";
	cout << "\n\t\tG. Get increment";
	cout << "\n\t\tH. Set increment";
	cout << "\n\t\tI. Get next number";
	cout << "\n\t\tJ. Get indirect next double [0.0, 1.0)";
	cout << "\n\t\tK. Run distribution experiment";
	cout << "\n\t" << string(80, char(196));
	cout << "\n\t\tR. Return";
	cout << "\n\t" << string(80, char(205)) << "\n";
}

void PseudorandomFunction()
{
	Pseudorandom p;

	do
	{
		system("cls");
		PseudorandomMenu();

		try
		{
			char opt = toupper(inputChar("\n\tOption: "));
			switch (opt)
			{
			case 'A':
				cout << "\n\tSeed = " << p.getSeed() << "\n";
				break;
			case 'B':
				p.setSeed(inputInteger("\n\tEnter seed: "));
				cout << "\n\tSeed updated to " << p.getSeed() << "\n";
				break;
			case 'C':
				cout << "\n\tMultiplier = " << p.getMultiplier() << "\n";
				break;
			case 'D':
				p.setMultiplier(inputInteger("\n\tEnter multiplier: "));
				cout << "\n\tMultiplier updated to " << p.getMultiplier() << "\n";
				break;
			case 'E':
				cout << "\n\tModulus = " << p.getModulus() << "\n";
				break;
			case 'F':
				p.setModulus(inputInteger("\n\tEnter modulus (> 0): ", 1, true));
				cout << "\n\tModulus updated to " << p.getModulus() << "\n";
				break;
			case 'G':
				cout << "\n\tIncrement = " << p.getIncrement() << "\n";
				break;
			case 'H':
				p.setIncrement(inputInteger("\n\tEnter increment: "));
				cout << "\n\tIncrement updated to " << p.getIncrement() << "\n";
				break;
			case 'I':
				cout << "\n\tNext number = " << p.getNextNumber() << "\n";
				break;
			case 'J':
				cout << "\n\tIndirect next double = " << fixed << setprecision(6) << p.getIndirectNextDouble() << "\n";
				cout.unsetf(ios::fixed);
				break;
			case 'K':
				p.runDistributionExperiment();
				break;
			case 'R':
				return;
			default:
				cout << "\n\tERROR: Invalid Input.\n";
				break;
			}
		}
		catch (const exception& e)
		{
			cout << "\n\tERROR: " << e.what() << "\n";
		}

		cout << "\n\n\t";
		system("pause");

	} while (true);
}

// ============================================================================
// 4. Rational Number
// ============================================================================

void RationalMenu()
{
	cout << "\n\t4> Rational Number Menu";
	cout << "\n\t" << string(80, char(205));
	cout << "\n\t\tA. Enter values for rational number R1";
	cout << "\n\t\tB. Display R1";
	cout << "\n\t\tC. Enter values for rational number R2";
	cout << "\n\t\tD. Display R2";
	cout << "\n\t\tE. Multiplication (R1 * R2)";
	cout << "\n\t\tF. Division (R1 / R2)";
	cout << "\n\t\tG. Addition (R1 + R2)";
	cout << "\n\t\tH. Subtraction (R1 - R2)";
	cout << "\n\t\tI. Equal comparison (R1 == R2)";
	cout << "\n\t\tJ. Less than comparison (R1 < R2)";
	cout << "\n\t" << string(80, char(196));
	cout << "\n\t\tR. Return";
	cout << "\n\t" << string(80, char(205)) << "\n";
}

void RationalFunction()
{
	Rational R1(0, 1);
	Rational R2(0, 1);

	do
	{
		system("cls");
		RationalMenu();

		try
		{
			char opt = toupper(inputChar("\n\tOption: "));
			switch (opt)
			{
			case 'A':
			{
				int n = inputInteger("\n\tEnter numerator for R1: ");
				int d = inputInteger("\tEnter denominator for R1 (non-zero): ");
				if (d == 0)
				{
					cout << "\n\tERROR: Denominator cannot be zero.\n";
					break;
				}
				R1.setNumerator(n);
				R1.setDenominator(d);
				cout << "\n\tR1 set to: " << R1.getNumerator() << "/" << R1.getDenominator() << "\n";
				break;
			}
			case 'B':
				cout << "\n\tRational number R1: " << R1.getNumerator() << "/" << R1.getDenominator() << "\n";
				break;
			case 'C':
			{
				int n = inputInteger("\n\tEnter numerator for R2: ");
				int d = inputInteger("\tEnter denominator for R2 (non-zero): ");
				if (d == 0)
				{
					cout << "\n\tERROR: Denominator cannot be zero.\n";
					break;
				}
				R2.setNumerator(n);
				R2.setDenominator(d);
				cout << "\n\tR2 set to: " << R2.getNumerator() << "/" << R2.getDenominator() << "\n";
				break;
			}
			case 'D':
				cout << "\n\tRational number R2: " << R2.getNumerator() << "/" << R2.getDenominator() << "\n";
				break;
			case 'E':
			{
				Rational R3 = R1 * R2;
				cout << "\n\tR1 * R2 = " << R3.getNumerator() << "/" << R3.getDenominator() << "\n";
				break;
			}
			case 'F':
			{
				Rational R3 = R1 / R2;
				cout << "\n\tR1 / R2 = " << R3.getNumerator() << "/" << R3.getDenominator() << "\n";
				break;
			}
			case 'G':
			{
				Rational R3 = R1 + R2;
				cout << "\n\tR1 + R2 = " << R3.getNumerator() << "/" << R3.getDenominator() << "\n";
				break;
			}
			case 'H':
			{
				Rational R3 = R1 - R2;
				cout << "\n\tR1 - R2 = " << R3.getNumerator() << "/" << R3.getDenominator() << "\n";
				break;
			}
			case 'I':
				cout << "\n\tR1 == R2 : " << ((R1 == R2) ? "TRUE" : "FALSE") << "\n";
				break;
			case 'J':
				cout << "\n\tR1 < R2  : " << ((R1 < R2) ? "TRUE" : "FALSE") << "\n";
				break;
			case 'R':
				return;
			default:
				cout << "\n\tERROR: Invalid Input.\n";
				break;
			}
		}
		catch (const exception& e)
		{
			cout << "\n\tERROR: " << e.what() << "\n";
		}

		cout << "\n\n\t";
		system("pause");

	} while (true);
}
