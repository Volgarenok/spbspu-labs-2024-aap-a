#include <iostream>
#include "io_utils.hpp"
#include "shape_utils.hpp"

int main()
{
  constexpr size_t shapesCapacity = 10'000;
  kizhin::Shape* shapes[shapesCapacity];
  size_t shapesSize = 0;
  double* scaleParams = nullptr;
  try {
    scaleParams = kizhin::processInput(std::cin, std::cerr, shapesSize, shapes);
    kizhin::outputShapesInfo(std::cout, shapes, shapesSize) << '\n';
    kizhin::scaleShapes(shapes, shapesSize, scaleParams);
    kizhin::outputShapesInfo(std::cout, shapes, shapesSize) << '\n';
  } catch (const std::exception& e) {
    delete[] scaleParams;
    kizhin::deleteShapes(shapes, shapesSize);
    std::cerr << "Error: " << e.what() << '\n';
    return 1;
  }
  delete[] scaleParams;
  kizhin::deleteShapes(shapes, shapesSize);
}

