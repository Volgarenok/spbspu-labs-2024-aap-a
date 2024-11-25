#include "making_new_cstring.hpp"
#include <cstddef>
#include <exception>

char * petrov::makeNumberArray(const char * string_2, size_t & capacity)
{
  size_t number_of_numbers = 0;
  size_t i = 0;
  while (string_2[i] != '\0')
  {
    if (std::isdigit(string_2[i]))
    {
      number_of_numbers++;
    }
    i++;
  }
  capacity += number_of_numbers;
  char * numbers = nullptr;
  try
  {
    numbers = new char[number_of_numbers + 1];
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
  }
  catch (const std::bad_alloc & e)
  {
    throw;
  }
  return numbers;
}