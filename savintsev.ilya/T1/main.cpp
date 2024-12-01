#include <iostream>
#include <cstring>
#include <iomanip>
#include <newlineterminatedstr.h>
#include "base-types.hpp"
#include "rectangle.hpp"

int main()
{
  char * line = nullptr;
  const char * separator = " ";
  char * token = nullptr;
  bool is_error_was = false;
  bool is_error_now = false;
  while (!std::cin.eof())
  {
    line = savintsev::inputNewlineTerminatedStr(std::cin);
    if (line == nullptr)
    {
      std::cerr << "Failed to allocate memory or EOF\n";
      return 1;
    }
    if (line[0] == '\0')
    {
      //std::cerr << "One of the lines is empty\n";
      delete[] line;
      continue;
    }
    char * pEnd = nullptr;
    token = std::strtok(line, separator);
    is_error_now = false;
    if (!std::strcmp(token, "RECTANGLE"))
    {
      double numbers[4] = {0., 0., 0., 0.};
      for (size_t i = 0; i < 4; ++i)
      {
        token = std::strtok(nullptr, separator);
        if (!token)
        {
          is_error_now = true;
          is_error_was = true;
          break;
        }
        numbers[i] = std::strtod(token, &pEnd);
        if (*pEnd != '\0')
        {
          is_error_now = true;
          is_error_was = true;
          break;
        }
      }
      if (std::strtok(nullptr, separator) || is_error_now)
      {
        delete[] line;
        continue;
      }
      std::cout << "ZAEBOK\n";
      point_t p1 = {numbers[0], numbers[1]};
      point_t p2 = {numbers[2], numbers[3]};
      p1.x = p2.x;
      p2.x = p1.x;
      delete[] line;
      continue;
    }
    else
    {
      delete[] line;
      continue;
    }
  }
  if (is_error_was)
  {
    std::cout << "BILA EROR\n";
  }
}
