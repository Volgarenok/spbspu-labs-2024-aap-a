#include "header.h"

namespace asafov {
    void table(double left, double right, double step, std::size_t numberMax, double error) {
        for (int i = 0; i < 34; i++) {
            std::cout << '_';
        }
        std::cout << '\n';
        for (double i = left; i < right; i += step) {
            double value = 0;
            try {
                value = f(i, numberMax, error);
            }
            catch (const std::logic_error& e) {
                std::cout << "<MATH ERROR>";
                return;
            }
            if (i >= 0) {
                std::cout << std::fixed << "| " << i << " | " << value << " | " << exp(-1.0 * i * i) << " | \n";
            }
            else {
                std::cout << std::fixed << "|" << i << " | " << value << " | " << exp(-1.0 * i * i) << " | \n";
            }
        }
        double value = 0;
        try {
            value = f(right, numberMax, error);
        }
        catch (const std::logic_error& e) {
            std::cout << "<MATH ERROR>";
        }
        if (right > 0) {
            std::cout << std::fixed << "| " << right << " | " << value << " | " << exp(-1.0 * right * right) << " | \n";
        }
        else {
            std::cout << std::fixed << "|" << right << " | " << value << " | " << exp(-1.0 * right * right) << " | \n";
        }
        for (int i = 0; i < 34; i++) {
            std::cout << '-';
        }
        std::cout << '\n';
    }
}
