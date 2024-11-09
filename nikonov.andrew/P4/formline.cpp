#include <formline.hpp>
#include <cstddef>
#include <cctype>
#include <iostream>
#include <exception>
size_t cntDigit(char* str)
{
  char elem = ' ';
  size_t cnt = 0;
  size_t iter = 0;
  while (std::cin >> elem && elem != '\0')
  {
    if (std::isdigit(str[iter]))
    {
      ++cnt;
    }
    ++iter;
  }
  if (!std::cin)
  {
    throw std::logic_error("Error: not a value");
  }
  return cnt;
}
void add_digit_symb(char* firstStr, char* secondStr)
{
  size_t iter1 = 0;
  while (secondStr[iter1] != '\0')
  {
    ++iter1;
  }
  size_t iter2 = 0;
  while (secondStr[iter2] != '\0')
  {
    if (std::isdigit(secondStr[iter2]))
    {
      firstStr[iter1] = secondStr[iter2];
      ++iter1;
    }
    ++iter2;
  }
}