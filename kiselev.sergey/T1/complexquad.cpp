#include "complexquad.hpp"
#include <cmath>
#include <stdexcept>
#include "shape.hpp"
namespace
{
  double getLengthSide(kiselev::point_t p1, kiselev::point_t p2)
  {
    return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
  }
  bool isTriangle(kiselev::point_t p1, kiselev::point_t p2, kiselev::point_t p3)
  {
    const double length1 = getLengthSide(p1, p2);
    const double length2 = getLengthSide(p1, p3);
    const double length3 = getLengthSide(p3, p2);
    return length1 < length2 + length3 || length2 < length1 + length3 || length3 < length1 + length2;
  }
  kiselev::point_t findP(kiselev::point_t p1, kiselev::point_t p2, kiselev::point_t p3, kiselev::point_t p4, bool& isIntersect)
  {
    const double a1 = p2.y - p1.y;
    const double b1 = p2.x - p1.x;
    const double c1 = p1.x * a1 + p1.y * b1;
    const double a2 = p4.y - p3.y;
    const double b2 = p4.x - p3.x;
    const double c2 = p3.x * a2 + p3.y * b2;
    const double determiner = a1 * b2 - b1 * a2;
    if (determiner == 0)
    {
      isIntersect = false;
      return { 0, 0 };
    }
    isIntersect = true;
    const double x = (c1 * b2 - c2 * b1) / determiner;
    const double y = (a2 * a1 - a2 * c1) / determiner;
    return { x, y };
  }
}
kiselev::Complexquad::Complexquad(point_t p1, point_t p2, point_t p3, point_t p4):
  size_(4),
  arr_{ p1, p2, p3, p4 }
{
  bool isIntersect = true;
  point_t centre = findP(p1, p2, p3, p4, isIntersect);
  if (!isTriangle(p1, p4, centre) || !isTriangle(p2, p3, centre) || !isIntersect || (p4.x > p1.x && p3.x > p1.x))
  {
    throw std::invalid_argument("Incorrect coordinates");
  }
}
kiselev::rectangle_t kiselev::Complexquad::getFrameRect() const
{
  const double leftDownX = std::min(std::min(arr_[0].x, arr_[1].x), std::min(arr_[2].x, arr_[3].x));
  const double leftDownY = std::min(std::min(arr_[0].y, arr_[1].y), std::min(arr_[2].y, arr_[3].y));
  const double rightUpX = std::max(std::max(arr_[0].x, arr_[1].x), std::max(arr_[2].x, arr_[3].x));
  const double rightUpY = std::max(std::max(arr_[0].y, arr_[1].y), std::max(arr_[2].y, arr_[3].y));
  const point_t centre = { leftDownX + (rightUpX - leftDownX) / 2, leftDownY + (rightUpY - leftDownY) / 2 };
  return { rightUpX - leftDownX, rightUpY - leftDownY, centre };
}
double kiselev::Complexquad::getArea() const
{
  const point_t centre = getFrameRect().pos;
  const double lengthP1p4 = getLengthSide(arr_[0], arr_[3]);
  const double lengthP1centre = getLengthSide(arr_[0], centre);
  const double lengthP4centre = getLengthSide(centre, arr_[3]);
  const double semiPer1 = (lengthP1p4 + lengthP1centre + lengthP4centre) / 2;
  const double area1 = std::sqrt(semiPer1 * (semiPer1 - lengthP1p4) * (semiPer1 - lengthP1centre) * (semiPer1 - lengthP4centre));
  const double lengthP2p3 = getLengthSide(arr_[2], arr_[1]);
  const double lengthP2centre = getLengthSide(centre, arr_[1]);
  const double lengthP3centre = getLengthSide(centre, arr_[2]);
  const double semiPer2 = (lengthP2p3 + lengthP2centre + lengthP3centre) / 2;
  const double area2 = std::sqrt(semiPer2 * (semiPer2 - lengthP2p3) * (semiPer2 - lengthP2centre) * (semiPer2 - lengthP3centre));
  return area1 + area2;
}
void kiselev::Complexquad::move(point_t a)
{
  const point_t centre = getFrameRect().pos;
  const double moveForX = a.x - centre.x;
  const double moveForY = a.y - centre.y;
  move(moveForX, moveForY);
}
void kiselev::Complexquad::move(double dx, double dy)
{
  for (size_t i = 0; i < size_; ++i)
  {
    arr_[i] = movePoint(arr_[i], dx, dy);
  }
}
void kiselev::Complexquad::scale(double k)
{
  const point_t centre = getFrameRect().pos;
  for (size_t i = 0; i < size_; ++i)
  {
    arr_[i] = scalePoint(arr_[i], centre, k);
  }
}
kiselev::Shape* kiselev::Complexquad::clone() const
{
  return new Complexquad(*this);
}
