#include <iostream>
#include <iomanip>
#include "make_Shapes.hpp"
#include "Shapes-utils.hpp"
#include "composite-shape.hpp"
#include "base-types.hpp"

int main()
{
  using namespace guseynov;
  CompositeShape compositeShape;
  try
  {
    inputShapes(std::cin, compositeShape);
  }
  catch (const std::exception & e)
  {
    std::cerr << e.what() << "\n";
    destroyShapes(compositeShape);
    return 1;
  }
  double centerX = 0.0, centerY = 0.0, scaleFactor = 0.0;
  std::cin >> centerX >> centerY >> scaleFactor;
  point_t scaleCoordinate = {centerX, centerY};
  std::cout << std::fixed << std::setprecision(1);
  printData(std::cout, compositeShape);
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
  printData(std::cout, compositeShape);
  std::cout << "\n";
  destroyShapes(compositeShape);
}
