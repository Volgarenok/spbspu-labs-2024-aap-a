#include "diamond.h"
#include <stdexcept>
#include <cmath>
namespace cherkasov
{
  constexpr double epsilon = 1e-6;
  Diamond::Diamond(point_t d1, point_t d2, point_t d3)
  {
    if ((d1.x == d2.x && d1.y == d2.y) || (d1.x == d3.x && d1.y == d3.y) || (d2.x == d3.x && d2.y == d3.y))
    {
      throw std::logic_error("Diamond vertices must be distinct");
    }
    if (std::abs(d2.y - d3.y) > epsilon || std::abs(d1.x - d3.x) > epsilon)
    {
      throw std::logic_error("...");
    }
    center = {(d1.x + d2.x) / 2, (d1.y + d3.y) / 2};
    width = std::abs(d2.x - d1.x);
    height = std::abs(d3.y - d1.y);
  }
  double Diamond::getArea() const
  {
    return (width * height) / 2;
  }
  rectangle_t Diamond::getFrameRect() const
  {
    return {width, height, center};
  }
  void Diamond::move(point_t c)
  {
    center = c;
  }
  void Diamond::move(double dx, double dy)
  {
    center.x += dx;
    center.y += dy;
  }
  void Diamond::scale(double k)
  {
    if (k <= 0)
    {
      throw std::logic_error("Scale factor must be positive");
    }
    width *= k;
    height *= k;
  }
}
