#include <cstddef>
#include <iostream>
#include "getShapeInfo.hpp"
#include "shape.hpp"
#include "outputRes.hpp"
#include "composite-shape.hpp"

void clearStr(char** stack, size_t stackSize)
{
  for (size_t i = 0; *(stack + i) && i < stackSize; i++) {
    delete(stack + i);
  }
}

int main()
{
  dribas::CompositeShape shapes;
  double scalingFactor[3] = {};
  try {
    shapes = dribas::getShapeInfo(std::cin, std::cerr, shapes, scalingFactor);
  } catch(const std::exception& e) {
    std::cerr << e.what() << '\n';
    return 1;
  }
  dribas::point_t scalePoint = { scalingFactor[0], scalingFactor[1] };
  try {
    dribas::outputRes(std::cout, shapes);
    std::cout << '\n';
    shapes.scaleWithCenter(scalePoint, scalingFactor[2]);
    dribas::outputRes(std::cout, shapes);
    std::cout << '\n';
  } catch (const std::invalid_argument& e) {
    std::cerr << e.what() << '\n';
    return 1;
  }
  return 0;
}
