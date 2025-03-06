#include "getShapeInfo.hpp"
#include <cstddef>
#include <iostream>
#include "composite-shape.hpp"
#include "concave.hpp"
#include "diamond.hpp"
#include "outputRes.hpp"
#include "rectangle.hpp"
#include "shape.hpp"
#include "triangle.hpp"

void dribas::scaleOne(Shape& t, double ratio, point_t Point)
{
  point_t cneter = t.getFrameRect().pos;
  t.move(Point);
  point_t center2 = t.getFrameRect().pos;
  double diffenceX = (center2.x - cneter.x) * ratio * -1;
  double diffenceY = (center2.y - cneter.y) * ratio * -1;
  t.scale(ratio);
  t.move(diffenceX, diffenceY);
}

bool getPoint(std::istream& in, size_t pointCount, dribas::point_t* points)
{
  size_t i = 0;
  for (; i < pointCount && in; i++) {
    in >> points[i].x >> points[i].y;
  }
  return i == pointCount;
}

dribas::CompositeShape dribas::getShapeInfo(std::istream& input, std::ostream& error, double* scalingFactor)
{
  CompositeShape shapes;
  std::string inputStr;
  bool scaled = false;
  Shape* shape = nullptr;
  while (input >> inputStr && inputStr != "SCALE") {
    try {
      if (inputStr == "RECTANGLE") {
        point_t pointR[2] = { 0, 0 };
        if (getPoint(std::cin, 2, pointR)) {
          shape = new Rectangle(pointR[0], pointR[1]);
          shapes.push_back(shape);
        }
      } else if (inputStr == "TRIANGLE") {
        point_t pointT[3] = { 0, 0 };
        if (getPoint(std::cin, 3, pointT)) {
          shape = new Triangle(pointT[0], pointT[1], pointT[2]);
          shapes.push_back(shape);
        }
      } else if (inputStr == "DIAMOND") {
        point_t pointD[3] = { 0, 0 };
        if (getPoint(std::cin, 3, pointD)) {
          shape = new Diamond(pointD[0], pointD[1], pointD[2]);
          shapes.push_back(shape);
        }
      } else if (inputStr == "CONCAVE") {
        point_t pointC[4] = { 0, 0 };
        if (getPoint(std::cin, 4, pointC)) {
          shape = new Concave(pointC[0], pointC[1], pointC[2], pointC[3]);
          shapes.push_back(shape);
        }
      }
    } catch (const std::invalid_argument& e) {
      error << e.what() << '\n';
    } catch (const std::overflow_error& e) {
      delete shape;
      throw e;
    } catch (const std::exception& e) {
      shapes.clear();
      throw e;
    }
  }
  if (inputStr == "SCALE") {
    scaled = true;
    if (shapes.size() == 0) {
      throw std::logic_error("No shapes for scale");
    }
    input >> scalingFactor[0];
    input >> scalingFactor[1];
    input >> scalingFactor[2];
    if (scalingFactor[2] <= 0) {
      shapes.clear();
      throw std::invalid_argument("under zero ratio with scale");
    }
  }
  if (!scaled) {
    shapes.clear();
    throw std::invalid_argument("No Arguments for scale");
  }
  return shapes;
}
