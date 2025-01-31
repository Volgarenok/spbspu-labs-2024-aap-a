#include "regular.hpp"
#include <algorithm>
#include <cmath>
#include <stdexcept>
#include "point_utils.hpp"

namespace kizhin {
  size_t computeSize(double, double);
  point_t* computeVerticesArray(const point_t&, const point_t&, size_t);
  Polygon createPolygon(const point_t&, const point_t&, const point_t&);
}

kizhin::Regular::Regular(const point_t& p1, const point_t& p2, const point_t& p3):
  polygon_(createPolygon(p1, p2, p3))
{
}

double kizhin::Regular::getArea() const
{
  return polygon_.getArea();
}

kizhin::rectangle_t kizhin::Regular::getFrameRect() const
{
  return polygon_.getFrameRect();
}

kizhin::Shape* kizhin::Regular::clone() const
{
  return new Regular(*this);
}

void kizhin::Regular::move(double dx, double dy)
{
  polygon_.move(dx, dy);
}

void kizhin::Regular::move(const point_t& newPos)
{
  polygon_.move(newPos);
}

void kizhin::Regular::unsafeScale(double scalingFactor)
{
  polygon_.scale(scalingFactor);
}

size_t kizhin::computeSize(double innerRadius, double outerRadius)
{
  const double calculatedSize = pi / std::acos(innerRadius / outerRadius);
  const size_t size = std::round(calculatedSize);
  if (std::abs(calculatedSize - size) > epsilon || size < 3) {
    throw std::logic_error("Fractional shape size");
  }
  return size;
}

kizhin::point_t* kizhin::computeVerticesArray(const point_t& center,
    const point_t& vertex, size_t size)
{
  point_t* vertices = new point_t[size];
  const double radius = computeDistance(vertex, center);
  const double angleStep = (2 * pi) / size;
  double angle = std::acos(std::abs(vertex.x - center.x) / radius);
  for (point_t* i = vertices; i != vertices + size; ++i) {
    *i = {
      center.x + radius * std::cos(angle),
      center.y + radius * std::sin(angle),
    };
    angle += angleStep;
  }
  return vertices;
}

kizhin::Polygon kizhin::createPolygon(const point_t& p1, const point_t& p2,
    const point_t& p3)
{
  if (!isRightTriangle(p1, p2, p3)) {
    throw std::invalid_argument("Invalid triangle for regular construction");
  }
  const double r1 = computeDistance(p1, p2);
  const double r2 = computeDistance(p1, p3);
  const double outerRadius = std::max(r1, r2);
  const double innerRadius = std::min(r1, r2);
  const point_t vertex = (outerRadius == r1) ? p2 : p3;
  const size_t size = computeSize(innerRadius, outerRadius);
  point_t* vertices = computeVerticesArray(p1, vertex, size);
  Polygon result(vertices, size);
  return result;
}

