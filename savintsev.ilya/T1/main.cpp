#include <iostream>
#include <cstring>
#include <iomanip>
#include <newlineterminatedstr.h>
#include "base-types.hpp"
#include "rectangle.hpp"

//CONCAVE COMPLEXQUAD
namespace savintsev
{
  bool readDescription(double * numbers, size_t amt, const char * sep, bool &erw, bool &ern);
}

bool savintsev::readDescription(double * numbers, size_t amt, const char * sep, bool &erw, bool &ern)
{
  char * pEnd = nullptr;
  char * token = nullptr;
  for (size_t i = 0; i < amt; ++i)
  {
    token = std::strtok(nullptr, sep);
    if (!token)
    {
      ern = true;
      erw = true;
      break;
    }
    numbers[i] = std::strtod(token, &pEnd);
    if (*pEnd != '\0')
    {
      ern = true;
      erw = true;
      break;
    }
  }
  if (std::strtok(nullptr, sep) || ern)
  {
    return false;
  }
  return true;
}

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
      delete[] line;
      continue;
    }
    
    token = std::strtok(line, separator);
    is_error_now = false;
    if (!std::strcmp(token, "RECTANGLE"))
    {
      double numbers[4] = {0., 0., 0., 0.};
      if (!savintsev::readDescription(numbers, 4, separator, is_error_was, is_error_now))
      {
        delete[] line;
        continue;
      }
      std::cout << "class\n";
      savintsev::point_t p1 = {numbers[0], numbers[1]};
      savintsev::point_t p2 = {numbers[2], numbers[3]};
      p1.x = p2.x;
      p2.x = p1.x;
      savintsev::Rectangle debil(p1, p2);
      delete[] line;
      continue;
    }
    if (!std::strcmp(token, "CONCAVE"))
    {
      double numbers[8] = {0., 0., 0., 0., 0., 0., 0., 0.};
      if (!savintsev::readDescription(numbers, 8, separator, is_error_was, is_error_now))
      {
        delete[] line;
        continue;
      }
      std::cout << "KRUTAKk!111\n";
      delete[] line;
      continue;
    }
    if (!std::strcmp(token, "COMPLEXQUAD"))
    {
      double numbers[8] = {0., 0., 0., 0., 0., 0., 0., 0.};
      if (!savintsev::readDescription(numbers, 8, separator, is_error_was, is_error_now))
      {
        delete[] line;
        continue;
      }
      std::cout << "SO COOL!!!1111!\n";
      delete[] line;
      continue;
    }
    if (!std::strcmp(token, "SCALE"))
    {
      delete[] line;
      break;
    }
    else
    {
      delete[] line;
      continue;
    }
  }
  if (is_error_was)
  {
    std::cerr << "BILA EROR\n";
  }
}
