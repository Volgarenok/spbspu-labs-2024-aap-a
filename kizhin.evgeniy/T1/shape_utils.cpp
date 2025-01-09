#include "shape_utils.hpp"
#include <stdexcept>
#include <string>
#include "polygon.hpp"
#include "rectangle.hpp"
#include "regular.hpp"

namespace kizhin {
  Rectangle* createRectangle(const double*);
  Regular* createRegular(const double*);
  Polygon* createPolygon(const double*);
}

void kizhin::scaleShape(Shape* shape, double scalingFactor, const point_t& scalingPoint)
{
  Shape* tempShape = nullptr;
  try {
    tempShape = shape->clone();
    const point_t oldFramePos = tempShape->getFrameRect().pos;
    tempShape->move(scalingPoint);
    const point_t newFramePos = tempShape->getFrameRect().pos;
    tempShape->scale(scalingFactor);
    const double dx = (oldFramePos.x - newFramePos.x) * scalingFactor;
    const double dy = (oldFramePos.y - newFramePos.y) * scalingFactor;
    tempShape->move(dx, dy);
    shape->copyAssign(tempShape);
  } catch (...) {
    delete tempShape;
    throw;
  }
  delete tempShape;
}

void kizhin::unsafeScaleShapes(CompositeShape& shapes, const double* params)
{
  const double scalingFactor = params[3];
  const point_t scalingPoint{ params[1], params[2] };
  for (size_t i = 0; i != shapes.size(); ++i) {
    scaleShape(shapes[i], scalingFactor, scalingPoint);
  }
}

void kizhin::scaleShapes(CompositeShape& shapes, const double* params)
{
  if (params == nullptr) {
    throw std::invalid_argument("No scaling parameters provided");
  } else if (static_cast< size_t >(params[0] != 3)) {
    throw std::invalid_argument("Invalid scaling parameters count");
  }
  return unsafeScaleShapes(shapes, params);
}

kizhin::Shape* kizhin::createShape(const std::string& shapeName, const double* shapeParams)
{
  if (shapeName == "RECTANGLE") {
    return createRectangle(shapeParams);
  }
  if (shapeName == "REGULAR") {
    return createRegular(shapeParams);
  }
  if (shapeName == "POLYGON") {
    return createPolygon(shapeParams);
  }
  throw std::logic_error("Unknown shape provided");
}

kizhin::Rectangle* kizhin::createRectangle(const double* params)
{
  const point_t leftDown{ params[1], params[2] };
  const point_t rightUp{ params[3], params[4] };
  return new Rectangle{ leftDown, rightUp };
}

kizhin::Regular* kizhin::createRegular(const double* params)
{
  const point_t p1{ params[1], params[2] };
  const point_t p2{ params[3], params[4] };
  const point_t p3{ params[5], params[6] };
  return new Regular{ p1, p2, p3 };
}

kizhin::Polygon* kizhin::createPolygon(const double* params)
{
  const size_t size = static_cast< size_t >(params[0]);
  const size_t pointCount = size / 2;
  point_t* points = new point_t[pointCount];
  for (size_t i = 0; i < pointCount; ++i) {
    points[i].x = params[1 + i * 2];
    points[i].y = params[2 + i * 2];
  }
  Polygon* result = nullptr;
  try {
    result = new Polygon(points, pointCount);
  } catch (...) {
    delete[] points;
    throw;
  }
  delete[] points;
  return result;
}

