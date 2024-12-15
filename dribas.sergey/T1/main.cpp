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
  std::cout << dribas::getShapeInfo(std::cin, std::cerr, myShapes);
  return 0;


}



