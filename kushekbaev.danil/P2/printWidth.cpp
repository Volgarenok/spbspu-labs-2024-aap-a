#include "sinh_taylor_calculator.hpp"
#include <iomanip>

void kushekbaev::printWidth(std::ostream &os, size_t width, double value)
{
  os << std::setw(width) << value;
}
