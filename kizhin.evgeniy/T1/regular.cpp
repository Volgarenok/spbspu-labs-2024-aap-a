#include "regular.hpp"
#include <cmath>
#include <stdexcept>
#include "point_utils.hpp"

kizhin::Regular::Regular(const point_t& p1, const point_t& p2, const point_t& p3):
  frame_{ 0.0, 0.0, p1 }
{
  if (!isRightTriangle(p1, p2, p3)) {
    throw std::invalid_argument("Invalid Triangle For Regular Construction");
  }
  const double r1 = computeDistance(p1, p2);
  const double r2 = computeDistance(p1, p3);
  const double outerRadius = std::max(r1, r2);
  const double innerRadius = std::min(r1, r2);
  vertex_ = (outerRadius == r1) ? p2 : p3;

  const double calculatedSize = pi / std::acos(innerRadius / outerRadius);
  size_ = std::round(calculatedSize);
  if (std::abs(calculatedSize - size_) > epsilon || size_ < 3) {
    throw std::logic_error("Invalid Regular Size");
  }
  computeFrameRect();
}

double kizhin::Regular::getArea() const
{
  const double radius = computeDistance(vertex_, frame_.pos);
  return size_ * std::pow(radius, 2) * 0.5 * std::sin(pi * 2 / size_);
}

kizhin::rectangle_t kizhin::Regular::getFrameRect() const
{
  return frame_;
}

void kizhin::Regular::move(double dx, double dy)
{
  vertex_ += { dx, dy };
  frame_.pos += { dx, dy };
}

void kizhin::Regular::move(const point_t& newPos)
{
  const double dx = newPos.x - frame_.pos.x;
  const double dy = newPos.y - frame_.pos.y;
  move(dx, dy);
}

void kizhin::Regular::scale(double scaleFactor)
{
  if (scaleFactor <= 0.0) {
    throw std::logic_error("Failed to scale");
  }
  vertex_.x *= scaleFactor;
  vertex_.y *= scaleFactor;
  computeFrameRect();
}

void kizhin::Regular::computeFrameRect()
{
  point_t* vertices = computeVerticesArray();
  double* edgeCords = computeEdgeCords(vertices, size_);
  delete[] vertices;
  frame_.width = edgeCords[1] - edgeCords[0];
  frame_.height = edgeCords[3] - edgeCords[2];
  delete[] edgeCords;
}

kizhin::point_t* kizhin::Regular::computeVerticesArray() const
{
  point_t* vertices = new point_t[size_];
  const double radius = computeDistance(vertex_, frame_.pos);
  const double angleStep = (2 * pi) / size_;
  double angle = std::acos(std::abs(vertex_.x - frame_.pos.x) / radius);
  for (point_t* i = vertices; i != vertices + size_; ++i) {
    *i = {
      frame_.pos.x + radius * std::cos(angle),
      frame_.pos.y + radius * std::sin(angle),
    };
    angle += angleStep;
  }
  return vertices;
}
