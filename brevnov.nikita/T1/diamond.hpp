#ifndef DIAMOND_HPP
#define DIAMOND_HPP
#include "shape.hpp"
namespace brevnov
{
  class Diamond: public Shape
  {
  public:
    Diamond(point_t center, point_t horizontal, point_t vertical);
    ~Diamond();
    double getArea() override;
    rectangle_t getFrameRect() override;
    void move(point_t new_centre) override;
    void move(double dx, double dy) override;
    void scale(double n) override;
  private:
    point_t center;
    point_t horizontal;
    point_t vertical;
  };
}
#endif
