#include <cmath>
#include <iostream>

#include "printing_utils.hpp"
#include "taylor_cosh.hpp"

int main()
{
  double intervalStart = 0;
  double intervalEnd = 0;
  size_t maxOperands = 0;

  if (!(std::cin >> intervalStart && std::cin >> intervalEnd)) {
    std::cerr << "Invalid input.\n";
    return 1;
  }
  if (intervalStart >= intervalEnd) {
    std::cerr << "Invalid interval.\n";
    return 1;
  }
  if (!(std::cin >> maxOperands) || maxOperands == 0) {
    std::cerr << "Invalid input.\n";
    return 1;
  }
  constexpr size_t stepCount = 10;
  const double stepSize = (intervalEnd - intervalStart) / (stepCount - 1);
  const double absoluteError = stepSize / 10.0;

  for (size_t i = 0; i < stepCount; ++i) {
    const double argument = intervalStart + i * stepSize;
    const double expectedValue = std::cosh(argument);
    double computedValue = 0.0;
    const char* errorMessage = nullptr;

    try {
      computedValue = kizhin::computeTaylorCosh(argument, maxOperands, absoluteError);
    } catch (const std::logic_error&) {
      errorMessage = "<MATH ERROR>";
    }
    if (errorMessage) {
      kizhin::printRow(std::cout, argument, errorMessage, expectedValue);
    } else {
      kizhin::printRow(std::cout, argument, computedValue, expectedValue);
    }
  }
}
