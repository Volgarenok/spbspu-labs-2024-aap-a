#include "composite_shape.hpp"
#include <cmath>
#include <cstddef>
#include <stdexcept>

void evstyunichev::CompositeShape::clear() noexcept
{
  for (size_t i = 0; i < size_; ++i)
  {
    delete shapes_[i];
  }
  delete[] shapes_;
}

void evstyunichev::CompositeShape::swap(CompositeShape &cmp) noexcept
{
  std::swap(shapes_, cmp.shapes_);
  std::swap(mxSize_, cmp.mxSize_);
  std::swap(size_, cmp.size_);
  std::swap(totalSquare_, cmp.totalSquare_);
}

void evstyunichev::CompositeShape::resize(size_t size)
{
  CompositeShape newCmp(size);
  for (size_t i = 0; i < size_; i++, newCmp.size_++)
  {
    newCmp.shapes_[i] = shapes_[i]->copy();
  }
  newCmp.totalSquare_ = totalSquare_;
  swap(newCmp);
}

evstyunichev::CompositeShape::CompositeShape(size_t mx):
  mxSize_(mx),
  size_(0),
  totalSquare_(0),
  shapes_(new Shape*[mxSize_])
{
}

evstyunichev::CompositeShape::CompositeShape(const CompositeShape &cmp):
  mxSize_(cmp.mxSize_),
  totalSquare_(cmp.totalSquare_),
  shapes_(new Shape*[mxSize_])
{
  size_ = 0;
  try
  {
    for (; size_ < mxSize_; size_++)
    {
      shapes_[size_] = cmp[size_]->copy();
    }
  }
  catch (const std::bad_alloc &e)
  {
    clear();
    throw;
  }
}

evstyunichev::CompositeShape::CompositeShape(CompositeShape &&cmp) noexcept:
  mxSize_(cmp.mxSize_),
  size_(cmp.size_),
  totalSquare_(cmp.totalSquare_),
  shapes_(cmp.shapes_)
{
  cmp.shapes_ = nullptr;
  cmp.size_ = 0;
  cmp.mxSize_ = 0;
  cmp.totalSquare_ = 0;
}

evstyunichev::CompositeShape & evstyunichev::CompositeShape::operator=(const CompositeShape &cmp)
{
  CompositeShape cpy(cmp);
  swap(cpy);
  return *this;
}

evstyunichev::CompositeShape & evstyunichev::CompositeShape::operator=(CompositeShape &&cmp) noexcept
{
  clear();
  shapes_ = cmp.shapes_;
  mxSize_ = cmp.mxSize_;
  size_ = cmp.size_;
  totalSquare_ = cmp.totalSquare_;
  cmp.shapes_ = nullptr;
  cmp.size_ = 0;
  cmp.mxSize_ = 0;
  cmp.totalSquare_ = 0;
  return *this;
}

void evstyunichev::CompositeShape::pushBack(Shape *shp)
{
  if (size_ >= mxSize_)
  {
    const size_t newMxSize = mxSize_ * 2 + 1;
    resize(newMxSize);
  }
  shapes_[size_++] = shp;
  totalSquare_ += shp->getArea();
}

void evstyunichev::CompositeShape::popBack()
{
  if (empty())
  {
    throw std::out_of_range("No shapes");
  }
  delete shapes_[size_];
  size_--;
}

const evstyunichev::Shape * evstyunichev::CompositeShape::at(size_t id) const
{
  if (id >= size_)
  {
    throw std::out_of_range("out of range");
  }
  return shapes_[id];
}

evstyunichev::Shape * evstyunichev::CompositeShape::at(size_t id)
{
  return const_cast< Shape * >(static_cast< const CompositeShape & >(*this).at(id));
}

const evstyunichev::Shape * evstyunichev::CompositeShape::operator[](size_t id) const noexcept
{
  return shapes_[id];
}

evstyunichev::Shape * evstyunichev::CompositeShape::operator[](size_t id) noexcept
{
  return const_cast< Shape * >(static_cast< const CompositeShape & >(*this).operator[](id));
}

bool evstyunichev::CompositeShape::empty() const noexcept
{
  return size_ == 0;
}

size_t evstyunichev::CompositeShape::size() const noexcept
{
  return size_;
}

double evstyunichev::CompositeShape::getArea() const
{
  return totalSquare_;
}

evstyunichev::rectangle_t evstyunichev::CompositeShape::getFrameRect() const
{
  if (empty())
  {
    throw std::logic_error("There are no figures");
  }
  double left = 0, right = 0, down = 0, up = 0;
  for (size_t i = 0; i < size_; i++)
  {
    const double width = shapes_[i]->getFrameRect().width;
    const double height = shapes_[i]->getFrameRect().height;
    point_t middle = shapes_[i]->getFrameRect().pos;
    left = std::min(left, middle.x - width / 2.0);
    down = std::min(down, middle.y - height / 2.0);
    right = std::max(right, middle.x + width / 2.0);
    up = std::max(up, middle.y + height / 2.0);
  }
  return { right - left, up - down, { (right + left) / 2, (up + down) / 2 } };
}

void evstyunichev::CompositeShape::scale(double k, point_t target)
{
  if (k <= 0)
  {
    throw std::logic_error("not positive k!");
  }
  for (size_t i = 0; i < size_; ++i)
  {
    point_t old = shapes_[i]->getFrameRect().pos;
    shapes_[i]->move(target);
    point_t cur = shapes_[i]->getFrameRect().pos;
    shapes_[i]->scale(k);
    shapes_[i]->move(-k * (cur.x - old.x), -k * (cur.y - old.y));
  }
  totalSquare_ = totalSquare_ * k * k;
}

evstyunichev::CompositeShape::~CompositeShape()
{
  clear();
}

evstyunichev::CompositeShape* evstyunichev::CompositeShape::copy() const
{
  return new CompositeShape(*this);
}
