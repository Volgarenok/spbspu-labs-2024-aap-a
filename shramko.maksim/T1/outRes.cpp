#include "outRes.hpp"
#include "createShape.hpp"
#include <iomanip>

void shramko::outRes(std::ostream& out, Shape** shape, size_t size)
{
  out << std::fixed << std::setprecision(1) << getEveryArea(shape, size);

  for (size_t i = 0; i < size; i++)
  {
    out << " " << shape[i]->getFrameRect().pos.x - (shape[i]->getFrameRect().width) / 2.0f;
    out << " " << shape[i]->getFrameRect().pos.y - (shape[i]->getFrameRect().height) / 2.0f;
    out << " " << shape[i]->getFrameRect().pos.x + (shape[i]->getFrameRect().width) / 2.0f;
    out << " " << shape[i]->getFrameRect().pos.y + (shape[i]->getFrameRect().height) / 2.0f;
  }

  out << '\n';
}
