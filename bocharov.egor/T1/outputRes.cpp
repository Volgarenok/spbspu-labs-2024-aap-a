#include "outputRes.hpp"
#include "getShapeInfo.hpp"

void bocharov::outputRes(std::ostream & output, const Shape * const * myShape, size_t shapeSize)
{
  output << getAllArea(myShape, shapeSize);
  for (size_t i = 0; i < shapeSize; i++)
  {
    output << " " << myShape[i]->getFrameRect().pos.x - (myShape[i]->getFrameRect().width) / 2.0f;
    output << " " << myShape[i]->getFrameRect().pos.y - (myShape[i]->getFrameRect().height) / 2.0f;
    output << " " << myShape[i]->getFrameRect().pos.x + (myShape[i]->getFrameRect().width) / 2.0f;
    output << " " << myShape[i]->getFrameRect().pos.y + (myShape[i]->getFrameRect().height) / 2.0f;
  }
}
