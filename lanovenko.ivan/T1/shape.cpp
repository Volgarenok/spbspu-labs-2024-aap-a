#include "shape.hpp"
#include <stdexcept>

void lanovenko::Shape::scale(double k)
{
	if (k < 0)
	{
		throw std::invalid_argument("Negative coefficient");
	}
	unsafeScale(k);
}
