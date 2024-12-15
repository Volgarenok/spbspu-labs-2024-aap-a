#include <cstddef>
#include <iostream>
#include "getShapeInfo.hpp"
#include "shape.hpp"

void clearStr(char** stack, size_t stackSize){
  for (size_t i = 0; *(stack+i) && i <stackSize; i++) {
    free(*(stack + i));
    }
     }
int main()
{
  constexpr size_t shapesSize = 10000;
  dribas::Shape * myShapes[shapesSize] = {};
  size_t shapeCount = 0;
  shapeCount = dribas::getShapeInfo(std::cin, std::cerr, myShapes);
  dribas::clear(myShapes, shapeCount - 1);
  return 0;
}
