#include "shapeUtils.hpp"

void cherkasov::scalePoint(point_t& vertex, const point_t& center, double k)
{
  vertex.x = center.x + (vertex.x - center.x) * k;
  vertex.y = center.y + (vertex.y - center.y) * k;
}
void cherkasov::moveVertex(point_t& vertex, double moveX, double moveY)
{
  vertex.x += moveX;
  vertex.y += moveY;
}
