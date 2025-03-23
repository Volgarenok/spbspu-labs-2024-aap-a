#include <cstddef>
#include <iostream>
#include "composite-shape.hpp"
#include "getShapeInfo.hpp"
#include "outputRes.hpp"
#include "shape.hpp"

int main()
{
  dribas::CompositeShape shapes;
  double scalingFactor[3] = {};
  try {
    shapes = dribas::getShapeInfo(std::cin, std::cerr, scalingFactor);
  } catch (const std::exception& e) {
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
