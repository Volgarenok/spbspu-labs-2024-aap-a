#include "complexquad.hpp"
#include <algorithm>
#include <cmath>
#include "base-types.hpp"
kiselev::Complexquad::Complexquad(point_t p1, point_t p2, point_t p3, point_t p4) noexcept : 
  p1_(p1),
  p2_(p2),
  p3_(p3),
  p4_(p4)
{
}
kiselev::rectangle_t kiselev::Complexquad::getFrameRect() const noexcept
{
  double leftDownX = std::min(std::min(p1_.x, p2_.x), std::min(p3_.x, p4_.x));
  double leftDownY = std::min(std::min(p1_.y, p2_.y), std::min(p3_.y, p4_.y));
  double rightUpX = std::max(std::max(p1_.x, p2_.x), std::max(p3_.x, p4_.x));
  double rightUpY = std::max(std::max(p1_.y, p2_.y), std::max(p3_.y, p4_.y));
  point_t centre = { leftDownX + (rightUpX - leftDownX) / 2, leftDownY + (rightUpY - leftDownY) / 2 };
  return { rightUpX - leftDownX, rightUpY - leftDownY, centre };
}
double kiselev::Complexquad::getArea() const noexcept
{
  point_t centre = this->getFrameRect().pos;
  double lenghtP1p4 = std::sqrt(std::pow(p4_.x - p1_.x, 2) + std::pow(p4_.y - p1_.y, 2));
  double lenghtP1centre = std::sqrt(std::pow(centre.x - p1_.x, 2) + std::pow(centre.y - p1_.y, 2));
  double lenghtP4centre = std::sqrt(std::pow(p4_.x - centre.x, 2) + std::pow(p4_.y - centre.y, 2));
  double semiPerimeter1 = (lenghtP1p4 + lenghtP1centre + lenghtP4centre) / 2;
  double area1
      = std::sqrt(semiPerimeter1 * (semiPerimeter1 - lenghtP1p4) * (semiPerimeter1 - lenghtP1centre) * (semiPerimeter1 - lenghtP4centre));
  double lenghtP2p3 = std::sqrt(std::pow(p2_.x - p3_.x, 2) + std::pow(p2_.y - p3_.y, 2));
  double lenghtP2centre = std::sqrt(std::pow(p2_.x - centre.x, 2) + std::pow(p2_.y - centre.y, 2));
  double lenghtP3centre = std::sqrt(std::pow(p3_.x - centre.x, 2) + std::pow(p3_.y - centre.y, 2));
  double semiPerimeter2 = (lenghtP2p3 + lenghtP2centre + lenghtP3centre) / 2;
  double area2
      = std::sqrt(semiPerimeter2 * (semiPerimeter2 - lenghtP2p3) * (semiPerimeter2 - lenghtP2centre) * (semiPerimeter2 - lenghtP3centre));
  return area1 + area2;
}
void kiselev::Complexquad::move(point_t a) noexcept
{
  point_t centre = this->getFrameRect().pos;
  double moveForX = a.x - centre.x;
  double moveForY = a.y - centre.y;
  p1_.x += moveForX;
  p1_.y += moveForY;
  p2_.x += moveForX;
  p2_.y += moveForY;
  p3_.x += moveForX;
  p3_.y += moveForY;
  p4_.x += moveForX;
  p4_.y += moveForY;
}
void kiselev::Complexquad::move(double dx, double dy) noexcept
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
void kiselev::Complexquad::scale(double k) noexcept
{
  point_t centre = this->getFrameRect().pos;
  p1_.x = centre.x + (p1_.x - centre.x) * k;
  p1_.y = centre.y + (p1_.y - centre.y) * k;
  p2_.x = centre.x + (p2_.x - centre.x) * k;
  p2_.y = centre.y + (p2_.y - centre.y) * k;
  p3_.x = centre.x + (p3_.x - centre.x) * k;
  p3_.y = centre.y + (p3_.y - centre.y) * k;
  p4_.x = centre.x + (p4_.x - centre.x) * k;
  p4_.y = centre.y + (p4_.y - centre.y) * k;
}
