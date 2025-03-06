#include "outRes.hpp"
#include "createShape.hpp"
#include <iomanip>

void shramko::outRes(std::ostream& out, Shape** shape, size_t size)
{
  out << std::fixed << std::setprecision(1) << getEveryArea(shape, size);

  for (size_t i = 0; i < size; i++)
  {
    rectangle_t frame = shape[i]->getFrameRect();
    out << " " << frame.pos.x - (frame.width / 2.0);
    out << " " << frame.pos.y - (frame.height / 2.0);
    out << " " << frame.pos.x + (frame.width / 2.0);
    out << " " << frame.pos.y + (frame.height / 2.0);
  }

  out << '\n';
}
