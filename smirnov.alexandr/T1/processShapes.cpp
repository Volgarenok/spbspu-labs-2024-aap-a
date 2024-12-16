#include "processShapes.hpp"
#include <iostream>

double smirnov::sumArea(Shape ** shapes, size_t count)
{
  double sumArea = 0;
  for (size_t i = 0; i < count; i++)
  {
    sumArea += shapes[i]->getArea();
  }
  return sumArea;
}

void smirnov::destroyShape(Shape ** shapes, size_t count)
{
  for (size_t i = 0; i < count; i++)
  {
    delete shapes[i];
  }
}

void smirnov::printFrameRect(Shape ** shapes, size_t count)
{
  for (size_t i = 0; i < count; i++)
  {
    rectangle_t rectangle = shapes[i]->getFrameRect();
    double x1 = rectangle.pos.x - rectangle.width / 2.0;
    double y1 = rectangle.pos.y - rectangle.height / 2.0;
    double x2 = rectangle.pos.x + rectangle.width / 2.0;
    double y2 = rectangle.pos.y + rectangle.height / 2.0;
    std::cout << " " << x1 << " " << x2 << " " << y1 << " " << y2;
  }
  std::cout << "\n";
}

void smirnov::scaleShape(Shape ** shapes, size_t count, point_t p, double factor)
{
  for (size_t i = 0; i < count; i++)
  {
    point_t startPos = shapes[i]->getFrameRect().pos;
    shapes[i]->move(p);
    point_t newPos = shapes[i]->getFrameRect().pos;
    point_t vector;
    vector.x = (newPos.x - startPos.x) * factor;
    vector.y = (newPos.y - startPos.y) * factor;
    shapes[i]->scale(factor);
    shapes[i]->move(-vector.x, -vector.y);
  }
}
