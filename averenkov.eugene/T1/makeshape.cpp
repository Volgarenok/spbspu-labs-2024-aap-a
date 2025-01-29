#include "makeshape.hpp"
#include <iostream>

void averenkov::readArray(std::istream& input, double* read, size_t count, bool& error)
{
  for (size_t i = 0; i < count; i++)
  {
    if (!(input >> read[i]))
    {
      error = true;
      return;
    }
  }
}

void averenkov::makeRectangle(averenkov::Shape** shapes, size_t& shapeCount, std::istream& input, bool& errors)
{
  double readed[4] = { 0 };
  readArray(input, readed, 4, errors);
  point_t a = { readed[0], readed[1] };
  point_t c = { readed[2], readed[3] };
  Rectangle* rect = new Rectangle(a, c);
  shapes[shapeCount++] = rect;
  return;
}

void averenkov::makeDiamond(averenkov::Shape** shapes, size_t& shapeCount, std::istream& input, bool& errors)
{
  double readed[6] = { 0 };
  readArray(input, readed, 6, errors);
  point_t a = { readed[0], readed[1] };
  point_t b = { readed[2], readed[3] };
  point_t c = { readed[4], readed[5] };
  Diamond* diam = new Diamond(a, b, c);
  shapes[shapeCount++] = diam;
  return;
}

void averenkov::makeEllipse(averenkov::Shape** shapes, size_t& shapeCount, std::istream& input, bool& errors)
{
  double readed[4] = { 0 };
  readArray(input, readed, 4, errors);
  point_t center = { readed[0], readed[1] };
  double a = readed[2], b = readed[3];
  Ellipse* ellip = new Ellipse(center, a, b);
  shapes[shapeCount++] = ellip;
  return;
}

void averenkov::makeScale(double& factor, point_t& scaling_center, std::istream& input)
{
  double x = 0;
  double y = 0;
  if (!(input >> x >> y >> factor) || factor <= 0)
  {
    throw std::invalid_argument("Incorrect input");
  }
  scaling_center = { x, y };
}
