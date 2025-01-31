#include <iostream>
#include <iomanip>
#include "inputShape.hpp"
#include "base-types.hpp"
#include "shapeManipulator.hpp"
#include "composite-shape.hpp"

int main()
{
  using namespace maslov;
  CompositeShape compositeShape;
  try
  {
    inputShapes(std::cin, compositeShape);
  }
  catch (const std::runtime_error & e)
  {
    std::cerr << e.what() << '\n';
    return 1;
  }
  catch (const std::bad_alloc &)
  {
    std::cerr << "Memory was not allocated\n";
    return 1;
  }
  double centerX = 0.0, centerY = 0.0, scaleFactor = 0.0;
  std::cin >> centerX >> centerY >> scaleFactor;
  if (scaleFactor <= 0.0)
  {
    std::cerr << "Incorrect scale factor\n";
    destroyShapes(compositeShape);
    return 1;
  }
  point_t scaleCoordinate = {centerX, centerY};
  std::cout << std::fixed << std::setprecision(1);
  std::cout << getSumArea(compositeShape) << " ";
  printCoordinates(std::cout, compositeShape);
  std::cout << "\n";
  scaleShapes(compositeShape, scaleCoordinate, scaleFactor);
  std::cout << getSumArea(compositeShape) << " ";
  printCoordinates(std::cout, compositeShape);
  std::cout << "\n";
  destroyShapes(compositeShape);
}
