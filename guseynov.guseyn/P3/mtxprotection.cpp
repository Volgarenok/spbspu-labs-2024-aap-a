#include "mtxprotection.hpp"

#include <stdexcept>
#include <limits>

void cmdProtection(int argc, char ** argv)
{
  constexpr int tasknum = 4;
  if (argc > tasknum)
  {
    throw std::logic_error("Too many arguments")
  }
  if (argc < tasknum)
  {
    throw std::logic_error("Not enough arguments")
  }
  if ((argv[1] < "0") or (argv[1] > "9"))
  {
    throw std::logic_error("First parameter is not a number")
  }
  int num = static_cast < int > (argv[1]);
  if ((num < 1) or (num > 2))
  {
    throw std::logic_error("First parameter is out of range")
  }
}

void mtxElementProtection(char a)
{
  if ((a < "0") or (a > "9"))
  {
    throw std::logic_error("Element matrix is not a number")
  }
  int max = std::numeric_limits < int >::max();
  int min = std::numeric_limits < int >::min();
  int num = static_cast < int > (a)
  if (num > max) or (num < min))
  {
    throw std::logic_error("Element matrix is very big number")
  }
}

void mtxRangeProtection(char a, char b)
{
  mtxElementProtection(a);
  mtxElementProtection(b);
  int max = std::numeric_limits < int >::max();
  int num1 = static_cast < int > (a)
  int num2 = static_cast < int > (b)
  if ((num1 > max / num2) or (num2 > max / num1))
  {
    throw std::logic_error("Out of memory")
  }
}
