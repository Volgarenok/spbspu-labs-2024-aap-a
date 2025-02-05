#include <iomanip>
#include <iostream>
#include <string>
#include "actionShapes.hpp"
#include "composite-shape.hpp"
#include "makeShapes.hpp"
int main()
{
  constexpr size_t capacity = 1;
  kiselev::CompositeShape compShp(capacity);
  std::string titleShape;
  bool isIncorrectShape = false;
  kiselev::Shape* shape = nullptr;
  kiselev::point_t scale;
  double ratio = 0;
  while (std::cin >> titleShape)
  {
    if (std::cin.eof())
    {
      std::cerr << "The input ended with eof\n";
      return 1;
    }
    try
    {
      if (titleShape == "SCALE")
      {
        scale = kiselev::makeScale(std::cin);
        std::cin >> ratio;
        break;
      }
      shape = kiselev::makeShape(std::cin, titleShape);
      if (!shape)
      {
        isIncorrectShape = true;
        continue;
      }
      try
      {
        compShp.pushBack(shape);
      }
      catch (const std::bad_alloc&)
      {
        delete shape;
        std::cerr << "Out of memory";
      }
    }
    catch (const std::exception& e)
    {
      std::cerr << e.what() << "\n";
      return 1;
    }
  }
  if (isIncorrectShape)
  {
    std::cerr << "There was an error in the description of the scale\n";
  }
  if (compShp.empty())
  {
    std::cerr << "The scales were not passed\n";
    return 1;
  }
  if (ratio == 0)
  {
    std::cerr << "Not entered SCALE\n";
    return 1;
  }
  try
  {
    std::cout << std::fixed << std::setprecision(1);
    kiselev::printInfo(std::cout, compShp) << "\n";
    compShp.scale(ratio, scale);
    kiselev::printInfo(std::cout, compShp) << "\n";
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
  return 0;
}
