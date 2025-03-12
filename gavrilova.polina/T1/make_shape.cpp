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
  gavrilova::Rectangle* make_rectangle(std::istream& in)
  {
    using namespace gavrilova;
    point_t arr[2] = {};
    point_t* points = arr;
    if (!(inputPoints(in, points, 2))) {
      throw std::logic_error("Errors in rectangle input");
    }
    Rectangle* rect = new Rectangle(points[0], points[1]);
    return rect;
  }

  gavrilova::Triangle* make_triangle(std::istream& in)
  {
    using namespace gavrilova;
    point_t arr[3] = {};
    point_t* points = arr;
    if (!(inputPoints(in, points, 3))) {
      throw std::logic_error("Errors in triangle input");
    }
    Triangle* triang = new Triangle(points[0], points[1], points[2]);
    return triang;
  }

  gavrilova::Polygon* make_polygon(std::istream& in)
  {
    using namespace gavrilova;
    size_t capacityVert = 10;
    size_t nVert = 0;
    point_t* verteces = new point_t[capacityVert];

    in >> verteces[nVert].x;
    while (in) {
      if (!(in >> verteces[nVert].y)) {
        delete[] verteces;
        throw std::logic_error("Errors in polygon input");
      }
      ++nVert;
      if (nVert >= capacityVert) {
        point_t* new_verteces = nullptr;
        try {
          new_verteces = new point_t[capacityVert + 10];
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

    Polygon* poligon = nullptr;
    try {
      poligon = new Polygon(nVert, verteces);
      delete[] verteces;
      return poligon;
    } catch (const std::exception&) {
      delete[] verteces;
      throw;
    }
  }

  gavrilova::Ellipse* make_ellipse(std::istream& in)
  {
    using namespace gavrilova;
    point_t center{0, 0};
    double radiusX = 0;
    double radiusY = 0;
    if (!(inputPoint(in, center) >> radiusX >> radiusY)) {
      throw std::logic_error("Errors in ellipse input");
    }
    Ellipse* ellipse = new Ellipse(center, radiusX, radiusY);
    return ellipse;
  }
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
