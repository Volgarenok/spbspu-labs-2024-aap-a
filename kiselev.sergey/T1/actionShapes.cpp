#include "actionShapes.hpp"
void kiselev::printCoordinatesRect(std::ostream& output, const CompositeShape& cmp)
{
  for (size_t i = 0; i < cmp.size(); ++i)
  {
    rectangle_t rect = cmp[i]->getFrameRect();
    double leftDownX = rect.pos.x - rect.width / 2;
    double leftDownY = rect.pos.y - rect.height / 2;
    double rightUpX = rect.pos.x + rect.width / 2;
    double rightUpY = rect.pos.y + rect.height / 2;
    output << " " << leftDownX << " " << leftDownY << " " << rightUpX << " " << rightUpY;
  }
  output << "\n";
}
