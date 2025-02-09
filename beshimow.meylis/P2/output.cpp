#include <iostream>
#include <cmath>
#include <stdexcept>

double taylor(double x, double error) {
    if (error <= 0) {
        throw std::invalid_argument("Ошибка: error должен быть положительным.");
    }
    return x;
}

int main() {
    double x = 1.0;
    double error = 0.001;

    try {
        double result = taylor(x, error);
        double exact = std::exp(x);

        std::cout << "x: " << x << ", Taylor series approximation: " << result << std::endl;
        std::cout << "Exact value using standard function: " << exact << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}
