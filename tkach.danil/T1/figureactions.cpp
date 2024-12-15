#include "figureactions.hpp"

void tkach::deleteShapes(tkach::Shape** shape_array, size_t counter_of_shapes)
{
  for (size_t i = 0; i < counter_of_shapes; ++i)
  {
    delete shape_array[i];
  }
}

double tkach::getTotalArea(tkach::Shape** shape_array, size_t counter_of_shapes)
{
  double sum = 0;
  for (size_t i = 0; i < counter_of_shapes; ++i)
  {
    sum += shape_array[i]->getArea();
  }
  return sum;
}

void tkach::printCoordinatesOfFrameRect(std::ostream& out, tkach::Shape** shape_array, size_t counter_of_shapes)
{
  for (size_t i = 0; i < counter_of_shapes; ++i)
  {
    tkach::rectangle_t frame_rect = shape_array[i]->getFrameRect();
    tkach::point_t left_bot_point, right_top_point;
    left_bot_point.x = frame_rect.pos.x - frame_rect.width / 2.0;
    left_bot_point.y = frame_rect.pos.y - frame_rect.height / 2.0;
    right_top_point.x = frame_rect.pos.x + frame_rect.width / 2.0;
    right_top_point.y = frame_rect.pos.y + frame_rect.height / 2.0;
    out << left_bot_point.x << " " << left_bot_point.y << " " << right_top_point.x << " " << right_top_point.y;
  }
}

void tkach::doIsoScaleShapes(tkach::Shape** shape_array, size_t counter_of_shapes, double scale_coef, const tkach::point_t& scale_point)
{
  for (size_t i = 0; i < counter_of_shapes; ++i)
  {
    tkach::point_t init_point = shape_array[i]->getFrameRect().pos;
    shape_array[i]->move(scale_point);
    tkach::point_t scaled_point = shape_array[i]->getFrameRect().pos;
    shape_array[i]->scale(scale_coef);
    double scaled_dx = (scaled_point.x - init_point.x) * scale_coef;
    double scaled_dy = (scaled_point.y - init_point.y) * scale_coef;
    shape_array[i]->move(-1 * scaled_dx, -1 * scaled_dy);
  }
}
