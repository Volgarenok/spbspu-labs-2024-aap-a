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
  constexpr size_t maxShapes = 10000;
  aleksandrov::Shape* shapes[maxShapes] = {};
  constexpr size_t maxParams = 4;
  double params[maxParams];
  bool wasDescriptionError = false;
  try
  {
    size_t count = aleksandrov::getShapes(std::cin, shapes, params, maxParams, wasDescriptionError);
    double x = 0.0;
    double y = 0.0;
    double k = 0.0;
    std::cin >> x >> y >> k;
    if (!std::cin || k <= 0)
    {
      throw std::logic_error("Incorrect input!");
    }

    std::cout << std::fixed << std::setprecision(1);
    std::cout << aleksandrov::getAreaSum(shapes, count) << " ";
    aleksandrov::printFrameRectCoords(std::cout, shapes, count);
    std::cout << "\n";

    aleksandrov::scaleShapes(shapes, count, x, y, k);

    std::cout << aleksandrov::getAreaSum(shapes, count) << " ";
    aleksandrov::printFrameRectCoords(std::cout, shapes, count);
    std::cout << "\n";
  }
  catch (const std::bad_alloc&)
  {
    std::cerr << "ERROR: Out of memory!\n";
    aleksandrov::deleteShapes(shapes);
    return 1;
  }
  catch (const std::logic_error& e)
  {
    std::cerr << "ERROR: " << e.what() << "\n";
    aleksandrov::deleteShapes(shapes);
    return 1;
  }
  if (wasDescriptionError)
  {
    std::cerr << "WARNING: Some supporting shapes had a description error!\n";
  }
  aleksandrov::deleteShapes(shapes);
}

