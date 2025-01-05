#include "fabric_shape.hpp"
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cstddef>
#include <inputStr.hpp>
#include "base-types.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "polygon.hpp"
#include "ellipse.hpp"
#include "shape.hpp"

namespace {
  bool hasSameVerteces(gavrilova::point_t * verteces, size_t size) {
    for (size_t i = 0; i < (size - 1); ++i) {
      for (size_t j = (i + 1); j < size; ++j) {
        if (verteces[i].x == verteces[j].x && verteces[i].y == verteces[j].y) {
          return true;
        }
      }
    }
    return false;
  }
  void make_verteces(gavrilova::point_t * verteces, size_t n) {
    for (size_t i = 0; i < n; ++i) {
      char * xStr = strtok(nullptr, " ");
      char * yStr = strtok(nullptr, " ");
      double x = std::atof(xStr);
      double y = std::atof(yStr);
      verteces[i] = {x, y};
    }
  }
  gavrilova::Rectangle* make_rectangle(char * line, size_t & nSpaces, size_t & nError) {
    if (nSpaces != 4) {
      ++nError;
      return nullptr;
    }

    gavrilova::point_t arr[2] = {};
    gavrilova::point_t * verteces = arr;
    make_verteces(verteces, 2);

    gavrilova::Rectangle * rect = nullptr;
    try {
      rect = new gavrilova::Rectangle(verteces[0], verteces[1]);
      return rect;
    } catch(const std::exception & e) {
      ++nError;
      return nullptr;
    }
  }
  gavrilova::Triangle* make_triangle(char * line, size_t & nSpaces, size_t & nError) {
    if (nSpaces != 6) {
      delete[] line;
      ++nError;
      return nullptr;
    }
    
    gavrilova::point_t arr[3] = {};
    gavrilova::point_t * verteces = arr;
    make_verteces(verteces, 3);
    delete[] line;
    gavrilova::Triangle * triang = nullptr;
    try {
      triang = new gavrilova::Triangle(verteces[0], verteces[1], verteces[2]);
      return triang;
    } catch(const std::exception & e) {
      ++nError;
      return nullptr;
    }
  }
  gavrilova::Polygon* make_polygon(char * line, size_t & nSpaces, size_t & nError) {
    if (nSpaces < 6 || nSpaces % 2 != 0) {
      ++nError;
      delete[] line;
      return nullptr;
    }
    size_t nPoints = nSpaces / 2;
    gavrilova::point_t * verteces = nullptr;
    try {
      verteces = new gavrilova::point_t[nPoints];
    } catch (const std::bad_alloc & e) {
      ++nError;
      delete[] line;
      return nullptr;
    }
    make_verteces(verteces, nPoints);
    delete[] line;
    if (hasSameVerteces(verteces, nPoints)) {
      delete[] verteces;
      ++nError;
      return nullptr;
    }
    gavrilova::Polygon * poligon = nullptr;
    try {
      poligon = new gavrilova::Polygon(nPoints, verteces);
      return poligon;
    } catch (const std::exception & e) {
      delete[] verteces;
      ++nError;
      return nullptr;
    }
  }
  gavrilova::Ellipse* make_ellipse(char* line, size_t & nSpaces, size_t & nError) {
    if (nSpaces != 4) {
        ++nError;
        delete[] line;
        return nullptr;
    }

    char* cXStr = strtok(nullptr, " ");
    char* cYStr = strtok(nullptr, " ");
    char* rXStr = strtok(nullptr, " ");
    char* rYStr = strtok(nullptr, " ");

    if (!cXStr || !cYStr || !rXStr || !rYStr) {
        ++nError;
        delete[] line;
        return nullptr;
    }

    double x = std::atof(cXStr);
    double y = std::atof(cYStr);
    double radiusX = std::atof(rXStr);
    double radiusY = std::atof(rYStr);

    try {
        gavrilova::Ellipse* ellipse = new gavrilova::Ellipse({x, y}, radiusX, radiusY);
        delete[] line;
        return ellipse;
    } catch (const std::exception & e) {
        ++nError;
        delete[] line;
        return nullptr;
    }
  }
}


gavrilova::Shape * gavrilova::make_shape(std::istream& in, gavrilova::point_t & center, double & koef, size_t & nError) {
  size_t len = 0;
  size_t nSpaces = 0;
  char * line = inputStr(in, len, nSpaces);
  if (!line || line[0] == '\0') {
    delete[] line;
    return nullptr;
  }
  char * shapeType = strtok(line, " ");
  
  if (!std::strcmp(shapeType, "RECTANGLE")) {
    Shape * new_shape = make_rectangle(line, nSpaces, nError);
  } else if (!std::strcmp(shapeType, "TRIANGLE")) {
    Shape * res = make_triangle(line, nSpaces, nError);
  } else if (!std::strcmp(shapeType, "POLYGON")) {
    Shape * res = make_polygon(line, nSpaces, nError);
  } else if (!std::strcmp(shapeType, "ELLIPSE")) {
    Shape* res = make_ellipse(line, nSpaces, nError);
  } else if (!std::strcmp(shapeType, "SCALE")) {
    char * cXStr = strtok(nullptr, " ");
    char * cYStr = strtok(nullptr, " ");
    center.x = std::atof(cXStr);
    center.y = std::atof(cYStr);
    char * koefStr = strtok(nullptr, " ");
    koef = std::atof(koefStr);
  }
  delete[] line;
  return nullptr;
}


