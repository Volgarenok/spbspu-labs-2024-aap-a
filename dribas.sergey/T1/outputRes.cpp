#include "outputRes.hpp"
#include <iomanip>
#include "getShapeInfo.hpp"

void dribas::outputRes(std::ostream & output, const Shape* const* Shape, const size_t shapeSize)
{
  output << std::fixed << std::setprecision(1) << getAllArea(Shape, shapeSize) << " ";
  for (size_t i = 0; i < shapeSize; i++) {
    output << Shape[i]->getFrameRect().pos.x - (Shape[i]->getFrameRect().width) / 2.0f << " ";
    output << Shape[i]->getFrameRect().pos.y - (Shape[i]->getFrameRect().height) / 2.0f << " ";
    output << Shape[i]->getFrameRect().pos.x + (Shape[i]->getFrameRect().width) / 2.0f << " ";
    output << Shape[i]->getFrameRect().pos.y + (Shape[i]->getFrameRect().height) / 2.0f << " ";
  }
  output << '\n';
  std::cout.flags();
}
