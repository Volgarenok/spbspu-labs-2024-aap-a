#include "scale_isotropically_and_output_data.hpp"
#include "base-types.hpp"
#include "composite-shape.hpp"
#include "shape.hpp"
#include <iostream>
void petrov::scaleIsotropicallyAndOutputData(petrov::point_t scale_point, double k, petrov::CompositeShape * composite_shape)
{
  size_t created = composite_shape->size();
  double first_sum_area = composite_shape->getArea();
  std::cout << first_sum_area;
  for (size_t i = 0; i < created; i++)
  {
    petrov::rectangle_t frame_rect = (*composite_shape)[i]->getFrameRect();
    std::cout << " " << frame_rect.pos.x - (frame_rect.width / 2);
    std::cout << " " << frame_rect.pos.y - (frame_rect.height / 2);
    std::cout << " " << frame_rect.pos.x + (frame_rect.width / 2);
    std::cout << " " << frame_rect.pos.y + (frame_rect.height / 2);
    double mv_dx = frame_rect.pos.x - scale_point.x;
    double mv_dy = frame_rect.pos.y - scale_point.y;
    (*composite_shape)[i]->move(scale_point);
    (*composite_shape)[i]->scale(k);
    mv_dx *= k;
    mv_dy *= k;
    (*composite_shape)[i]->move(mv_dx, mv_dy);
  }
  std::cout << "\n";
  double second_sum_area = 0.0;
  second_sum_area = composite_shape->getArea();
  std::cout << second_sum_area;
  for (size_t i = 0; i < created; i++)
  {
    petrov::rectangle_t frame_rect = (*composite_shape)[i]->getFrameRect();
    std::cout << " " << frame_rect.pos.x - (frame_rect.width / 2);
    std::cout << " " << frame_rect.pos.y - (frame_rect.height / 2);
    std::cout << " " << frame_rect.pos.x + (frame_rect.width / 2);
    std::cout << " " << frame_rect.pos.y + (frame_rect.height / 2);
  }
  std::cout << "\n";
}
