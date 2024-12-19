#include "outRes.hpp"
#include "createShape.hpp"
#include <iomanip>

void shramko::outRes(std::ostream& out, Shape** shapes, size_t, count)
{
  out << std::fixed << std::setprecision(1) << getArea(shapes, count);

  for (size_t i = 0; i < count; i++)
  {
    out << " " << shapes[i]->getRectangleFrame().pos.x - (shapes[i]->getRectangleFrame().width) / 2.0f;
    out << " " << shapes[i]->getRectangleFrame().pos.y - (shapes[i]->getRectangleFrame().height) / 2.0f;
    out << " " << shapes[i]->getRectangleFrame().pos.x + (shapes[i]->getRectangleFrame().width) / 2.0f;
    out << " " << shapes[i]->getRectangleFrame().pos.y + (shapes[i]->getRectangleFrame().height) / 2.0f;
  }

  out << '\n';
}
