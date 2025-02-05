#include "createShapes.hpp"
#include <stdexcept>

void smirnov::inputCoords(double * coordsArray, size_t count, std::istream & in)
{
  for (size_t i = 0; i < count; ++i)
  {
    if (!(in >> coordsArray[i]))
    {
      throw std::invalid_argument("Incorrect coordinates");
    }
  }
}

smirnov::Rectangle * smirnov::createRectangle(std::istream & in)
{
  constexpr size_t coordinateCount = 4;
  double coordsArray[coordinateCount];
  inputCoords(coordsArray, coordinateCount, in);
  double x1 = coordsArray[0];
  double y1 = coordsArray[1];
  double x2 = coordsArray[2];
  double y2 = coordsArray[3];
  return new Rectangle(x1, y1, x2, y2);
}

smirnov::Square * smirnov::createSquare(std::istream & in)
{
  constexpr size_t coordinateCount = 3;
  double coordsArray[coordinateCount];
  inputCoords(coordsArray, coordinateCount, in);
  double x = coordsArray[0];
  double y = coordsArray[1];
  double length = coordsArray[2];
  return new Square(x, y, length);
}

smirnov::Diamond * smirnov::createDiamond(std::istream & in)
{
  constexpr size_t coordinateCount = 6;
  double coordsArray[coordinateCount];
  inputCoords(coordsArray, coordinateCount, in);
  point_t p1, p2, p3;
  p1 = {coordsArray[0], coordsArray[1]};
  p2 = {coordsArray[2], coordsArray[3]};
  p3 = {coordsArray[4], coordsArray[5]};
  return new Diamond(p1, p2, p3);
}

smirnov::Parallelogram * smirnov::createParallelogram(std::istream & in)
{
  constexpr size_t coordinateCount = 6;
  double coordsArray[coordinateCount];
  inputCoords(coordsArray, coordinateCount, in);
  point_t p1, p2, p3;
  p1 = {coordsArray[0], coordsArray[1]};
  p2 = {coordsArray[2], coordsArray[3]};
  p3 = {coordsArray[4], coordsArray[5]};
  if (!(p1.y == p2.y || p1.y == p3.y || p2.y == p3.y))
  {
    throw std::invalid_argument("The sides of the parallelogram must be parallel to the X-axis");
  }
  return new Parallelogram(p1, p2, p3);
}
