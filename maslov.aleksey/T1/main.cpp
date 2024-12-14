#include "shape.hpp"
#include "inputShape.hpp"
#include "base-types.hpp"
#include "shapeManipulator.hpp"
#include <iostream>
#include <iomanip>

int main()
{
  constexpr int maxShapes = 10000;
  maslov::Shape * shapes[maxShapes] = {};
  size_t count = 0;
  try
  {
    count = maslov::inputShape(std::cin, shapes);
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    return 1;
  }
  double centerX = 0.0, centerY = 0.0, scaleFactor = 0.0;
  if (!(std::cin >> centerX >> centerY >> scaleFactor))
  {
    throw std::invalid_argument("Incorrect parameters");
    return 1;
  }
  maslov::point_t scaleCoor = {centerX, centerY};
  std::cout << std::fixed << std::setprecision(1) << getSumArea(shapes, count);
  printCoor(shapes, count);
  std::cout << "\n";
  scaleShapes(shapes, count, scaleCoor, scaleFactor);
  std::cout << getSumArea(shapes, count);
  printCoor(shapes, count);
  std::cout << "\n";
}
