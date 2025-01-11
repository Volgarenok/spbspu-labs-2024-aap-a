#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"
namespace alymova
{
  struct Shape
  {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(point_t point) = 0;
    virtual void move(double shift_x, double shift_y) = 0;
    void scale(double ratio);
    virtual Shape* clone() const = 0;
  protected:
    virtual void unsafeScale(double ratio) = 0;
    friend void unsafeScale(Shape** sahpes, point_t s, double ratio);
  };
  void scale(Shape** shapes, point_t s, double ratio);
  void unsafeScale(Shape** shapes, point_t s, double ratio);
  void checkRatioScale(double ratio);
}
#endif
