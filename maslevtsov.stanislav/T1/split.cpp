#include "split.hpp"
#include <cstring>
#include <cstdlib>

double* maslevtsov::split(char* str, std::size_t& splitted)
{
  double* result = new double[10'000];
  str = std::strtok(str, " ");
  std::size_t argumentIndex = 0;

  while (str != nullptr)
  {
    result[argumentIndex++] = std::atof(str);
    ++splitted;
    str = std::strtok(nullptr, " ");
  }

  return result;
}
