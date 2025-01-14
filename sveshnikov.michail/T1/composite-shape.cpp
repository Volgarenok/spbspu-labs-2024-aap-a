#include "composite-shape.hpp"
#include <exception>

sveshnikov::CompositeShape::CompositeShape():
  size_(0),
  shapes_{nullptr}
{}

sveshnikov::CompositeShape::CompositeShape(const CompositeShape &copied_shp):
  size_(copied_shp.size_),
  shapes_{nullptr}
{
  for (size_t i = 0; i < size_; i++)
  {
    push_back(copied_shp.shapes_[i]->clone());
  }
}

sveshnikov::CompositeShape::CompositeShape(CompositeShape &&copied_shp):
  size_(copied_shp.size_),
  shapes_{nullptr}
{
  for (size_t i = 0; i < size_; i++)
  {
    push_back(copied_shp.shapes_[i]);
    copied_shp.shapes_[i] = nullptr;
  }
}

sveshnikov::CompositeShape::~CompositeShape()
{
  for (size_t i = 0; size_ != 0; i++)
  {
    pop_back();
  }
}

sveshnikov::CompositeShape &sveshnikov::CompositeShape::operator=(const CompositeShape &comp_shp)
{
  if (this != &comp_shp)
  {
    while (size_ > 0)
    {
      pop_back();
    }
    size_ = comp_shp.size_;
    for (size_t i = 0; i < size_; i++)
    {
      shapes_[i] = comp_shp.shapes_[i]->clone();
    }
  }
  return *this;
}

sveshnikov::CompositeShape &sveshnikov::CompositeShape::operator=(CompositeShape &&comp_shp)
{
  if (this != &comp_shp)
  {
    while (size_ > 0)
    {
      pop_back();
    }
    size_ = comp_shp.size_;
    for (size_t i = 0; i < size_; i++)
    {
      shapes_[i] = comp_shp.shapes_[i]->clone();
      comp_shp.shapes_[i] = nullptr;
    }
  }
  return *this;
}

sveshnikov::Shape *sveshnikov::CompositeShape::operator[](size_t id) noexcept
{
  return shapes_[id];
}

const sveshnikov::Shape *sveshnikov::CompositeShape::operator[](size_t id) const noexcept
{
  return shapes_[id];
}

sveshnikov::Shape *sveshnikov::CompositeShape::at(size_t id)
{
  if (id >= size_)
  {
    throw std::logic_error("ERROR: id out of range!");
  }
  return shapes_[id];
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

sveshnikov::rectangle_t sveshnikov::CompositeShape::getFrameRect() const noexcept
{
  double low_left_x = 0.0, low_left_y = 0.0, up_right_x = 0.0, up_right_y = 0.0;
  for (size_t i = 0; i != size_; i++)
  {
    rectangle_t frame = shapes_[i]->getFrameRect();
    if (low_left_x > frame.pos.x - frame.width / 2)
    {
      low_left_x = frame.pos.x - frame.width / 2;
    }
    if (low_left_y > frame.pos.y - frame.height / 2)
    {
      low_left_y = frame.pos.y - frame.height / 2;
    }
    if (up_right_x < frame.pos.x + frame.width / 2)
    {
      up_right_x = frame.pos.x + frame.width / 2;
    }
    if (up_right_y < frame.pos.y + frame.height / 2)
    {
      up_right_y = frame.pos.y + frame.height / 2;
    }
  }
  double width = up_right_x - low_left_x;
  double height = up_right_y - low_left_y;
  point_t center = {low_left_x + width / 2, low_left_y + height / 2};
  return {width, height, center};
}

void sveshnikov::CompositeShape::move(point_t p) noexcept
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
  point_t center = getFrameRect().pos;
  for (size_t i = 0; i != size_; i++)
  {
    point_t pos = shapes_[i]->getFrameRect().pos;
    shapes_[i]->move(center);
    double dx = 0.0, dy = 0.0;
    shapes_[i]->scale(k);
    dx = k * (pos.x - center.x);
    dy = k * (pos.y - center.y);
    shapes_[i]->move(dx, dy);
  }
}
