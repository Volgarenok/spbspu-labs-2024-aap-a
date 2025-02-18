#include "concave.hpp"
#include <cmath>
#include <algorithm>
#include <stdexcept>
#include "geometric_calculations.hpp"

petrov::Concave::Concave(point_t p1, point_t p2, point_t p3, point_t p4):
  triangle_1_(p2, { (p2.x + p1.x) / 2, (p2.y + p1.y) / 2 }, p4),
  triangle_2_(p1, { (p2.x + p1.x) / 2, (p2.y + p1.y) / 2 }, p4),
  triangle_3_(p1, { (p3.x + p1.x) / 2, (p3.y + p1.y) / 2 }, p4),
  triangle_4_(p3, { (p3.x + p1.x) / 2, (p3.y + p1.y) / 2 }, p4)
{
  if ((p1.x == p4.x && p1.y == p4.y) || (p2.x == p4.x && p2.y == p4.y) || (p3.x == p4.x && p3.y == p4.y))
  {
    throw std::invalid_argument("NOTE: Scaling of some figures skipped due to their invalid description");
  }
  double a = calculateDistBtwPoints(p1, p2);
  double b = calculateDistBtwPoints(p3, p2);
  double c = calculateDistBtwPoints(p1, p3);
  if (a + b <= c || a + c <= b || b + c <= a)
  {
    throw std::invalid_argument("NOTE: Scaling of some figures skipped due to their invalid description");
  }
  double p = (a + b + c) / 2;
  double area_of_triangle = std::sqrt(p * (p - a) * (p - b) * (p - c));
  double area_1 = getAreaOfComponent(p2, p3, p4);
  double area_2 = getAreaOfComponent(p1, p2, p4);
  double area_3 = getAreaOfComponent(p1, p3, p4);
  if (std::round(area_of_triangle) / 10 != std::round(area_1 + area_2 + area_3) / 10)
  {
    throw std::invalid_argument("NOTE: Scaling of some figures skipped due to their invalid description");
  }
}

double petrov::Concave::getArea() const
{
  double area = 0.0;
  area += triangle_1_.getArea();
  area += triangle_2_.getArea();
  area += triangle_3_.getArea();
  area += triangle_4_.getArea();
  return area;
}

double petrov::Concave::getAreaOfComponent(point_t p1, point_t p2, point_t p3) const
{
  double a = calculateDistBtwPoints(p1, p2);
  double b = calculateDistBtwPoints(p3, p2);
  double c = calculateDistBtwPoints(p1, p3);
  double p = (a + b + c) / 2;
  return std::sqrt(p * (p - a) * (p - b) * (p - c));
}

petrov::rectangle_t petrov::Concave::getFrameRect() const
{
  const Shape * triangles[4] = { &triangle_1_, &triangle_2_, &triangle_3_, &triangle_4_ };
  return getFrameRectByOtherShapes(triangles, 4);
}

void petrov::Concave::move(const point_t & concrete_point)
{
  point_t pos = getFrameRect().pos;
  double dx = concrete_point.x - pos.x;
  double dy = concrete_point.y - pos.y;
  this->move(dx, dy);
}

void petrov::Concave::move(double dx, double dy)
{
  Triangle * triangles[4] = { &triangle_1_, &triangle_2_, &triangle_3_, &triangle_4_ };
  for (size_t i = 0; i < 4; i++)
  {
    triangles[i]->move(dx, dy);
  }
}

void petrov::Concave::scale(double k)
{
  point_t pos = getFrameRect().pos;
  point_t pos_1 = triangle_1_.getFrameRect().pos;
  point_t pos_2 = triangle_2_.getFrameRect().pos;
  point_t pos_3 = triangle_3_.getFrameRect().pos;
  point_t pos_4 = triangle_4_.getFrameRect().pos;
  point_t triangles_pos[4] = { pos_1, pos_2, pos_3, pos_4 };
  Triangle * triangles[4] = { &triangle_1_, &triangle_2_, &triangle_3_, &triangle_4_ };
  for (size_t i = 0; i < 4; i++)
  {
    double dx_unique = triangles_pos[i].x - pos.x;
    double dy_unique = triangles_pos[i].y - pos.y;
    triangles[i]->scale(k);
    triangles[i]->move(dx_unique, dy_unique);
  }
}

petrov::Shape * petrov::Concave::clone() const
{
  return new Concave(*this);
}
