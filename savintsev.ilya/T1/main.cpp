#include <iostream>
#include <cstring>
#include <iomanip>
#include <newlineterminatedstr.h>
#include <lrgcpy.hpp>
#include "base-types.hpp"
#include "rectangle.hpp"

//CONCAVE COMPLEXQUAD
namespace savintsev
{
  int actWithShpByDesc(char * desc, Shape ** rhs, size_t & amt, point_t & p, double & k);
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

int savintsev::actWithShpByDesc(char * desc, Shape ** rhs, size_t & amt, point_t & p, double & k)
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
    double numbers[3] = {0., 0., 0.};
    readDblfromDesc(numbers, 3);
    p = {numbers[0], numbers[1]};
    k = numbers[2];
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
  savintsev::point_t scaleC = {0, 0};
  double scaleK = 0.;
  while (true)
  {
    delete[] line;
    line = savintsev::inputNewlineTerminatedStr(std::cin);
    if (line == nullptr || std::cin.eof())
    {
      std::cerr << "ERROR: Memory full OR EOF\n";
      return 2;
    }
    if (line[0] == '\0')
    {
      continue;
    }
    int result = savintsev::actWithShpByDesc(line, ShapeList, amtOfShapes, scaleC, scaleK);
    if (result == 1)
    {
      if (scaleK > 0)
      {
        std::setprecision(2);
        savintsev::printSumAreaAndBorders(std::cout, ShapeList, amtOfShapes);
        savintsev::scaleAllRelativeTo(ShapeList, amtOfShapes, scaleC, scaleK);
        savintsev::printSumAreaAndBorders(std::cout, ShapeList, amtOfShapes);
      }
      else
      {
        continue;
      }
      delete[] line;
      savintsev::destroyShapes(ShapeList, amtOfShapes);
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
        savintsev::destroyShapes(ShapeList, amtOfShapes);
        ShapeList = newList;
        capac += capac;
      }
      catch (const std::bad_alloc & e)
      {
        delete[] line;
        savintsev::destroyShapes(ShapeList, amtOfShapes);
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
