#include "composite-shape.hpp"
#include <stdexcept>
#include <cmath>
#include <algorithm>
#include "additional-utilities.hpp"
nikonov::CompositeShape::CompositeShape():
  size_(0)
{
  for (size_t i = 0; i < 10000; ++i)
  {
    shp[i] = nullptr;
  }
}
nikonov::CompositeShape::CompositeShape(CompositeShape &copy):
  size_(copy.size_)
{
  for (size_t i = 0; i < copy.size(); ++i)
  {
    shp[i] = copy.shp[i]->clone();
  }
}
nikonov::CompositeShape::CompositeShape(CompositeShape &&copy):
  size_(copy.size_)
{
  for (size_t i = 0; i < copy.size(); ++i)
  {
    shp[i] = copy.shp[i];
    copy.shp[i] = nullptr;
  }
  copy.size_ = 0;
}
nikonov::CompositeShape::~CompositeShape()
{
  nikonov::destoy(*this);
}
nikonov::Shape *nikonov::CompositeShape::operator[](size_t id)
{
  return shp[id];
}
nikonov::CompositeShape &nikonov::CompositeShape::operator=(const CompositeShape &another)
{
  if (&another != this)
  {
    nikonov::destoy(*this);
    for (size_t i = 0; i < another.size(); ++i)
    {
      shp[i] = another.shp[i]->clone();
    }
    size_ = another.size_;
  }
  return *this;
}
nikonov::CompositeShape &nikonov::CompositeShape::operator=(CompositeShape &&another)
{
  if (&another != this)
  {
    nikonov::destoy(*this);
    for (size_t i = 0; i < another.size(); ++i)
    {
      shp[i] = another.shp[i];
      another.shp[i] = nullptr;
    }
    size_ = another.size_;
    another.size_ = 0;
    nikonov::destoy(another);
  }
  return *this;
}
double nikonov::CompositeShape::getArea() const
{
  double sumArea = 0;
  for (size_t i = 0; i < size_; ++i)
  {
    sumArea += shp[i]->getArea();
  }
  return sumArea;
}
nikonov::rectangle_t nikonov::CompositeShape::getFrameRect() const
{
  if (empty())
  {
    throw std::logic_error("ShapeCollection is empty");
  }
  point_t currCenter = (*shp)->getFrameRect().pos;
  double currDivWidth = (*shp)->getFrameRect().width / 2;
  double currDivHeight = (*shp)->getFrameRect().height / 2;
  double minX = currCenter.x - currDivWidth;
  double minY = currCenter.y - currDivHeight;
  double maxX = currCenter.x + currDivWidth;
  double maxY = currCenter.y + currDivHeight;
  for (size_t i = 0; i < size_; ++i)
  {
    currCenter = shp[i]->getFrameRect().pos;
    currDivWidth = shp[i]->getFrameRect().width / 2;
    currDivHeight = shp[i]->getFrameRect().height / 2;
    minX = std::min(minX, currCenter.x - currDivWidth);
    minY = std::min(minY, currCenter.y - currDivHeight);
    maxX = std::max(maxX, currCenter.x + currDivWidth);
    maxY = std::max(maxY, currCenter.y + currDivHeight);
  }
  double width = maxX - minX;
  double height = maxY - minY;
  return rectangle_t({ width, height, point_t({ minX + width / 2, minY + height / 2 }) });
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
    shp[i]->move(x, y);
  }
}
void nikonov::CompositeShape::scale(double k) noexcept
{
  for (size_t i = 0; i < size_; ++i)
  {
    point_t S = getFrameRect().pos;
    point_t origCenter = shp[i]->getFrameRect().pos;
    shp[i]->move(S);
    point_t newCenter = shp[i]->getFrameRect().pos;
    double diffX = newCenter.x - origCenter.x;
    double diffY = newCenter.y - origCenter.y;
    shp[i]->scale(k);
    shp[i]->move(diffX * k * (-1), diffY * k * (-1));
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
  shp[size_] = newElem;
  ++size_;
}
void nikonov::CompositeShape::pop_back()
{
  delete shp[size_ - 1];
  shp[size_ - 1] = nullptr;
  --size_;
}
nikonov::Shape *nikonov::CompositeShape::at(size_t id)
{
  if (id >= size_)
  {
    throw std::logic_error("noncorrect id");
  }
  return shp[id];
}
bool nikonov::CompositeShape::empty() const noexcept
{
  return size_ == 0;
}
size_t nikonov::CompositeShape::size() const noexcept
{
  return size_;
}
