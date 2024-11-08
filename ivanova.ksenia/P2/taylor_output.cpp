#include "taylor.h"
#include <iostream>
#include <iomanip>
#include <cstring>

void ivanova::Output(double x, size_t k, double error)
{
    const size_t MathErr = std::strlen("<MATH ERROR>") + 3;
    const size_t Cols = 11;
    try
    {
        std::cout << std::setw(MathErr) << ivanova::exp(x, k, error);
    }
    catch(const std::logic_error & e)
    {
        std::cout << std::setw(MathErr) << "<MATH ERROR>";
    }
    try
    {
        std::cout << std::setw(MathErr) << ivanova::arctg(x, k, error);
    }
    catch (const std::logic_error& e)
    {
        std::cout << std::setw(MathErr) << "<MATH ERROR>";
    }
    try
    {
        std::cout << std::setw(MathErr) << ivanova::exp(x, k, error) + ivanova::arctg(x, k, error);
    }
    catch (const std::logic_error& e)
    {
        std::cout << std::setw(MathErr) << "<MATH ERROR>";
    }
    std::cout << " " << std::setw(Cols) << ivanova::stdExp(x);
    std::cout << " " << std::setw(Cols) << ivanova::stdArctg(x);
    std::cout << " " << std::setw(Cols) << ivanova::stdExp(x) + stdArctg(x);


}