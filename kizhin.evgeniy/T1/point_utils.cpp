#include "point_utils.hpp"
#include <algorithm>
#include <cmath>

namespace kizhin {
  double computeDotProduct(const point_t&, const point_t&, const point_t&);
  bool areCollinear(const point_t&, const point_t&, const point_t&);
}

bool kizhin::isRightTriangle(const point_t& p1, const point_t& p2, const point_t& p3)
{
  const bool isRightAngleAtP1 = !areCollinear(p1, p2, p3) && !computeDotProduct(p1, p2, p3);
  const bool isRightAngleAtP2 = isRightAngleAtP1 || !computeDotProduct(p2, p1, p3);
  const bool isRightAngleAtP3 = isRightAngleAtP2 || !computeDotProduct(p3, p1, p2);
  return isRightAngleAtP3;
}

double kizhin::computeDistance(const point_t& p1, const point_t& p2)
{
  double dx = p1.x - p2.x;
  double dy = p1.y - p2.y;
  return std::sqrt(dx * dx + dy * dy);
}

std::array< double, 4 > kizhin::computeEdgeCords(const point_t* points, size_t size)
{
  std::array< double, 4 > res = {
    points->x,
    points->x,
    points->y,
    points->y,
  };
  for (const point_t* i = points; i != points + size; ++i) {
    const point_t& point = *i;
    res[0] = std::min(point.x, res[0]);
    res[1] = std::max(point.x, res[1]);
    res[2] = std::min(point.y, res[2]);
    res[3] = std::max(point.y, res[3]);
  }
  return res;
}

double kizhin::computeDotProduct(const point_t& vertex, const point_t& p1, const point_t& p2)
{
  const double v1x = p1.x - vertex.x;
  const double v1y = p1.y - vertex.y;
  const double v2x = p2.x - vertex.x;
  const double v2y = p2.y - vertex.y;
  return v1x * v2x + v1y * v2y;
}

bool kizhin::areCollinear(const point_t& p1, const point_t& p2, const point_t& p3)
{
  const double leftProduct = (p3.x - p1.x) * (p2.y - p1.y);
  const double rigthProduct = (p2.x - p1.x) * (p3.y - p1.y);
  return std::abs(leftProduct - rigthProduct) < epsilon;
}

kizhin::point_t& kizhin::operator+=(point_t& lhs, const kizhin::point_t& rhs)
{
  lhs.x += rhs.x;
  lhs.y += rhs.y;
  return lhs;
}

