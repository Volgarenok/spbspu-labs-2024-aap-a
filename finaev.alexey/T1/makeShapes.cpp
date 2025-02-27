#include "makeShapes.hpp"
#include <iostream>

namespace
{
  void addArrPoints(std::istream& in, finaev::point_t* arr, size_t size)
  {
    for (size_t i = 0; i < size; ++i)
    {
      double a = 0.0;
      double b = 0.0;
      in >> a;
      in >> b;
      arr[i] = { a, b };
    }
  }
}

finaev::Rectangle* finaev::makeRectangle(std::istream& in)
{
  constexpr size_t size = 2;
  point_t arr[size] = {};
  addArrPoints(in, arr, size);
  point_t l = arr[0];
  point_t r = arr[1];
  Rectangle* rect = new Rectangle(l, r);
  return rect;
}

finaev::Square* finaev::makeSquare(std::istream& in)
{
  constexpr size_t size = 1;
  point_t arr[size] = {};
  addArrPoints(in, arr, size);
  point_t l = arr[0];
  double side = 0;
  in >> side;
  Square* square = new Square(l, side);
  return square;
}

finaev::Concave* finaev::makeConcave(std::istream& in)
{
  constexpr size_t size = 4;
  point_t arr[size] = {};
  addArrPoints(in, arr, size);
  point_t first = arr[0];
  point_t second = arr[1];
  point_t third = arr[2];
  point_t internal = arr[3];
  Concave* concave = new Concave(first, second, third, internal);
  return concave;
}

finaev::Shape* finaev::makeShapes(std::istream& in, std::string str)
{
  if (str == "RECTANGLE")
  {
    return makeRectangle(in);
  }
  else if (str == "SQUARE")
  {
    return makeSquare(in);
  }
  else if (str == "CONCAVE")
  {
    return makeConcave(in);
  }
  else
  {
    throw std::invalid_argument("Not a name of figure");
  }
}
