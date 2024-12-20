#include "rectangle.hpp"
#include <cmath>
#include <stdexcept>

savintsev::Rectangle::Rectangle(point_t lhs, point_t rhs) :
  pLowLeft_(lhs),
  pUpRight_(rhs)
{
  if (pLowLeft_.x >= pUpRight_.x || pLowLeft_.y >= pUpRight_.y)
  {
    throw std::invalid_argument("ERROR: Invalid argumets for Rectangle");
  }
}

double savintsev::Rectangle::getArea() const
{
  return (pUpRight_.y - pLowLeft_.y) * (pUpRight_.x - pLowLeft_.x);
}

savintsev::rectangle_t savintsev::Rectangle::getFrameRect() const
{
  double centerByX = pLowLeft_.x + ((pUpRight_.x - pLowLeft_.x) / 2.);
  double centerByY = pLowLeft_.y + ((pUpRight_.y - pLowLeft_.y) / 2.);
  return {pUpRight_.x - pLowLeft_.x, pUpRight_.y - pLowLeft_.y, {centerByX, centerByY}};
}

void savintsev::Rectangle::move(point_t p)
{
  point_t center = getFrameRect().pos;
  double moveByX = p.x - center.x;
  double moveByY = p.y - center.y;
  this->pLowLeft_ = {pLowLeft_.x + moveByX, pLowLeft_.y + moveByY};
  this->pUpRight_ = {pUpRight_.x + moveByX, pUpRight_.y + moveByY};
}

void savintsev::Rectangle::move(double x, double y)
{
  this->pLowLeft_ = {pLowLeft_.x + x, pLowLeft_.y + y};
  this->pUpRight_ = {pUpRight_.x + x, pUpRight_.y + y};
}

void savintsev::Rectangle::scale(double k)
{
  if (k <= 0)
  {
    return;
  }
  point_t center = getFrameRect().pos;
  this->pLowLeft_ = {center.x - (center.x - pLowLeft_.x) * k, center.y - (center.y - pLowLeft_.y) * k};
  this->pUpRight_ = {center.x + (pUpRight_.x - center.x) * k, center.y + (pUpRight_.y - center.y) * k};
}
