#include <iostream>
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"

int main()
{
    point_t x1(1, 1);
    point_t y1(10, 11);
    Rectangle r(x1, y1);
    point_t shift(7.5, 1);
    r.move(shift);
    std::cout << r.upp_right_.getX() << " " << r.upp_right_.getY();
}