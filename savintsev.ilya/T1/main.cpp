#include <iostream>
#include <newlineterminatedstr.h>
#include "shape.hpp"

int main()
{
  char * line = nullptr;
  bool was_error = false;
  constexpr size_t capac = 1000;
  size_t amtOfShapes = 0;
  savintsev::Shape * ShapeList[capac];
  savintsev::point_t scaleC = {0, 0};
  double scaleK = 0.0;
  int result = 0;
  while (result != 1)
  {
    delete[] line;
    line = savintsev::inputNewlineTerminatedStr(std::cin);
    if (line == nullptr)
    {
      std::cerr << "ERROR: Memory full\n";
      savintsev::destroyArray(ShapeList, amtOfShapes);
      return 2;
    }
    if (std::cin.eof())
    {
      savintsev::destroyArray(ShapeList, amtOfShapes);
      delete[] line;
      std::cerr << "ERROR: EOF is not implemented\n";
      return 2;
    }
    result = savintsev::actWithShpByDesc(line, ShapeList, amtOfShapes, scaleC, scaleK);
    if (result == 1)
    {
      if (!amtOfShapes)
      {
        delete[] line;
        std::cerr << "ERROR: No shapes\n";
        return 2;
      }
      savintsev::printSumAreaAndBorders(std::cout, ShapeList, amtOfShapes);
      savintsev::scaleAllRelativeTo(ShapeList, amtOfShapes, scaleC, scaleK);
      savintsev::printSumAreaAndBorders(std::cout, ShapeList, amtOfShapes);
      delete[] line;
      break;
    }
    if (amtOfShapes == capac)
    {
      std::cerr << "ERROR: Memory full\n";
      savintsev::destroyArray(ShapeList, amtOfShapes);
      delete[] line;
      return 2;
    }
    was_error = (result == 2) ? true : was_error;
    continue;
  }
  savintsev::destroyArray(ShapeList, amtOfShapes);
  if (was_error)
  {
    std::cerr << "WARNING: Some shapes were ignored because they were described incorrectly\n";
  }
}
