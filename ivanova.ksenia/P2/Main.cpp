#include <iostream>
#include <stdexcept>
#include <cmath>
#include <iomanip>

namespace ivanova
{
    double f(double x, size_t k, double error);
    double stdf(double x);
}
int main()
{
    double left = 0.0, right = 0.0;
    size_t k = 0;

    std::cout << "Enter the start and end of the calculation interval:";
    std::cin >> left >> right;
    std::cout << "Enter the maximum number of terms:";
    std::cin >> k; 

    const double error = 0.042;
    const double step = 0.04;

    std::cout << std::setw(10);
    for (auto i = left; i < right; i += step)
    {
        double value = ivanova::f(i, k, error);
        std::cout << i;
        std::cout << ' ';
        try
        {
            std::cout << ivanova::f(right, k, error);
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
        std::cout << " " << ivanova::f(right, k, error);
    }
    catch(const std::logic_error& e)
    {
        std::cout << "<MATH ERROR>";
    }
    std::cout << " " << ivanova::stdf(right) << '\n';
}

double ivanova::f(double x, size_t k, double error)
{
    double next = x;
    double result = next;
    for (size_t i = 1; i < k; ++i)
    {
        next *= x;
        result += next;
    }
    if (std::abs(next) > error)
    {
        throw std::logic_error("math-error");
    }
    return result;
}

double ivanova::stdf(double)
{
    return 0.0;
}
