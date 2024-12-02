#include <iostream>
#include <cstring>
#include <newlineterminatedstr.h>
#include <lrgcpy.hpp>
#include "base-types.hpp"
#include "rectangle.hpp"

//CONCAVE COMPLEXQUAD
namespace savintsev
{
  int actWithShpByDesc(char * desc, Shape ** rhs, size_t & amt);
}

namespace
{
  void readDblfromDesc(double * numbers, size_t amt);

  void readDblfromDesc(double * numbers, size_t amt)
  {
    char * token = nullptr;
    for (size_t i = 0; i < amt; ++i)
    {
      token = std::strtok(nullptr, " ");
      if (!token)
      {
        break;
      }
      numbers[i] = std::atof(token);
    }
  }
}

int savintsev::actWithShpByDesc(char * desc, Shape ** rhs, size_t & amt)
{
  char * token = std::strtok(desc, " ");
  if (!std::strcmp(token, "RECTANGLE"))
  {
    double numbers[4] = {0., 0., 0., 0.};
    readDblfromDesc(numbers, 4);
    try
    {
      Rectangle * Rect = new Rectangle({numbers[0], numbers[1]}, {numbers[2], numbers[3]});
      rhs[amt++] = Rect;
    }
    catch (const std::invalid_argument & e)
    {
      return 2;
    }
    return 0;
  }
  if (!std::strcmp(token, "SCALE"))
  {
    return 1;
  }
  return -1;
}

int main()
{
  char * line = nullptr;
  bool was_error = false;
  size_t capac = 10;
  size_t amtOfShapes = 0;
  savintsev::Shape ** ShapeList = nullptr;
  ShapeList = new savintsev::Shape * [capac];
  while (!std::cin.eof())
  {
    delete[] line;
    line = savintsev::inputNewlineTerminatedStr(std::cin);
    if (line == nullptr)
    {
      std::cerr << "ERROR: Memory full\n";
      return 2;
    }
    if (line[0] == '\0')
    {
      continue;
    }
    int result = savintsev::actWithShpByDesc(line, ShapeList, amtOfShapes);
    if (result == 1)
    {
      delete[] line;
      delete[] ShapeList;
      break;
    }
    if (result == -1)
    {
      continue;
    }
    if (result == 2)
    {
      was_error = true;
      continue;
    }
    if (amtOfShapes == capac)
    {
      try
      {
        savintsev::Shape ** newList = savintsev::createAmpCpyAny(ShapeList, capac, capac + capac);
        delete[] ShapeList;
        ShapeList = newList;
        capac += capac;
      }
      catch (const std::bad_alloc & e)
      {
        delete[] line;
        delete[] ShapeList;
        std::cerr << "ERROR: Memory full\n";
        return 3;
      }
    }
  }
  if (was_error)
  {
    std::cerr << "WARNING: Some shapes were ignored because they were described incorrectly\n";
  }
}
