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
    count = maslov::inputShapes(std::cin, shapes);
  }
  catch(const std::runtime_error & e)
  {
    std::cerr << e.what() << '\n';
    return 1;
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Memory was not allocated\n";
    return 1;
  }
  double centerX = 0.0, centerY = 0.0, scaleFactor = 0.0;
  std::cin >> centerX >> centerY >> scaleFactor;
  if (scaleFactor < 0)
  {
    std::cerr << "Incorrect scale factor\n";
    maslov::destroyShapes(shapes, count);
    return 1;
  }
  maslov::point_t scaleCoordinate = {centerX, centerY};

  std::cout << std::fixed << std::setprecision(1);
  std::cout << maslov::getSumArea(shapes, count);
  maslov::printCoordinates(shapes, count);
  std::cout << "\n";
  maslov::scaleShapes(shapes, count, scaleCoordinate, scaleFactor);
  std::cout << getSumArea(shapes, count);
  maslov::printCoordinates(shapes, count);
  std::cout << "\n";
  maslov::destroyShapes(shapes, count);
}
