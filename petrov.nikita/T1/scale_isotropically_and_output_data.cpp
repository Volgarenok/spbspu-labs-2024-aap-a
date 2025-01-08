#include "scale_isotropically_and_output_data.hpp"
#include "base-types.hpp"
#include "shape.hpp"
#include <iostream>
void petrov::scaleIsotropicallyAndOutputData(petrov::point_t scale_point, double k, petrov::Shape ** shape, size_t created)
{
  double first_sum_area = 0.0;
  for (size_t i = 0; i < created; i++)
  {
    first_sum_area += shape[i]->getArea();
  }
  std::cout << first_sum_area << " ";
  for (size_t i = 0; i < created; i++)
  {
    petrov::rectangle_t frame_rect = shape[i]->getFrameRect();
    std::cout << frame_rect.pos.x - (frame_rect.width / 2) << " ";
    std::cout << frame_rect.pos.y - (frame_rect.height / 2) << " ";
    std::cout << frame_rect.pos.x + (frame_rect.width / 2) << " ";
    std::cout << frame_rect.pos.y + (frame_rect.height / 2) << " ";
    double mv_dx = frame_rect.pos.x - scale_point.x;
    double mv_dy = frame_rect.pos.y - scale_point.y;
    shape[i]->move(scale_point);
    shape[i]->scale(k);
    mv_dx *= k;
    mv_dy *= k;
    shape[i]->move(mv_dx, mv_dy);
  }
  std::cout << "\b\n";
  double second_sum_area = 0.0;
  for (size_t i = 0; i < created; i++)
  {
    second_sum_area += shape[i]->getArea();
  }
  std::cout << second_sum_area << " ";
  for (size_t i = 0; i < created; i++)
  {
    petrov::rectangle_t frame_rect = shape[i]->getFrameRect();
    std::cout << frame_rect.pos.x - (frame_rect.width / 2) << " ";
    std::cout << frame_rect.pos.y - (frame_rect.height / 2) << " ";
    std::cout << frame_rect.pos.x + (frame_rect.width / 2) << " ";
    std::cout << frame_rect.pos.y + (frame_rect.height / 2) << " ";
  }
  std::cout << "\b\n";
}
