#ifndef RING_HPP
#define RING_HPP
#include "shape.hpp"
using asafov::point_t;
using asafov::rectangle_t;
namespace asafov
{
  class Ring : public Shape
  {
    point_t center;
    double radiusi;
    double radiuso;
  public:
    Ring(point_t pos, double radi, double rado);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t pos);
    void move(double x, double y);
    void scale(point_t pos, double scale);
  };
}
#endif
