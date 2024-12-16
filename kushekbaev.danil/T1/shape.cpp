#include "shape.hpp"

namespace kushekbaev
{
    double getLineLength(point_t first, point_t second)
    {
        double width = (first.x - second.x);
        double length = (first.y - second.y);
        return (width * width + length * length);
    }
}
