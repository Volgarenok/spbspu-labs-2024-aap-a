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
  point_t p1 = {coordsArray[0], coordsArray[1]};
  point_t p2 = {coordsArray[2], coordsArray[3]};
  point_t p3 = {coordsArray[4], coordsArray[5]};
  point_t center;
  double dx = 0.0, dy = 0.0;
  if ((p1.x == p2.x) && ((p1.y == p3.y) || (p2.y == p3.y)))
  {
    center = {p1.x, p3.y};
    dx = std::abs(center.x - p3.x) * 2;
    dy = std::abs(p1.y - p2.y) * 2;
  }
  else if ((p1.x == p3.x) && ((p1.y == p2.y) || (p2.y == p3.y)))
  {
    center = {p3.x, p2.y};
    dx = std::abs(center.x - p2.x) * 2;
    dy = std::abs(p3.y - p1.y) * 2;
  }
  else if ((p2.x == p3.x) && ((p1.y == p2.y) || (p1.y == p3.y)))
  {
    center = {p3.x, p1.y};
    dx = std::abs(p1.x - p2.x) * 2;
    dy = std::abs(center.y - p3.y) * 2;
  }
  else
  {
    throw std::invalid_argument("Diagonals must be parallel to the coordinate axes");
  }
  point_t vertex1 = {center.x + dx / 2, center.y};
  point_t vertex2 = {center.x, center.y - dy / 2};
  point_t vertex3 = {center.x - dx / 2, center.y};
  return new Diamond(vertex1, vertex2, vertex3);
}

smirnov::Parallelogram * smirnov::createParallelogram(std::istream & in)
{
  constexpr size_t coordinateCount = 6;
  double coordsArray[coordinateCount];
  inputCoords(coordsArray, coordinateCount, in);
  point_t p1 = {coordsArray[0], coordsArray[1]};
  point_t p2 = {coordsArray[2], coordsArray[3]};
  point_t p3 = {coordsArray[4], coordsArray[5]};
  if (!(p1.y == p2.y || p1.y == p3.y || p2.y == p3.y))
  {
    throw std::invalid_argument("The sides of the parallelogram must be parallel to the X-axis");
  }
  return new Parallelogram(p1, p2, p3);
}

smirnov::Shape * smirnov::createShapes(std::istream & in, const std::string & shapeType)
{
  if (shapeType == "RECTANGLE")
  {
    return createRectangle(in);
  }
  else if (shapeType == "DIAMOND")
  {
    return createDiamond(in);
  }
  else if (shapeType == "SQUARE")
  {
    return createSquare(in);
  }
  else if (shapeType == "PARALLELOGRAM")
  {
    return createParallelogram(in);
  }
  else
  {
    return nullptr;
  }
}
