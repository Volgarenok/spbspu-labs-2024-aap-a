#include "makeShapes.hpp"
#include <iostream>

namespace
{
  size_t addArrPoints(std::istream& in, finaev::point_t* arr, size_t size)
  {
    for (size_t i = 0; i < size; ++i)
    {
      double a = 0.0;
      double b = 0.0;
      in >> a;
      in >> b;
      if (!std::cin.good())
      {
        return i;
      }
      arr[i] = {a, b};
    }
    return size;
  }
}

finaev::Rectangle* finaev::makeRectangle(std::istream& in)
{
  const size_t size = 2;
  point_t* arr = new point_t[size];
  if (addArrPoints(in, arr, size) != size)
  {
    delete[] arr;
    throw std::length_error("Incomplete input");
  }
  point_t l = arr[0];
  point_t r = arr[1];
  delete[] arr;
  Rectangle* rect = new Rectangle(l, r);
  return rect;
}

finaev::Square* finaev::makeSquare(std::istream& in)
{
  const size_t size = 1;
  point_t* arr = new point_t[size];
  if (addArrPoints(in, arr, size) != size)
  {
    delete[] arr;
    throw std::length_error("Incomplete input");
  }
  double side = 0;
  in >> side;
  point_t l = arr[0];
  delete[] arr;
  Square* square = new Square(l, side);
  return square;
}

finaev::Concave* finaev::makeConcave(std::istream& in)
{
  const size_t size = 4;
  point_t* arr = new point_t[size];
  if (addArrPoints(in, arr, size) != size)
  {
    delete[] arr;
    throw std::length_error("Incomplete input");
  }
  point_t first = arr[0];
  point_t second = arr[1];
  point_t third = arr[2];
  point_t internal = arr[3];
  delete[] arr;
  Concave* concave = new Concave(first, second, third, internal);
  return concave;
}

finaev::Shape* finaev::makeShapes(std::istream& in, const std::string str)
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
