#include "printResult.hpp"
#include <iostream>
#include <iomanip>
#include <cstddef>

void duhanina::outFigures(std::ostream& out, const Shape* const* shapes, size_t i)
{
  rectangle_t frame = shapes[i]->getFrameRect();
  out << frame.pos.x - frame.width / 2.0 << " ";
  out << frame.pos.y - frame.height / 2.0 << " ";
  out << frame.pos.x + frame.width / 2.0 << " ";
  out << frame.pos.y + frame.height / 2.0;
}

double duhanina::calcArea(const Shape* const* shapes, size_t shapeCount)
{
  double totalArea = 0;
  for (size_t i = 0; i < shapeCount; ++i)
  {
    if (shapes[i])
    {
      totalArea += shapes[i]->getArea();
    }
  }
  return totalArea;
}

void duhanina::printFiguresInfo(std::ostream& out, const Shape* const* shapes, size_t shapeCount)
{
  out << std::fixed << std::setprecision(1) << calcArea(shapes, shapeCount);
  for (size_t i = 0; i < shapeCount; i++)
  {
    out << " ";
    outFigures(out, shapes, i);
  }
  out << "\n";
}

void duhanina::processScaling(Shape* const* shapes, size_t shapeCount, point_t point, double scalingFactor)
{
  for (size_t i = 0; i < shapeCount; ++i)
  {
    duhanina::point_t pos = shapes[i]->getFrameRect().pos;
    shapes[i]->move(point);
    duhanina::point_t newPos = shapes[i]->getFrameRect().pos;
    duhanina::point_t vect;
    vect.x = (newPos.x - pos.x) * scalingFactor;
    vect.y = (newPos.y - pos.y) * scalingFactor;
    shapes[i]->scale(scalingFactor);
    shapes[i]->move(vect.x * -1, vect.y * -1);
  }
}
