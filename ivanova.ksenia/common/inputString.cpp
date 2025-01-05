#include "inputString.hpp"
#include <iostream>
#include <cstddef>

char* ivanova::getLine(std::istream& in)
{
  size_t size = 10;
  size_t max = 0;
  char* string = new char[size + 1];
  char sym = '\0';
  char* nstring = nullptr;

  in >> std::noskipws;

  while((in >> sym) && (sym != '\n'))
  {
    if (max == size - 1)
    {
      string[max] = '\0';
      size += 10;
      try
      {
        nstring = ivanova::moreSpace(string, size);
        delete[] string;
        string = nstring;
      }
      catch(const std::bad_alloc& e)
      {
        delete[] string;
        throw;
      }
    }
    string[max++] = sym;
  }

  string[max] = '\0';
  return string;
}

char* ivanova::moreSpace(const char* string, size_t newSize)
{
  char* nstring = new char[newSize + 1];
  for (size_t i = 0; i < newSize; ++i)
  {
    if (string[i] == '\0') break;
    nstring[i] = string[i];
  }
  nstring[newSize] = '\0';
  return nstring;
}
