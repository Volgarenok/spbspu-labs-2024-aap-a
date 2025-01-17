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

  template< typename Container >
  std::ostream& printFrameRects(std::ostream& Out, const Container& Shapes, const size_t Size)
  {
    tkach::rectangle_t frame_rect = Shapes[0]->getFrameRect();
    tkach::point_t left_bot_point, right_top_point;
    setFrameRectPoints(frame_rect, left_bot_point, right_top_point);
    Out << left_bot_point.x << " " << left_bot_point.y << " " << right_top_point.x << " " << right_top_point.y;
    for (size_t i = 1; i < Size; ++i)
    {
      frame_rect = Shapes[i]->getFrameRect();
      setFrameRectPoints(frame_rect, left_bot_point, right_top_point);
      Out << " " << left_bot_point.x << " " << left_bot_point.y << " " << right_top_point.x << " " << right_top_point.y;
    }
    return Out;
  }
}

void tkach::deleteShapes(Shape** shape_array, const size_t counter_of_shapes)
{
  for (size_t i = 0; i < counter_of_shapes; ++i)
  {
    delete shape_array[i];
  }
}

double tkach::getTotalArea(const Shape* const* const shape_array, const size_t counter_of_shapes)
{
  double sum = 0.0;
  for (size_t i = 0; i < counter_of_shapes; ++i)
  {
    sum += shape_array[i]->getArea();
  }
  return sum;
}

std::ostream& tkach::printCoordinatesOfAllFrameRects(std::ostream& out, const Shape* const* const shape_array,
  const size_t counter_of_shapes)
{
  return printFrameRects(out, shape_array, counter_of_shapes);
}

std::ostream& tkach::printAllFrameRectsFromCompShape(std::ostream& out, const CompositeShape& shape_array)
{
  return printFrameRects(out, shape_array, shape_array.size());
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
  const tkach::point_t& scale_point)
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
