#include "making_new_cstring.hpp"
#include <iostream>
#include <exception>

char * petrov::inputCSring(char * string, size_t & length)
{
  char * temp_string = nullptr;
  string = nullptr;
  try
  {
    string = new char[1];
    string[0] = '0';
    size_t i = 0;
    std::cin >> string[i];
    if (string[i] == '\n' || std::cin.eof())
    {
      return string;
      delete[] string;
    }
    i++;
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
      std::cin >> string[i];
      i++;
      if (std::cin.eof())
      {
        return string;
        delete[] string;
      }
    }
    string[i - 1] = '\0';
    length = i - 1;
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
  delete[] temp_string;
  return string;
  delete[] string;
}
