#include "shape_actions.hpp"
#include <cstddef>

void sveshnikov::isotropic_scaling(Shape **shapes, double zoom_ctr_x, double zoom_ctr_y, double k)
{
  for (size_t i = 0; shapes[i] != nullptr; i++)
  {
    point_t pos = shapes[i]->getFrameRect().pos;
    shapes[i]->move({zoom_ctr_x, zoom_ctr_y});
    double dx = 0.0, dy = 0.0;
    shapes[i]->scale(k);
    dx = k * (pos.x - shapes[i]->getFrameRect().pos.x);
    dy = k * (pos.y - shapes[i]->getFrameRect().pos.y);
    shapes[i]->move(dx, dy);
  }
}

void sveshnikov::output_total_area(std::ostream &out, Shape **shapes)
{
  double total_area = 0.0;
  for (size_t i = 0; shapes[i] != nullptr; i++)
  {
    total_area += shapes[i]->getArea();
  }
  out << total_area << " ";
}

void sveshnikov::output_frame(std::ostream &out, Shape **shapes)
{
  double low_left_x = 0.0, low_left_y = 0.0, up_right_x = 0.0, up_right_y = 0.0;
  for (size_t i = 0; shapes[i] != nullptr; i++)
  {
    rectangle_t frame = shapes[i]->getFrameRect();
    low_left_x = frame.pos.x - frame.width / 2;
    low_left_y = frame.pos.y - frame.height / 2;
    up_right_x = frame.pos.x + frame.width / 2;
    up_right_y = frame.pos.y + frame.height / 2;
    out << low_left_x << " " << low_left_y << " " << up_right_x << " " << up_right_y;
    if (shapes[i + 1] != nullptr)
    {
      out << " ";
    }
  }
  out << '\n';
}
