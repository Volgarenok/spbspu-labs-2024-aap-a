#include "shapeManip.hpp"
#include <iomanip>

void gavrilova::scaleShape(Shape& shape, const point_t& center, double k) {
  if (k <= 0) {
    throw std::logic_error("Коэффицент должен быть положительным");
  }
  point_t pos1 = shape.getFrameRect().pos;
  double difX = center.x - pos1.x;
  double difY = center.y - pos1.y;
  shape.move(center);
  shape.scale(k);
  difX *= k;
  difY *= k;
  shape.move(-difX, -difY);
}
void gavrilova::outRectangles(std::ostream& out, gavrilova::Shape ** Shapes, size_t nShapes) noexcept {
  if (nShapes) {
    for (size_t i = 0; i < nShapes; ++i) {
      rectangle_t rect = Shapes[i]->getFrameRect();
      out << std::setprecision(1);
      out << " " << rect.pos.x - rect.width / 2 << " " << rect.pos.y - rect.height / 2;
      out << " " << rect.pos.x + rect.width / 2 << " " << rect.pos.y + rect.height / 2;
    }
    out << "\n";
  }
}

void gavrilova::scaleShapes(gavrilova::Shape** Shapes, size_t nShapes, const gavrilova::point_t& center, double k, double& areaAfter) {
  for (size_t i = 0; i < nShapes; ++i) {
    gavrilova::scaleShape(*(Shapes[i]), center, k);
    areaAfter += Shapes[i]->getArea();
  }
}

void gavrilova::clearShapes(Shape** Shapes, size_t n) {
  for (size_t i = 0; i < n; ++i) {
    delete Shapes[i];
  }
}
