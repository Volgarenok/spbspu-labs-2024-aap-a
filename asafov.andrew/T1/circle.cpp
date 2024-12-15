#include "circle.h"
#define _USE_MATH_DEFINES
#include <cmath>

Circle::Circle(point_t pos, double rad):
center(pos), radius(rad)
{
  
}

double Circle::getArea() const
{
	return radius * radius * M_PI;
}

rectangle_t Circle::getFrameRect() const
{
	rectangle_t frect;
	frect.pos = center;
	frect.height = 2 * radius;
	frect.width = 2 * radius;
	return frect;
}

void Circle::move(double x, double y)
{
	center.x += x;
	center.y += y;
}

void Circle::move(point_t pos)
{
	center = pos;
}

void Circle::scale(point_t pos, double scale)
{
	center.x += (center.x - pos.x) * (scale - 1);
	center.y += (center.y - pos.y) * (scale - 1);
	radius *= scale;
}
