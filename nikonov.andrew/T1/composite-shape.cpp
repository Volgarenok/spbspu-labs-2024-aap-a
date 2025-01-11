#include "composite-shape.hpp"
#include <stdexcept>
#include <algorithm>
namespace nikonov
{
  CompositeShape::CompositeShape()
  {}
  CompositeShape::CompositeShape(CompositeShape &&copy):
    size_(copy.size_)
  {
    for (size_t i = 0; i < copy.size(); ++i)
    {
      shp[i] = copy[i];
      copy.shp[i] = nullptr;
    }
    copy.size_ = 0;
  }
  Shape *CompositeShape::operator[](size_t id) const
  {
    return shp[id];
  }
  double CompositeShape::getArea() const
  {
    double sumArea = 0;
    for (size_t i = 0; i < size_; ++i)
    {
      sumArea += shp[i]->getArea();
    }
    return sumArea;
  }
  rectangle_t CompositeShape::getFrameRect() const
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
  void CompositeShape::move(const point_t &a)
  {
    rectangle_t crntRect = getFrameRect();
    double diffX = a.x - crntRect.pos.x;
    double diffY = a.y - crntRect.pos.y;
    move(diffX, diffY);
  }
  void CompositeShape::move(double x, double y)
  {
    for (size_t i = 0; i < size_; ++i)
    {
      shp[i]->move(x, y);
    }
  }
  void CompositeShape::scale(double k) noexcept
  {
    for (size_t i = 0; i < size_; ++i)
    {
      shp[i]->scale(k);
    }
  }
  void CompositeShape::scaleWithCheck(double k)
  {
    if (k <= 0)
    {
      throw std::logic_error("noncorrect scale parameter");
    }
    scale(k);
  }
  void CompositeShape::push_back(Shape *newElem)
  {
    shp[size_] = newElem;
    ++size_;
  }
  void CompositeShape::pop_back()
  {
    shp[size_ - 1] = nullptr;
    --size_;
  }
  Shape *CompositeShape::at(size_t id) const
  {
    if (id >= size_)
    {
      throw std::logic_error("noncorrect id");
    }
    return shp[id];
  }
  bool CompositeShape::empty() const noexcept
  {
    return size_ == 0;
  }
  size_t CompositeShape::size() const noexcept
  {
    return size_;
  }
}
