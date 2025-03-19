#include "concave.hpp"
#include <stdexcept>
#include <algorithm>
#include "base-types.hpp"
#include "shapeUtils.hpp"

kushekbaev::Concave::Concave(point_t p1, point_t p2, point_t p3, point_t p4):
  points_{ p1, p2, p3, p4 },
  mainpar_(p1, p2, p3),
  concpar_(p2, p3, p4)
{
  if (!isTriangle(p1, p2, p3) || !isPointInsideTriangle(p1, p2, p3, p4))
  {
    throw std::invalid_argument("Incorrect concave");
  }
}

double kushekbaev::Concave::getArea() const
{
  double standart = mainpar_.getArea();
  double concavity = concpar_.getArea();
  return standart - concavity;
}

kushekbaev::rectangle_t kushekbaev::Concave::getFrameRect() const
{
  double lowerLeftx = std::min({ points_[0].x, points_[1].x, points_[2].x, points_[3].x });
  double lowerLefty = std::min({ points_[0].y, points_[1].y, points_[2].y, points_[3].y });
  double upperRightx = std::max({ points_[0].x, points_[1].x, points_[2].x, points_[3].x });
  double upperRighty = std::max({ points_[0].y, points_[1].y, points_[2].y, points_[3].y });
  point_t lowerLeft { lowerLeftx, lowerLefty };
  point_t upperRight { upperRightx, upperRighty };

  double width = upperRight.x - lowerLeft.x;
  double height = upperRight.y - lowerLeft.y;
  double midx = lowerLeft.x + width / 2;
  double midy = lowerLeft.y + height / 2;
  point_t mid { midx, midy };
  return { width, height, mid };
}

void kushekbaev::Concave::move(point_t scalePoint)
{
  mainpar_.move(scalePoint);
  concpar_.move(scalePoint);
}

void kushekbaev::Concave::move(double dx, double dy)
{
  mainpar_.move(dx, dy);
  concpar_.move(dx, dy);
}

kushekbaev::Shape* kushekbaev::Concave::clone() const
{
  return new Concave(*this);
}

void kushekbaev::Concave::doUnsafeScale(double scaleCoeff)
{
  mainpar_.doUnsafeScale(scaleCoeff);
  concpar_.doUnsafeScale(scaleCoeff);
}
