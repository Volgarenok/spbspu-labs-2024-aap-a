#include "fabric_shape.hpp"
#include <cstdlib>
#include "inputStr.hpp"
#include <cstring>
#include "base-types.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "polygon.hpp"
#include "shape.hpp"
#include <iostream>
//
namespace {
  bool hasSameVerteces(gavrilova::point_t * verteces, size_t size) {
    for (size_t i = 0; i < size; ++i) {
      for (size_t j = 0; j < size; ++j) {
        if (verteces[i].x == verteces[j].x && verteces[i].y == verteces[j].y && i != j) {
          std::cout << verteces[i].x << " " << verteces[j].x << " " << verteces[i].y << " " << verteces[j].y << "\n";
          return true;
        }
      }
    }
    return false;
  }
}
gavrilova::Shape * gavrilova::fabric_shape(std::istream& in, gavrilova::point_t & center, double koef, size_t nError) {
  ++koef;
  size_t len = 0;
  size_t nSpaces = 0;
  char * line = inputStr(in, len, nSpaces);
  char * shapeType = strtok(line, " ");
  if (!std::strcmp(shapeType, "RECTANGLE")) {
    if (nSpaces != 4) {
      throw std::logic_error("Invalid number of arguments for rectangle");
      ++nError;
      return nullptr;
    }
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
    if (nSpaces != 6) {
      throw std::logic_error("Invalid number of arguments for triangle");
      ++nError;
      return nullptr;
    }
    char * parametrsStr[6] = {};
    double parametrsDbl[6] = {};
    for (int i = 0; i < 6; ++i) {
      parametrsStr[i] = strtok(nullptr, " ");
      parametrsDbl[i] = std::atof(parametrsStr[i]);
    }
    point_t a{parametrsDbl[0], parametrsDbl[1]}, b{parametrsDbl[2], parametrsDbl[3]}, c{parametrsDbl[4], parametrsDbl[5]};
    Triangle * T = new Triangle(a, b, c);
    return T;
  } else if (!std::strcmp(shapeType, "POLYGON")) {
    if (nSpaces < 6 || nSpaces % 2 != 0) {
      throw std::logic_error("Invalid number of arguments for polygon");
      ++nError;
      return nullptr;
    }
    size_t nPoints = nSpaces / 2;
    double * parametrsDbl = nullptr;
    char ** parametrsStr = nullptr;
    point_t * verteces = nullptr;
    try {
      parametrsDbl = new double[nPoints * 2];
      parametrsStr = new char *[nPoints * 2];
      verteces = new point_t[nPoints];
    } catch (...) {
      delete[] parametrsDbl;
      delete[] parametrsStr;
      delete[] verteces;
      throw;
    }
    for (size_t i = 0; i < nPoints; ++i) {
      parametrsStr[i*2] = strtok(nullptr, " ");
      parametrsDbl[i*2] = std::atof(parametrsStr[i*2]);
      parametrsStr[i*2+1] = strtok(nullptr, " ");
      parametrsDbl[i*2+1] = std::atof(parametrsStr[i*2+1]);
      verteces[i] = {parametrsDbl[i*2], parametrsDbl[i*2+1]};
      std::cout << verteces[i].x << " " << verteces[i].y << "\n";
    }
    delete[] parametrsDbl;
    delete[] parametrsStr;
    if (!hasSameVerteces(verteces, nPoints)) {
      try {
        Polygon * P = new Polygon(nPoints, verteces);
        return P;
      } catch (...) {
        delete[] verteces;
        throw;
      }
    } else {
      delete[] verteces;
      ++nError;
      throw std::logic_error("There are the same points");
    }

  } else if (!std::strcmp(shapeType, "SCALE"))  {
    char * cXStr = strtok(nullptr, " ");
    char * cYStr = strtok(nullptr, " ");
    char * koefStr = strtok(nullptr, " ");
    center.x = std::atof(cXStr);
    center.y = std::atof(cYStr);
    koef = std::atof(koefStr);
  }
  return nullptr;
  
}