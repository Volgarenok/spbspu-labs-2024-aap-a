#include "shapeManipulator.hpp"

double mozhegova::getSumArea(const Shape * const * shapes, size_t n)
{
  double sum = 0;
  for (size_t i = 0; i < n; i++)
  {
    sum += shapes[i]->getArea();
  }
  return sum;
}

void mozhegova::printCoorRect(std::ostream & out, const Shape * const * shapes, size_t n)
{
  rectangle_t rect = shapes[0]->getFrameRect();
  double lx = rect.pos.x - rect.width / 2.0;
  double ly = rect.pos.y - rect.height / 2.0;
  double rx = rect.pos.x + rect.width / 2.0;
  double ry = rect.pos.y + rect.height / 2.0;
  out << lx << " " << ly << " " << rx << " " << ry;
  for (size_t i = 1; i < n; i++)
  {
    rectangle_t rect = shapes[i]->getFrameRect();
    double lx = rect.pos.x - rect.width / 2.0;
    double ly = rect.pos.y - rect.height / 2.0;
    double rx = rect.pos.x + rect.width / 2.0;
    double ry = rect.pos.y + rect.height / 2.0;
    out << " " << lx << " " << ly << " " << rx << " " << ry;
  }
}

void mozhegova::scaleShapes(Shape ** shapes, size_t n, point_t p, double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Incorrect scale");
  }
  for (size_t i = 0; i < n; i++)
  {
    point_t ptr = shapes[i]->getFrameRect().pos;
    shapes[i]->move(p);
    point_t newptr = shapes[i]->getFrameRect().pos;
    point_t vectorMove = {(newptr.x - ptr.x) * k, (newptr.y - ptr.y) * k};
    shapes[i]->scaleImpl(k);
    shapes[i]->move(-vectorMove.x, -vectorMove.y);
  }
}

void mozhegova::destroy(Shape ** shapes, size_t n)
{
  for (size_t i = 0; i < n; i++)
  {
    delete shapes[i];
  }
}
