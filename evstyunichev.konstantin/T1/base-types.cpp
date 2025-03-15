#include "base-types.hpp"
#include <cmath>

evstyunichev::point_t & evstyunichev::point_t::operator+=(point_t &b)
{
  x += b.x;
  y += b.y;
  return *this;
}

evstyunichev::point_t evstyunichev::point_t::operator+(const point_t &b) const
{
  return point_t{x + b.x, y + b.y};
}

evstyunichev::point_t evstyunichev::point_t::operator-(const point_t &b) const
{
  return point_t{x - b.x, y - b.y};
}

bool is_equal(double a, double b, double p)
{
  if (std::abs(a - b) <= p)
  {
    return 1;
  }
  return 0;
}

double evstyunichev::findDist(point_t A, point_t B)
{
  double a = A.x - B.x, b = A.y - B.y;
  double ans = std::sqrt(a * a + b * b);
  return ans;
}
