#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include "shape.hpp"
#include "triangle.hpp"
#include <array>

namespace shramko
{
  class Diamond final: public Shape
  {
  public:
    Diamond(point_t one, point_t two, point_t three);
    ~Diamond() override;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(double x, double y) override;
  private:
    static const size_t TRIANGLE_COUNT = 4;
    Triangle** triangles_;
    std::array< point_t, 4 > vertices_;
    point_t center_;
    void doScale(double k) override;
  };
}

#endif
