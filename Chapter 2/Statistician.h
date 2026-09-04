#pragma once

#include <iostream>
#include <stdexcept>
#include <algorithm>

class Statistician
{
private:
    int count;          // number of elements in sequence
    double total;       // sum of elements
    double lastValue;   // last number entered
    double smallest;    // minimum value
    double largest;     // maximum value
    bool isEmpty;       // true if no numbers have been entered

public:
    // Pre-condition:  None
    // Post-condition: Initializes empty Statistician
    Statistician()
    {
        reset();
    }

    // Pre-condition:  None
    // Post-condition: Resets sequence to empty state
    void reset()
    {
        count = 0;
        total = 0.0;
        lastValue = 0.0;
        smallest = 0.0;
        largest = 0.0;
        isEmpty = true;
    }

    // Pre-condition:  num is a valid double
    // Post-condition: Adds num to sequence, updates count, total, lastValue, smallest, and largest
    void next_number(double num)
    {
        // TODO: To be implemented by team
        (void)num;
        std::cout << "\n\t[Not yet implemented: next_number]\n";
    }

    // Pre-condition:  None
    // Post-condition: Returns count of numbers in sequence
    int length() const
    {
        return count;
    }

    // Pre-condition:  None
    // Post-condition: Returns sum of numbers in sequence
    double sum() const
    {
        return total;
    }

    // Pre-condition:  Sequence is not empty (length() > 0)
    // Post-condition: Returns the last number entered; throws runtime_error if empty
    double last() const
    {
        // TODO: To be implemented by team
        if (isEmpty)
            throw std::runtime_error("No numbers entered. Cannot get last number.");
        return lastValue;
    }

    // Pre-condition:  Sequence is not empty (length() > 0)
    // Post-condition: Returns mean (total / count); throws runtime_error if empty
    double mean() const
    {
        // TODO: To be implemented by team
        if (isEmpty)
            throw std::runtime_error("No numbers entered. Cannot calculate mean.");
        return 0.0;
    }

    // Pre-condition:  Sequence is not empty (length() > 0)
    // Post-condition: Returns smallest value; throws runtime_error if empty
    double minimum() const
    {
        // TODO: To be implemented by team
        if (isEmpty)
            throw std::runtime_error("No numbers entered. Cannot get minimum.");
        return smallest;
    }

    // Pre-condition:  Sequence is not empty (length() > 0)
    // Post-condition: Returns largest value; throws runtime_error if empty
    double maximum() const
    {
        // TODO: To be implemented by team
        if (isEmpty)
            throw std::runtime_error("No numbers entered. Cannot get maximum.");
        return largest;
    }

    // Pre-condition:  s1 and s2 are valid Statistician objects
    // Post-condition: Returns a combined Statistician with all values from s1 and s2
    friend Statistician operator+(const Statistician& s1, const Statistician& s2)
    {
        // TODO: To be implemented by team
        (void)s1;
        (void)s2;
        std::cout << "\n\t[Not yet implemented: operator+]\n";
        Statistician result;
        return result;
    }
};
