#include "composite-shape.hpp"
#include <stdexcept>
#include "shape_transformations.hpp"

abramov::CompositeShape::CompositeShape(size_t capacity):
  shapes_(0),
  capacity_(capacity),
  shapeptrs_(nullptr)
{
  shapeptrs_ = new Shape*[capacity];
  for (size_t i = 0; i < capacity; ++i)
  {
    shapeptrs_[i] = nullptr;
  }
}

abramov::CompositeShape::CompositeShape(const CompositeShape &comp_shp):
  shapes_(comp_shp.shapes_),
  capacity_(comp_shp.capacity_),
  shapeptrs_(nullptr)
{
  shapeptrs_ = new Shape*[capacity_];
  for (size_t i = 0; i < shapes_; ++i)
  {
    shapeptrs_[i] = comp_shp.shapeptrs_[i];
  }
}

abramov::CompositeShape::~CompositeShape()
{
  for (size_t i = 0; i < shapes_; ++i)
  {
    delete shapeptrs_[i];
  }
  delete[] shapeptrs_;
}

abramov::CompositeShape::CompositeShape(abramov::CompositeShape &&comp_shp) noexcept:
  shapes_(comp_shp.shapes_),
  capacity_(comp_shp.capacity_),
  shapeptrs_(comp_shp.shapeptrs_)
{
  comp_shp.shapeptrs_ = nullptr;
  comp_shp.shapes_ = 0;
  comp_shp.capacity_ = 0;
}

abramov::CompositeShape &abramov::CompositeShape::operator=(const abramov::CompositeShape &comp_shp)
{
  if (&comp_shp != this)
  {
    Shape **arr = new Shape*[comp_shp.capacity_];
    for (size_t i = 0; i < comp_shp.capacity_; ++i)
    {
      arr[i] = comp_shp.shapeptrs_[i];
    }
    delete[] shapeptrs_;
    shapeptrs_ = arr;
    shapes_ = comp_shp.shapes_;
    capacity_ = comp_shp.capacity_;
  }
  return *this;
}

abramov::CompositeShape &abramov::CompositeShape::operator=(abramov::CompositeShape &&comp_shp) noexcept
{
  if (&comp_shp != this)
  {
    delete[] shapeptrs_;
    shapeptrs_ = comp_shp.shapeptrs_;
    comp_shp.shapeptrs_ = nullptr;
  }
  return *this;
}

double abramov::CompositeShape::getArea() const noexcept
{
  double area = 0;
  for (size_t i = 0; i < shapes_; ++i)
  {
    area += shapeptrs_[i]->getArea();
  }
  return area;
}

void abramov::getRectCoords(rectangle_t rect, double &x1, double &y1, double &x2, double &y2)
{
  x1 = std::min(x1, rect.pos.x - rect.width / 2);
  x2 = std::max(x2, rect.pos.x + rect.width / 2);
  y1 = std::min(y1, rect.pos.y - rect.height / 2);
  y2 = std::max(y2, rect.pos.y + rect.height / 2);
}

abramov::rectangle_t abramov::CompositeShape::getFrameRect() const noexcept
{
  if (shapes_ == 0)
  {
    return rectangle_t{0.0, 0.0, {0.0, 0.0}};
  }
  double x1 = 0;
  double x2 = 0;
  double y1 = 0;
  double y2 = 0;
  for (size_t i = 0; i < shapes_; ++i)
  {
    getRectCoords(shapeptrs_[i]->getFrameRect(), x1, y1, x2, y2);
  }
  rectangle_t rect{x2 - x1, y2 - y1, {(x2 + x1) / 2, (y2 + y1) / 2}};
  return rect;
}

abramov::rectangle_t abramov::CompositeShape::getFrameRect(size_t id) const noexcept
{
  return shapeptrs_[id]->getFrameRect();
}

void abramov::CompositeShape::move(point_t p)
{
  const double dx = p.x - getFrameRect().pos.x;
  const double dy = p.y - getFrameRect().pos.y;
  move(dx, dy);
}

void abramov::CompositeShape::move(double dx, double dy)
{
  for (size_t i = 0; i < shapes_; ++i)
  {
    shapeptrs_[i]->move(dx, dy);
  }
}

void abramov::CompositeShape::scale(double k)
{
  if (k <= 0)
  {
    throw std::logic_error("Wrong scale coef\n");
  }
  for (size_t i = 0; i < shapes_; ++i)
  {
    scaleFigure(shapeptrs_[i], getFrameRect().pos, k);
  }
}

void abramov::CompositeShape::push_back(Shape *shp)
{
  if (capacity_ == shapes_)
  {
    Shape **new_shapeptrs = expandArray(shapeptrs_, capacity_);
    if (new_shapeptrs == nullptr)
    {
      throw std::bad_alloc();
    }
    capacity_ *= 2;
    delete[] shapeptrs_;
    shapeptrs_ = new_shapeptrs;
  }
  shapeptrs_[shapes_++] = shp;
}

void abramov::CompositeShape::pop_back() noexcept
{
  delete shapeptrs_[shapes_];
  shapeptrs_[shapes_] = nullptr;
}

abramov::Shape *abramov::CompositeShape::at(size_t id)
{
  if (id >= shapes_)
  {
    throw std::logic_error("There is no such element\n");
  }
  return shapeptrs_[id];
}

abramov::Shape *abramov::CompositeShape::at(size_t id) const
{
  if (id >= shapes_)
  {
    throw std::logic_error("There is no such element\n");
  }
  return shapeptrs_[id];
}

abramov::Shape *abramov::CompositeShape::operator[](size_t id) noexcept
{
  return shapeptrs_[id];
}

abramov::Shape *abramov::CompositeShape::operator[](size_t id) const noexcept
{
  return shapeptrs_[id];
}

bool abramov::CompositeShape::empty() const noexcept
{
  return (shapes_ == 0);
}

size_t abramov::CompositeShape::size() const noexcept
{
  return shapes_;
}

abramov::CompositeShape *abramov::CompositeShape::clone() const
{
  try
  {
    return new CompositeShape(*this);
  }
  catch (std::bad_alloc &e)
  {
    return nullptr;
  }
}

size_t abramov::CompositeShape::getShapes_() const noexcept
{
  return shapes_;
}

abramov::Shape **abramov::expandArray(Shape **arr, size_t capacity)
{
  Shape **array = nullptr;
  try
  {
    array = new Shape*[capacity * 2];
  }
  catch (const std::bad_alloc &e)
  {
    return nullptr;
  }
  for (size_t i = 0; i < capacity; ++i)
  {
    array[i] = arr[i];
  }
  return array;
}
