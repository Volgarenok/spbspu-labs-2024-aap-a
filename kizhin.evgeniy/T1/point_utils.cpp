#include "point_utils.hpp"
#include <cmath>
#include <limits>

namespace kizhin {
  double computeDotProduct(const point_t&, const point_t&, const point_t&);
  bool areCollinear(const point_t&, const point_t&, const point_t&);
}

bool kizhin::isRightTriangle(const point_t& p1, const point_t& p2, const point_t& p3)
{
  const bool isRightAngleAtP1 = !computeDotProduct(p1, p2, p3);
  const bool isRightAngleAtP2 = isRightAngleAtP1 || !computeDotProduct(p2, p1, p3);
  const bool isRightAngleAtP3 = isRightAngleAtP2 || !computeDotProduct(p3, p1, p2);
  return isRightAngleAtP3;
}

double kizhin::computeDistanceSqr(const point_t& p1, const point_t& p2)
{
  double dx = p1.x - p2.x;
  double dy = p1.y - p2.y;
  return dx * dx + dy * dy;
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
  return std::abs(leftProduct - rigthProduct) < std::numeric_limits< double >::epsilon();
}

