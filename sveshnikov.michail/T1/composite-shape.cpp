#include "composite-shape.hpp"
#include <stdexcept>
#include <algorithm>

sveshnikov::CompositeShape::CompositeShape():
  size_(0),
  shapes_(new Shape *[10000]())
{}

sveshnikov::CompositeShape::CompositeShape(const CompositeShape &copied_shp):
  size_(0),
  shapes_(new Shape *[10000])
{
  try
  {
    for (size_t i = 0; i < copied_shp.size_; i++)
    {
      push_back(copied_shp.shapes_[i]->clone());
    }
  }
  catch (const std::exception &e)
  {
    clear();
    throw;
  }
}

sveshnikov::CompositeShape::CompositeShape(CompositeShape &&copied_shp):
  size_(copied_shp.size_),
  shapes_(copied_shp.shapes_)
{
  copied_shp.shapes_ = nullptr;
}

sveshnikov::CompositeShape::~CompositeShape()
{
  clear();
}

sveshnikov::CompositeShape &sveshnikov::CompositeShape::operator=(const CompositeShape &comp_shp)
{
  if (this != std::addressof(comp_shp))
  {
    CompositeShape rhs(comp_shp);
    swap(rhs);
  }
  return *this;
}

sveshnikov::CompositeShape &sveshnikov::CompositeShape::operator=(CompositeShape &&comp_shp)
{
  if (this != std::addressof(comp_shp))
  {
    CompositeShape temp(std::move(comp_shp));
    swap(comp_shp);
  }
  return *this;
}

sveshnikov::Shape *sveshnikov::CompositeShape::operator[](size_t id) noexcept
{
  return const_cast< Shape * >(static_cast< const CompositeShape & >(*this)[id]);
}

const sveshnikov::Shape *sveshnikov::CompositeShape::operator[](size_t id) const noexcept
{
  return shapes_[id];
}

sveshnikov::Shape *sveshnikov::CompositeShape::at(size_t id)
{
  return const_cast< Shape * >(static_cast< const CompositeShape * >(this)->at(id));
}

const sveshnikov::Shape *sveshnikov::CompositeShape::at(size_t id) const
{
  if (id >= size_)
  {
    throw std::logic_error("ERROR: id out of range!");
  }
  return shapes_[id];
}

void sveshnikov::CompositeShape::push_back(Shape *shp)
{
  if (size_ + 1 > 10000)
  {
    throw std::logic_error("ERROR: the composition is filled in!");
  }
  shapes_[size_] = shp;
  size_++;
}

void sveshnikov::CompositeShape::pop_back()
{
  if (empty())
  {
    throw std::logic_error("ERROR: the composition is empty!");
  }
  delete shapes_[--size_];
}

bool sveshnikov::CompositeShape::empty() const noexcept
{
  return size_ == 0;
}

size_t sveshnikov::CompositeShape::size() const noexcept
{
  return size_;
}

sveshnikov::CompositeShape *sveshnikov::CompositeShape::clone() const
{
  return new CompositeShape(*this);
}

double sveshnikov::CompositeShape::getArea() const noexcept
{
  double total_area = 0.0;
  for (size_t i = 0; i != size_; i++)
  {
    total_area += shapes_[i]->getArea();
  }
  return total_area;
}

sveshnikov::rectangle_t sveshnikov::CompositeShape::getFrameRect() const
{
  if (empty())
  {
    throw std::logic_error("Composite-shape is empty!");
  }
  rectangle_t frame0 = shapes_[0]->getFrameRect();
  double low_left_x = frame0.pos.x - frame0.width / 2;
  double low_left_y = frame0.pos.y - frame0.height / 2;
  double up_right_x = frame0.pos.x + frame0.width / 2;
  double up_right_y = frame0.pos.y + frame0.height / 2;
  for (size_t i = 0; i != size_; i++)
  {
    rectangle_t frame = shapes_[i]->getFrameRect();
    low_left_x = std::min(low_left_x, frame.pos.x - frame.width / 2);
    low_left_y = std::min(low_left_y, frame.pos.y - frame.height / 2);
    up_right_x = std::max(up_right_x, frame.pos.x + frame.width / 2);
    up_right_y = std::max(up_right_y, frame.pos.y + frame.height / 2);
  }
  double width = up_right_x - low_left_x;
  double height = up_right_y - low_left_y;
  point_t center = {low_left_x + width / 2, low_left_y + height / 2};
  return {width, height, center};
}

void sveshnikov::CompositeShape::move(point_t p)
{
  point_t center = getFrameRect().pos;
  double dx = p.x - center.x;
  double dy = p.y - center.y;
  move(dx, dy);
}

void sveshnikov::CompositeShape::move(double dx, double dy) noexcept
{
  for (size_t i = 0; i != size_; i++)
  {
    shapes_[i]->move(dx, dy);
  }
}

void sveshnikov::CompositeShape::scale(double k)
{
  if (k < 0)
  {
    throw std::logic_error("ERROR: zoom coefficient must be positive!");
  }
  unsafeScale(k);
}

void sveshnikov::CompositeShape::unsafeScale(double k)
{
  point_t center = getFrameRect().pos;
  for (size_t i = 0; i != size_; i++)
  {
    point_t pos = shapes_[i]->getFrameRect().pos;
    shapes_[i]->move(center);
    shapes_[i]->unsafeScale(k);
    double dx = k * (pos.x - center.x);
    double dy = k * (pos.y - center.y);
    shapes_[i]->move(dx, dy);
  }
}

void sveshnikov::CompositeShape::clear()
{
  while (size_ > 0)
  {
    pop_back();
  }
  delete[] shapes_;
}

void sveshnikov::CompositeShape::swap(CompositeShape &rhs) noexcept
{
  std::swap(size_, rhs.size_);
  std::swap(shapes_, rhs.shapes_);
}
