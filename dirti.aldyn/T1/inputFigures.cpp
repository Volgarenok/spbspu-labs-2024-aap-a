#include "inputFigures.hpp"

namespace
{
  dirti::point_t inputPoint(std::istream& in)
  {
    double x = 0.0, y = 0.0;
    in >> x >> y;
    return { x, y };
  }
}

dirti::Rectangle* dirti::makeRectangle(std::istream& in)
{
  point_t left_low = inputPoint(in);
  point_t right_high = inputPoint(in);
  Rectangle* newRectangle = new Rectangle(left_low, right_high);
  return newRectangle;
}

dirti::Square* dirti::makeSquare(std::istream& in)
{
  double leftX = 0.0, leftY = 0.0;
  double length = 0.0;
  in >> leftX >> leftY >> length;
  point_t left_low = { leftX, leftY };
  Square* newSquare = new Square(left_low, length);
  return newSquare;
}

dirti::Parallelogram* dirti::makeParallelogram(std::istream& in)
{
  point_t p1 = inputPoint(in);
  point_t p2 = inputPoint(in);
  point_t p3 = inputPoint(in);
  Parallelogram* newParallelogram = new Parallelogram(p1, p2, p3);
  return newParallelogram;
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
