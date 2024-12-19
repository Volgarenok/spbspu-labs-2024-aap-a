#ifndef DIAMOND_HPP
#define DIAMOND_HPP
#include "shape.hpp"


namespace lanovenko
{
  class Diamond : public Shape
  {
  public:
    Diamond(point_t center, point_t py, point_t px);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(point_t p);
    virtual void move(double dx, double dy);
    void unsScale(double k);

  private:
    point_t center_;
    point_t py_;
    point_t px_;
  };
}


#endif
