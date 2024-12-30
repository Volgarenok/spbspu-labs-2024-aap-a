#include <iostream>
#include "io_utils.hpp"
#include "shape_utils.hpp"

int main()
{
  constexpr size_t shapesCapacity = 10'000;
  kizhin::Shape* shapes[shapesCapacity]{};
  double* scaleParams = nullptr;
  try {
    scaleParams = kizhin::processInput(std::cin, std::cerr, shapes);
    kizhin::outputShapesInfo(std::cout, shapes) << '\n';
    kizhin::scaleShapes(shapes, scaleParams);
    kizhin::outputShapesInfo(std::cout, shapes) << '\n';
  } catch (const std::exception& e) {
    delete[] scaleParams;
    kizhin::deleteShapes(shapes);
    std::cerr << "Error: " << e.what() << '\n';
    return 1;
  }
  delete[] scaleParams;
  kizhin::deleteShapes(shapes);
}
