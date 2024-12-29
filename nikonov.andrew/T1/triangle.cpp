#include "triangle.hpp"
#include <iostream>
#include <exception>
#include <cmath>
#include "base-types.hpp"
nikonov::point_t getCenterOfGravity(const nikonov::point_t &A, const nikonov::point_t &B, const nikonov::point_t &C)
{
  return nikonov::point_t({ (A.x + B.x + C.x) / 3, ((A.y + B.y + C.y) / 3) });
}
nikonov::Triangle::Triangle(const point_t &A, const point_t &B, const point_t &C)
{
  double AB = std::sqrt(std::pow(B_.x - A_.x, 2) + std::pow(B_.y - A_.y, 2));
  double BC = std::sqrt(std::pow(C_.x - B_.x, 2) + std::pow(C_.y - B_.y, 2));
  double CA = std::sqrt(std::pow(C_.x - A_.x, 2) + std::pow(C_.y - A_.y, 2));
  if (!((AB + BC > CA) && (AB + CA > BC) && (CA + BC > AB)))
  {
    throw std::logic_error("ERROR:noncorrect triangle parameters");
  }
  A_ = A;
  B_ = B;
  C_ = C;
}
double nikonov::Triangle::getArea() const
{
  rectangle_t tempRect = getFrameRect();
  return (tempRect.height * tempRect.width) / 2;
}
nikonov::rectangle_t nikonov::Triangle::getFrameRect() const
{
  double tempX = (A_.x > B_.x ? A_.x : B_.x);
  double maxX = (C_.x > tempX ? C_.x : tempX);
  double tempY = (A_.y > B_.y ? A_.y : B_.y);
  double maxY = (C_.y > tempY ? C_.y : tempY);
  tempX = (A_.x < B_.x ? A_.x : B_.x);
  double minX = (C_.x < tempX ? C_.x : tempX);
  tempY = (A_.y < B_.y ? A_.y : B_.y);
  double minY = (C_.y < tempY ? C_.y : tempY);
  double width = maxX - minX;
  double height = maxY - minY;
  point_t pos = point_t({ minX + (width / 2), minY + (height / 2) });
  return rectangle_t({ width, height, pos });
}
void nikonov::Triangle::move(const point_t &newPos)
{
  point_t center = getCenterOfGravity(A_, B_, C_);
  double diffX = newPos.x - center.x;
  double diffY = newPos.y - center.y;
  move(diffX, diffY);
}
void nikonov::Triangle::move(double x, double y)
{
  movePoint(A_, x, y);
  movePoint(B_, x, y);
  movePoint(C_, x, y);
}
void nikonov::Triangle::scale(double k)
{
  if (k <= 0)
  {
    throw std::logic_error("Scale denied: k must be more than zero");
  }
  point_t center = getCenterOfGravity(A_, B_, C_);
  A_.x = center.x + (A_.x - center.x) * k;
  A_.y = center.y + (A_.y - center.y) * k;
  B_.x = center.x + (B_.x - center.x) * k;
  B_.y = center.y + (B_.y - center.y) * k;
  C_.x = center.x + (C_.x - center.x) * k;
  C_.y = center.y + (C_.y - center.y) * k;
}
