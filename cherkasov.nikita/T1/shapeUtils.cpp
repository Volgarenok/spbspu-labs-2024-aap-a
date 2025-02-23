#include "shapeUtils.hpp"
#include <stdexcept>

void cherkasov::Shape::scale(double k)
{
  if (k < 0)
  {
    throw std::logic_error("k must be positive");
  }
  scale(k);
}
void cherkasov::scalePoint(point_t& point, const point_t& center, double k)
{
  point.x = center.x + (point.x - center.x) * k;
  point.y = center.y + (point.y - center.y) * k;
}
void cherkasov::moveVertex(point_t& point, double moveX, double moveY)
{
  point.x += moveX;
  point.y += moveY;
}
