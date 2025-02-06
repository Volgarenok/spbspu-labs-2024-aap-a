#include "parallelogram.hpp"
#include <stdexcept>
#include <cmath>
#include "shapeBreeding.hpp"
#include "shapeUtils.hpp"

namespace
{
  bool isParToX(kushekbaev::point_t first, kushekbaev::point_t second)
  {
    return (first.x == second.x);
  }
}

namespace kushekbaev
{
  Parallelogram::Parallelogram(point_t first, point_t second, point_t third):
    points_{first, second, third}
  {
    bool isParToXflag = isParToX(first, second) || isParToX (second, third) || isParToX(first, third);
    if (!details::isTriangle(first, second, third) || !isParToXflag)
    {
      throw std::invalid_argument("Incorrect parallelogram\n");
    }
  }

  double Parallelogram::getArea() const
  {
    double firstSecondLL = getLineLength(points_[0], points_[1]);
    double secondThirdLL = getLineLength(points_[1], points_[2]);
    double firstThirdLL = getLineLength(points_[0], points_[2]);
    double p = (firstSecondLL + secondThirdLL + firstThirdLL) / 2;
    double squaredAreaOfTriangle = (p) * (p - firstSecondLL) * (p - secondThirdLL) * (p - firstThirdLL);
    double areaOfTriangle = std::sqrt(squaredAreaOfTriangle);
    return 2 * areaOfTriangle;
  }

  rectangle_t Parallelogram::getFrameRect() const
  {
    point_t firstalt({ points_[0].x + points_[2].x - points_[1].x, points_[0].y + points_[2].y - points_[1].y });

    double heigth = std::abs(points_[0].y - points_[2].y);
    double maxX = std::max(std::max(points_[0].x, points_[1].x), std::max(points_[2].x, firstalt.x));
    double minX = std::min(std::min(points_[0].x, points_[1].x), std::min(points_[2].x, firstalt.x));
    double width = maxX - minX;
    double middleX = (points_[0].x + points_[1].x + points_[2].x + firstalt.x) / 4.0;
    double middleY = (points_[0].y + points_[1].y + points_[2].y + firstalt.y) / 4.0;
    return { width, heigth, { middleX, middleY } };
  }

  void Parallelogram::move(point_t scalePoint)
  {
    point_t mid = getFrameRect().pos;
    double dx = scalePoint.x - mid.x;
    double dy = scalePoint.y - mid.y;

    move(dx, dy);
  }

  void Parallelogram::move(double dx, double dy)
  {
    size_t size = 3;
    point_t* points[] = { &points_[0], &points_[1], &points_[2] };
    movePoints(points, size, dx, dy);
  }

  void Parallelogram::scale(double scaleCoeff)
  {
    if (scaleCoeff <= 0)
    {
      throw std::logic_error("Scale coefficient should be greater than zero\n");
    }
    point_t mid = getFrameRect().pos;

    size_t size = 3;
    point_t* points[] = { &points_[0], &points_[1], &points_[2] };
    scalePoints(points, size, scaleCoeff, mid);
  }
}
