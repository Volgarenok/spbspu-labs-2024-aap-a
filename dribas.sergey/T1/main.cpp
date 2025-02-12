#include <cstddef>
#include <iostream>
#include "getShapeInfo.hpp"
#include "shape.hpp"
#include "outputRes.hpp"

void clearStr(char** stack, size_t stackSize)
{
  for (size_t i = 0; *(stack+i) && i < stackSize; i++) {
    delete (stack + i);
  }
}

int main()
{
  constexpr size_t shapesSize = 10000;
  dribas::Shape * shapes[shapesSize] = {};
  double scalingFactor[3] = {};
  int shapeCount = 0;
  shapeCount = dribas::getShapeInfo(std::cin, std::cerr, shapes, scalingFactor);
  if (shapeCount == -1) {
    return 1;
  }
  dribas::point_t scalePoint = {scalingFactor[0], scalingFactor[1]};

  dribas::outputRes(std::cout, shapes, shapeCount);
  dribas::scalingAll(shapes, shapeCount, scalePoint, scalingFactor[2]);
  dribas::outputRes(std::cout, shapes, shapeCount);
  dribas::clear(shapes, shapeCount);
  return 0;
}
