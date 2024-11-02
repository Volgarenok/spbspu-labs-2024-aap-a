#include <iostream>
#include <stdexcept>
#include <cmath>
#include <iomanip>
#include "taylor.h"

int main()
{

    const double error = 0.042;
    const double step = 0.04;
    double left = 0.0, right = 0.0;
    size_t max = 0;

    std::cout << "Enter the start and end of the calculation interval:";
    std::cin >> left >> right;
    std::cout << "Enter the maximum number of terms:";
    std::cin >> max; 

    if (std::cin.fail())
    {
        std::cerr << "Error. Wrong imput." << '\n';
        return 1;
    }

    if (max <= 0 || left <= -0.7 || right >= 0.7 || left > right)
    {
        std::cerr << "Error. Incorrect values." << '\n';
        return 1;
    }

    std::cout << std::setw(10);
    for (auto i = left; i < right; i += step)
    {
        double value = ivanova::f(i, max, error);
        std::cout << i;
        std::cout << ' ';
        try
        {
            std::cout << ivanova::f(right, max, error);
        } 
        catch (const std::logic_error & e)
        {
            std::cout << "<MATH ERROR>";
        }
        std::cout << " " << ivanova::stdf(i) << '\n';
    }
    std::cout << right;
    try
    {
        std::cout << " " << ivanova::f(right, max, error);
    }
    catch(const std::logic_error& e)
    {
        std::cout << "<MATH ERROR>";
    }
    std::cout << " " << ivanova::stdf(right) << '\n';
}


double ivanova::stdf(double)
{
    return 0.0;
}
