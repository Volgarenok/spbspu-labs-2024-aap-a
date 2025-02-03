#include "shape_actions.hpp"
#include <cstddef>

void sveshnikov::isotropic_scaling(CompositeShape &comp_shp, double zoom_ctr_x, double zoom_ctr_y, double k)
{
  point_t center = comp_shp.getFrameRect().pos;
  comp_shp.move({zoom_ctr_x, zoom_ctr_y});
  double dx = 0.0, dy = 0.0;
  comp_shp.scale(k);
  dx = k * (center.x - zoom_ctr_x);
  dy = k * (center.y - zoom_ctr_y);
  comp_shp.move(dx, dy);
}

void sveshnikov::output_frame(std::ostream &out, const CompositeShape &comp_shp)
{
  double low_left_x = 0.0, low_left_y = 0.0, up_right_x = 0.0, up_right_y = 0.0;
  for (size_t i = 0; i != comp_shp.size(); i++)
  {
    rectangle_t frame = comp_shp[i]->getFrameRect();
    low_left_x = frame.pos.x - frame.width / 2;
    low_left_y = frame.pos.y - frame.height / 2;
    up_right_x = frame.pos.x + frame.width / 2;
    up_right_y = frame.pos.y + frame.height / 2;
    out << low_left_x << " " << low_left_y << " " << up_right_x << " " << up_right_y;
    if (comp_shp[i + 1] != nullptr)
    {
      out << " ";
    }
  }
}
