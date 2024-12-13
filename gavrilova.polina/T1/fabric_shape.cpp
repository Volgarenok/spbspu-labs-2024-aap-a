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
  Polygon* make_polygon(char * line, size_t & nSpaces, size_t & nError);
}

gavrilova::Shape * gavrilova::fabric_shape(std::istream& in, gavrilova::point_t & center, double & koef, size_t & nError) {
  size_t len = 0;
  size_t nSpaces = 0;
  char * line = inputStr(in, len, nSpaces);
  if (!line || line[0] == '\0') {
    delete[] line;
    return nullptr;
  }
  char * shapeType = strtok(line, " ");

  if (!std::strcmp(shapeType, "RECTANGLE")) {
    Shape * res = nullptr;
    try {
      res = make_rectangle(nSpaces, nError);
      return res;
    } catch (...) {
      ++nError;
      delete[] line;
      return nullptr;
    }
  } else if (!std::strcmp(shapeType, "TRIANGLE")) {
    Shape * res = nullptr;
    try {
      res = make_triangle(nSpaces, nError);
      return res;
    } catch (...) {
      ++nError;
      delete[] line;
      return nullptr;
    }
  } else if (!std::strcmp(shapeType, "POLYGON")) {
    return make_polygon(line, nSpaces, nError);
  } else if (!std::strcmp(shapeType, "SCALE")) {
    char * cXStr = strtok(nullptr, " ");
    char * cYStr = strtok(nullptr, " ");
    center.x = std::atof(cXStr);
    center.y = std::atof(cYStr);
    char * koefStr = strtok(nullptr, " ");
    koef = std::atof(koefStr);
    //std::cout << "KOEF =" << koef << "\n";
  }
  delete[] line;
  return nullptr;
}

gavrilova::Rectangle* gavrilova::make_rectangle(size_t & nSpaces, size_t & nError) {
  if (nSpaces != 4) {
    ++nError;
    return nullptr;
  }
  //point_t * verteces = nullptr;
  point_t* verteces = new point_t[2];
  /* try {

  } catch(const std::bad_alloc & e) {
    ++nError;
    delete[] line;
    return nullptr;
  } */
  verteces = make_verteces(verteces, 2);
  //delete[] line;
  //Rectangle * R = nullptr;
  if (verteces[0].x < verteces[1].x && verteces[0].y < verteces[1].y){
    Rectangle * R = new Rectangle(verteces[0], verteces[1]);
    delete[] verteces;
    return R;
  } else {
    delete[] verteces;
    return nullptr;
  }
  
  /* try {
    R = new Rectangle(verteces[0], verteces[1]);
  } catch(const std::bad_alloc & e) {
    ++nError;
    delete[] verteces;
    return nullptr;
  } */
  
}

gavrilova::Triangle* gavrilova::make_triangle(size_t & nSpaces, size_t & nError) {
  if (nSpaces != 6) {
    ++nError;
    return nullptr;
  }
  //point_t * verteces = nullptr;
  point_t* verteces = new point_t[3];
  /* try {

  } catch(const std::bad_alloc & e) {
    ++nError;
    delete[] line;
    return nullptr;
  } */
  verteces = make_verteces(verteces, 3);
  //delete[] line;
  //Rectangle * R = nullptr;
  Triangle * T = new Triangle(verteces[0], verteces[1], verteces[2]);
  /* try {
    R = new Rectangle(verteces[0], verteces[1]);
  } catch(const std::bad_alloc & e) {
    ++nError;
    delete[] verteces;
    return nullptr;
  } */
  delete[] verteces;
  return T;
}
gavrilova::Polygon* gavrilova::make_polygon(char * line, size_t & nSpaces, size_t & nError) {
  if (nSpaces < 6 || nSpaces % 2 != 0) {
    ++nError;
    delete[] line;
    return nullptr;
  }
  size_t nPoints = nSpaces / 2;
  point_t * verteces = nullptr;
  try {
    verteces = new point_t[nPoints];
  } catch (const std::bad_alloc & e) {
    ++nError;
    delete[] line;
    return nullptr;
  }
  verteces = make_verteces(verteces, nPoints);
  delete[] line;
  if (hasSameVerteces(verteces, nPoints)) {
    delete[] verteces;
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

