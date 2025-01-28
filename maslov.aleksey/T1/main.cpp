#include <iostream>
#include <iomanip>
#include "inputShape.hpp"
#include "base-types.hpp"
#include "shapeManipulator.hpp"
#include "composite-shape.hpp"

int main()
{
  maslov::CompositeShape compositeShape;
  try
  {
    maslov::inputShapes(std::cin, compositeShape);
  }
  catch (const std::runtime_error & e)
  {
    std::cerr << e.what() << '\n';
    return 1;
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << "Memory was not allocated\n";
    return 1;
  }
  double centerX = 0.0, centerY = 0.0, scaleFactor = 0.0;
  std::cin >> centerX >> centerY >> scaleFactor;
  if (scaleFactor <= 0.0)
  {
    std::cerr << "Incorrect scale factor\n";
    maslov::destroyShapes(compositeShape);
    return 1;
  }
  maslov::point_t scaleCoordinate = {centerX, centerY};
  std::cout << std::fixed << std::setprecision(1);
  std::cout << maslov::getSumArea(compositeShape) << " ";
  maslov::printCoordinates(std::cout, compositeShape);
  std::cout << "\n";
  maslov::scaleShapes(compositeShape, scaleCoordinate, scaleFactor);
  std::cout << maslov::getSumArea(compositeShape) << " ";
  maslov::printCoordinates(std::cout, compositeShape);
  std::cout << "\n";
  maslov::destroyShapes(compositeShape);
}
