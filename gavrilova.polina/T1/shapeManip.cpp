#include "shapeManip.hpp"
#include <iomanip>


void gavrilova::scaleShapeWithoutCheck(Shape& shape, const point_t& center, double k)
{
  point_t pos1 = shape.getFrameRect().pos;
  double difX = center.x - pos1.x;
  double difY = center.y - pos1.y;
  shape.move(center);
  shape.scaleWithoutCheck(k);
  difX *= k;
  difY *= k;
  shape.move(-difX, -difY);
}
void gavrilova::scaleShape(Shape& shape, const point_t& center, double k)
{
  if (k <= 0) {
    throw std::logic_error("Коэффицент должен быть положительным");
  }
  scaleShapeWithoutCheck(shape, center, k);
}

void gavrilova::outRectangle(std::ostream& out, const rectangle_t& rect)
{
  out << rect.pos.x - rect.width / 2 << " " << rect.pos.y - rect.height / 2;
  out << " " << rect.pos.x + rect.width / 2 << " " << rect.pos.y + rect.height / 2;
}

void gavrilova::outRectangles(std::ostream& out, const CompositeShape& shapes)
{
  if (!shapes.empty()) {
    out << std::setprecision(1);
    rectangle_t rect = shapes[0]->getFrameRect();
    outRectangle(out, rect);
    for (size_t i = 1; i < shapes.size(); ++i) {
      rectangle_t rect = shapes[i]->getFrameRect();
      out << " ";
      outRectangle(out, rect);
    }
  }
}

void gavrilova::scaleShapes(CompositeShape& shapes, const point_t& center, double k)
{
  for (size_t i = 0; i < shapes.size(); ++i) {
    scaleShape(*(shapes[i]), center, k);
  }
}

gavrilova::rectangle_t gavrilova::getFrameRectForShapes(const Shape* const* shapes, size_t size) noexcept
{
  double minX = shapes[0]->getFrameRect().pos.x - shapes[0]->getFrameRect().width / 2;
  double maxX = shapes[0]->getFrameRect().pos.x + shapes[0]->getFrameRect().width / 2;
  double minY = shapes[0]->getFrameRect().pos.y - shapes[0]->getFrameRect().height / 2;
  double maxY = shapes[0]->getFrameRect().pos.y + shapes[0]->getFrameRect().height / 2;

  for (size_t i = 1; i < size; ++i) {
    auto rect = shapes[i]->getFrameRect();
    minX = std::min(minX, rect.pos.x - rect.width / 2);
    maxX = std::max(maxX, rect.pos.x + rect.width / 2);
    minY = std::min(minY, rect.pos.y - rect.height / 2);
    maxY = std::max(maxY, rect.pos.y + rect.height / 2);
  }

  rectangle_t frameRect = {
    maxX - minX,
    maxY - minY,
    {minX + (maxX - minX) / 2, minY + (maxY - minY) / 2}
  };
  return frameRect;
}
void gavrilova::clearShapes(Shape** shapes, size_t size)
{
   for (size_t i = 0; i < size; ++i) {
    delete shapes[i];
  }
  delete[] shapes;
}
