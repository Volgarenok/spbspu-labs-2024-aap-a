#include "shape.hpp"
#include <iomanip>
#include <iostream>
#include "rectangle.hpp"
#include "regular.hpp"
#include "polygon.hpp"

void maslevtsov::clearShapes(Shape** shapes, std::size_t border)
{
  for (std::size_t i = 0; i < border; ++i)
  {
    delete shapes[i];
  }
}

maslevtsov::Shape* maslevtsov::makeShape(std::string figureName, const double* arguments, std::size_t nArguments)
{
  if (figureName == "RECTANGLE")
  {
    return makeRectangle(arguments);
  }
  if (figureName == "REGULAR")
  {
    return makeRegular(arguments);
  }
  if (figureName == "POLYGON")
  {
    return makePolygon(arguments, nArguments);
  }
  throw std::logic_error("not supported");
}

void maslevtsov::scale(Shape* shape, point_t pnt, double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("invalid coefficient");
  }
  point_t frameCenterBefore = shape->getFrameRect().pos;
  shape->move(pnt);
  point_t frameCenterAfter = shape->getFrameRect().pos;
  point_t offset{(frameCenterAfter.x - frameCenterBefore.x) * k, (frameCenterAfter.y - frameCenterBefore.y) * k};
  shape->scale(k);
  shape->move(-offset.x, -offset.y);
}

void maslevtsov::scaleShapes(Shape** shapes, point_t pnt, double k, std::size_t border)
{
  for (std::size_t i = 0; i < border; ++i)
  {
    scale(shapes[i], pnt, k);
  }
}

void maslevtsov::outputAreaSum(std::ostream& out, const Shape* const* shapes, std::size_t border)
{
  double areaSum = 0;
  for (std::size_t i = 0; i < border; ++i)
  {
    areaSum += shapes[i]->getArea();
  }
  out << areaSum;
}

void maslevtsov::outputShapes(std::ostream& out, const Shape* const* shapes, std::size_t border)
{
  for (std::size_t i = 0; i < border; ++i)
  {
    rectangle_t rect = shapes[i]->getFrameRect();
    point_t bottomLeft{rect.pos.x - rect.width / 2, rect.pos.y - rect.height / 2};
    point_t topRight{rect.pos.x + rect.width / 2, rect.pos.y + rect.height / 2};
    out << bottomLeft.x << ' ' << bottomLeft.y;
    out << ' ' << topRight.x << ' ' << topRight.y;
    if (i != border - 1 && border > 1)
    {
      out << ' ';
    }
  }
}

void maslevtsov::outputShapesData(std::ostream& out, const Shape* const* shapes, std::size_t border)
{
  std::cout << std::fixed << std::setprecision(1);
  outputAreaSum(out, shapes, border);
  std::cout << ' ';
  outputShapes(out, shapes, border);
}
