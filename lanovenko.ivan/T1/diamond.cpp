#include "diamond.hpp"
#include <stdexcept>
#include <cmath>

lanovenko::Diamond::Diamond(point_t p1, point_t p2, point_t p3): 
	center_(p1), 
	vertical_(p2), 
	horizontal_(p3)
{
	bool valid = false;
	point_t points[3] = { p1, p2, p3 };
	for (size_t i = 0; i < 3; i++)
	{
		point_t candidate = points[i];
		point_t other1 = points[(i + 1) % 3];
		point_t other2 = points[(i + 2) % 3];
		if (candidate.x == other1.x && candidate.y == other2.y)
		{
			valid = true;
			center_ = candidate;
			vertical_ = other1;
			horizontal_ = other2;
			break;
		}
		if (candidate.x == other2.x && candidate.y == other1.y)
		{
			valid = true;
			center_ = candidate;
			vertical_ = other2;
			horizontal_ = other1;
			break;
		}
	}
	if (!valid)
	{
		throw std::invalid_argument("Wrong Diamond parametrs");
	}
}

double lanovenko::Diamond::getArea() const
{
	double d1 = std::fabs(center_.x - horizontal_.x) * 2.0;
	double d2 = std::fabs(center_.y - vertical_.y) * 2.0;
	return (d1 * d2) / 2.0;
}

lanovenko::rectangle_t lanovenko::Diamond::getFrameRect() const
{
	double width = std::fabs(center_.x - horizontal_.x) * 2.0;
	double heigth = std::fabs(center_.y - vertical_.y) * 2.0;
	return { width, heigth, center_ };
}

void lanovenko::Diamond::move(point_t p)
{
	double deltaX = p.x - center_.x;
	double deltaY = p.y - center_.y;
	move(deltaX, deltaY);
}

void lanovenko::Diamond::move(double dx, double dy)
{
	point_t* points[3] = { &center_, &horizontal_, &vertical_ };
	for (size_t i = 0; i < 3; i++)
	{
		points[i]->x += dx;
		points[i]->y += dy;
	}
}

void lanovenko::Diamond::unsafeScale(double k)
{
	double d1 = std::fabs(center_.x - horizontal_.x) * 2.0;
	double d2 = std::fabs(center_.y - vertical_.y) * 2.0;
	double new_d1 = d1 * k;
	double new_d2 = d2 * k;
	double deltaX = (new_d1 - d1) / 2.0;
	double deltaY = (new_d2 - d2) / 2.0;
	vertical_.y += deltaY;
	horizontal_.x -= deltaX;
}
