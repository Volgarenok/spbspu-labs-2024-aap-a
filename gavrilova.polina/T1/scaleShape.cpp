#include "scaleShape.hpp"
void gavrilova::scaleShape(Shape & shape, const point_t & center, double k) {
    point_t pos1 = shape.getFrameRect().pos;
    double difX = center.x - pos1.x;
    double difY = center.y - pos1.y;
    shape.move(center);
    shape.scale(k);
    difX *= k;
    difY *= k;
    shape.move(-difX, -difY);
}
