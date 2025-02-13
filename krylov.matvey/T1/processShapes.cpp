#include "processShapes.hpp"
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "rectangle.hpp"
#include "ring.hpp"
#include "triangle.hpp"
#include "complexquad.hpp"


krylov::Shape* krylov::createRectangle()
{
  double x1 = 0.0, y1 = 0.0, x2 = 0.0, y2 = 0.0;
  if (!(std::cin >> x1 >> y1 >> x2 >> y2))
  {
    throw std::invalid_argument("Invalid RECTANGLE parameters");
  }
  return new krylov::Rectangle({x1, y1}, {x2, y2});
}

krylov::Shape* krylov::createTriangle()
{
  double x1 = 0.0, y1 = 0.0;
  double x2 = 0.0, y2 = 0.0;
  double x3 = 0.0, y3 = 0.0;
  if (!(std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3))
  {
    throw std::invalid_argument("Invalid TRIANGLE parameters");
  }
  return new krylov::Triangle({x1, y1}, {x2, y2}, {x3, y3});
}

krylov::Shape* krylov::createRing()
{
  double x, y, outerRadius, innerRadius;
  if (!(std::cin >> x >> y >> outerRadius >> innerRadius))
  {
    throw std::invalid_argument("Invalid RING parameters");
  }
  return new krylov::Ring({x, y}, outerRadius, innerRadius);
}

krylov::Shape* krylov::createComplexquad()
{
  double x1 = 0.0, y1 = 0.0;
  double x2 = 0.0, y2 = 0.0;
  double x3 = 0.0, y3 = 0.0;
  double x4 = 0.0, y4 = 0.0;
  if (!(std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4))
  {
    throw std::invalid_argument("Invalid COMPLEXQUAD parameters");
  }
  return new krylov::Complexquad({x1, y1}, {x2, y2}, {x3, y3}, {x4, y4});
}

void krylov::deleteShapes(krylov::Shape** shapes, size_t shapeCount)
{
  for (size_t i = 0; i < shapeCount; ++i)
  {
    delete shapes[i];
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
