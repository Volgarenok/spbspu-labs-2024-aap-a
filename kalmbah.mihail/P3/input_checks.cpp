#include "input_checks.h"
#include <limits>

namespace kalmbah
{

bool isNumber(const std::string& str)
{
  for (char const& c : str)
  {
    if (!isdigit(c) && c != '-') return false;
  }
  return true;
}

bool isInputFileEmpty(std::ifstream& inputFile)
{
  return inputFile.peek() == std::ifstream::traits_type::eof();
}

bool isValidMatrixSize(int rows, int cols)
{
  return rows >= 0 && cols >= 0;
}

bool isValidMatrixElement(int value)
{
  return value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max();
}

}
