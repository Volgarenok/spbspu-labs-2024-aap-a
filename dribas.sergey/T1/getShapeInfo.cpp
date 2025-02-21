#include "getShapeInfo.hpp"
#include <iostream>
#include <cstddef>
#include "rectangle.hpp"
#include "triangle.hpp"
#include "diamond.hpp"
#include "concave.hpp"
#include "outputRes.hpp"
#include "shape.hpp"

double dribas::getAllArea(const Shape* const* Shapes, const size_t shapeCount)
{
  double allArea = 0.0;
  for (size_t i = 0; i < shapeCount; i++) {
    allArea += Shapes[i]->getArea();
  }
  return allArea;
}

void dribas::scaleOne(Shape& t, double ratio, point_t Point)
{
  dribas::point_t cneter = t.getFrameRect().pos;
  t.move(Point);
  dribas::point_t center2 = t.getFrameRect().pos;
  double diffenceX = (center2.x - cneter.x) * ratio * - 1;
  double diffenceY = (center2.y - cneter.y) * ratio * - 1;
  t.scale(ratio);
  t.move(diffenceX, diffenceY);
}

void dribas::scalingAll(Shape** shapes, size_t shapeCount, point_t center, double ratio)
{
  for (size_t i = 0; i < shapeCount; i++) {
    dribas::point_t cneter = shapes[i]->getFrameRect().pos;
    shapes[i]->move(center);
    dribas::point_t center2 = shapes[i]->getFrameRect().pos;
    double diffenceX = (center2.x - cneter.x) * ratio * - 1;
    double diffenceY = (center2.y - cneter.y) * ratio * - 1;
    shapes[i]->scale(ratio);
    shapes[i]->move(diffenceX, diffenceY);
  }
}

bool getPoint(std::istream& in, size_t pointCount, dribas::point_t * points) {
  size_t i = 0;
  for (; i < pointCount && in; i++) {
    double a = 0;
    double b = 0;
    in >> a >> b;
    points[i] = {a,b};
  }
  return i == pointCount;
}

size_t dribas::getShapeInfo(std::istream& input, std::ostream& error, Shape** Shapes, double* scalingFactor)
{
  std::string InputStr;
  int shapesCount = 0;
  bool scaled = false;
  try {
    while (input >> InputStr) {
      try {
        if (InputStr == "RECTANGLE") {
          point_t pointR[2] = {};
          if (getPoint(std::cin, 2, pointR)) {
            Shapes[shapesCount] = new Rectangle{pointR[0], pointR[1]};
            shapesCount++;
          }
        } else if (InputStr == "TRIANGLE") {
          point_t pointT[3] = {};
          if (getPoint(std::cin, 3, pointT)) {
            Shapes[shapesCount] = new Triangle{pointT[0], pointT[1], pointT[2]};
            shapesCount++;
          }
        } else if (InputStr == "DIAMOND") {
          point_t pointD[3] = {};
          if (getPoint(std::cin, 3, pointD)) {
            Shapes[shapesCount] = new Diamond{pointD[0], pointD[1], pointD[2]};
            shapesCount++;
          }
        } else if (InputStr == "CONCAVE") {
          point_t pointC[4] = {};
          if (getPoint(std::cin, 4, pointC)) {
            Shapes[shapesCount] = new Concave{pointC[0], pointC[1], pointC[2], pointC[3]};
            shapesCount++;
          }
        }
      } catch(const std::invalid_argument& e) {
        error << e.what() << '\n';
      }
      if (InputStr == "SCALE") {
        scaled = true;
        if (shapesCount == 0) {
          throw std::logic_error("No shapes for scale");
        }
        input >> scalingFactor[0];
        input >> scalingFactor[1];
        input >> scalingFactor[2];
        if (scalingFactor[2] <= 0) {
          throw std::invalid_argument("under zero ratio with scale");
        }
      }
    }
  } catch (const std::exception& e) {
    clear(Shapes, shapesCount);
    throw e;
    return 0;
  }
  if (!scaled) {
    clear(Shapes, shapesCount);
    throw std::invalid_argument("No Arguments for scale");
    return 0;
  }
  return shapesCount;
}

void dribas::clear(Shape ** shape, size_t shapeCount) {
  for (size_t i = 0; i < shapeCount; i++) {
    delete shape[i];
  }
}
