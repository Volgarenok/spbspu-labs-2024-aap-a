#include "rectangle.hpp"
#include <cmath>
#include <stdexcept>

savintsev::Rectangle::Rectangle(point_t lhs, point_t rhs):
  stay_(nullptr),
  lay_(nullptr)
{
  if (lhs.x >= rhs.x || lhs.y >= rhs.y)
  {
    throw std::invalid_argument("ERROR: Invalid argumets for Rectangle");
  }
  try
  {
    stay_ = new Complexquad(lhs, rhs, {lhs.x, rhs.y}, {rhs.x, lhs.y});
    lay_ = new Complexquad(lhs, rhs, {rhs.x, lhs.y}, {lhs.x, rhs.y});
  }
  catch(const std::bad_alloc & e)
  {
    delete stay_;
  }
}

savintsev::Rectangle::~Rectangle()
{
  delete stay_;
  delete lay_;
}

double savintsev::Rectangle::getArea() const
{
  return stay_->getArea() + lay_->getArea();
}

savintsev::rectangle_t savintsev::Rectangle::getFrameRect() const
{
  return stay_->getFrameRect();
}

void savintsev::Rectangle::move(point_t p)
{
  this->stay_->move(p);
  this->lay_->move(p);
}

void savintsev::Rectangle::move(double x, double y)
{
  this->stay_->move(x, y);
  this->lay_->move(x, y);
}

void savintsev::Rectangle::doScale(double k)
{
  this->stay_->scale(k);
  this->lay_->scale(k);
}
