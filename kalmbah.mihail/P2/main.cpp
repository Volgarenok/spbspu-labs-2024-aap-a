#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdexcept>
#include <sstream>
#include <string>
#include "taylor_functions.h"
int main()
{
  try {
    std::cout << "Enter the interval boundaries (-0.5 and 0.5) and max number of sum value:\n";
    std::string input;
    std::getline(std::cin, input);
    std::istringstream iss(input);
    double start, end;
    size_t maxNumber_of_iter;
    if (!(iss >> start) || !(iss >> end) || !(iss >> maxNumber_of_iter)) {
      std::cerr << "Incorrect value format\n";
      return 1;
    }
    if (iss >> start) {
      std::cerr << "A lot of value\n";
      return 1;
    }
    const size_t maxIter = 10;
    const double minGranInterval = -0.5;
    const double maxGranInterval = 0.5;
    if (start < minGranInterval || end > maxGranInterval || maxNumber_of_iter > maxIter) {
      std::cerr << "Going beyond the allowed interval";
      return 1;
    }
    std::cout << std::left << std::setw(15) << "x"
              << std::setw(15) << "Arcsin(Taylor)"
              << std::setw(15) << "Arctan(Taylor)"
              << std::setw(15) << "Sum"
              << std::setw(15) << "Arcsin(cmath)"
              << std::setw(15) << "Arctan(cmath)"
              << std::setw(15) << "Sum(cmath)\n";
    const double epsilon = 1e-6;
    for (double x = start; x <= end; x += 0.1) {
      double arcsinC = std::asin(x);
      double arctanC = std::atan(x);
      double sumC = arcsinC + arctanC;
      try {
        double arcsinT = kalmbah::arcsinTaylor(x, maxNumber_of_iter, epsilon);
        try {
          double arctanT = kalmbah::arctanTaylor(x, maxNumber_of_iter, epsilon);
          double sumT = arcsinT + arctanT;
          std::cout << std::fixed << std::setprecision(6)
                    << std::left << std::setw(15) << x
                    << std::setw(15) << arcsinT
                    << std::setw(15) << arctanT
                    << std::setw(15) << sumT
                    << std::setw(15) << arcsinC
                    << std::setw(15) << arctanC
                    << std::setw(15) << sumC << "\n";
        } catch (const std::runtime_error& e) {
          std::cout << std::fixed << std::setprecision(6)
                    << std::left << std::setw(15) << x
                    << std::setw(15) << arcsinT
                    << std::setw(15) << e.what()
                    << std::setw(15) << e.what()
                    << std::setw(15) << arcsinC
                    << std::setw(15) << arctanC
                    << std::setw(15) << sumC << "\n";
        }
      } catch (const std::runtime_error& e) {
        try {
          double arctanT = kalmbah::arctanTaylor(x, maxNumber_of_iter, epsilon);
          std::cout << std::fixed << std::setprecision(6)
                    << std::left << std::setw(15) << x
                    << std::setw(15) << e.what()
                    << std::setw(15) << arctanT
                    << std::setw(15) << e.what()
                    << std::setw(15) << arcsinC
                    << std::setw(15) << arctanC
                    << std::setw(15) << sumC << "\n";
        } catch (const std::runtime_error& e) {
          std::cout << std::fixed << std::setprecision(6)
                    << std::left << std::setw(15) << x
                    << std::setw(15) << e.what()
                    << std::setw(15) << e.what()
                    << std::setw(15) << e.what()
                    << std::setw(15) << arcsinC
                    << std::setw(15) << arctanC
                    << std::setw(15) << sumC << "\n";
        }
      }
    }
    return 0;
  } catch (const std::exception &t) {
    std::cerr << "Error: " << t.what() << "\n";
    return 1;
  }
}
