#include "shapeManip.hpp"
#include <iomanip>

void gavrilova::scaleShape_without_check(Shape& shape, const point_t& center, double k)
{
  point_t pos1 = shape.getFrameRect().pos;
  double difX = center.x - pos1.x;
  double difY = center.y - pos1.y;
  shape.move(center);
  shape.scale_without_check(k);
  difX *= k;
  difY *= k;
  shape.move(-difX, -difY);
}
void gavrilova::scaleShape(Shape& shape, const point_t& center, double k)
{
  if (k <= 0) {
    throw std::logic_error("Коэффицент должен быть положительным");
  }
  scaleShape_without_check(shape, center, k);
}

void gavrilova::outRectangle(std::ostream& out, const rectangle_t& rect)
{
  out << rect.pos.x - rect.width / 2 << " " << rect.pos.y - rect.height / 2;
  out << " " << rect.pos.x + rect.width / 2 << " " << rect.pos.y + rect.height / 2;
}

void gavrilova::outRectangles(std::ostream& out, Shape ** Shapes, size_t nShapes)
{
  if (nShapes) {
    out << std::setprecision(1);
    rectangle_t rect = Shapes[0]->getFrameRect();
    outRectangle(out, rect);
    for (size_t i = 0; i < nShapes; ++i) {
      rectangle_t rect = Shapes[i]->getFrameRect();
      out << " ";
      outRectangle(out, rect);
    }
  }
}

double gavrilova::scaleShapes(Shape** Shapes, size_t nShapes, const point_t& center, double k)
{
  double areaAfter = 0;
  for (size_t i = 0; i < nShapes; ++i) {
    scaleShape(*(Shapes[i]), center, k);
    areaAfter += Shapes[i]->getArea();
  }
  return areaAfter;
}

void gavrilova::clearShapes(Shape** Shapes, size_t n)
{
  for (size_t i = 0; i < n; ++i) {
    delete Shapes[i];
  }
}
