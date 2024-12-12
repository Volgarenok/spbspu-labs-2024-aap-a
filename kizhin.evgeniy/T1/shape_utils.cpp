#include "shape_utils.hpp"
#include <cassert>
#include <cstring>
#include <stdexcept>
#include "base-types.hpp"
#include "polygon.hpp"
#include "rectangle.hpp"
#include "regular.hpp"

namespace kizhin {
  Rectangle* createRectangle(const double*);
  Regular* createRegular(const double*);
  Polygon* createPolygon(const double*);
  void scaleShape(Shape*, const double*);
}

void kizhin::scaleShapes(Shape* const* shapes, size_t size, const double* params)
{
  for (Shape* const* i = shapes; i != shapes + size; ++i) {
    scaleShape(*i, params);
  }
}

void kizhin::scaleShape(Shape* shape, const double* params)
{
  assert(params && params[0] == 3);
  const double scalingFactor = params[3];
  if (scalingFactor <= 0) {
    throw std::logic_error("Invalid Scale Factor");
  }
  const point_t scalingPoint { params[1], params[2] };

  const point_t oldFramePos = shape->getFrameRect().pos;
  shape->move(scalingPoint);
  const point_t newFramePos = shape->getFrameRect().pos;
  shape->scale(scalingFactor);

  const double dx = (oldFramePos.x - newFramePos.x) * scalingFactor;
  const double dy = (oldFramePos.y - newFramePos.y) * scalingFactor;
  shape->move(dx, dy);
}

double kizhin::computeTotalArea(const Shape* const* shapes, size_t size)
{
  double area = 0.0;
  for (const Shape* const* i = shapes; i != shapes + size; ++i) {
    area += (*i)->getArea();
  }
  return area;
}

kizhin::Shape* kizhin::createShape(const char* shapeName, const double* shapeParams)
{
  if (!shapeName || !shapeParams) {
    return nullptr;
  }
  if (std::strcmp(shapeName, "RECTANGLE") == 0) {
    return createRectangle(shapeParams);
  }
  if (std::strcmp(shapeName, "REGULAR") == 0) {
    return createRegular(shapeParams);
  }
  if (std::strcmp(shapeName, "POLYGON") == 0) {
    return createPolygon(shapeParams);
  }
  return nullptr;
}

kizhin::Rectangle* kizhin::createRectangle(const double* params)
{
  assert(params && params[0] == 4);
  const point_t leftDown { params[1], params[2] };
  const point_t rightUp { params[3], params[4] };
  if (leftDown.x >= rightUp.x || leftDown.y >= rightUp.y) {
    return nullptr;
  }
  const double width = rightUp.x - leftDown.x;
  const double height = rightUp.y - leftDown.y;
  const point_t center { 0.5 * (leftDown.x + rightUp.x), 0.5 * (leftDown.y + rightUp.y) };
  return new Rectangle { width, height, center };
}

kizhin::Regular* kizhin::createRegular(const double* params)
{
  assert(params && params[0] == 6);
  const point_t p1 { params[1], params[2] };
  const point_t p2 { params[3], params[4] };
  const point_t p3 { params[5], params[6] };
  Regular* result = nullptr;
  try {
    result = new Regular { p1, p2, p3 };
  } catch (const std::logic_error&) {
    return nullptr;
  }
  return result;
}

kizhin::Polygon* kizhin::createPolygon(const double* params)
{
  assert(params);
  const size_t size = static_cast< size_t >(params[0]);
  assert(size && size % 2 == 0);
  const size_t pointCount = size / 2;
  point_t* points = new point_t[pointCount];
  for (size_t i = 0; i < pointCount; ++i) {
    points[i].x = params[1 + i * 2];
    points[i].y = params[2 + i * 2];
  }
  Polygon* result = nullptr;
  try {
    result = new Polygon(points, pointCount);
    delete[] points;
  } catch (const std::logic_error&) {
    delete[] points;
    return nullptr;
  } catch (...) {
    delete[] points;
    throw;
  }
  return result;
}
