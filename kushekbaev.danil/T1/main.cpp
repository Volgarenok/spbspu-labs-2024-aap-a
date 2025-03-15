#include <string>
#include <iostream>
#include "shapeCreation.hpp"
#include "shapeManipulations.hpp"
#include "shape.hpp"
#include "composite-shape.hpp"

int main()
{
  kushekbaev::point_t scalePoint{ 0, 0 };
  double scaleCoeff = 0;
  bool invalid_argument = false;
  kushekbaev::CompositeShape compShape(100);
  std::string shapeName;
  while ((std::cin >> shapeName && shapeName != "SCALE") && !std::cin.eof())
  {
    try
    {
      kushekbaev::createShape(std::cin, compShape, shapeName);
    }

    catch (const std::logic_error&)
    {
      std::cin.clear();
      invalid_argument = true;
    }

    catch (const std::bad_alloc&)
    {
      std::cerr << "Bad alloc\n";
      return 1;
    }
  }

  std::cin >> scalePoint.x >> scalePoint.y >> scaleCoeff;

  if (scaleCoeff <= 0)
  {
    std::cerr << "There was no SCALE command\n";
    return 1;
  }

  if (compShape.size() == 0)
  {
    std::cerr << "Shapeless input\n";
    return 1;
  }

  if (invalid_argument)
  {
    std::cerr << "Some shapes were inputed incorrectly\n";
  }

  kushekbaev::output(std::cout, compShape, scalePoint, scaleCoeff);
}
