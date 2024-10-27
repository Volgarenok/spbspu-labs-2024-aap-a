#include <iostream>
#include <iomanip>
#include <cmath>
#include "Tylor.h"
int main() {
    double absError=0.001;
    int numberMax;
    double start, end, step=0.05;
    std::cin >> start >> end >> numberMax;
    if (!std::cin) {
        std::cerr << ("Bad input") << "\n";
        return 1;
    }
    if (step <= 0) {
        std::cerr << "Step must be positive." << "\n";
        return 2;
    }
    if (end<start) {
        std::cerr << ("Logic error") << "\n";
        return 3;
    }
    std::cout << std::fixed << std::setprecision(6);
    std::cout << std::string(10, ' ') << "X\tSUMM\tSTDfunction\n";
    for (double x = start; x <= end; x += step) {
        try {
            double calculatedValue = lungu::TylorFunc(x, absError, numberMax);
            double standardValue = std::exp(-x * x); 
            std::cout << std::string(10, ' ') << x << "\t" << calculatedValue << "\t" << standardValue << "\n";
        } 
        catch (const std::exception& e) {
            std::cout << std::string(10, ' ') << x << "\tMathError" << "\n";
        }
    }
    return 0;
}
