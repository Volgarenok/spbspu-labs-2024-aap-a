#include "composite-shape.hpp"
#include <stdexcept>
#include <memory>
#include <algorithm>
#include "shape_transformations.hpp"

namespace
{
  void getRectCoords(abramov::rectangle_t rect, double &x1, double &y1, double &x2, double &y2)
  {
    x1 = std::min(x1, rect.pos.x - rect.width / 2);
    x2 = std::max(x2, rect.pos.x + rect.width / 2);
    y1 = std::min(y1, rect.pos.y - rect.height / 2);
    y2 = std::max(y2, rect.pos.y + rect.height / 2);
  }
}

void abramov::CompositeShape::deleteShapes(size_t k)
{
  for (size_t i = 0; i < k; ++i)
  {
    delete shapeptrs_[i];
  }
  delete[] shapeptrs_;
}

abramov::CompositeShape::CompositeShape(size_t capacity):
  shapes_(0),
  capacity_(capacity),
  shapeptrs_(new Shape*[capacity])
{}

abramov::CompositeShape::CompositeShape(const CompositeShape &comp_shp):
  shapes_(comp_shp.shapes_),
  capacity_(comp_shp.capacity_),
  shapeptrs_(new Shape*[capacity_])
{
  size_t k = 0;
  try
  {
    while (k < shapes_)
    {
      shapeptrs_[k] = comp_shp.shapeptrs_[k]->clone();
      ++k;
    }
  }
  catch (const std::bad_alloc&)
  {
    deleteShapes(k);
    throw;
  }
}

abramov::CompositeShape::~CompositeShape()
{
  deleteShapes(shapes_);
}

abramov::CompositeShape::CompositeShape(CompositeShape &&comp_shp) noexcept:
  shapes_(comp_shp.shapes_),
  capacity_(comp_shp.capacity_),
  shapeptrs_(comp_shp.shapeptrs_)
{
  comp_shp.shapeptrs_ = nullptr;
}

void abramov::CompositeShape::swap(CompositeShape &comp_shp) noexcept
{
  std::swap(shapeptrs_, comp_shp.shapeptrs_);
  std::swap(shapes_, comp_shp.shapes_);
  std::swap(capacity_, comp_shp.capacity_);
}

abramov::CompositeShape &abramov::CompositeShape::operator=(const CompositeShape &comp_shp)
{
  CompositeShape copy{comp_shp};
  if (std::addressof(comp_shp) != this)
  {
    swap(copy);
  }
  return *this;
}

abramov::CompositeShape &abramov::CompositeShape::operator=(CompositeShape &&comp_shp) noexcept
{
  if (std::addressof(comp_shp) != this)
  {
    deleteShapes(shapes_);
    shapeptrs_ = comp_shp.shapeptrs_;
    comp_shp.shapeptrs_ = nullptr;
    shapes_ = comp_shp.shapes_;
    capacity_ = comp_shp.capacity_;
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

abramov::rectangle_t abramov::CompositeShape::getFrameRect() const
{
  if (shapes_ == 0)
  {
    throw std::logic_error("There is no frame rect\n");
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

void abramov::CompositeShape::move(const point_t &p)
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
    scaleFigureUnsafe(shapeptrs_[i], getFrameRect().pos, k);
  }
}

void abramov::CompositeShape::scaleUnsafe(double k)
{
  for (size_t i = 0; i < shapes_; ++i)
  {
    scaleFigureUnsafe(shapeptrs_[i], getFrameRect().pos, k);
  }
}

abramov::Shape **expandArray(abramov::Shape **arr, size_t capacity)
{
  abramov::Shape **array = new abramov::Shape*[capacity + 10];
  for (size_t i = 0; i < capacity; ++i)
  {
    array[i] = arr[i];
  }
  return array;
}
void abramov::CompositeShape::pushBack(Shape *shp)
{
  if (capacity_ == shapes_)
  {
    Shape **new_shapeptrs = expandArray(shapeptrs_, capacity_);
    capacity_ += 10;
    delete[] shapeptrs_;
    shapeptrs_ = new_shapeptrs;
  }
  shapeptrs_[shapes_++] = shp;
}

void abramov::CompositeShape::popBack() noexcept
{
  delete shapeptrs_[--shapes_];
  shapeptrs_[shapes_] = nullptr;
}

abramov::Shape *abramov::CompositeShape::at(size_t id)
{
  return const_cast< Shape* >(const_cast< const CompositeShape* >(this)->at(id));
}

const abramov::Shape *abramov::CompositeShape::at(size_t id) const
{
  if (id >= shapes_)
  {
    throw std::logic_error("There is no such element\n");
  }
  return shapeptrs_[id];
}

abramov::Shape *abramov::CompositeShape::operator[](size_t id) noexcept
{
  return const_cast< Shape* >(const_cast< const CompositeShape* >(this)->operator[](id));
}

const abramov::Shape *abramov::CompositeShape::operator[](size_t id) const noexcept
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
  return new CompositeShape(*this);
}

