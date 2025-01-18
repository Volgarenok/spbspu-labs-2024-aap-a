#include "figureactions.hpp"

namespace
{
  void moveShapeInIsoScale(tkach::Shape* shape, const double scale_coef, const tkach::point_t& scale_point)
  {
    tkach::point_t init_point = shape->getFrameRect().pos;
    shape->move(scale_point);
    tkach::point_t scaled_point = shape->getFrameRect().pos;
    double scaled_dx = (scaled_point.x - init_point.x) * scale_coef;
    double scaled_dy = (scaled_point.y - init_point.y) * scale_coef;
    shape->move(-1 * scaled_dx, -1 * scaled_dy);
  }
}

void tkach::doSaveIsoScaleCompShape(CompositeShape& shape_array, double scale_coef, const point_t& scale_point)
{
  for (size_t i = 0; i < shape_array.size(); ++i)
  {
    doSaveIsoScaleOneShape(shape_array[i], scale_coef, scale_point);
  }
}

void tkach::doUnsaveIsoScaleCompShape(CompositeShape& shape_array, double scale_coef, const point_t& scale_point)
{
  for (size_t i = 0; i < shape_array.size(); ++i)
  {
    doUnsaveIsoScaleOneShape(shape_array[i], scale_coef, scale_point);
  }
}

void tkach::doUnsaveIsoScaleOneShape(Shape* shape, const double scale_coef, const point_t& scale_point)
{
  shape->doUnsafeScale(scale_coef);
  moveShapeInIsoScale(shape, scale_coef, scale_point);
}

void tkach::doUnsaveIsoScaleShapes(Shape* const* const shape_array, const size_t counter_of_shapes, const double scale_coef,
  const point_t& scale_point)
{
  for (size_t i = 0; i < counter_of_shapes; ++i)
  {
    doUnsaveIsoScaleOneShape(shape_array[i], scale_coef, scale_point);
  }
}

void tkach::doSaveIsoScaleOneShape(Shape* shape, const double scale_coef, const point_t& scale_point)
{
  shape->scale(scale_coef);
  moveShapeInIsoScale(shape, scale_coef, scale_point);
}

void tkach::doSaveIsoScaleShapes(Shape* const* const shape_array, const size_t counter_of_shapes, const double scale_coef,
  const point_t& scale_point)
{
  for (size_t i = 0; i < counter_of_shapes; ++i)
  {
    doSaveIsoScaleOneShape(shape_array[i], scale_coef, scale_point);
  }
}
