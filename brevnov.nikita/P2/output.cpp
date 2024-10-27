#include "brevnov.hpp"

void brevnov::outputing(const double left, const double right, const size_t k)
{
    const double error = 0.001;
    const double step = 0.05;
    const char * errorsum = "<MATH ERROR>";
    const size_t second_width = std::strlen(errorsum);
    const size_t usually_width = 10;
    const size_t usu = usually_width;
    const size_t snd = second_width;
    for (auto i = left; i < right; i += step)
    {
        std::cout << std::fixed << std::setw(usu) << i;
        std::cout << " ";
        try
        {
            std::cout << std::fixed << std::setw(snd) << brevnov::f(i,k,error);
        }
        catch (std::logic_error & e)
        {
            std::cout << std::setw(snd) << "<MATH ERROR>";
        }
        std::cout << " " << std::fixed << std::setw(usu) << atan(i);
        std::cout<< "\n";
    }
    std::cout << std::fixed << std::setw(usu) << right;
    try
    {
        std::cout << " " << std::fixed << std::setw(snd) << brevnov::f(right, k, error);
    }
    catch (std::logic_error & e)
    {
        std::cout << std::setw(snd) << "<MATH ERROR>";
    }
    std::cout << " " << std::fixed << std::setw(usu) <<atan(right);
    std::cout << "\n";
}
