#include "outputRes.hpp"
#include "getShapeInfo.hpp"

void bocharov::outputRes(std::ostream & output, const Shape * const * shapes, size_t shapeSize)
{
  output << getAllArea(shapes, shapeSize);
  for (size_t i = 0; i < shapeSize; i++)
  {
    output << " " << shapes[i]->getFrameRect().pos.x - (shapes[i]->getFrameRect().width) / 2.0f;
    output << " " << shapes[i]->getFrameRect().pos.y - (shapes[i]->getFrameRect().height) / 2.0f;
    output << " " << shapes[i]->getFrameRect().pos.x + (shapes[i]->getFrameRect().width) / 2.0f;
    output << " " << shapes[i]->getFrameRect().pos.y + (shapes[i]->getFrameRect().height) / 2.0f;
  }
}
