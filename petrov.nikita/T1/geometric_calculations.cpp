#include "geometric_calculations.hpp"
#include <cmath>

double petrov::calculateDistBtwPoints(const point_t & p1, const point_t & p2)
{
  return std::sqrt(std::pow((p1.x - p2.x), 2) + std::pow((p1.y - p2.y), 2));
}

void petrov::changeCoordinates(point_t ** points, size_t number_of_points, double dx, double dy)
{
  for (size_t i = 0; i < number_of_points; i++)
  {
    points[i]->x += dx;
    points[i]->y += dy;
  }
}

void petrov::changeCoordinatesDueToScaling(point_t ** points, const point_t & pos, size_t pts_num, double scale_value)
{
  for (size_t i = 0; i < pts_num; i++)
  {
    points[i]->x = pos.x + (points[i]->x - pos.x) * scale_value;
    points[i]->y = pos.y + (points[i]->y - pos.y) * scale_value;
  }
}

petrov::rectangle_t petrov::getFrameRectByOtherShapes(const Shape * const * ptr_shapes, size_t number_of_shapes)
{
  rectangle_t shape_frame_rect = ptr_shapes[0]->getFrameRect();
  double xmin = shape_frame_rect.pos.x - shape_frame_rect.width / 2;
  double ymin = shape_frame_rect.pos.y - shape_frame_rect.height / 2;
  double xmax = shape_frame_rect.pos.x + shape_frame_rect.width / 2;
  double ymax = shape_frame_rect.pos.y + shape_frame_rect.height / 2;
  for (size_t i = 1; i < number_of_shapes; i++)
  {
    shape_frame_rect = ptr_shapes[i]->getFrameRect();
    double temp_xmin = shape_frame_rect.pos.x - shape_frame_rect.width / 2;
    double temp_ymin = shape_frame_rect.pos.y - shape_frame_rect.height / 2;
    double temp_xmax = shape_frame_rect.pos.x + shape_frame_rect.width / 2;
    double temp_ymax = shape_frame_rect.pos.y + shape_frame_rect.height / 2;
    temp_xmin < xmin ? xmin = temp_xmin : xmin = xmin;
    temp_ymin < ymin ? ymin = temp_ymin : ymin = ymin;
    temp_xmax > xmax ? xmax = temp_xmax : xmax = xmax;
    temp_ymax > ymax ? ymax = temp_ymax : ymax = ymax;
  }
  double width = xmax - xmin;
  double height = ymax - ymin;
  point_t pos = { ((xmin + xmax) / 2.0), ((ymin + ymax) / 2.0) };
  return { width, height, pos };
}
