#include "fabric_shape.hpp"
#include <cstdlib>
#include <inputStr.hpp>
#include <cstring>
#include "base-types.hpp"
#include "rectangle.hpp"
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
    double parametrsDouble[4] = {};
    for (int i = 0; i < 4;++i){
      parametrsDouble[i] = std::atof(parametrsStr[i]);
    }
    Rectangle * R = new Rectangle({parametrsDouble[0], parametrsDouble[1]}, {parametrsDouble[2], parametrsDouble[3]});
    return R; 
  }
  return nullptr;
  
}