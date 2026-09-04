#pragma once

#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

class Pseudorandom
{
private:
    int seed;
    int multiplier;
    int increment;
    int modulus;

public:
    // Pre-condition:  mod > 0
    // Post-condition: Initializes Pseudorandom generator with given parameters
    Pseudorandom(int s, int m, int i, int mod)
    {
        seed = s;
        multiplier = m;
        increment = i;
        modulus = (mod > 0) ? mod : 729;
    }

    // Pre-condition:  None
    // Post-condition: Initializes Pseudorandom generator with default values:
    //                 seed = 1, multiplier = 40, increment = 725, modulus = 729
    Pseudorandom()
    {
        seed = 1;
        multiplier = 40;
        increment = 725;
        modulus = 729;
    }

    // ================================= Accessors ==================================

    // Pre-condition:  None
    // Post-condition: Returns current seed value
    int getSeed() const { return seed; }

    // Pre-condition:  None
    // Post-condition: Returns current multiplier value
    int getMultiplier() const { return multiplier; }

    // Pre-condition:  None
    // Post-condition: Returns current increment value
    int getIncrement() const { return increment; }

    // Pre-condition:  None
    // Post-condition: Returns current modulus value
    int getModulus() const { return modulus; }

    // =================================== Mutators ====================================

    // Pre-condition:  s is a valid integer
    // Post-condition: Seed is updated to s
    void setSeed(int s) { seed = s; }

    // Pre-condition:  m is a valid integer
    // Post-condition: Multiplier is updated to m
    void setMultiplier(int m) { multiplier = m; }

    // Pre-condition:  i is a valid integer
    // Post-condition: Increment is updated to i
    void setIncrement(int i) { increment = i; }

    // Pre-condition:  mod > 0
    // Post-condition: Modulus is updated to mod; throws runtime_error if mod <= 0
    void setModulus(int mod)
    {
        if (mod <= 0) throw std::runtime_error("Modulus must be > 0.");
        modulus = mod;
    }

    // ============================= Calculation Methods ==============================

    // Pre-condition:  modulus > 0
    // Post-condition: Computes (multiplier * seed + increment) % modulus, updates seed, and returns new number
    int getNextNumber()
    {
        // TODO: To be implemented by team
        std::cout << "\n\t[Not yet implemented: getNextNumber]\n";
        return seed;
    }

    // Pre-condition:  modulus > 0
    // Post-condition: Returns next pseudorandom number as double in [0.0, 1.0)
    double getIndirectNextDouble()
    {
        // TODO: To be implemented by team
        std::cout << "\n\t[Not yet implemented: getIndirectNextDouble]\n";
        return 0.0;
    }

    // Pre-condition:  modulus > 0
    // Post-condition: Generates 12 random numbers and returns approximate Gaussian distribution value
    double getGaussian()
    {
        // TODO: To be implemented by team
        std::cout << "\n\t[Not yet implemented: getGaussian]\n";
        return 0.0;
    }

    // Pre-condition:  arr is valid, n >= 0
    // Post-condition: Sorts arr in ascending order using Selection Sort
    void selectionSort(double arr[], int n)
    {
        // TODO: To be implemented by team
        (void)arr;
        (void)n;
    }

    // Pre-condition:  iterations > 0
    // Post-condition: Runs distribution experiment across 10 intervals [0.0..1.0)
    void runDistributionExperiment(int iterations = 1000000)
    {
        // TODO: To be implemented by team
        (void)iterations;
        std::cout << "\n\t[Not yet implemented: runDistributionExperiment]\n";
    }
};
