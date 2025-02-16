#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace lanovenko
{
	class Rectangle final: public Shape
	{
	public:
		~Rectangle() = default;
		Rectangle(point_t p1, point_t p2);
		virtual double getArea() const override;
		virtual rectangle_t getFrameRect() const override;
		virtual void move(point_t p) override;
		virtual void move(double dx, double dy) override;
		virtual void unsafeScale(double k) override;
	private:
		point_t leftDown_;
		point_t rightUpper_;
	};
}

#endif
