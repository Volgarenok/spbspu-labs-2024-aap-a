#include "makeshape.hpp"
#include <iostream>

namespace
{
  void readArray(std::istream& input, double* read, size_t count, bool& error)
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
  void readPointsArray(std::istream& input, averenkov::point_t* read, size_t count, bool& error)
  {
    for (size_t i = 0; i < count; i++)
    {
      readArray(input, &read[i].x, 1, error);
      readArray(input, &read[i].y, 1, error);
    }
  }
}

void averenkov::makeRectangle(Shape** shapes, size_t& shapeCount, std::istream& input, bool& errors)
{
  point_t points[2] = { 0 };
  readPointsArray(input, points, 2, errors);
  Rectangle* rect = new Rectangle(points[0], points[1]);
  shapes[shapeCount++] = rect;
  return;
}

void averenkov::makeDiamond(Shape** shapes, size_t& shapeCount, std::istream& input, bool& errors)
{
  point_t points[3] = { 0 };
  readPointsArray(input, points, 3, errors);
  Diamond* diam = new Diamond(points[0], points[1], points[2]);
  shapes[shapeCount++] = diam;
  return;
}

void averenkov::makeEllipse(Shape** shapes, size_t& shapeCount, std::istream& input, bool& errors)
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
