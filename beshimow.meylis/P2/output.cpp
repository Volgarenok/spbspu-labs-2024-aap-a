#include "output.hpp"
#include <iostream>
#include <iomanip>

namespace beshimow {

void print_header()
{
  std::cout << std::left << std::setw(10) << "X"
            << std::setw(20) << "Taylor Approximation"
            << std::setw(20) << "Exact Value" << std::endl;
}

void print_footer()
{
  std::cout << "End of results." << std::endl;
}

void print_line(double x, double taylor, double exact, bool error)
{
  std::cout << std::left << std::setw(10) << x
            << std::setw(20) << (error ? "<MATH ERROR>" : std::to_string(taylor))
            << std::setw(20) << std::to_string(exact) << std::endl;
}

}
