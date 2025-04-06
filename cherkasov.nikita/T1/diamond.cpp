#include "diamond.hpp"
#include "shapeUtils.hpp"
#include <stdexcept>
#include <cmath>
#include <algorithm>

namespace cherkasov
{
  Diamond::Diamond(point_t vertex1, point_t vertex2, point_t vertex3):
    vertex{ vertex1, vertex2, vertex3 }
    {
      point_t center{};
      if ((vertex1.x == vertex2.x && vertex1.y == vertex3.y) || (vertex1.y == vertex2.y && vertex1.x == vertex3.x))
      {
        center = { vertex1.x, vertex1.y };
        vertex[0] = { vertex2.x, vertex2.y };
        vertex[1] = { vertex3.x, vertex3.y };
      }
      else if ((vertex1.x == vertex2.x && vertex2.y == vertex3.y) || (vertex1.y == vertex2.y && vertex2.x == vertex3.x))
      {
        center = { vertex2.x, vertex2.y };
        vertex[0] = { vertex1.x, vertex1.y };
        vertex[1] = { vertex3.x, vertex3.y };
      }
      else if ((vertex3.x == vertex2.x && vertex1.y == vertex3.y) || (vertex3.y == vertex2.y && vertex1.x == vertex3.x))
      {
        center = { vertex3.x, vertex3.y };
        vertex[0] = { vertex2.x, vertex2.y };
        vertex[1] = { vertex1.x, vertex1.y };
      }
      else
      {
        throw std::invalid_argument("no input coordinat");
      }
      vertex[2] = { 2.0 * center.x - vertex[0].x, 2.0 * center.y - vertex[0].y };
      vertex[3] = { 2.0 * center.x - vertex[1].x, 2.0 * center.y - vertex[1].y };
    }
  double Diamond::getArea() const
  {
    double diag1 = std::hypot(vertex[0].x - vertex[2].x, vertex[0].y - vertex[2].y);
    double diag2 = std::hypot(vertex[1].x - vertex[3].x, vertex[1].y - vertex[3].y);
    return (diag1 * diag2) / 2;
  }
  rectangle_t Diamond::getFrameRect() const
  {
    double minX = std::min({ vertex[0].x, vertex[1].x, vertex[2].x, vertex[3].x });
    double maxX = std::max({ vertex[0].x, vertex[1].x, vertex[2].x, vertex[3].x });
    double minY = std::min({ vertex[0].y, vertex[1].y, vertex[2].y, vertex[3].y });
    double maxY = std::max({ vertex[0].y, vertex[1].y, vertex[2].y, vertex[3].y });
    double width = maxX - minX;
    double height = maxY - minY;
    point_t center { (minX + maxX) / 2, (minY + maxY) / 2 };
    rectangle_t rect { width, height, center };
    return rect;
  }
  void Diamond::move(point_t c)
  {
    point_t currentPos = getFrameRect().pos;
    double dx = c.x - currentPos.x;
    double dy = c.y - currentPos.y;
    move(dx, dy);
  }
  void Diamond::move(double dx, double dy)
  {
    moveVertex(vertex[0], dx, dy);
    moveVertex(vertex[1], dx, dy);
    moveVertex(vertex[2], dx, dy);
    moveVertex(vertex[3], dx, dy);
  }
  void Diamond::scalingFactor(double k)
  {
    point_t center = getFrameRect().pos;
    scalePoint(vertex[0], center, k);
    scalePoint(vertex[1], center, k);
    scalePoint(vertex[2], center, k);
    scalePoint(vertex[3], center, k);
  }
}
