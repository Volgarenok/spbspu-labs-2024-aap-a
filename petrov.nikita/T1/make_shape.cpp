#include "make_shape.hpp"
#include <cstring>
#include "input_cstring_until_ws.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "concave.hpp"

namespace
{
  void inputPointsCoordinates(std::istream & in, petrov::point_t * points, size_t number_of_points);
  petrov::Shape * makeRectangle(std::istream & in);
  petrov::Shape * makeTriangle(std::istream & in);
  petrov::Shape * makeConcave(std::istream & in);

  void inputPointsCoordinates(std::istream & in, petrov::point_t * points, size_t number_of_points)
  {
    for (size_t i = 0; i < number_of_points; i++)
    {
      in >> points[i].x >> points[i].y;
    }
  }

  petrov::Shape * makeRectangle(std::istream & in)
  {
    petrov::point_t points[2] = {};
    inputPointsCoordinates(in, points, 2);
    return new petrov::Rectangle(points[0], points[1]);
  }

  petrov::Shape * makeTriangle(std::istream & in)
  {
    petrov::point_t points[3] = {};
    inputPointsCoordinates(in, points, 3);
    return new petrov::Triangle(points[0], points[1], points[2]);
  }

  petrov::Shape * makeConcave(std::istream & in)
  {
    petrov::point_t points[4] = {};
    inputPointsCoordinates(in, points, 4);
    return new petrov::Concave(points[0], points[1], points[2], points[3]);
  }
}

petrov::Shape * petrov::makeShape(std::istream & in)
{
  const char RECTANGLE[10] = "RECTANGLE";
  const char TRIANGLE[9] = "TRIANGLE";
  const char CONCAVE[8] = "CONCAVE";
  const char SCALE[6] = "SCALE";
  size_t capacity = 1;
  char * type_of_shape = inputCStringUntilWS(in, capacity);
  if (!std::strcmp(type_of_shape, RECTANGLE))
  {
    delete[] type_of_shape;
    return makeRectangle(in);
  }
  else if (!std::strcmp(type_of_shape, TRIANGLE))
  {
    delete[] type_of_shape;
    return makeTriangle(in);
  }
  else if (!std::strcmp(type_of_shape, CONCAVE))
  {
    delete[] type_of_shape;
    return makeConcave(in);
  }
  else if (!std::strcmp(type_of_shape, SCALE))
  {
    delete[] type_of_shape;
    return nullptr;
  }
  else
  {
    delete[] type_of_shape;
    throw std::logic_error("Unsupported");
  }
}
