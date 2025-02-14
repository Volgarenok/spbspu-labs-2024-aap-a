#include "processShapes.hpp"
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "rectangle.hpp"
#include "ring.hpp"
#include "triangle.hpp"
#include "complexquad.hpp"


krylov::Shape* krylov::createRectangle(std::istream& in)
{
  double x1 = 0.0, y1 = 0.0, x2 = 0.0, y2 = 0.0;
  Shape* rectangle = nullptr;
  if (!(in >> x1 >> y1 >> x2 >> y2))
  {
    throw std::invalid_argument("Invalid RECTANGLE parameters");
  }
  try
  {
    rectangle = new krylov::Rectangle({x1, y1}, {x2, y2});
    return rectangle;
  }
  catch (const std::exception& e)
  {
    if (rectangle) delete rectangle;
    throw;
  }
}

krylov::Shape* krylov::createTriangle(std::istream& in)
{
  double x1 = 0.0, y1 = 0.0;
  double x2 = 0.0, y2 = 0.0;
  double x3 = 0.0, y3 = 0.0;
  Shape* triangle = nullptr;
  if (!(in >> x1 >> y1 >> x2 >> y2 >> x3 >> y3))
  {
    throw std::invalid_argument("Invalid TRIANGLE parameters");
  }
  try
  {
    triangle = new krylov::Triangle({x1, y1}, {x2, y2}, {x3, y3});
    return triangle;
  }
  catch (const std::exception& e)
  {
    if (triangle) delete triangle;
    throw;
  }
}

krylov::Shape* krylov::createRing(std::istream& in)
{
  double x, y, outerRadius, innerRadius;
  Shape* ring = nullptr;
  if (!(in >> x >> y >> outerRadius >> innerRadius))
  {
    throw std::invalid_argument("Invalid RING parameters");
  }
  try
  {
    ring = new krylov::Ring({x, y}, outerRadius, innerRadius);
    return ring;
  }
  catch (const std::exception& e)
  {
    if (ring) delete ring;
    throw;
  }
}

krylov::Shape* krylov::createComplexquad(std::istream& in)
{
  double x1 = 0.0, y1 = 0.0;
  double x2 = 0.0, y2 = 0.0;
  double x3 = 0.0, y3 = 0.0;
  double x4 = 0.0, y4 = 0.0;
  Shape* complexquad = nullptr;
  if (!(in >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4))
  {
    throw std::invalid_argument("Invalid COMPLEXQUAD parameters");
  }
  try
  {
    complexquad = new krylov::Complexquad({x1, y1}, {x2, y2}, {x3, y3}, {x4, y4});
    return complexquad;
  }
  catch (const std::exception& e)
  {
    if (complexquad) delete complexquad;
    throw;
  }
}

void krylov::deleteShapes(krylov::Shape** shapes, size_t shapeCount)
{
  for (size_t i = 0; i < shapeCount; ++i)
  {
    if (shapes[i] != nullptr)
    {
      delete shapes[i];
    }
  }
}
void krylov::printAreaAndFrameCoords(Shape** shapes, size_t shapeCount, double totalArea)
{
  std::cout << std::fixed << std::setprecision(1) << totalArea << ' ';
  for (size_t i = 0; i < shapeCount; ++i)
  {
    krylov::rectangle_t frame = shapes[i]->getFrameRect();
    std::cout << frame.pos.x - frame.width / 2 << ' ';
    std::cout << frame.pos.y - frame.height / 2 << ' ';
    std::cout << frame.pos.x + frame.width / 2 << ' ';
    std::cout << frame.pos.y + frame.height / 2;
    if (i < shapeCount - 1)
    {
      std::cout << ' ';
    }
  }
}
std::istream& krylov::simpleGetLine(std::istream& in, std::string& str)
{
  str.clear();
  char ch = '\0';
  while (in.get(ch))
  {
    if (ch == '\n')
    {
      break;
    }
    str += ch;
  }
  return in;
}
