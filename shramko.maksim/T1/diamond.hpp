#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include "shape.hpp"
#include "triangle.hpp"

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
        static const size_t TRIANGLE_COUNT = 8;
        Triangle** triangles_;
        point_t vertices_[4];
        point_t center_;
        void doScale(double k) override;
        point_t midpoint(const point_t& a, const point_t& b) const;
    };
}

#endif
