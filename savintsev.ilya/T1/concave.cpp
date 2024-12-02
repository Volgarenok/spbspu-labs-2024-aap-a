#include "concave.hpp"
#include <cmath>

savintsev::Concave::Concave(point_t p1, point_t p2, point_t p3, point_t p4)
{
  double l1 = getLength(p1, p2);
  double l2 = getLength(p2, p3);
  double l3 = getLength(p3, p1);
  double largest = std::fmax(l1, std::fmax(l2, l3));
  if (largest >= (l1 + l2 + l3 - largest) || !isPointInTriangle(p1, p2, p3, p4))
  {
    throw std::invalid_argument("ERROR: Invalid argumets for Concave");
  }
  this->p1_ = p1;
  this->p2_ = p2;
  this->p3_ = p3;
  this->p4_ = p4;
}

double savintsev::Concave::getArea() const
{
  double l1 = getLength(p1_, p2_);
  double l2 = getLength(p2_, p3_);
  double l3 = getLength(p3_, p1_);
  double per = (l1 + l2 + l3) / 2.;
  double sqbig = std::sqrt(per * (per - l1) * (per - l2) * (per - l3));
  l1 = getLength(p2_, p3_);
  l2 = getLength(p3_, p4_);
  l3 = getLength(p4_, p2_);
  per = (l1 + l2 + l3) / 2.;
  return sqbig - std::sqrt(per * (per - l1) * (per - l2) * (per - l3));
}

savintsev::rectangle_t savintsev::Concave::getFrameRect() const
{
  double mostLeft = std::fmin(p1_.x, std::fmin(p2_.x, p3_.x));
  double mostRight = std::fmax(p1_.x, std::fmax(p2_.x, p3_.x));
  double mostLow = std::fmin(p1_.y, std::fmin(p2_.y, p3_.y));
  double mostHigh = std::fmax(p1_.y, std::fmax(p2_.y, p3_.y));
  return {mostRight - mostLeft, mostHigh - mostLow, p4_};
}

void savintsev::Concave::move(point_t p)
{
  double moveByX = p.x - p4_.x;
  double moveByY = p.y - p4_.y;
  this->p1_ = {p1_.x + moveByX, p1_.y + moveByY};
  this->p2_ = {p2_.x + moveByX, p2_.y + moveByY};
  this->p3_ = {p3_.x + moveByX, p3_.y + moveByY};
  this->p4_ = {p4_.x + moveByX, p4_.y + moveByY};
}

void savintsev::Concave::move(double x, double y)
{
  this->p1_ = {p1_.x + x, p1_.y + y};
  this->p2_ = {p2_.x + x, p2_.y + y};
  this->p3_ = {p3_.x + x, p3_.y + y};
  this->p4_ = {p4_.x + x, p4_.y + y};
}

void savintsev::Concave::scale(double k)
{
  if (k <= 0)
  {
    return;
  }
  this->p1_ = {p4_.x - (p4_.x - p1_.x) * k, p4_.y - (p4_.y - p1_.y) * k};
  this->p2_ = {p4_.x - (p4_.x - p2_.x) * k, p4_.y - (p4_.y - p2_.y) * k};
  this->p3_ = {p4_.x - (p4_.x - p3_.x) * k, p4_.y - (p4_.y - p3_.y) * k};
}