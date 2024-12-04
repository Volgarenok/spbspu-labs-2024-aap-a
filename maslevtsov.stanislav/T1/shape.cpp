#include "shape.hpp"
#include <string>
#include "rectangle.hpp"

maslevtsov::Shape* maslevtsov::makeShape(std::istream& in)
{
  std::string figureName = "";
  in >> figureName;

  if (figureName == "RECTANGLE")
  {
    double bottomLeftX = 0, bottomLeftY = 0, topRightX = 0, topRightY = 0;
    in >> bottomLeftX >> bottomLeftY >> topRightX >> topRightY;
    Rectangle* rect = new Rectangle({bottomLeftX, bottomLeftY}, {topRightX, topRightY});
    return rect;
  }
  throw std::logic_error("not supported");
}

void maslevtsov::scale(Shape* shape, point_t pnt, double k)
{
  point_t frameCenterBefore = shape->getFrameRect().pos;
  shape->move(pnt);
  point_t frameCenterAfter = shape->getFrameRect().pos;
  point_t offset{(frameCenterAfter.x - frameCenterBefore.x) * k, (frameCenterAfter.y - frameCenterBefore.y) * k};
  shape->scale(k);
  shape->move(-offset.x, -offset.y);
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
  }
}
