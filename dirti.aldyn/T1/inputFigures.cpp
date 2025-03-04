#include "inputFigures.hpp"

namespace
{
  using namespace dirti;
  point_t inputPoint(std::istream& in)
  {
    double x = 0.0, y = 0.0;
    in >> x >> y;
    return { x, y };
  }

  Rectangle* makeRectangle(std::istream& in)
  {
    point_t left_low = inputPoint(in);
    point_t right_high = inputPoint(in);
    Rectangle* newRectangle = new Rectangle(left_low, right_high);
    return newRectangle;
  }

  Square* makeSquare(std::istream& in)
  {
    point_t left_low = inputPoint(in);
    double length = 0.0;
    in >> length;
    Square* newSquare = new Square(left_low, length);
    return newSquare;
  }

  Parallelogram* makeParallelogram(std::istream& in)
  {
    point_t p1 = inputPoint(in);
    point_t p2 = inputPoint(in);
    point_t p3 = inputPoint(in);
    if (p2.y == p3.y)
    {
      std::swap(p1, p3);
    }
    Parallelogram* newParallelogram = new Parallelogram(p1, p2, p3);
    return newParallelogram;
  }
}


dirti::Shape* dirti::makeShape(std::istream& in, std::string figure)
{
  Shape* newShape = nullptr;
  if (figure == "RECTANGLE")
  {
    newShape = makeRectangle(in);
  }
  if (figure == "SQUARE")
  {
    newShape = makeSquare(in);
  }
  if (figure == "PARALLELOGRAM")
  {
    newShape = makeParallelogram(in);
  }
  return newShape;
}
