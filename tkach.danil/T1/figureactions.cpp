#include "figureactions.hpp"

namespace
{
  void setFrameRectPoints(const tkach::rectangle_t& frame_rect, tkach::point_t& left_bot_point, tkach::point_t& right_top_point)
  {
    left_bot_point.x = frame_rect.pos.x - frame_rect.width / 2.0;
    left_bot_point.y = frame_rect.pos.y - frame_rect.height / 2.0;
    right_top_point.x = frame_rect.pos.x + frame_rect.width / 2.0;
    right_top_point.y = frame_rect.pos.y + frame_rect.height / 2.0;
  }

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

void tkach::deleteShapes(tkach::Shape** shape_array, const size_t counter_of_shapes)
{
  for (size_t i = 0; i < counter_of_shapes; ++i)
  {
    delete shape_array[i];
  }
}

double tkach::getTotalArea(const tkach::Shape* const* const shape_array, const size_t counter_of_shapes)
{
  double sum = 0.0;
  for (size_t i = 0; i < counter_of_shapes; ++i)
  {
    sum += shape_array[i]->getArea();
  }
  return sum;
}

std::ostream& tkach::printCoordinatesOfAllFrameRects(std::ostream& out, const tkach::Shape* const* const shape_array, const size_t counter_of_shapes)
{
  tkach::rectangle_t frame_rect = shape_array[0]->getFrameRect();
  tkach::point_t left_bot_point, right_top_point;
  setFrameRectPoints(frame_rect, left_bot_point, right_top_point);
  out << left_bot_point.x << " " << left_bot_point.y << " " << right_top_point.x << " " << right_top_point.y;
  for (size_t i = 1; i < counter_of_shapes; ++i)
  {
    frame_rect = shape_array[i]->getFrameRect();
    setFrameRectPoints(frame_rect, left_bot_point, right_top_point);
    out << " " << left_bot_point.x << " " << left_bot_point.y << " " << right_top_point.x << " " << right_top_point.y;
  }
  return out;
}

void tkach::doUnsaveIsoScaleOneShape(tkach::Shape* shape, const double scale_coef, const tkach::point_t& scale_point)
{
  shape->scaleOneOfUniqueShapes(scale_coef);
  moveShapeInIsoScale(shape, scale_coef, scale_point);
}

void tkach::doUnsaveIsoScaleShapes(tkach::Shape* const* const shape_array, const size_t counter_of_shapes, const double scale_coef,
  const tkach::point_t& scale_point)
{
  for (size_t i = 0; i < counter_of_shapes; ++i)
  {
    doUnsaveIsoScaleOneShape(shape_array[i], scale_coef, scale_point);
  }
}

void tkach::doSaveIsoScaleOneShape(tkach::Shape* shape, const double scale_coef, const tkach::point_t& scale_point)
{
  shape->scale(scale_coef);
  moveShapeInIsoScale(shape, scale_coef, scale_point);
}

void tkach::doSaveIsoScaleShapes(tkach::Shape* const* const shape_array, const size_t counter_of_shapes, const double scale_coef,
  const tkach::point_t& scale_point)
{
  for (size_t i = 0; i < counter_of_shapes; ++i)
  {
    doSaveIsoScaleOneShape(shape_array[i], scale_coef, scale_point);
  }
}
