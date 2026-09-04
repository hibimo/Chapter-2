#pragma once

#include <iostream>
#include <algorithm>
#include <string>
#include <limits>
#include <cctype>

using namespace std;

// PreCondition:  spaces (boolean true or false)
// PostCondition: returns a string including space character(s) or without space character
inline string inputString(string prompt, bool spaces)
{
	string input = "";
	cout << prompt;
	if (spaces)
	{
		getline(cin, input);
	}
	else
	{
		cin >> input;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return input;
}

// PreCondition:  valid string of options
// PostCondition: returns an uppercase character matching one of options
inline char inputChar(string prompt, string options)
{
	char input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input. Must be a character type.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else
		{
			bool found = false;
			for (size_t i = 0; i < options.length(); i++)
			{
				if (toupper(options.at(i)) == toupper(input))
				{
					found = true;
					break;
				}
			}
			if (found)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			}
			else
			{
				cout << "ERROR: Invalid input. Must be one of '" << options << "' character.\n";
			}
		}
	} while (true);
	return static_cast<char>(toupper(input));
}

// PreCondition:  valid yes (char) or no (char)
// PostCondition: returns an uppercase yes (char) or no (char)
inline char inputChar(string prompt, char yes, char no)
{
	char input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input. Must be a character type.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else if (tolower(input) != tolower(yes) && tolower(input) != tolower(no))
		{
			cout << "ERROR: Invalid input. Must be a '" << static_cast<char>(toupper(yes)) << "' or '" << static_cast<char>(toupper(no)) << "' character.\n";
		}
		else
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
	} while (true);
	return static_cast<char>(toupper(input));
}

// PreCondition:  alphaOrDigit (boolean true or false)
// PostCondition: returns an alphabet or a digit character
inline char inputChar(string prompt, bool alphaOrDigit)
{
	char input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input. Must be a character type.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else if (alphaOrDigit && !isalpha(static_cast<unsigned char>(input)))
		{
			cout << "ERROR: Invalid input. Must be an alphabet character.\n";
		}
		else if (!alphaOrDigit && !isdigit(static_cast<unsigned char>(input)))
		{
			cout << "ERROR: Invalid input. Must be a digit character.\n";
		}
		else
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
	} while (true);
	return input;
}

// PreCondition:  NA
// PostCondition: returns any character in uppercase
inline char inputChar(string prompt)
{
	char input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input. Must be a character type.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else
		{
			break;
		}
	} while (true);
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return static_cast<char>(toupper(input));
}

// PreCondition:  NA
// PostCondition: returns any integer value
inline int inputInteger(string prompt)
{
	int input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input. Must be an integer type.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else
		{
			break;
		}
	} while (true);
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return input;
}

// PreCondition:  posNeg (boolean true or false)
// PostCondition: returns a positive integer value (posNeg = true) or a negative integer value (posNeg = false)
inline int inputInteger(string prompt, bool posNeg)
{
	int input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input. Must be an integer type.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else if (posNeg && input <= 0)
		{
			cout << "ERROR: Invalid input. Must be a positive number.\n";
		}
		else if (!posNeg && input >= 0)
		{
			cout << "ERROR: Invalid input. Must be a negative number.\n";
		}
		else
		{
			break;
		}
	} while (true);
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return input;
}

// PreCondition:  start (integer) and greater (boolean true or false)
// PostCondition: returns an integer value greater than start or lesser than start
inline int inputInteger(string prompt, int start, bool greater)
{
	int input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input. Must be an integer type.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else if (greater && input < start)
		{
			cout << "ERROR: Invalid input. Must be greater than or equal to " << start << ".\n";
		}
		else if (!greater && input > start)
		{
			cout << "ERROR: Invalid input. Must be lesser than or equal to " << start << ".\n";
		}
		else
		{
			break;
		}
	} while (true);
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return input;
}

// PreCondition:  startRange (integer) and endRange (integer)
// PostCondition: returns an integer value within range [startRange..endRange]
inline int inputInteger(string prompt, int startRange, int endRange)
{
	int input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input. Must be an integer type.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else if (!(input >= min(startRange, endRange) && input <= max(startRange, endRange)))
		{
			cout << "ERROR: Invalid input. Must be from " << startRange << ".." << endRange << ".\n";
		}
		else
		{
			break;
		}
	} while (true);
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return input;
}

// PreCondition:  NA
// PostCondition: returns any double value
inline double inputDouble(string prompt)
{
	double input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input. Must be a double type.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else
		{
			break;
		}
	} while (true);
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return input;
}

// PreCondition:  posNeg (boolean true or false)
// PostCondition: returns a positive double (posNeg = true) or negative double (posNeg = false)
inline double inputDouble(string prompt, bool posNeg)
{
	double input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input. Must be a double type.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else if (posNeg && input <= 0.0)
		{
			cout << "ERROR: Invalid input. Must be a positive number.\n";
		}
		else if (!posNeg && input >= 0.0)
		{
			cout << "ERROR: Invalid input. Must be a negative number.\n";
		}
		else
		{
			break;
		}
	} while (true);
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return input;
}

// PreCondition:  start (double) and posNeg (boolean true or false)
// PostCondition: returns a double value greater/lesser than start
inline double inputDouble(string prompt, double start, bool posNeg)
{
	double input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input. Must be a double type.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else if (posNeg && input < start)
		{
			cout << "ERROR: Invalid input. Must be greater than or equal to " << start << ".\n";
		}
		else if (!posNeg && input > start)
		{
			cout << "ERROR: Invalid input. Must be lesser than or equal to " << start << ".\n";
		}
		else
		{
			break;
		}
	} while (true);
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return input;
}

// PreCondition:  startRange (double) and endRange (double)
// PostCondition: returns a double value within range [startRange..endRange]
inline double inputDouble(string prompt, double startRange, double endRange)
{
	double input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR: Invalid input. Must be a double type.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else if (!(input >= min(startRange, endRange) && input <= max(startRange, endRange)))
		{
			cout << "ERROR: Invalid input. Must be from " << startRange << ".." << endRange << ".\n";
		}
		else
		{
			break;
		}
	} while (true);
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return input;
}
