#include <string>
#include <iostream>
#include "shapeBreeding.hpp"
#include "shapeCreation.hpp"
#include "shapeManipulations.hpp"
#include "shape.hpp"
#include "composite-shape.hpp"

int main()
{
  using namespace kushekbaev;
  point_t scalePoint{0, 0};
  double scaleCoeff = 0;
  bool invalid_argument = false;
  CompositeShape compShape(100);
  std::string shapeName;
  while (std::cin >> shapeName && !std::cin.eof())
  {
    try
    {
      createShape(std::cin, compShape, scalePoint, scaleCoeff, shapeName);
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

  if (compShape.size() == 0)
  {
    std::cerr << "Shapeless input\n";
    return 1;
  }

  if (scaleCoeff <= 0)
  {
    std::cerr << "There was no SCALE command\n";
    return 1;
  }

  if (invalid_argument)
  {
    std::cerr << "Some shapes were inputed incorrectly\n";
  }

  output(std::cout, compShape, scalePoint, scaleCoeff);
}
