#include "read_input_array.hpp"
#include <iostream>

char* kushekbaev::readInputArray(std::istream& input, char stop)
{
  size_t max = 10;
  char* str = nullptr;
  try
  {
    str = new char[max + 1];
    size = 0;
    input >> std::noskipws;
    while ((input >> stop) && (stop != '\n'))
    {
      if (size == max)
      {
        max *= 10;
        char* new_str = new char[max + 1];
        for (size_t i = 0; i < size; i++)
        {
          new_str[i] = str[i];
        }
        delete[] str;
        str = new_str;
      }
      str[size++] = stop;
    }
    str[size] = '\0';
    input >> std::skipws;
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Error allocating memory";
    input >> std::skipws;
    delete[] str;
    str = nullptr;
  }
  return str;
}
