#include "complexquad.hpp"
#include <algorithm>
#include <cmath>
#include <stdexcept>
#include "base-types.hpp"
namespace kiselev
{
  bool isTriangle(point_t p1, point_t p2, point_t p3)
  {
    double lenght1 = std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
    double lenght2 = std::sqrt(std::pow(p3.x - p1.x, 2) + std::pow(p3.y - p1.y, 2));
    double lenght3 = std::sqrt(std::pow(p2.x - p3.x, 2) + std::pow(p2.y - p3.y, 2));
    return lenght1 < lenght2 + lenght3 || lenght2 < lenght1 + lenght3 || lenght3 < lenght1 + lenght2;
  }
  point_t findIntersectionPoint(point_t p1, point_t p2, point_t p3, point_t p4, bool& isIntersect)
  {
    double A1 = p2.y - p1.y;
    double B1 = p2.x - p1.x;
    double C1 = p1.x * A1 + p1.y * B1;
    double A2 = p4.y - p3.y;
    double B2 = p4.x - p3.x;
    double C2 = p3.x * (A2) + p3.y * (B2);
    double determiner = A1 * B2 - B1 * A2;
    if (determiner == 0)
    {
      isIntersect = false;
      return { 0, 0 };
    }
    isIntersect = true;
    double x = (C1 * B2 - C2 * B1) / determiner;
    double y = (C2 * A1 - A2 * C1) / determiner;
    return { x, y };
  }
}
kiselev::Complexquad::Complexquad() :
  p1_(),
  p2_(),
  p3_(),
  p4_()
{
}
kiselev::Complexquad::Complexquad(point_t p1, point_t p2, point_t p3, point_t p4) :
  p1_(p1),
  p2_(p2),
  p3_(p3),
  p4_(p4)
{
  bool isIntersect = true;
  point_t centre = findIntersectionPoint(p1, p2, p3, p4, isIntersect);
  if (!isTriangle(p1, p4, centre) || !isTriangle(p2, p3, centre) || !isIntersect || (p4.x > p1.x && p3.x > p1.x))
  {
    throw std::invalid_argument("Incorrect coordinates");
  }
}
kiselev::rectangle_t kiselev::Complexquad::getFrameRect() const
{
  double leftDownX = std::min(std::min(p1_.x, p2_.x), std::min(p3_.x, p4_.x));
  double leftDownY = std::min(std::min(p1_.y, p2_.y), std::min(p3_.y, p4_.y));
  double rightUpX = std::max(std::max(p1_.x, p2_.x), std::max(p3_.x, p4_.x));
  double rightUpY = std::max(std::max(p1_.y, p2_.y), std::max(p3_.y, p4_.y));
  point_t centre = { leftDownX + (rightUpX - leftDownX) / 2, leftDownY + (rightUpY - leftDownY) / 2 };
  return { rightUpX - leftDownX, rightUpY - leftDownY, centre };
}
double kiselev::Complexquad::getArea() const
{
  point_t centre = this->getFrameRect().pos;
  double lenghtP1p4 = std::sqrt(std::pow(p4_.x - p1_.x, 2) + std::pow(p4_.y - p1_.y, 2));
  double lenghtP1centre = std::sqrt(std::pow(centre.x - p1_.x, 2) + std::pow(centre.y - p1_.y, 2));
  double lenghtP4centre = std::sqrt(std::pow(p4_.x - centre.x, 2) + std::pow(p4_.y - centre.y, 2));
  double semiPer1 = (lenghtP1p4 + lenghtP1centre + lenghtP4centre) / 2;
  double area1 = std::sqrt(semiPer1 * (semiPer1 - lenghtP1p4) * (semiPer1 - lenghtP1centre) * (semiPer1 - lenghtP4centre));
  double lenghtP2p3 = std::sqrt(std::pow(p2_.x - p3_.x, 2) + std::pow(p2_.y - p3_.y, 2));
  double lenghtP2centre = std::sqrt(std::pow(p2_.x - centre.x, 2) + std::pow(p2_.y - centre.y, 2));
  double lenghtP3centre = std::sqrt(std::pow(p3_.x - centre.x, 2) + std::pow(p3_.y - centre.y, 2));
  double semiPer2 = (lenghtP2p3 + lenghtP2centre + lenghtP3centre) / 2;
  double area2 = std::sqrt(semiPer2 * (semiPer2 - lenghtP2p3) * (semiPer2 - lenghtP2centre) * (semiPer2 - lenghtP3centre));
  return area1 + area2;
}
void kiselev::Complexquad::move(point_t a)
{
  point_t centre = this->getFrameRect().pos;
  double moveForX = a.x - centre.x;
  double moveForY = a.y - centre.y;
  move(moveForX, moveForY);
}
void kiselev::Complexquad::move(double dx, double dy)
{
  p1_.x += dx;
  p1_.y += dy;
  p2_.x += dx;
  p2_.y += dy;
  p3_.x += dx;
  p3_.y += dy;
  p4_.x += dx;
  p4_.y += dy;
}
void kiselev::Complexquad::scale(double k)
{
  point_t centre = this->getFrameRect().pos;
  scalePoint(p1_, centre, k);
  scalePoint(p2_, centre, k);
  scalePoint(p3_, centre, k);
  scalePoint(p4_, centre, k);
}
