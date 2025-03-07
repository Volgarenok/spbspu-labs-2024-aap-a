#include "outputRes.hpp"
#include <iomanip>
#include "getShapeInfo.hpp"

void dribas::outputRes(std::ostream& output, const CompositeShape& shape)
{
  output << std::fixed << std::setprecision(1) << shape.getArea();
  for (size_t i = 0; i < shape.size(); i++) {
    output << " ";
    output << shape[i]->getFrameRect().pos.x - (shape[i]->getFrameRect().width) / 2.0f << " ";
    output << shape[i]->getFrameRect().pos.y - (shape[i]->getFrameRect().height) / 2.0f << " ";
    output << shape[i]->getFrameRect().pos.x + (shape[i]->getFrameRect().width) / 2.0f << " ";
    output << shape[i]->getFrameRect().pos.y + (shape[i]->getFrameRect().height) / 2.0f;
  }
  std::cout.flags();
}
