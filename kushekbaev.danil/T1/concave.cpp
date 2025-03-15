#include "concave.hpp"
#include <stdexcept>
#include "base-types.hpp"
#include "shapeUtils.hpp"

namespace kushekbaev
{
  Concave::Concave(point_t first, point_t second, point_t third, point_t last):
    points_{first, second, third, last}
  {
    if (!isTriangle(first, second, third) || !isPointInsideTriangle(first, second, third, last))
    {
      throw std::invalid_argument("Incorrect concave\n");
    }
  }

  double Concave::getArea() const
  {
    double standart = getAreaOfTriangle(points_[0], points_[1], points_[2]);
    double concavity = getAreaOfTriangle(points_[1], points_[2], points_[3]);
    return standart - concavity;
    }

  rectangle_t Concave::getFrameRect() const
  {
    double lowerLeftx = std::min(std::min(std::min(points_[0].x, points_[1].x), points_[2].x), points_[3].x);
    double lowerLefty = std::min(std::min(std::min(points_[0].y, points_[1].y), points_[2].y), points_[3].y);
    double upperRightx = std::max(std::max(std::max(points_[0].x, points_[1].x), points_[2].x), points_[3].x);
    double upperRighty = std::max(std::max(std::max(points_[0].y, points_[1].y), points_[2].y), points_[3].y);

    point_t lowerLeft { lowerLeftx, lowerLefty };
    point_t upperRight { upperRightx, upperRighty };

    double width = upperRight.x - lowerLeft.x;
    double height = upperRight.y - lowerLeft.y;
    point_t mid;
    mid.x = lowerLeft.x + width / 2;
    mid.y = lowerLeft.y + height / 2;
    return { width, height, mid };
  }

  void Concave::move(point_t scalePoint)
  {
    point_t mid = getFrameRect().pos;
    double dx = scalePoint.x - mid.x;
    double dy = scalePoint.y - mid.y;

    move(dx, dy);
  }

  void Concave::move(double dx, double dy)
  {
    size_t size = 4;
    point_t* points[] = { &points_[0], &points_[1], &points_[2], &points_[3] };
    movePoints(points, size, dx, dy);
  }

  void Concave::scale(double scaleCoeff)
  {
    if (scaleCoeff <= 0)
    {
      throw std::logic_error("Scale coefficient should be greater than zero\n");
    }
    point_t mid = getFrameRect().pos;
    size_t size = 4;
    point_t* points[] = { &points_[0], &points_[1], &points_[2], &points_[3] };
    scalePoints(points, size, scaleCoeff, mid);
  }
}
