#include "func.h"
#include <stdexcept>
#include <iostream>

namespace asafov {
    void table(double left, double right, double step, size_t numberMax, double error)
    {
        for (int i = 0; i < 34; i++)
        {
            std::cout << '_';
        }
        std::cout << '\n';
        for (double i = left; i < right; i += step)
        {
            double value = 0;
            try {
                value = expNegPow2x(i, numberMax, error);
            }
            catch (const std::logic_error& e) {
                std::cout << "<MATH ERROR>";
                return;
            }
            (i < 0) ? (std::cout << std::fixed << "|") : (std::cout << std::fixed << "| ");
            std::cout << std::fixed << i << " | " << value << " | " << std::exp(-1.0 * i * i) << " | \n";
        }
        double value = 0;
        try {
            value = expNegPow2x(right, numberMax, error);
        }
        catch (const std::logic_error& e) {
            std::cout << "<MATH ERROR>";
        }
        (right < 0) ? (std::cout << std::fixed << "|") : (std::cout << std::fixed << "| ");
        std::cout << std::fixed << right << " | " << value << " | " << std::exp(-1.0 * right * right) << " | \n";
        for (int i = 0; i < 34; i++)
        {
            std::cout << '-';
        }
        std::cout << '\n';
    }
}
