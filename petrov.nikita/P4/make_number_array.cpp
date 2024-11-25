#include "making_new_cstring.hpp"
#include <cstddef>
#include <exception>

char * petrov::makeNumberArray(const char * string_2, size_t & capacity)
{
  capacity += sizeof(string_2) / sizeof(char);
  char * numbers = nullptr;
  numbers = new char[capacity + 1];
  size_t i = 0;
  size_t j = 0;
  while (string_2[j] != '\0')
  {
    if (std::isdigit(string_2[j]))
    {
      numbers[i] = string_2[j];
      i++;
    }
    j++;
  }
  numbers[i] = '\0';
  return numbers;
}
