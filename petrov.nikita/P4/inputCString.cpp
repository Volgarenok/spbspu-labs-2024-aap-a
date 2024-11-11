#include "making_new_cstring.hpp"
#include <iostream>

std::istream & petrov::inputCSring(std::istream & in, char * string, size_t & length)
{
  char * temp_string = nullptr;
  try
  {
    string = new char[1];
    size_t i = 0;
    in >> string[i];
    i++;
    length++;
    while (string[i - 1] != '\n')
    {
      temp_string = new char[i];
      for (size_t j = 0; j < i; j++)
      {
        temp_string[j] = string[j];
      }
      delete[] string;
      string = nullptr;
      string = new char[i + 1];
      for (size_t j = 0; j < i; j++)
      {
        string[j] = temp_string[j];
      }
      delete[] temp_string;
      temp_string = nullptr;
      in >> string[i];
      i++;
      length++;
    }
    string[i - 1] = '\0';
    length++;
    for (size_t j = 0; j < i; j++)
    {
      std::clog << string[j];
    }
    std::clog << "\n";
    return in;
  }
  catch(const std::bad_alloc & e)
  {
    if (temp_string == nullptr && string != nullptr)
    {
      delete[] string;
    }
    else if (string == nullptr && temp_string != nullptr)
    {
      delete[] temp_string;
    }
    throw;
  }
}