#include "scale_isotropically_and_output_data.hpp"
#include <iostream>

namespace
{
  void outputCoordinatesOfFrameRect(std::ostream & out, const petrov::rectangle_t & frame_rect);

  void outputCoordinatesOfFrameRect(std::ostream & out, const petrov::rectangle_t & frame_rect)
  {
    out << " " << frame_rect.pos.x - (frame_rect.width / 2);
    out << " " << frame_rect.pos.y - (frame_rect.height / 2);
    out << " " << frame_rect.pos.x + (frame_rect.width / 2);
    out << " " << frame_rect.pos.y + (frame_rect.height / 2);
  }
}

void petrov::scaleIsotropicallyAndOutputData(const point_t & scale_point, double k, CompositeShape & composite_shape)
{
  size_t created = composite_shape.size();
  double first_sum_area = composite_shape.getArea();
  std::cout << first_sum_area;
  for (size_t i = 0; i < created; i++)
  {
    rectangle_t frame_rect = composite_shape[i]->getFrameRect();
    outputCoordinatesOfFrameRect(std::cout, frame_rect);
    double mv_dx = frame_rect.pos.x - scale_point.x;
    double mv_dy = frame_rect.pos.y - scale_point.y;
    composite_shape[i]->move(scale_point);
    composite_shape[i]->scale(k);
    mv_dx *= k;
    mv_dy *= k;
    composite_shape[i]->move(mv_dx, mv_dy);
  }
  std::cout << "\n";
  double second_sum_area = 0.0;
  second_sum_area = composite_shape.getArea();
  std::cout << second_sum_area;
  for (size_t i = 0; i < created; i++)
  {
    rectangle_t frame_rect = composite_shape[i]->getFrameRect();
    outputCoordinatesOfFrameRect(std::cout, frame_rect);
  }
  std::cout << "\n";
}
