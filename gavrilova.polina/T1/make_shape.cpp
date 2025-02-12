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


gavrilova::Rectangle* make_rectangle(std::istream& in)
{
  gavrilova::point_t arr[2] = {};
  gavrilova::point_t* points = arr;
  if (!(gavrilova::input_points(in, points, 2))) {
    throw std::logic_error("Errors in rectangle input");
  }
  gavrilova::Rectangle* rect = new gavrilova::Rectangle(points[0], points[1]);
  return rect;
}

gavrilova::Triangle* make_triangle(std::istream& in)
{
  gavrilova::point_t arr[3] = {};
  gavrilova::point_t* points = arr;
  if (!(gavrilova::input_points(in, points, 3))) {
    throw std::logic_error("Errors in triangle input");
  }
  gavrilova::Triangle* triang = new gavrilova::Triangle(points[0], points[1], points[2]);
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
      throw std::logic_error("Errors in polygon input");
    }
    ++nVert;
    if (nVert >= capacityVert) {
      gavrilova::point_t* new_verteces = nullptr;
      try {
        new_verteces = new gavrilova::point_t[capacityVert + 10];
      } catch(const std::bad_alloc&) {
        delete[] verteces;
        throw;
      }
      for (size_t i = 0; i < nVert; ++i) {
        new_verteces[i] = verteces[i];
      }
      delete[] verteces;
      verteces = new_verteces;
      capacityVert += 10;
    }
  }

  gavrilova::Polygon* poligon = nullptr;
  try {
    poligon = new gavrilova::Polygon(nVert, verteces);
    delete[] verteces;
    return poligon;
  } catch (const std::exception&) {
    delete[] verteces;
    throw;
  }
}

gavrilova::Ellipse* make_ellipse(std::istream& in)
{
  gavrilova::point_t center;
  double radiusX = 0;
  double radiusY = 0;
  if (!(in >> center >> radiusX >> radiusY)) {
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
    throw std::logic_error("Error! Unknown figure entered");
  }
  return new_shape;
}
