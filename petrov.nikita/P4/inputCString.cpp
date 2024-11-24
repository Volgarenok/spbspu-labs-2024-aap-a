#include "making_new_cstring.hpp"
#include <iostream>
#include <exception>

char * petrov::inputCString(char * string, size_t & capacity)
{
  char * temp_string = nullptr;
  try
  {
    string = new char[2];
    std::cin >> string[0];
    if (string[0] == '\n' || std::cin.eof())
    {
      return string;
    }
    string[1] = '\0';
    size_t i = 2;
    while (string[i - 2] != '\n')
    {
      temp_string = new char[i];
      size_t j = 0;
      while (string[j] != '\0')
      {
        temp_string[j] = string[j];
        j++;
      }
      temp_string[j] = '\0';
      delete[] string;
      string = nullptr;
      i++;
      string = new char[i];
      j = 0;
      while (temp_string[j] != '\0')
      {
        string[j] = temp_string[j];
        j++;
      }
      delete[] temp_string;
      temp_string = nullptr;
      std::cin >> string[i - 2];
      string[i - 1] = '\0';
      if ((i - 1) > capacity)
      {
        capacity++;
      }
      if (std::cin.eof())
      {
        std::cout << "\n";
        return string;
      }
    }
    string[i - 2] = '\0';
    delete[] temp_string;
    return string;
  }
  catch(const std::bad_alloc & e)
  {
    if (temp_string == nullptr && string != nullptr)
    {
      delete[] string;
      string = nullptr;
    }
    else if (string == nullptr && temp_string != nullptr)
    {
      delete[] temp_string;
    }
    throw;
  }
}
