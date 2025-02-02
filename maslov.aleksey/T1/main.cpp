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
  catch (const std::bad_alloc &)
  {
    std::cerr << "Memory was not allocated\n";
    destroyShapes(compositeShape);
    return 1;
  }
  double centerX = 0.0, centerY = 0.0, scaleFactor = 0.0;
  std::cin >> centerX >> centerY >> scaleFactor;
  point_t scaleCoordinate = {centerX, centerY};
  std::cout << std::fixed << std::setprecision(1);
  std::cout << getSumArea(compositeShape) << " ";
  printCoordinates(std::cout, compositeShape);
  std::cout << "\n";
  try
  {
    scaleShapes(compositeShape, scaleCoordinate, scaleFactor);
  }
  catch (const std::invalid_argument & e)
  {
    std::cerr << e.what() << '\n';
    destroyShapes(compositeShape);
    return 1;
  }
  std::cout << getSumArea(compositeShape) << " ";
  printCoordinates(std::cout, compositeShape);
  std::cout << "\n";
  destroyShapes(compositeShape);
}
