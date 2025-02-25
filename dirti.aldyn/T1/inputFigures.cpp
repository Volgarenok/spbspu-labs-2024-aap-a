#include "inputFigures.hpp"

dirti::Rectangle* dirti::makeRectangle(std::istream& in)
{
  double leftX = 0.0, leftY = 0.0;
  double rightX = 0.0, rightY = 0.0;
  in >> leftX >> leftY >> rightX >> rightY;
  point_t left_low = { leftX, leftY };
  point_t right_high = { rightX, rightY };
  Rectangle* newRectangle = nullptr;
  newRectangle = new Rectangle(left_low, right_high);
  return newRectangle;
}

dirti::Square* dirti::makeSquare(std::istream& in)
{
  double leftX = 0.0, leftY = 0.0;
  double length = 0.0;
  in >> leftX >> leftY >> length;
  point_t left_low = { leftX, leftY };
  Square* newSquare = nullptr;
  newSquare = new Square(left_low, length);
  return newSquare;
}

dirti::Parallelogram* dirti::makeParallelogram(std::istream& in)
{
  double p1_x = 0.0, p1_y = 0.0;
  double p2_x = 0.0, p2_y = 0.0;
  double p3_x = 0.0, p3_y = 0.0;
  in >> p1_x >> p1_y >> p2_x >> p2_y >> p3_x >> p3_y;
  point_t p1 = { p1_x, p1_y };
  point_t p2 = { p2_x, p2_y };
  point_t p3 = { p3_x, p3_y };
  Parallelogram* newParallelogram = nullptr;
  newParallelogram = new Parallelogram(p1, p2, p3);
  return newParallelogram;
}
