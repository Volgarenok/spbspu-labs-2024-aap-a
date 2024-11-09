#include <iostream>
#include <ios>
#include "latinRemove.h"

int main()
{
  std::size_t maxSize = 2;
  char* str = nullptr;
  try
  {
    str = new char[maxSize + 1]{};
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "ERROR: Out of memory!\n";
    delete[] str;
    return 1;
  }

  std::size_t size = 0;
  char c = '\0';
  std::noskipws(std::cin);
  while ((std::cin >> c) && (c != '\n'))
  {
    if (!std::cin)
    {
      std::cerr << "ERROR: Input was incorrect!\n";
      delete[] str;
      return 1;
    }
    if (size == maxSize)
    {
      constexpr const int coef = 2;
      maxSize += coef;
      char* newStr = nullptr;
      try
      {
        newStr = new char[maxSize + 1]{};
      }
      catch (const std::bad_alloc& e)
      {
        std::cerr << "ERROR: Out of memory!\n";
        delete[] newStr;
        delete[] str;
        return 1;
      }
      for (size_t i = 0; i < maxSize; ++i)
      {
        newStr[i] = str[i];
      }
      delete[] str;
      str = newStr;
    }
    str[size++] = c;
  }
  std::skipws(std::cin);
  std::cout << aleksandrov::latinRemove(str, size) << "\n";
  delete[] str;
}

