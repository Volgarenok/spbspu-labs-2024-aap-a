#include "shape_utils.hpp"
#include <stdexcept>
#include "polygon.hpp"
#include "rectangle.hpp"
#include "regular.hpp"

namespace kizhin {
  Rectangle* createRectangle(const double*);
  Regular* createRegular(const double*);
  Polygon* createPolygon(const double*);
  void scaleShape(Shape*, const double*);
}

void kizhin::scaleShapes(Shape* const* shapes, const double* params)
{
  for (Shape* const* i = shapes; *i != nullptr; ++i) {
    scaleShape(*i, params);
  }
}

void kizhin::scaleShape(Shape* shape, const double* params)
{
  const double scalingFactor = params[3];
  const point_t scalingPoint { params[1], params[2] };
  const point_t oldFramePos = shape->getFrameRect().pos;
  shape->move(scalingPoint);
  const point_t newFramePos = shape->getFrameRect().pos;
  shape->scale(scalingFactor);
  const double dx = (oldFramePos.x - newFramePos.x) * scalingFactor;
  const double dy = (oldFramePos.y - newFramePos.y) * scalingFactor;
  shape->move(dx, dy);
}

double kizhin::computeTotalArea(const Shape* const* shapes)
{
  double area = 0.0;
  for (const Shape* const* i = shapes; *i != nullptr; ++i) {
    area += (*i)->getArea();
  }
  return area;
}

void kizhin::deleteShapes(Shape* const* shapes)
{
  for (Shape* const* i = shapes; *i != nullptr; ++i) {
    delete *i;
  }
}

kizhin::Shape* kizhin::createShape(const std::string& shapeName, const double* shapeParams)
{
  if (shapeName == "RECTANGLE") {
    return createRectangle(shapeParams);
  }
  if (shapeName == "REGULAR") {
    return createRegular(shapeParams);
  }
  if (shapeName== "POLYGON") {
    return createPolygon(shapeParams);
  }
  throw std::logic_error("Failed to create shape");
}

kizhin::Rectangle* kizhin::createRectangle(const double* params)
{
  const point_t leftDown { params[1], params[2] };
  const point_t rightUp { params[3], params[4] };
  if (leftDown.x >= rightUp.x || leftDown.y >= rightUp.y) {
    throw std::logic_error("Failed to create rectangle");
  }
  const double width = rightUp.x - leftDown.x;
  const double height = rightUp.y - leftDown.y;
  const point_t center { 0.5 * (leftDown.x + rightUp.x), 0.5 * (leftDown.y + rightUp.y) };
  return new Rectangle { width, height, center };
}

kizhin::Regular* kizhin::createRegular(const double* params)
{
  const point_t p1 { params[1], params[2] };
  const point_t p2 { params[3], params[4] };
  const point_t p3 { params[5], params[6] };
  return new Regular { p1, p2, p3 };
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

