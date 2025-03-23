#include "actionShapes.hpp"
#include <ostream>
namespace
{
  std::ostream& printCoordinatesRect(std::ostream& output, const kiselev::Shape* shp)
  {
    const kiselev::rectangle_t rect = shp->getFrameRect();
    const double leftDownX = rect.pos.x - rect.width / 2;
    const double leftDownY = rect.pos.y - rect.height / 2;
    const double rightUpX = rect.pos.x + rect.width / 2;
    const double rightUpY = rect.pos.y + rect.height / 2;
    return output << leftDownX << " " << leftDownY << " " << rightUpX << " " << rightUpY;
  }
}
std::ostream& kiselev::printInfo(std::ostream& output, const CompositeShape& cmp)
{
  output << cmp.getArea();
  for (size_t i = 0; i < cmp.size(); ++i)
  {
    printCoordinatesRect(output << " ", cmp[i]);
  }
  return output;
}
