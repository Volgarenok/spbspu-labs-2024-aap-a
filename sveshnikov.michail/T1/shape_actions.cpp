#include "shape_actions.hpp"
#include <cstddef>

void sveshnikov::isotropic_scaling(CompositeShape &comp_shp, double zoom_ctr_x, double zoom_ctr_y, double k)
{
  point_t center = comp_shp.getFrameRect().pos;
  comp_shp.move({zoom_ctr_x, zoom_ctr_y});
  comp_shp.scale(k);
  double dx = k * (center.x - zoom_ctr_x);
  double dy = k * (center.y - zoom_ctr_y);
  comp_shp.move(dx, dy);
}

void sveshnikov::output_one_frame(std::ostream &out, const Shape *shp)
{
  rectangle_t frame = shp->getFrameRect();
  double low_left_x = frame.pos.x - frame.width / 2;
  double low_left_y = frame.pos.y - frame.height / 2;
  double up_right_x = frame.pos.x + frame.width / 2;
  double up_right_y = frame.pos.y + frame.height / 2;
  out << low_left_x << " " << low_left_y << " " << up_right_x << " " << up_right_y;
}

void sveshnikov::output_frames(std::ostream &out, const CompositeShape &comp_shp)
{
  output_one_frame(out, comp_shp[0]);
  for (size_t i = 1; i != comp_shp.size(); i++)
  {
    out << " ";
    output_one_frame(out, comp_shp[i]);
  }
}
