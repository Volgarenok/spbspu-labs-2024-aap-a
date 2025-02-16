#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include "shape.hpp"

namespace lanovenko
{
  class Diamond final: public Shape
  {
  public:
    ~Diamond() = default;
    Diamond(point_t p1, point_t p2, point_t p3);
    virtual double getArea() const override;
    virtual rectangle_t getFrameRect() const override;
    virtual void move(point_t p) override;
    virtual void move(double dx, double dy) override;
    virtual void unsafeScale(double k) override;
  private:
    point_t center_;
    point_t vertical_;
    point_t horizontal_;
  };
}

#endif
