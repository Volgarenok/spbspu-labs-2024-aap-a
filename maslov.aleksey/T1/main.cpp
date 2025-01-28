#include <iostream>
#include <iomanip>
#include "shape.hpp"
#include "inputShape.hpp"
#include "base-types.hpp"
#include "shapeManipulator.hpp"
#include "composite-shape.hpp"

int main()
{
  maslov::CompositeShape compositeShapes;
  try
  {
    maslov::inputShapes(std::cin, compositeShapes);
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
  if (scaleFactor < 0)
  {
    std::cerr << "Incorrect scale factor\n";
    maslov::destroyShapes(compositeShapes);
    return 1;
  }
  maslov::point_t scaleCoordinate = {centerX, centerY};
  std::cout << std::fixed << std::setprecision(1);
  std::cout << maslov::getSumArea(compositeShapes) << " ";
  maslov::printCoordinates(std::cout, compositeShapes);
  std::cout << "\n";
  maslov::scaleShapes(compositeShapes, scaleCoordinate, scaleFactor);
  std::cout << maslov::getSumArea(compositeShapes) << " ";
  maslov::printCoordinates(std::cout, compositeShapes);
  std::cout << "\n";
  maslov::destroyShapes(compositeShapes);
}
