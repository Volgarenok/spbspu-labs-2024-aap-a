#include "making_new_cstring.hpp"
#include <cstddef>
#include <cctype>
#include <exception>

char * petrov::makeNewCStringOutOfTwo(char * new_cstring, const char * string_1, const char * string_2, const size_t capacity)
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
    i = 0;
    j = 0;
    new_cstring = new char[capacity + number_of_numbers];
    while (string_1[j] != '\0')
    {
      new_cstring[i] = string_1[j];
      i++;
      j++;
    }
    j = 0;
    while (numbers[j] != '\0')
    {
      new_cstring[i] = numbers[j];
      i++;
      j++;
    }
    new_cstring[i] = '\0';
    delete[] numbers;
    return new_cstring;
  }
  catch(const std::bad_alloc & e)
  {
    if (numbers != nullptr)
    {
      delete[] numbers;
    }
    throw;
  }
}
