#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"
struct Shape
{
    virtual double getArea() = 0;
    virtual rectangle_t getFrameRect() = 0;
    virtual void move(point_t point) = 0;
    virtual void move(double shift_x, double shift_y) = 0;
    //virtual void scale(double ratio) = 0;
};
#endif