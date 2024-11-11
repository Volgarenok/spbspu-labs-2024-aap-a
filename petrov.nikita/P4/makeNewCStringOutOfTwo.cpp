#include "making_new_cstring.hpp"
#include <cctype>

void petrov::makeNewCStringOutOfTwo(char * new_cstring, const char * string_1, const char * string_2, const size_t length_1, const size_t length_2)
{
  size_t number_of_numbers = 0;
  for (size_t i = 0; i < length_2; i++)
  {
    if (std::isdigit(string_2[i]))
    {
      number_of_numbers++;
    }
  }
  char * numbers = nullptr;
  try
  {
    numbers = new char[number_of_numbers];
    size_t i = 0;
    for (size_t j = 0; j < length_2; j++)
    {
      if (std::isdigit(string_2[i]))
      {
        numbers[i] = string_2[j];
        i++;
      }
    }
    i = 0;
    new_cstring = new char[length_1 + number_of_numbers + 1];
    for (size_t j = 0; j < length_1; j++)
    {
      new_cstring[i] = string_1[j];
      i++;
    }
    for (size_t j = 0; j < number_of_numbers; j++)
    {
      new_cstring[i] = numbers[j];
      i++;
    }
    new_cstring[i - 1] = '\0'; 
  }
  catch(const std::bad_alloc & e)
  {
    if (new_cstring == nullptr)
    {
      delete[] numbers;
    }
    throw;
  }
}

