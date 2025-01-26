#ifndef DIAMOND
#define DIAMOND
#include "shape.hpp"
#include "rectangle.hpp"

namespace averenkov
{
  class Diamond final: public Shape
  {
  public:
    Diamond(const point_t& a, const point_t& b, const point_t& c);
    void buildRectangles(const point_t& a, const point_t& b, const point_t& c);
    void scale(double factor);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(const point_t& s);
    void move(double x_plus, double y_plus);
  private:
    Rectangle rectangles[40];
    double widthR_;
    double heightR_;
    double sumx_;
    double sumy_;
  };
}

#endif
