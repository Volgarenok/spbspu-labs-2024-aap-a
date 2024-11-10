#include "string.hpp"

char * mozhegova::inputString(std::istream & in, char stop)
{
  size_t length = 10;
  char * str = nullptr;
  try
  {
    str = new char [length];
  }
  catch(const std::bad_alloc & e)
  {
    throw;
  }
  char next = '\0';
  std::noskipws(std::cin);
  for (size_t size = 0; (std::cin >> next) && (next != '\n'); size++)
  {
    if (size == length)
    {

    }
    str[size] = next;
  }
  std::skipws(std::cin);
  return str;
}