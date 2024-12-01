#include "rectangle.hpp"
#include <cmath>

savintsev::Rectangle::Rectangle(point_t pLL, point_t pUR) :
  pLowLeft_(pLL),
  pUpRight_(pUR)
{}

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
  point_t center = this->getFrameRect().pos;
  double moveByX = p.x - center.x;
  double moveByY = p.y - center.y;
  this->pLowLeft_ = {this->pLowLeft_.x + moveByX, this->pLowLeft_.y + moveByY};
  this->pUpRight_ = {this->pUpRight_.x + moveByX, this->pUpRight_.y + moveByY};
}

void savintsev::Rectangle::move(double x, double y)
{
  this->pLowLeft_ = {this->pLowLeft_.x + x, this->pLowLeft_.y + y};
  this->pUpRight_ = {this->pUpRight_.x + x, this->pUpRight_.y + y};
}

void savintsev::Rectangle::scale(point_t, double k)
{}
