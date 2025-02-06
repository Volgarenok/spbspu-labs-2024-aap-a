#include "split.hpp"
#include <cstring>
#include <cstdlib>

double* maslevtsov::split(const std::string& str, std::size_t& splitted)
{
  splitted = 1;
  for (std::size_t i = 0; i < str.size(); ++i)
  {
    if (str[i] == ' ')
    {
      ++splitted;
    }
  }
  double* result = new double[splitted];
  std::size_t nextSubstrPos = 0;
  for (std::size_t i = 0; i < splitted; ++i)
  {
    result[i] = std::stod(str.substr(nextSubstrPos));
    for (std::size_t j = nextSubstrPos + 1; j < str.size() - 1; ++j)
    {
      if (str[j] == ' ')
      {
        nextSubstrPos = j;
        break;
      }
    }
  }
  return result;
}
