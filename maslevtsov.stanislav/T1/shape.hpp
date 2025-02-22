#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <ostream>
#include <string>
#include "base-types.hpp"

namespace maslevtsov
{
  struct Shape
  {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(point_t pnt) = 0;
    virtual void move(double dx, double dy) = 0;
    virtual void scale(double k) = 0;
    virtual void unsafeScale(double k) noexcept = 0;
  };

  void clearShapes(Shape** shapes, std::size_t border);
  Shape* makeShape(std::string figureName, const double* arguments, std::size_t nArguments);
  void unsafeScale(Shape* shape, point_t pnt, double k);
  void safeScale(Shape* shape, point_t pnt, double k);
  void scaleShapes(Shape** shapes, point_t pnt, double k, std::size_t border);
  void outputAreaSum(std::ostream& out, const Shape* const* shapes, std::size_t border);
  void outputShapes(std::ostream& out, const Shape* const* shapes, std::size_t border);
  void outputShapesData(std::ostream& out, const Shape* const* shapes, std::size_t border);
}

#endif
