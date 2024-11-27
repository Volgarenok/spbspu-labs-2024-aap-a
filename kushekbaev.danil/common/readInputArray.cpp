#include <iostream>
#include <istream>
#include "read_input_array.hpp"

char* kushekbaev::readInputArray(std::istream& input, char stop, size_t& size, size_t& max)
{
  char* str = nullptr;
  try
  {
    char* str = new char[max + 1];
    size = 0;

    std::noskipws(std::cin);
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
    std::skipws(std::cin);
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Error allocating memory";
    delete[] str;
    return 1;
  }
  return str;
}
