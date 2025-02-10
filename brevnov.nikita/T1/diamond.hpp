#ifndef DIAMOND_HPP
#define DIAMOND_HPP
#include "shape.hpp"
namespace brevnov
{
  class Diamond final: public Shape
  {
  public:
    Diamond(point_t center, point_t horizontal, point_t vertical);
    ~Diamond() = default;
    double getArea() const noexcept override;
    rectangle_t getFrameRect() const noexcept override;
    void move(point_t new_centre) noexcept override;
    void move(double dx, double dy) noexcept override;
    void scale(double n) noexcept override;
    Shape * clone() const;
  private:
    point_t center_;
    point_t horizontal_;
    point_t vertical_;
  };
  point_t getCenter(point_t a, point b, point_t c);
  point_t getHorizontal(point_t center, point a, point_t b, point_t c);
  point_t getVertical(point_t center, point_t horizontal, point a, point_t b, point_t c);
  bool isCorrectDiamond(point_t a, point_t b, point_t c);
}
#endif
