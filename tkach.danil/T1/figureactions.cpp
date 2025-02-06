#include "figureactions.hpp"
#include <stdexcept>

namespace
{
  void moveShapeInIsoScale(tkach::Shape* shape, const double scale_coef, const tkach::point_t& scale_point)
  {
    tkach::point_t init_point = shape->getFrameRect().pos;
    shape->move(scale_point);
    tkach::point_t scaled_point = shape->getFrameRect().pos;
    double scaled_dx = tkach::getCoordDistMultiplied(scaled_point.x, init_point.x, scale_coef);
    double scaled_dy = tkach::getCoordDistMultiplied(scaled_point.y, init_point.y, scale_coef);
    shape->move(-1 * scaled_dx, -1 * scaled_dy);
  }

  void doUnsafeIsoScaleOneShape(tkach::Shape* shape, const double scale_coef, const tkach::point_t& scale_point)
  {
    shape->doUnsafeScale(scale_coef);
    moveShapeInIsoScale(shape, scale_coef, scale_point);
  }
}

void tkach::doSafeIsoScaleCompShape(CompositeShape& shape_array, const double scale_coef, const point_t& scale_point)
{
  if (scale_coef <= 0)
  {
    throw std::logic_error("Not positive coef");
  }
  doUnsafeIsoScaleCompShape(shape_array, scale_coef, scale_point);
}

void tkach::doUnsafeIsoScaleCompShape(CompositeShape& shape_array, const double scale_coef, const point_t& scale_point)
{
  for (size_t i = 0; i < shape_array.size(); ++i)
  {
    doUnsafeIsoScaleOneShape(shape_array[i], scale_coef, scale_point);
  }
}

