#include "composite-shape.hpp"
#include <stdexcept>
#include <cmath>
#include <lrgcpy.hpp>

savintsev::CompositeShape::~CompositeShape()
{
  destroy(lst_, amt_);
}

savintsev::CompositeShape::CompositeShape(size_t capacity):
  lst_(nullptr),
  amt_(0),
  cap_(capacity)
{
  lst_ = new Shape * [cap_];
}

savintsev::CompositeShape::CompositeShape(const CompositeShape & rhs)
{
  Shape ** new_lst = createAmpCopy(rhs.lst_, rhs.cap_, rhs.cap_);
  lst_ = new_lst;
  amt_ = rhs.amt_;
  cap_ = rhs.cap_;
}

savintsev::CompositeShape::CompositeShape(CompositeShape && rhs)
{
  lst_ = rhs.lst_;
  amt_ = rhs.amt_;
  cap_ = rhs.cap_;
  rhs.lst_ = nullptr;
}

savintsev::CompositeShape & savintsev::CompositeShape::operator=(const CompositeShape & rhs)
{
  if (&rhs != this)
  {
    Shape ** new_lst = createAmpCopy(rhs.lst_, rhs.cap_, rhs.cap_);
    destroy(lst_, amt_);
    lst_ = new_lst;
    amt_ = rhs.amt_;
    cap_ = rhs.cap_;
  }
  return *this;
}

savintsev::CompositeShape & savintsev::CompositeShape::operator=(CompositeShape && rhs)
{
  if (&rhs != this)
  {
    lst_ = rhs.lst_;
    amt_ = rhs.amt_;
    cap_ = rhs.cap_;
    rhs.lst_ = nullptr;
  }
  return *this;
}

double savintsev::CompositeShape::getArea() const
{
  double area = 0.0;
  for (size_t i = 0; i < amt_; ++i)
  {
    area += lst_[i]->getArea();
  }
  return area;
}

savintsev::rectangle_t savintsev::CompositeShape::getFrameRect() const
{
  double lx = NAN;
  double rx = NAN;
  double ly = NAN;
  double ry = NAN;
  for (size_t i = 0; i < amt_; ++i)
  {
    double height = lst_[i]->getFrameRect().height;
    double width = lst_[i]->getFrameRect().width;
    point_t center = lst_[i]->getFrameRect().pos;
    lx = std::fmin(lx, center.x - width / 2);
    ly = std::fmin(ly, center.y - height / 2);
    rx = std::fmax(rx, center.x + width / 2);
    ry = std::fmax(ry, center.y + height / 2);
  }
  return {rx - lx, ry - ly, {(rx + lx) / 2, (ry + ly) / 2}};
}

void savintsev::CompositeShape::move(point_t p)
{
  double moveByX = p.x - getFrameRect().pos.x;
  double moveByY = p.y - getFrameRect().pos.y;
  for (size_t i = 0; i < amt_; ++i)
  {
    lst_[i]->move(moveByX, moveByY);
  }
}

void savintsev::CompositeShape::move(double x, double y)
{
  for (size_t i = 0; i < amt_; ++i)
  {
    lst_[i]->move(x, y);
  }
}

void savintsev::CompositeShape::scale(double k)
{
  if (k <= 0)
  {
    return;
  }
  point_t center = getFrameRect().pos;
  for (size_t i = 0; i < amt_; ++i)
  {
    point_t jFirst = lst_[i]->getFrameRect().pos;
    lst_[i]->move(center);
    point_t jSecond = lst_[i]->getFrameRect().pos;
    point_t vector = {(jSecond.x - jFirst.x) * k, (jSecond.y - jFirst.y) * k};
    lst_[i]->scale(k);
    lst_[i]->move(-vector.x, -vector.y);
  }
}

savintsev::CompositeShape::CompositeShape(): CompositeShape(1)
{}

void savintsev::CompositeShape::push_back(Shape * shp)
{
  if (amt_ + 1 == cap_)
  {
    Shape ** new_lst = createAmpCopy(lst_, cap_, cap_ + cap_);
    if (!new_lst)
    {
      throw std::bad_alloc();
    }
    destroy(lst_, amt_);
    lst_ = new_lst;
    cap_ = cap_ + cap_;
  }
  lst_[amt_++] = shp;
}

void savintsev::CompositeShape::pop_back() noexcept
{
  delete lst_[--amt_];
}

savintsev::Shape * savintsev::CompositeShape::at(size_t id) const
{
  if (id >= amt_)
  {
    throw std::out_of_range("ERROR: Out of range");
  }
  return lst_[id];
}

savintsev::Shape * savintsev::CompositeShape::operator[](size_t id) const noexcept
{
  return lst_[id];
}

bool savintsev::CompositeShape::empty() const
{
  return (amt_ == 0);
}

size_t savintsev::CompositeShape::size() const
{
  return amt_;
}

void savintsev::CompositeShape::destroy(Shape ** shps, size_t n)
{
  for (size_t i = 0; i < n; ++i)
  {
    delete shps[i];
  }
  delete shps;
}
