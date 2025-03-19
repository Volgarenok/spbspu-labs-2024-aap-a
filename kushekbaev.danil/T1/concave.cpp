#include "concave.hpp"
#include <stdexcept>
#include <algorithm>
#include "base-types.hpp"
#include "shapeUtils.hpp"

kushekbaev::Concave::Concave(point_t first, point_t second, point_t third, point_t last):
  points_{ first, second, third, last }
{
  if (!isTriangle(first, second, third) || !isPointInsideTriangle(first, second, third, last))
  {
    throw std::invalid_argument("Incorrect concave");
  }
}

double kushekbaev::Concave::getArea() const
{
  double standart = getAreaOfTriangle(points_[0], points_[1], points_[2]);
  double concavity = getAreaOfTriangle(points_[1], points_[2], points_[3]);
  return standart - concavity;
}

kushekbaev::rectangle_t kushekbaev::Concave::getFrameRect() const
{
  double lowerLeftx = std::min({ points_[0].x, points_[1].x, points_[2].x, points_[3].x });
  double lowerLefty = std::min({ points_[0].y, points_[1].y, points_[2].y, points_[3].y});
  double upperRightx = std::max({ points_[0].x, points_[1].x, points_[2].x, points_[3].x });
  double upperRighty = std::max({ points_[0].y, points_[1].y, points_[2].y, points_[3].y });

  point_t lowerLeft { lowerLeftx, lowerLefty };
  point_t upperRight { upperRightx, upperRighty };

  double width = upperRight.x - lowerLeft.x;
  double height = upperRight.y - lowerLeft.y;
  double midX = lowerLeft.x + width / 2;
  double midY = lowerLeft.y + height / 2;
  point_t mid { midX, midY };
  return { width, height, mid };
}

void kushekbaev::Concave::move(point_t scalePoint)
{
  point_t mid = getFrameRect().pos;
  double dx = scalePoint.x - mid.x;
  double dy = scalePoint.y - mid.y;

  move(dx, dy);
}

void kushekbaev::Concave::move(double dx, double dy)
{
  size_t size = 4;
  point_t* points[] = { &points_[0], &points_[1], &points_[2], &points_[3] };
  movePoints(points, size, dx, dy);
}

kushekbaev::Shape* kushekbaev::Concave::clone() const
{
  return new Concave(*this);
}

void kushekbaev::Concave::doUnsafeScale(double scaleCoeff)
{
  kushekbaev::point_t mid = kushekbaev::Concave::getFrameRect().pos;
  size_t size = 4;
  kushekbaev::point_t* points[] = { &points_[0], &points_[1], &points_[2], &points_[3] };
  scalePoints(points, size, scaleCoeff, mid);
}
