#include <iostream>
#include <iomanip>
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "ellipse.hpp"
#include "circle.hpp"
#include "shapeManip.h"

int main()
{
  constexpr const size_t maxShapes = 10000;
  aleksandrov::Shape* shapes[maxShapes] = {};
  bool wasDescriptionError = false;
  size_t count = 0;
  try
  {
    count = aleksandrov::getShapes(std::cin, shapes, wasDescriptionError);
    double x = 0.0;
    double y = 0.0;
    double k = 0.0;
    aleksandrov::getScaleParams(std::cin, x, y, k);

    std::cout << std::fixed << std::setprecision(1);
    std::cout << aleksandrov::getAreaSum(shapes, count) << " ";
    aleksandrov::printFrameRectCoords(std::cout, shapes, count);
    std::cout << "\n";

    aleksandrov::scaleShapes(shapes, count, x, y, k);

    std::cout << aleksandrov::getAreaSum(shapes, count) << " ";
    aleksandrov::printFrameRectCoords(std::cout, shapes, count);
    std::cout << "\n";
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "ERROR: Out of memory!\n";
    aleksandrov::deleteShapes(shapes, count);
    return 1;
  }
  catch (const std::logic_error& e)
  {
    std::cerr << "ERROR: " << e.what() << "\n";
  }
  if (wasDescriptionError)
  {
    std::cout << "WARNING: Some supporting shapes had a description error!\n";
  }
  aleksandrov::deleteShapes(shapes, count);
}

