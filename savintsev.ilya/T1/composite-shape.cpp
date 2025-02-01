#include "composite-shape.hpp"
#include <stdexcept>
#include <memory>
#include <iomanip>
#include <cmath>
#include <lrgcpy.hpp>

savintsev::CompositeShape::~CompositeShape()
{
  destroy(lst_, amt_);
}

savintsev::CompositeShape::CompositeShape(size_t capacity):
  amt_(0),
  cap_(capacity),
  lst_(new Shape * [cap_])
{}

savintsev::CompositeShape::CompositeShape(const CompositeShape & rhs):
  amt_(rhs.amt_),
  cap_(rhs.cap_),
  lst_(new Shape * [rhs.cap_])
{
  size_t created = 0;
  try
  {
    for (size_t i = 0; i < amt_; ++i)
    {
      lst_[i] = rhs.lst_[i]->clone();
      created++;
    }
  }
  catch (const std::bad_alloc & e)
  {
    destroy(lst_, created);
    throw;
  }
}

savintsev::CompositeShape::CompositeShape(CompositeShape && rhs) noexcept:
  amt_(rhs.amt_),
  cap_(rhs.cap_),
  lst_(rhs.lst_)
{
  rhs.lst_ = nullptr;
  rhs.amt_ = 0;
  rhs.cap_ = 0;
}

savintsev::CompositeShape & savintsev::CompositeShape::operator=(const CompositeShape & rhs)
{
  if (std::addressof(rhs) == this)
  {
    return *this;
  }
  Shape ** new_lst = new Shape * [rhs.cap_];
  size_t created = 0;
  try
  {
    for (size_t i = 0; i < amt_; ++i)
    {
      new_lst[i] = rhs.lst_[i]->clone();
      created++;
    }
  }
  catch (const std::bad_alloc & e)
  {
    destroy(new_lst, created);
    throw;
  }
  destroy(lst_, amt_);
  amt_ = rhs.amt_;
  cap_ = rhs.cap_;
  lst_ = new_lst;
  return *this;
}

savintsev::CompositeShape & savintsev::CompositeShape::operator=(CompositeShape && rhs) noexcept
{
  if (std::addressof(rhs) == this)
  {
    return *this;
  }
  destroy(lst_, amt_);
  amt_ = rhs.amt_;
  cap_ = rhs.cap_;
  lst_ = rhs.lst_;
  rhs.lst_ = nullptr;
  rhs.amt_ = 0;
  rhs.cap_ = 0;
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

savintsev::rectangle_t savintsev::CompositeShape::getFrameRect() const noexcept
{
  rectangle_t rect = lst_[0]->getFrameRect();
  double xmin = rect.pos.x - rect.width / 2;
  double xmax = rect.pos.x + rect.width / 2;
  double ymin = rect.pos.y - rect.height / 2;
  double ymax = rect.pos.y + rect.height / 2;
  for (size_t i = 1; i < amt_; ++i)
  {
    rect = lst_[i]->getFrameRect();
    xmin = std::fmin(xmin, rect.pos.x - rect.width / 2);
    xmax = std::fmax(xmax, rect.pos.x + rect.width / 2);
    ymin = std::fmin(ymin, rect.pos.y - rect.height / 2);
    ymax = std::fmax(ymax, rect.pos.y + rect.height / 2);
  }
  return {xmax - xmin, ymax - ymin, {(xmax + xmin) / 2, (ymax + ymin) / 2}};
}

savintsev::rectangle_t savintsev::CompositeShape::safeGetFrameRect() const
{
  if (empty())
  {
    throw std::logic_error("ERROR: CompositeShape is empty");
  }
  return getFrameRect();
}

void savintsev::CompositeShape::move(point_t p)
{
  double moveByX = p.x - getFrameRect().pos.x;
  double moveByY = p.y - getFrameRect().pos.y;
  move(moveByX, moveByY);
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
    throw std::invalid_argument("ERROR: Invalid ratio");
  }
  unsafeScale(k);
}

void savintsev::CompositeShape::unsafeScale(double k) noexcept
{
  unsafeScaleRelativeTo(k, getFrameRect().pos);
}

savintsev::CompositeShape * savintsev::CompositeShape::clone() const
{
  return new CompositeShape(*this);
}

void savintsev::CompositeShape::scaleRelativeTo(double k, point_t p)
{
  if (k <= 0)
  {
    throw std::invalid_argument("ERROR: Invalid ratio");
  }
  unsafeScaleRelativeTo(k, p);
}

void savintsev::CompositeShape::unsafeScaleRelativeTo(double k, point_t p) noexcept
{
  point_t center = p;
  for (size_t i = 0; i < amt_; ++i)
  {
    point_t jFirst = lst_[i]->getFrameRect().pos;
    lst_[i]->move(center);
    point_t jSecond = lst_[i]->getFrameRect().pos;
    point_t vector = {(jSecond.x - jFirst.x) * k, (jSecond.y - jFirst.y) * k};
    lst_[i]->unsafeScale(k);
    lst_[i]->move(-vector.x, -vector.y);
  }
}

savintsev::CompositeShape::CompositeShape():
  CompositeShape(1)
{}

void savintsev::CompositeShape::push_back(Shape * shp)
{
  if (amt_ + 1 == cap_)
  {
    Shape ** new_lst = createExpandCopy(lst_, cap_, cap_ + cap_);
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

const savintsev::Shape * savintsev::CompositeShape::at(size_t id) const
{
  if (id >= amt_)
  {
    throw std::out_of_range("ERROR: Out of range");
  }
  return lst_[id];
}

savintsev::Shape * savintsev::CompositeShape::at(size_t id)
{
  if (id >= amt_)
  {
    throw std::out_of_range("ERROR: Out of range");
  }
  return lst_[id];
}

const savintsev::Shape * savintsev::CompositeShape::operator[](size_t id) const noexcept
{
  return lst_[id];
}

savintsev::Shape * savintsev::CompositeShape::operator[](size_t id) noexcept
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
  delete[] shps;
}

void savintsev::printAreaAndBorder(std::ostream & out, const CompositeShape & rhs)
{
  out << std::fixed << std::setprecision(1) << rhs.getArea();
  for (size_t i = 0; i < rhs.size(); ++i)
  {
    rectangle_t rect = rhs[i]->getFrameRect();
    point_t lowLeft = {rect.pos.x - rect.width / 2, rect.pos.y - rect.height / 2};
    point_t upRight = {rect.pos.x + rect.width / 2, rect.pos.y + rect.height / 2};
    out << ' ' << lowLeft.x << ' ' << lowLeft.y << ' ' << upRight.x << ' ' << upRight.y;
  }
  out << '\n';
}
