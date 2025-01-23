#include "concave.hpp"
#include <cmath>
#include <stdexcept>
#include "geometry-utils.hpp"

savintsev::Concave::Concave(point_t p1, point_t p2, point_t p3, point_t p4):
  p1_(p1),
  p2_(p2),
  p3_(p3),
  p4_(p4)
{
  if (!isTriangle(p1_, p2_, p3_) || !isPointInTriangle(p1_, p2_, p3_, p4_))
  {
    throw std::invalid_argument("ERROR: Invalid argumets for Concave");
  }
}

double savintsev::Concave::getArea() const
{
  return getTriangleArea(p1_, p2_, p3_) - getTriangleArea(p2_, p3_, p4_);
}

savintsev::rectangle_t savintsev::Concave::getFrameRect() const
{
  double mostLeft = std::fmin(p1_.x, std::fmin(p2_.x, p3_.x));
  double mostRight = std::fmax(p1_.x, std::fmax(p2_.x, p3_.x));
  double mostLow = std::fmin(p1_.y, std::fmin(p2_.y, p3_.y));
  double mostHigh = std::fmax(p1_.y, std::fmax(p2_.y, p3_.y));
  point_t center = {mostLeft + (mostRight - mostLeft) / 2, mostLow + (mostHigh - mostLow) / 2};
  return {mostRight - mostLeft, mostHigh - mostLow, center};
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

savintsev::Shape * savintsev::Concave::clone() const
{
  return new Concave(*this);
}

void savintsev::Concave::unsafeScale(double k) noexcept
{
  this->p1_ = {p4_.x - (p4_.x - p1_.x) * k, p4_.y - (p4_.y - p1_.y) * k};
  this->p2_ = {p4_.x - (p4_.x - p2_.x) * k, p4_.y - (p4_.y - p2_.y) * k};
  this->p3_ = {p4_.x - (p4_.x - p3_.x) * k, p4_.y - (p4_.y - p3_.y) * k};
}
