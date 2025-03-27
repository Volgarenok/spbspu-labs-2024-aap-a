#include "diamond.hpp"
#include "shapeUtils.hpp"
#include <stdexcept>
#include <cmath>
#include <algorithm>

namespace cherkasov
{
  Diamond::Diamond(double x1, double y1, double x2, double y2, double x3, double y3)
    {
      point_t center{};
      if ((x1 == x2 && y1 == y3) || (y1 == y2 && x1 == x3))
      {
        center = { x1, y1 };
        vertex[0] = { x2, y2 };
        vertex[1] = { x3, y3 };
      }
      else if ((x1 == x2 && y2 == y3) || (y1 == y2 && x2 == x3))
      {
        center = { x2, y2 };
        vertex[0] = { x1, y1 };
        vertex[1] = { x3, y3 };
      }
      else if ((x3 == x2 && y1 == y3) || (y3 == y2 && x1 == x3))
      {
        center = { x3, y3 };
        vertex[0] = { x2, y2 };
        vertex[1] = { x1, y1 };
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
    rectangle_t rect { maxX - minX, maxY - minY, { (minX + maxX) / 2, (minY + maxY) / 2 } };
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
