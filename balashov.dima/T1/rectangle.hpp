#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace balashov
{
    class Rectangle : public Shape
    {
    public:
        Rectangle(double xLeft, double yUp, double xRight, double yDowm);
        virtual rectangle_t getFrameRect() const override;
        double getArea() const override;
        void move(point_t s) override;
        void move(double x, double y) override;
        void scale(double k) override;
    private:
        point_t angleUpLeft_;
        point_t angleDownRight_;
        point_t сentre;
    };
}
#endif
