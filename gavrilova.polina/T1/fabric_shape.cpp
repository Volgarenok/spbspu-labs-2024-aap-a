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
#include <cstddef>
namespace {
  bool hasSameVerteces(gavrilova::point_t * verteces, size_t size) {
    for (size_t i = 0; i < size; ++i) {
      for (size_t j = 0; j < size; ++j) {
        if (verteces[i].x == verteces[j].x && verteces[i].y == verteces[j].y && i != j) {
          //std::cout << verteces[i].x << " " << verteces[j].x << " " << verteces[i].y << " " << verteces[j].y << "\n";
          return true;
        }
      }
    }
    return false;
  }
  gavrilova::point_t * make_verteces(gavrilova::point_t * verteces, size_t n) {
  for (size_t i = 0; i < n; ++i) {
    char * xStr = strtok(nullptr, " ");
    char * yStr = strtok(nullptr, " ");
    double x = std::atof(xStr);
    double y = std::atof(yStr);
    verteces[i] = {x, y};
  }
  return verteces;
}

}
namespace gavrilova
{
  Rectangle* make_rectangle(size_t & nSpaces, size_t & nError);
  Triangle* make_triangle(size_t & nSpaces, size_t & nError);
  Polygon* make_polygon(size_t & nSpaces, size_t & nError);
}

gavrilova::Shape * gavrilova::fabric_shape(std::istream& in, gavrilova::point_t & center, double & koef, size_t & nError) {
  size_t len = 0;
  size_t nSpaces = 0;
  char * line = inputStr(in, len, nSpaces);
  if (!line || line[0] == '\0') {
    return nullptr;
  }
  char * shapeType = strtok(line, " ");

  if (!std::strcmp(shapeType, "RECTANGLE")) {
    return make_rectangle(nSpaces, nError);
  } else if (!std::strcmp(shapeType, "TRIANGLE")) {
    return make_triangle(nSpaces, nError);
  } else if (!std::strcmp(shapeType, "POLYGON")) {
    return make_polygon(nSpaces, nError);
  } else if (!std::strcmp(shapeType, "SCALE")) {
    point_t * cntr = nullptr;
    try {
      cntr = new point_t;
    } catch(const std::bad_alloc & e) {
      return nullptr;
    }
    cntr = make_verteces(cntr, 1);
    center = *cntr;
    char * koefStr = strtok(nullptr, " ");
    
    koef = std::atof(koefStr);
    std::cout << "KOEF =" << koef << "\n";
  }
  return nullptr;
}

gavrilova::Rectangle* gavrilova::make_rectangle(size_t & nSpaces, size_t & nError) {
  if (nSpaces != 4) {
    ++nError;
    return nullptr;
  }
  point_t * verteces = nullptr;
  point_t arr[2] = {};
  verteces = arr;
  verteces = make_verteces(verteces, 2);
  Rectangle * R = nullptr;
  try {
    R = new Rectangle({verteces[0], verteces[1]});
  } catch(const std::bad_alloc & e) {
    ++nError;
    return nullptr;
  }
  return R;
}

gavrilova::Triangle* gavrilova::make_triangle(size_t & nSpaces, size_t & nError) {
  if (nSpaces != 6) {
    ++nError;
    return nullptr;
  }
  point_t * verteces = nullptr;
  point_t arr[3] = {};
  verteces = arr;
  verteces = make_verteces(verteces, 3);
  Triangle * T = nullptr;
  try {
    T = new Triangle(verteces[0], verteces[1], verteces[2]);
  } catch(const std::bad_alloc & e) {
    ++nError;
    return nullptr;
  }
  return T;
}
gavrilova::Polygon* gavrilova::make_polygon(size_t & nSpaces, size_t & nError) {
  if (nSpaces < 6 || nSpaces % 2 != 0) {
    ++nError;
    return nullptr;
  }
  size_t nPoints = nSpaces / 2;
  point_t * verteces = nullptr;
  try {
    verteces = new point_t[nPoints];
  } catch (const std::bad_alloc & e) {
    ++nError;
    return nullptr;
  }
  verteces = make_verteces(verteces, nPoints);
  if (hasSameVerteces(verteces, nPoints)) {
    ++nError;
    return nullptr;
  }
  Polygon * P = nullptr;
  try {
    P = new Polygon(nPoints, verteces);
  } catch (const std::bad_alloc & e) {
    delete[] verteces;
    ++nError;
    return nullptr;
  }
  return P;
}

