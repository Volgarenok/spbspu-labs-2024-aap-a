
#include "make_shape.hpp"
#include <cstdlib>
#include <cstring>
#include <cstddef>
#include "base-types.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "polygon.hpp"
#include "ellipse.hpp"
#include "shape.hpp"

namespace {
  bool hasSameVerteces(gavrilova::point_t* verteces, size_t size)
  {
    for (size_t i = 0; i < (size - 1); ++i) {
      for (size_t j = (i + 1); j < size; ++j) {
        if (verteces[i].x == verteces[j].x && verteces[i].y == verteces[j].y) {
          return true;
        }
      }
    }
    return false;
  }
}

gavrilova::Rectangle* make_rectangle(std::istream& in, size_t& nError)
{
  gavrilova::point_t point1, point2;
  if (!(in >> point1.x >> point1.y >> point2.x >> point2.y )) {
    ++nError;
    return nullptr;
  }
  gavrilova::Rectangle* rect = nullptr;
  try {
    rect = new gavrilova::Rectangle(point1, point2);
    return rect;
  } catch(const std::exception&) {
    ++nError;
    return nullptr;
  }
}

gavrilova::Triangle* make_triangle(std::istream& in, size_t& nError)
{
  gavrilova::point_t point1, point2, point3;
  if (!(in >> point1.x >> point1.y >> point2.x >> point2.y >> point3.x >> point3.y)) {
    ++nError;
    return nullptr;
  }
  gavrilova::Triangle* triang = nullptr;
  try {
    triang = new gavrilova::Triangle(point1, point2, point3);
    return triang;
  } catch(const std::exception&) {
    ++nError;
    return nullptr;
  }
}

gavrilova::Polygon* make_polygon(std::istream& in, size_t& nError)
{
  size_t capacityVert = 10, nVert = 0;
  gavrilova::point_t* verteces = new gavrilova::point_t[capacityVert];

  in >> verteces[nVert].x;
  while (in) {
    if (!(in >> verteces[nVert].y)) {
      ++nError;
      delete[] verteces;
      return nullptr;
    }
    ++nVert;
    if (nVert >= capacityVert) {
      gavrilova::point_t* new_verteces = new gavrilova::point_t[capacityVert + 10];
      for (size_t i = 0; i < nVert; ++i) {
        new_verteces[i] = verteces[i];
      }
      delete[] verteces;
      verteces = new_verteces;
      capacityVert += 10;
    }
  }
  if (!nVert || hasSameVerteces(verteces, nVert)) {
    ++nError;
    delete[] verteces;
    return nullptr;
  }

  gavrilova::Polygon* poligon = nullptr;
  try {
    poligon = new gavrilova::Polygon(nVert, verteces);
    delete[] verteces;
    return poligon;
  }catch (const std::exception&) {
    delete[] verteces;
    ++nError;
    return nullptr;
  }
}

gavrilova::Ellipse* make_ellipse(std::istream& in, size_t& nError)
{
  gavrilova::point_t center;
  double radiusX = 0, radiusY = 0;
  if (!(in >> center.x >> center.y >> radiusX >> radiusY)) {
    ++nError;
    return nullptr;
  }

  try {
    gavrilova::Ellipse* ellipse = new gavrilova::Ellipse(center, radiusX, radiusY);
    return ellipse;
  } catch (const std::exception&) {
    ++nError;
    return nullptr;
  }
}

gavrilova::Shape* gavrilova::make_shape(std::istream& in, std::string shapeType, size_t& nError)
{
  Shape* new_shape = nullptr;

  if (shapeType == "RECTANGLE") {
    new_shape = make_rectangle(in, nError);
  } else if (shapeType ==  "TRIANGLE") {
    new_shape = make_triangle(in, nError);
  } else if (shapeType ==  "POLYGON") {
    new_shape = make_polygon(in, nError);
  } else if (shapeType == "ELLIPSE") {
    new_shape = make_ellipse(in, nError);
  }
  
  return new_shape;
}
