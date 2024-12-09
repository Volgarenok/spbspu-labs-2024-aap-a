#include "fabric_shape.hpp"
#include <cstdlib>
#include <inputStr.hpp>
#include <cstring>
#include "base-types.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "shape.hpp"
//, point_t & center, double koef

gavrilova::Shape * gavrilova::fabric_shape(std::istream& in) {
  size_t len = 0;
  char * line = inputStr(in, len);
  char * shapeType = strtok(line, " ");
  if (!std::strcmp(shapeType, "RECTANGLE")) {
    char * pBottomLeftX = strtok(nullptr, " ");
    char * pBottomLeftY = strtok(nullptr, " ");
    char * pTopRightX = strtok(nullptr, " ");
    char * pTopRightY = strtok(nullptr, " ");
    char * parametrsStr[4] = {pBottomLeftX, pBottomLeftY, pTopRightX, pTopRightY};
    double parametrsDbl[4] = {};
    for (int i = 0; i < 4;++i){
      parametrsDbl[i] = std::atof(parametrsStr[i]);
    }
    Rectangle * R = new Rectangle({parametrsDbl[0], parametrsDbl[1]}, {parametrsDbl[2], parametrsDbl[3]});
    return R; 
  } else if (!std::strcmp(shapeType, "TRIANGLE")) {
    char * parametrsStr[6] = {};
    int i = 0;
    while (shapeType != nullptr && i < 6) {
      parametrsStr[i++] = strtok(nullptr, " ");
    }
    double parametrsDbl[6] = {};
    for (int i = 0; i < 6;++i){
      parametrsDbl[i] = std::atof(parametrsStr[i]);
    }
    point_t a{parametrsDbl[0], parametrsDbl[1]}, b{parametrsDbl[2], parametrsDbl[3]}, c{parametrsDbl[4], parametrsDbl[5]};
    Triangle * T = new Triangle(a, b, c);
    return T;
  }
  return nullptr;
  
}