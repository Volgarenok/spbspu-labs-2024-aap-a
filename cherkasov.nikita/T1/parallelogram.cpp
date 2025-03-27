#include "parallelogram.hpp"
#include "shapeUtils.hpp"
#include <stdexcept>
#include <cmath>
#include <algorithm>

namespace cherkasov
{
  Parallelogram::Parallelogram(point_t vertex1, point_t vertex2, point_t vertex3):
    vertex{ vertex1, vertex2, vertex3 }
    {
      if (((vertex1.x == vertex3.x && vertex2.y == vertex3.y) || (vertex2.x == vertex3.x && vertex1.y == vertex3.y)) ||
         (!(vertex1.y == vertex2.y || vertex1.y == vertex3.y || vertex2.y == vertex3.y) && (vertex1.y != vertex3.y)))
      {
        throw std::invalid_argument("no correct coordinat the parallelogram");
      }
      vertex[3] = { (vertex1.x + vertex3.x) - vertex2.x, (vertex1.y + vertex3.y) - vertex2.y };
    }
  double Parallelogram::getArea() const
  {
    double vector1x = vertex[1].x - vertex[0].x;
    double vector1y = vertex[1].y - vertex[0].y;
    double vector2x = vertex[2].x - vertex[0].x;
    double vector2y = vertex[2].y - vertex[0].y;
    return std::abs(vector1x * vector2y - vector1y * vector2x);
  }
  rectangle_t Parallelogram::getFrameRect() const
  {
    double minX = std::min({ vertex[0].x, vertex[1].x, vertex[2].x, vertex[3].x });
    double maxX = std::max({ vertex[0].x, vertex[1].x, vertex[2].x, vertex[3].x });
    double minY = std::min({ vertex[0].y, vertex[1].y, vertex[2].y, vertex[3].y });
    double maxY = std::max({ vertex[0].y, vertex[1].y, vertex[2].y, vertex[3].y });
    point_t center{};
    center.x = (vertex[0].x + vertex[1].x + vertex[2].x + vertex[3].x) / 4;
    center.y = (vertex[0].y + vertex[1].y + vertex[2].y + vertex[3].y) / 4;
    double width = maxX - minX;
    double height = maxY - minY;
    rectangle_t rect { width, height, center };
    return rect;
  }
  void Parallelogram::move(point_t c)
  {
    point_t currentPos = getFrameRect().pos;
    double dx = c.x - currentPos.x;
    double dy = c.y - currentPos.y;
    move(dx, dy);
  }
  void Parallelogram::move(double dx, double dy)
  {
    moveVertex(vertex[0], dx, dy);
    moveVertex(vertex[1], dx, dy);
    moveVertex(vertex[2], dx, dy);
    moveVertex(vertex[3], dx, dy);
  }
  void Parallelogram::scalingFactor(double k)
  {
    point_t center = getFrameRect().pos;
    scalePoint(vertex[0], center, k);
    scalePoint(vertex[1], center, k);
    scalePoint(vertex[2], center, k);
    scalePoint(vertex[3], center, k);
  }
}
