#include <iostream>
#include <ios>
#include "rep_sym.hpp"

int main()
{
  std::size_t len = 100;
  char *str = new char[len];
  char *new_str = nullptr;
  char *longer_str = nullptr;
  std::size_t size = 0;
  char c = '\0';
  std::noskipws(std::cin);
  while ((std::cin >> c) && (c != '\n'))
  {
    if (size == len)
    {
      len += 100;
      try
      {
        longer_str = new char[len];
      }
      catch (const std::bad_alloc &e)
      {
        std::cerr << e.what() << '\n';
        return 1;
      }
      for (std::size_t i = 0; i < len - 100; i++)
      {
        longer_str[i] = str[i];
      }
      delete[] str;
      str = longer_str;
    }
    str[size++] = c;
  }
  char *new_str = new char[len];
  new_str = sveshnikov::rep_sym(str, new_str);
  std::skipws(std::cin);
  return 0;
}
