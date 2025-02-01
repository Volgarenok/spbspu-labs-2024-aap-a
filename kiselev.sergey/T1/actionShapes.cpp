#include "actionShapes.hpp"
#include "shape.hpp"
#include <iomanip>
#include <ios>
#include <ostream>
namespace
{
  void printCoordinatesRect(std::ostream& output, const kiselev::Shape* shp)
  {
    kiselev::rectangle_t rect = shp->getFrameRect();
    double leftDownX = rect.pos.x - rect.width / 2;
    double leftDownY = rect.pos.y - rect.height / 2;
    double rightUpX = rect.pos.x + rect.width / 2;
    double rightUpY = rect.pos.y + rect.height / 2;
    output << leftDownX << " " << leftDownY << " " << rightUpX << " " << rightUpY;
  }
}
void kiselev::printInfo(std::ostream& output, const CompositeShape &cmp)
{
  output << std::fixed << std::setprecision(1) << cmp.getArea();
  for (size_t i = 0; i <  cmp.size(); ++i)
  {
    printCoordinatesRect(output << " ", cmp[i]);
  }
}
