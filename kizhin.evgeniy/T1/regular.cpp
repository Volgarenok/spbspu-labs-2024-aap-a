#include "regular.hpp"
#include <cassert>
#include <cmath>
#include <stdexcept>
#include "base-types.hpp"
#include "point_utils.hpp"

kizhin::Regular::Regular(const point_t& p1, const point_t& p2, const point_t& p3)
{
  if (!isRightTriangle(p1, p2, p3)) {
    throw std::invalid_argument("Invalid Triangle Points");
  }
  center_ = p1;
  const double r1 = std::sqrt(kizhin::computeDistanceSqr(p1, p2));
  const double r2 = std::sqrt(kizhin::computeDistanceSqr(p1, p3));
  outerRadius_ = std::max(r1, r2);
  innerRadius_ = std::min(r1, r2);
  vtx_ = std::max(r1, r2) == r1 ? p2 : p3;
  updateFrameRect();
}

double kizhin::Regular::getArea() const
{
  const double verticesCount = computeVerticesCount();
  return verticesCount * std::pow(outerRadius_, 2) * 0.5 * std::sin(M_PI * 2 / verticesCount);
}

kizhin::rectangle_t kizhin::Regular::getFrameRect() const
{
  return frameRect_;
}

void kizhin::Regular::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
  frameRect_.pos.x += dx;
  frameRect_.pos.y += dy;
  vtx_.x += dx;
  vtx_.y += dy;
}

void kizhin::Regular::move(const point_t& newPos)
{
  const double dx = newPos.x - center_.x;
  const double dy = newPos.y - center_.y;
  move(dx, dy);
}

void kizhin::Regular::scale(double scaleFactor)
{
  assert(scaleFactor > 0);
  outerRadius_ *= scaleFactor;
  innerRadius_ *= scaleFactor;
  vtx_.x *= scaleFactor;
  vtx_.y *= scaleFactor;
  updateFrameRect();
}

void kizhin::Regular::updateFrameRect()
{
  point_t* verticesBegin = nullptr;
  point_t* verticesEnd = nullptr;
  computeVerticesArray(&verticesBegin, &verticesEnd);

  double minX = verticesBegin[0].x, maxX = verticesBegin[0].x;
  double minY = verticesBegin[0].y, maxY = verticesBegin[0].y;
  for (const point_t* i = verticesBegin; i != verticesEnd; ++i) {
    minX = std::min(minX, i->x);
    minY = std::min(minY, i->y);
    maxX = std::max(maxX, i->x);
    maxY = std::max(maxY, i->y);
  }

  frameRect_ = { maxX - minX, maxY - minY, center_ };
  delete[] verticesBegin;
}

void kizhin::Regular::computeVerticesArray(point_t** begin, point_t** end) const
{
  const size_t verticesCount = static_cast< size_t >(std::round(computeVerticesCount()));
  const double angleStep = (2 * M_PI) / verticesCount;

  ;
  *begin = new point_t[verticesCount];
  *end = *begin + verticesCount;
  for (size_t i = 0; i != verticesCount; ++i) {
    double angle = std::acos(std::abs(vtx_.x - center_.x) / outerRadius_) + i * angleStep;
    point_t vertex = {
      center_.x + outerRadius_ * std::cos(angle),
      center_.y + outerRadius_ * std::sin(angle),

    };
    (*begin)[i] = vertex;
  }
}

double kizhin::Regular::computeVerticesCount() const
{
  const double res = M_PI / (std::acos(innerRadius_ / outerRadius_));
  if (std::abs(res - std::round(res)) > 1e-6) {
    throw std::logic_error("");
  }
  return res;
}

