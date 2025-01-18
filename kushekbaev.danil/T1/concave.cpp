#include "concave.hpp"
#include <stdexcept>
#include <array>
#include "base-types.hpp"
#include "shapeBreeding.hpp"

namespace kushekbaev
{
  Concave::Concave(point_t first, point_t second, point_t third, point_t last):
    first_(first),
    second_(second),
    third_(third),
    last_(last)
  {
    if (!isTriangle(first, second, third) || !isPointInsideTriangle(first, second, third, last))
    {
      throw std::invalid_argument("Incorrect concave\n");
    }
  }

  double Concave::getArea() const
  {
    double standart = getAreaOfTriangle(first_, second_, third_);
    double concavity = getAreaOfTriangle(second_, third_, last_);
    return standart - concavity;
  }

  rectangle_t Concave::getFrameRect() const
  {
    point_t lowerLeft { 0, 0 };
    lowerLeft.x = std::min(std::min(std::min(first_.x, second_.x), third_.x), last_.x);
    lowerLeft.y = std::min(std::min(std::min(first_.y, second_.y), third_.y), last_.y);

    point_t upperRight { 0, 0 };
    upperRight.x = std::max(std::max(std::max(first_.x, second_.x), third_.x), last_.x);
    upperRight.y = std::max(std::max(std::max(first_.y, second_.y), third_.y), last_.y);

    rectangle_t frame_rect;
    frame_rect.height = upperRight.y - lowerLeft.y;
    frame_rect.width = upperRight.x - lowerLeft.x;
    frame_rect.pos.x = lowerLeft.x + frame_rect.width / 2;
    frame_rect.pos.y = lowerLeft.y + frame_rect.height / 2;
    return frame_rect;
  }

  void Concave::move(point_t scalePoint)
  {
    point_t middle = getFrameRect().pos;
    double dx = scalePoint.x - middle.x;
    double dy = scalePoint.y - middle.y;

    move(dx, dy);
  }

  void Concave::move(double dx, double dy)
  {
    std::array<point_t*, 4> points = { &first_, &second_, &third_, &last_ };

    for (point_t* point: points)
    {
      point->x += dx;
      point->y += dy;
    }
  }

  void Concave::scale(double scaleCoeff)
  {
    if (scaleCoeff <= 0)
    {
      throw std::out_of_range("Scale coefficient should be greater than zero\n");
    }
    point_t middle = getFrameRect().pos;
    std::array<point_t*, 4> points = { &first_, &second_, &third_, &last_ };

    for (point_t* point: points)
    {
      point->x = middle.x + (point->x - middle.x) * scaleCoeff;
      point->y = middle.y + (point->y - middle.y) * scaleCoeff;
    }
  }
}
