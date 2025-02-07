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

gavrilova::Rectangle* make_rectangle(std::istream& in)
{
  gavrilova::point_t point1, point2;
  if (!(in >> point1.x >> point1.y >> point2.x >> point2.y )) {
    throw std::logic_error("Errors in rectangle input");
  }
  gavrilova::Rectangle* rect = new gavrilova::Rectangle(point1, point2);
  return rect;
}

gavrilova::Triangle* make_triangle(std::istream& in)
{
  gavrilova::point_t point1;
  gavrilova::point_t point2;
  gavrilova::point_t point3;
  if (!(in >> point1.x >> point1.y >> point2.x >> point2.y >> point3.x >> point3.y)) {
    throw std::logic_error("Errors in triangle input");
  }
  gavrilova::Triangle* triang = new gavrilova::Triangle(point1, point2, point3);
  return triang;
}

gavrilova::Polygon* make_polygon(std::istream& in)
{
  size_t capacityVert = 10;
  size_t nVert = 0;
  gavrilova::point_t* verteces = new gavrilova::point_t[capacityVert];

  in >> verteces[nVert].x;
  while (in) {
    if (!(in >> verteces[nVert].y)) {
      delete[] verteces;
      throw std::logic_error("Errors in ellipse input");
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
    delete[] verteces;
    throw std::logic_error("Errors in polygon input");
  }

  gavrilova::Polygon* poligon = nullptr;
  try {
    poligon = new gavrilova::Polygon(nVert, verteces);
    delete[] verteces;
    return poligon;
  }catch (const std::bad_alloc&) {
    delete[] verteces;
    throw;
  }
}

gavrilova::Ellipse* make_ellipse(std::istream& in)
{
  gavrilova::point_t center;
  double radiusX = 0;
  double radiusY = 0;
  if (!(in >> center.x >> center.y >> radiusX >> radiusY)) {
    throw std::logic_error("Errors in ellipse input");
  }
  gavrilova::Ellipse* ellipse = new gavrilova::Ellipse(center, radiusX, radiusY);
  return ellipse;
}

gavrilova::Shape* gavrilova::make_shape(std::istream& in, std::string shapeType)
{
  Shape* new_shape = nullptr;

  if (shapeType == "RECTANGLE") {
    new_shape = make_rectangle(in);
  } else if (shapeType ==  "TRIANGLE") {
    new_shape = make_triangle(in);
  } else if (shapeType ==  "POLYGON") {
    new_shape = make_polygon(in);
  } else if (shapeType == "ELLIPSE") {
    new_shape = make_ellipse(in);
  } else {
    throw std::logic_error("Error! Unknown figure entered")
  }
}
