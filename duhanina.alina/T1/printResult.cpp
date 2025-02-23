#include "printResult.hpp"
#include <iomanip>
#include <cstddef>

double duhanina::calcArea(const Shape* const* shapes, size_t shapeCount)
{
  double totalArea = 0;
  for (size_t i = 0; i < shapeCount; ++i)
  {
    totalArea += shapes[i]->getArea();
  }
  return totalArea;
}

void duhanina::outFigures(std::ostream& out, const Shape* const* shapes, size_t i)
{
  rectangle_t frame = shapes[i]->getFrameRect();
  out << frame.pos.x - frame.width / 2.0 << " ";
  out << frame.pos.y - frame.height / 2.0 << " ";
  out << frame.pos.x + frame.width / 2.0 << " ";
  out << frame.pos.y + frame.height / 2.0;
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
  if (scalingFactor <= 0)
  {
    throw std::logic_error("Incorrect scalingFactor");
  }
  for (size_t i = 0; i < shapeCount; ++i)
  {
    point_t pos = shapes[i]->getFrameRect().pos;
    shapes[i]->move(point);
    point_t newPos = shapes[i]->getFrameRect().pos;
    double x = (newPos.x - pos.x) * scalingFactor;
    double y = (newPos.y - pos.y) * scalingFactor;
    point_t vect = { x, y };
    shapes[i]->scaleUnsafe(scalingFactor);
    shapes[i]->move(vect.x * -1, vect.y * -1);
  }
}
