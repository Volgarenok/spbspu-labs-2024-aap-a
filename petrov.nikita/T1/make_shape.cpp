#include <cstring>
#include "input_cstring_until_ws.hpp"
#include "make_shape.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "concave.hpp"
petrov::Shape * petrov::makeShape(std::istream & in)
{
  const char RECTANGLE[10] = "RECTANGLE";
  const char TRIANGLE[9] = "TRIANGLE";
  const char CONCAVE[8] = "CONCAVE";
  const char SCALE[6] = "SCALE";
  char * type_of_shape = nullptr;
  size_t capacity = 1;
  type_of_shape = inputCStringUntilWS(in, capacity);
  if (!strcmp(type_of_shape, RECTANGLE))
  {
    delete[] type_of_shape;
    return makeRectangle(in);
  }
  else if (!strcmp(type_of_shape, TRIANGLE))
  {
    delete[] type_of_shape;
    return makeTriangle(in);
  }
  else if (!strcmp(type_of_shape, CONCAVE))
  {
    delete[] type_of_shape;
    return makeConcave(in);
  }
  else if (!strcmp(type_of_shape, SCALE))
  {
    delete[] type_of_shape;
    return nullptr;
  }
  else
  {
    delete[] type_of_shape;
    throw std::logic_error("Unsupported\n");
  }
}

petrov::Shape * petrov::makeRectangle(std::istream & in)
{
  petrov::point_t p1 = {};
  petrov::point_t p2 = {};
  in >> p1.x >> p1.y >> p2.x >> p2.y;
  petrov::Rectangle * ptr_rectangle = nullptr;
  ptr_rectangle = new petrov::Rectangle(p1, p2);
  return ptr_rectangle;
}

petrov::Shape * petrov::makeTriangle(std::istream & in)
{
  petrov::point_t p1 = {};
  petrov::point_t p2 = {};
  petrov::point_t p3 = {};
  in >> p1.x >> p1.y >> p2.x >> p2.y;
  in >> p3.x >> p3.y;
  petrov::Triangle * ptr_triangle = nullptr;
  ptr_triangle = new petrov::Triangle(p1, p2, p3);
  return ptr_triangle;
}

petrov::Shape * petrov::makeConcave(std::istream & in)
{
  petrov::point_t p1 = {};
  petrov::point_t p2 = {};
  petrov::point_t p3 = {};
  petrov::point_t p4 = {};
  in >> p1.x >> p1.y >> p2.x >> p2.y;
  in >> p3.x >> p3.y >> p4.x >> p4.y;
  petrov::Concave * ptr_concave = nullptr;
  ptr_concave = new petrov::Concave(p1, p2, p3, p4);
  return ptr_concave;
}
