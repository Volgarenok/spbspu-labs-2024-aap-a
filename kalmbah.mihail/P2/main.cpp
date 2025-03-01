#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdexcept>
#include <sstream>
#include <string>
#include "taylor_functions.h"
int main() {
  try {
    std::cout << "Enter the interval boundaries (-0.5 and 0.5:)\n";
    std::string input;
    std::getline(std::cin, input);
    std::istringstream iss(input);
    double start, end; //Инициализация start и end
    if (!(iss >> start)) { // Пробуем прочитать первое число
        std::cerr << "Incorrect interval start format\n";
        return 1;
    }
    if (!(iss >> end)) { // Пробуем прочитать второе число
        std::cerr << "incorrect interval end format\n";
        return 1;
    }
    if (iss >> start) { // Проверяем, есть ли еще одно число после второго
        std::cerr << "incorrect interval\n";
        return 1;
    }
    std::cout << std::left << std::setw(10) << "x"
              << std::setw(15) << "Arcsin(Taylor)"
              << std::setw(15) << "Arctan(Taylor)"
              << std::setw(15) << "Sum"
              << std::setw(15) << "Arcsin(cmath)"
              << std::setw(15) << "Arctan(cmath)"
              << std::setw(15) << "Sum(cmath)\n";
    const size_t maxIter = 10;
    const double epsilon = 1e-6;
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
