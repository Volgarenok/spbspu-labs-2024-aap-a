#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdexcept>
#include "taylor_functions.h"
int main() {
  try {
    double start = 0;
    double end = 0;
    size_t maxIter = 10;
    double epsilon = 1e-6;
    std::cout << "Enter the interval boundaries (-0.5 and 0.5:)\n";
    std::cin >> start >> end;
    if (!(std::cin >> start) || !(std::cin >> end || start >= end || start < -0.5 || end > 0.5)) {
      std::cerr << "Invalid interval!\n";
      return 1;
    }
    std::cout << std::left << std::setw(10) << "x"
              << std::setw(15) << "Arcsin(Taylor)"
              << std::setw(15) << "Arctan(Taylor)"
              << std::setw(15) << "Sum"
              << std::setw(15) << "Arcsin(cmath)"
              << std::setw(15) << "Arctan(cmath)"
              << std::setw(15) << "Sum(cmath)\n";
    for (double x = start; x <= end; x += 0.1) {
      double arcsinT = arcsinTaylor(x, maxIter, epsilon);
      double arctanT = arctanTaylor(x, maxIter, epsilon);
      double arcsinC = std::asin(x);
      double arctanC = std::atan(x);
      double sumT = arcsinT + arctanT;
      double sumC = arcsinC + arctanC;
      std::cout << std::fixed << std::setprecision(6) << std::left << std::setw(10) << x
                << std::setw(15) << arcsinT
                << std::setw(15) << arctanT
                << std::setw(15) << sumT
                << std::setw(15) << arcsinC
                << std::setw(15) << arctanC
                << std::setw(15) << sumC << "\n";
    }
    return 0;
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << "\n";
    return 1;
  }
}
