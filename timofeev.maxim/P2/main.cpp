#include <iostream>
#include "arctanTaylor.hpp"


int main()
{
    double start = 0;
    double end = 0;
    int numberMax = 0;
    const double absError = 0.005;
    const double step = 0.02;

    std::cout << "Enter the maximum number of terms: ";
    std::cin >> numberMax;

    if (!std::cin)
    {
        std::cerr << "The input value must be an integer" << std::endl;
        return -1;
    }

    if (numberMax <= 0)
    {
        std::cerr << "The maximum number of terms must be a positive integer" << std::endl;
        return -1;
    }

    std::cout << "Enter the beginning of the interval: ";
    std::cin >> start;

    if (!std::cin)
    {
        std::cerr << "The input value must be a floating point number" << std::endl;
        return -1;
    }

    std::cout << "Enter the end of the interval: ";
    std::cin >> end;

    if (!std::cin)
    {
        std::cerr << "The input value must be a floating point number" << std::endl;
        return -1;
    }

    if (start >= end)
    {
        std::cerr << "The beginning of the interval should be less than the end of the interval" << std::endl;
        return -1;
    }

    std::cout << "x" << "\t|" << "Tangent"  << "\t| " << "Taylor's row" << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    try
    {
        for (double x = start; x <= end; x += step)
        {
            double arctanTaylorValue = arctanTaylor(x, absError, numberMax);
            std::cout << x << "\t|" << std::atan(x) << "\t|" << arctanTaylorValue << std::endl;
        }
    }
    catch (const std::logic_error& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
