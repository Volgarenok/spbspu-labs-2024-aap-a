#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdexcept>
#include "compute_hyperbol_functions.h"

int main()
{
  try
  {
    std::cout << "Enter the interval boundaries (-0.5 and 0.5) and max number of sum value:\n";
    double start = 0.0, end = 0.0;
    size_t maxNumberOfIter = 0;
    std::cin >> start >> end >> maxNumberOfIter;
    if (!std::cin)
    {
      std::cerr << "<INPUT_ERROR>" << "\n";
      return 1;
    }

    const size_t maxIter = 10;
    const double minGranInterval = -0.5;
    const double maxGranInterval = 0.5;
    if (start < minGranInterval || end > maxGranInterval || maxNumberOfIter > maxIter)
    {
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
    const double step = 0.1;
    for (double x = start; x <= end; x += step )
    {
      double arcsinCmath = std::asin(x);
      double arctanCmath = std::atan(x);
      double sumCmath = arcsinCmath + arctanCmath;
      try
      {
        double arcsinTaylor = kalmbah::computeArcsinTaylor(x, maxNumberOfIter, epsilon);
        try
        {
          double arctanTaylor = kalmbah::computeArctanTaylor(x, maxNumberOfIter, epsilon);
          double sumTaylor = arcsinTaylor + arctanTaylor;
          std::cout << std::fixed << std::setprecision(6)
                    << std::left << std::setw(15) << x
                    << std::setw(15) << arcsinTaylor
                    << std::setw(15) << arctanTaylor
                    << std::setw(15) << sumTaylor
                    << std::setw(15) << arcsinCmath
                    << std::setw(15) << arctanCmath
                    << std::setw(15) << sumCmath << "\n";
        }
        catch (const std::runtime_error& e)
        {
          std::cout << std::fixed << std::setprecision(6)
                    << std::left << std::setw(15) << x
                    << std::setw(15) << arcsinTaylor
                    << std::setw(15) << e.what()
                    << std::setw(15) << e.what()
                    << std::setw(15) << arcsinCmath
                    << std::setw(15) << arctanCmath
                    << std::setw(15) << sumCmath << "\n";
        }
      }
      catch (const std::runtime_error& e)
      {
        try
        {
          double arctanTaylor = kalmbah::computeArctanTaylor(x, maxNumberOfIter, epsilon);
          std::cout << std::fixed << std::setprecision(6)
                    << std::left << std::setw(15) << x
                    << std::setw(15) << e.what()
                    << std::setw(15) << arctanTaylor
                    << std::setw(15) << e.what()
                    << std::setw(15) << arcsinCmath
                    << std::setw(15) << arctanCmath
                    << std::setw(15) << sumCmath << "\n";
        }
        catch (const std::runtime_error& e)
        {
          std::cout << std::fixed << std::setprecision(6)
                    << std::left << std::setw(15) << x
                    << std::setw(15) << e.what()
                    << std::setw(15) << e.what()
                    << std::setw(15) << e.what()
                    << std::setw(15) << arcsinCmath
                    << std::setw(15) << arctanCmath
                    << std::setw(15) << sumCmath << "\n";
        }
      }
    }
    return 0;
  }
  catch (const std::exception &prog)
  {
    std::cerr << "Error: " << prog.what() << "\n";
    return 2;
  }
}
