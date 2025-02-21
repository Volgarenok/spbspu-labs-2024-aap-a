#include <iostream>
#include "io_utils.hpp"
#include "shape_utils.hpp"

int main()
{
  using namespace kizhin;
  CompositeShape shapes;
  double* scaleParams = nullptr;
  try {
    scaleParams = processInput(std::cin, std::cerr, shapes);
    outputShapesInfo(std::cout, shapes) << '\n';
    scaleShapes(shapes, scaleParams);
    outputShapesInfo(std::cout, shapes) << '\n';
  } catch (const std::exception& e) {
    delete[] scaleParams;
    std::cerr << "Error: " << e.what() << '\n';
    return 1;
  }
  delete[] scaleParams;
}

