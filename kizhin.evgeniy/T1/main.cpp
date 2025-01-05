#include <iostream>
#include "io_utils.hpp"
#include "shape_utils.hpp"

int main()
{
  kizhin::CompositeShape shapes;
  double* scaleParams = nullptr;
  try {
    scaleParams = kizhin::processInput(std::cin, std::cerr, shapes);
    kizhin::outputShapesInfo(std::cout, shapes) << '\n';
    kizhin::scaleShapes(shapes, scaleParams);
    kizhin::outputShapesInfo(std::cout, shapes) << '\n';
  } catch (const std::exception& e) {
    delete[] scaleParams;
    std::cerr << "Error: " << e.what() << '\n';
    return 1;
  }
  delete[] scaleParams;
}

