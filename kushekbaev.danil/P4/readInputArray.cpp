#include "arrays_reading.hpp"
#include <iostream>

char* kushekbaev::readInputArray(size_t& size, size_t& max)
{
  char* str = new char[max + 1];
  size = 0;
  char stop = '\0';

  std::noskipws(std::cin);
  while ((std::cin >> stop) && (stop != '\n'))
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
    return str;
}
