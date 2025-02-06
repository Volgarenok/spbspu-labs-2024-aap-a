#include "composite-shape.hpp"
#include <memory>
#include "additional-utilities.hpp"
nikonov::CompositeShape::CompositeShape():
  size_(0)
{
  constexpr size_t maxSize = 10000;
  for (size_t i = 0; i < maxSize; ++i)
  {
    shp_[i] = nullptr;
  }
}
nikonov::CompositeShape::CompositeShape(const CompositeShape &copy):
  size_(copy.size_)
{
  size_t realSize = 0;
  try
  {
    for (size_t i = 0; i < copy.size(); ++i)
    {
      shp_[i] = copy.shp_[i]->clone();
      ++realSize;
    }
  }
  catch (const std::exception& e)
  {
    destroy(shp_, realSize);
    throw;
  }
}
nikonov::CompositeShape::CompositeShape(CompositeShape &&copy) noexcept:
  size_(copy.size_)
{
  for (size_t i = 0; i < copy.size(); ++i)
  {
    shp_[i] = copy.shp_[i];
    copy.shp_[i] = nullptr;
  }
  copy.size_ = 0;
}
nikonov::CompositeShape::~CompositeShape()
{
  destroy(shp_, size());
}
nikonov::Shape *nikonov::CompositeShape::operator[](size_t id) noexcept
{
  return shp_[id];
}
const nikonov::Shape *nikonov::CompositeShape::operator[](size_t id) const noexcept
{
  return shp_[id];
}
nikonov::CompositeShape &nikonov::CompositeShape::operator=(const CompositeShape &another)
{
  if (std::addressof(another) != this)
  {
    CompositeShape tempObj{ another };
    swap(tempObj);
  }
  return *this;
}
nikonov::CompositeShape &nikonov::CompositeShape::operator=(CompositeShape &&another) noexcept
{
  if (std::addressof(another) != this)
  {
    CompositeShape tempObj{ std::move(another) };
    swap(tempObj);
  }
  return *this;
}
double nikonov::CompositeShape::getArea() const
{
  double sumArea = 0;
  for (size_t i = 0; i < size_; ++i)
  {
    sumArea += shp_[i]->getArea();
  }
  return sumArea;
}
nikonov::rectangle_t nikonov::CompositeShape::getFrameRect() const
{
  if (empty())
  {
    throw std::logic_error("ShapeCollection is empty");
  }
  point_t currCenter = shp_[0]->getFrameRect().pos;
  double currDivWidth = shp_[0]->getFrameRect().width / 2;
  double currDivHeight = shp_[0]->getFrameRect().height / 2;
  double minX = currCenter.x - currDivWidth;
  double minY = currCenter.y - currDivHeight;
  double maxX = currCenter.x + currDivWidth;
  double maxY = currCenter.y + currDivHeight;
  for (size_t i = 0; i < size_; ++i)
  {
    currCenter = shp_[i]->getFrameRect().pos;
    currDivWidth = shp_[i]->getFrameRect().width / 2;
    currDivHeight = shp_[i]->getFrameRect().height / 2;
    minX = std::min(minX, currCenter.x - currDivWidth);
    minY = std::min(minY, currCenter.y - currDivHeight);
    maxX = std::max(maxX, currCenter.x + currDivWidth);
    maxY = std::max(maxY, currCenter.y + currDivHeight);
  }
  double width = maxX - minX;
  double height = maxY - minY;
  return { width, height, { minX + width / 2, minY + height / 2 } };
}
void nikonov::CompositeShape::move(const point_t &a)
{
  rectangle_t crntRect = getFrameRect();
  double diffX = a.x - crntRect.pos.x;
  double diffY = a.y - crntRect.pos.y;
  move(diffX, diffY);
}
void nikonov::CompositeShape::move(double x, double y)
{
  for (size_t i = 0; i < size_; ++i)
  {
    shp_[i]->move(x, y);
  }
}
void nikonov::CompositeShape::scale(double k) noexcept
{
  for (size_t i = 0; i < size_; ++i)
  {
    point_t s = getFrameRect().pos;
    point_t origCenter = shp_[i]->getFrameRect().pos;
    shp_[i]->move(s);
    point_t newCenter = shp_[i]->getFrameRect().pos;
    double diffX = newCenter.x - origCenter.x;
    double diffY = newCenter.y - origCenter.y;
    shp_[i]->scale(k);
    shp_[i]->move(diffX * k * (-1), diffY * k * (-1));
  }
}
void nikonov::CompositeShape::scaleWithCheck(double k)
{
  if (k <= 0)
  {
    throw std::logic_error("noncorrect scale parameter");
  }
  scale(k);
}
void nikonov::CompositeShape::push_back(Shape *newElem)
{
  constexpr size_t maxSize = 10000;
  if (size_ + 1 > maxSize)
  {
    throw std::logic_error("maximum size has been exceeded");
  }
  shp_[size_] = newElem;
  ++size_;
}
void nikonov::CompositeShape::pop_back()
{
  if (size_ == 0)
  {
    throw std::logic_error("the collection is empty");
  }
  delete shp_[size_ - 1];
  shp_[size_ - 1] = nullptr;
  --size_;
}
nikonov::Shape *nikonov::CompositeShape::at(size_t id)
{
  return const_cast< Shape * >(const_cast< const CompositeShape * >(this)->at(id));
}
const nikonov::Shape *nikonov::CompositeShape::at(size_t id) const
{
  if (id >= size_)
  {
    throw std::logic_error("noncorrect id");
  }
  return shp_[id];
}
bool nikonov::CompositeShape::empty() const noexcept
{
  return size_ == 0;
}
size_t nikonov::CompositeShape::size() const noexcept
{
  return size_;
}
void nikonov::CompositeShape::swap(CompositeShape &another) noexcept
{
  std::swap(size_, another.size_);
  for (size_t i = 0; i < std::max(size_, another.size_); ++i)
  {
    std::swap(shp_[i], another.shp_[i]);
  }
}
