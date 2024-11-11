#include "making_new_cstring.hpp"
#include <iostream>

std::istream & petrov::inputCSring(std::istream & in, char * string)
{
  try
  {
    string = new char[1];
    size_t i = 0;
    in >> string[i];
    i++;
    while (string[i - 1] != '\n')
    {
      char * temp_string = new char[i];
      for (size_t j = 0; j < i; j++)
      {
        temp_string[j] = string[j];
      }
      delete[] string;
      string = new char[i + 1];
      for (size_t j = 0; j < i; j++)
      {
        string[j] = temp_string[j];
      }
      delete[] temp_string;
      in >> string[i];
      i++;
    }
    string[i - 1] = '\0';
    for (size_t j = 0; j < i; j++)
    {
      std::clog << string[j];
    }
    std::clog << "\n";
    return in;
  }
  catch(const std::bad_alloc & e)
  {
    throw;
  }
}