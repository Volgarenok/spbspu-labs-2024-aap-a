#include "string.h"
#include <iostream>
#include <cstddef>

char* ivanova::getLine(std::istream& in)
{
  size_t size = 10;
  char* string = new char[size++];
  char sym = '\0';
  size_t max = 0;
  char* nstring = nullptr;
  in >> std::noskipws;
  while((in >> sym) && (sym != '\n'))
  {
    if (max == size - 1)
    {
      size += 10;
      string[size] = '\0';
      try
      {
        nstring = ivanova::moreSpace(string, size);
      }
      catch(const std::bad_alloc& e)
      {
        delete[] string;
        throw;
      }
      delete[] string;
      string = nstring;
    }
    string[size++] = sym;
  }
  std::skipws(in);
  string[size] = '\0';
  return string;
}

char* ivanova::moreSpace(const char* string, size_t newSize)
{
  char* nstring = new char[newSize];
  for (size_t i = 0; string[i] != '\0'; ++i)
  {
    nstring[i] = string[i];
  }
  return nstring;
}
