#include "shape.hpp"
#include <iomanip>
#include <iostream>
#include "rectangle.hpp"
#include "regular.hpp"
#include "polygon.hpp"

namespace
{
  std::ostream& outputOneShape(std::ostream& out, const maslevtsov::Shape* shape)
  {
    maslevtsov::rectangle_t rect = shape->getFrameRect();
    maslevtsov::point_t bottomLeft{rect.pos.x - rect.width / 2, rect.pos.y - rect.height / 2};
    maslevtsov::point_t topRight{rect.pos.x + rect.width / 2, rect.pos.y + rect.height / 2};
    return out << bottomLeft.x << ' ' << bottomLeft.y << ' ' << topRight.x << ' ' << topRight.y;
  }
}

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
    Rectangle* rect = new Rectangle({arguments[0], arguments[1]}, {arguments[2], arguments[3]});
    return rect;
  }
  if (figureName == "REGULAR")
  {
    point_t pnt1 = {arguments[0], arguments[1]};
    point_t pnt2 = {arguments[2], arguments[3]};
    point_t pnt3 = {arguments[4], arguments[5]};
    Regular* reg = new Regular(pnt1, pnt2, pnt3);
    return reg;
  }
  if (figureName == "POLYGON")
  {
    return makePolygon(arguments, nArguments);
  }
  throw std::logic_error("not supported");
}

void maslevtsov::unsafeScale(Shape* shape, point_t pnt, double k)
{
  point_t frameCenterBefore = shape->getFrameRect().pos;
  shape->move(pnt);
  point_t frameCenterAfter = shape->getFrameRect().pos;
  point_t offset{(frameCenterAfter.x - frameCenterBefore.x) * k, (frameCenterAfter.y - frameCenterBefore.y) * k};
  shape->unsafeScale(k);
  shape->move(-offset.x, -offset.y);
}

void maslevtsov::safeScale(Shape* shape, point_t pnt, double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("invalid coefficient");
  }
  unsafeScale(shape, pnt, k);
}

void maslevtsov::scaleShapes(Shape** shapes, point_t pnt, double k, std::size_t border)
{
  if (k <= 0)
  {
    throw std::invalid_argument("invalid coefficient");
  }
  for (std::size_t i = 0; i < border; ++i)
  {
    unsafeScale(shapes[i], pnt, k);
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
  for (std::size_t i = 0; i < border - 1; ++i)
  {
    outputOneShape(out, shapes[i]) << ' ';
  }
  outputOneShape(out, shapes[border - 1]);
}

void maslevtsov::outputShapesData(std::ostream& out, const Shape* const* shapes, std::size_t border)
{
  std::cout << std::fixed << std::setprecision(1);
  outputAreaSum(out, shapes, border);
  std::cout << ' ';
  outputShapes(out, shapes, border);
}
