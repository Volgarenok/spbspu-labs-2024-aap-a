#include <iostream>
#include <ios>
#include "latinRemove.h"

int main()
{
  std::size_t max = 2;
  constexpr const int coef = 2;
  char* str = new char[max + 1];

  std::size_t size = 0;
  char c = '\0';
  std::noskipws(std::cin);

  while ((std::cin >> c) && (c != '\n'))
  {
    if (size == max)
    {
      max += coef;
      char* newStr = new char[max + 1];
      for (size_t i = 0; i < max; ++i)
      {
        newStr[i] = str[i];
      }
      delete[] str;
      str = newStr;
    }
    str[size++] = c;
  }
  std::skipws(std::cin);
  std::cout << latinRemove(str, size) << "\n";
}

