#include "concave.hpp"
#include <cmath>
#include <stdexcept>
#include <cctype>
#include <array>
#include "base-types.hpp"
#include "shapeBreeding.hpp"

namespace kushekbaev
{
  Concave::Concave(point_t first,
    point_t second,
  point_t third,
  point_t final):
  first_(first),
  second_(second),
  third_(third),
  final_(final),
  parallelogram1_(first_, second_, third_),
  parallelogram2_(second_, third_, final_)
  {
    if (!isTriangle(first, second, third) || !isPointInsideTriangle(first, second, third, final))
    {
      throw std::invalid_argument("Incorrect concave\n");
    }
  }

  double Concave::getArea() const
  {
    double standart = getAreaOfTriangle(first_, second_, third_);
    double concavity = getAreaOfTriangle(second_, third_, final_);
    return standart - concavity;
  }

  rectangle_t Concave::getFrameRect() const
  {
    point_t lowerLeft { 0, 0 };
    lowerLeft.x = std::min(std::min(std::min(first_.x, second_.x), third_.x), final_.x);
    lowerLeft.y = std::min(std::min(std::min(first_.y, second_.y), third_.y), final_.y);

    point_t upperRight { 0, 0 };

    upperRight.x = std::max(std::max(std::max(first_.x, second_.x), third_.x), final_.x);
    upperRight.y = std::max(std::max(std::max(first_.y, second_.y), third_.y), final_.y);

    rectangle_t frame_rect;
    frame_rect.height = upperRight.y - lowerLeft.y;
    frame_rect.width = upperRight.x - lowerLeft.x;
    frame_rect.pos.x = lowerLeft.x + frame_rect.width / 2;
    frame_rect.pos.y = lowerLeft.y + frame_rect.height / 2;
    return frame_rect;
  }

  void Concave::move(point_t Z)
  {
    point_t middle = getFrameRect().pos;
    double dx = Z.x - middle.x;
    double dy = Z.y - middle.y;

    std::array<point_t*, 4> points = { &first_, &second_, &third_, &final_ };

    for (point_t* point : points)
    {
      point->x += dx;
      point->y += dy;
    }
  }

  void Concave::move(double dx, double dy)
  {
    std::array<point_t*, 4> points = { &first_, &second_, &third_, &final_ };

    for (point_t* point : points)
    {
      point->x += dx;
      point->y += dy;
    }
  }

  void Concave::scale(double V)
  {
    if (V <= 0)
    {
      throw std::out_of_range("Scale coefficient should be greater than zero\n");
    }
    point_t middle = getFrameRect().pos;
    std::array<point_t*, 4> points = { &first_, &second_, &third_, &final_ };

    for (point_t* point : points)
    {
      point->x = middle.x + (point->x - middle.x) * V;
      point->y = middle.y + (point->y - middle.y) * V;
    }
  }
}
