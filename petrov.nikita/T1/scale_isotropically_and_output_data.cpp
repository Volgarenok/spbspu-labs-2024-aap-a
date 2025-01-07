#include "scale_isotropically_and_output_data.hpp"
#include "base-types.hpp"
#include "shape.hpp"
#include <iostream>
void petrov::scaleIsotropicallyAndOutputData(petrov::point_t scale_point, double k, petrov::Shape ** shape, size_t count)
{
  double first_sum_area = 0.0;
  double second_sum_area = 0.0;
  double first_all_coordinates[10000][4] = { 0 };
  double second_all_coordinates[10000][4] = { 0 };
  for (size_t i = 0; i < count; i++)
  {
    petrov::rectangle_t frame_rect = shape[i]->getFrameRect();
    petrov::point_t lower_left_corner = { (frame_rect.pos.x - (frame_rect.width / 2)), (frame_rect.pos.y - (frame_rect.height / 2)) };
    petrov::point_t upper_right_corner = { (frame_rect.pos.x + (frame_rect.width / 2)), (frame_rect.pos.y + (frame_rect.height / 2)) };
    first_all_coordinates[i][0] = lower_left_corner.x;
    first_all_coordinates[i][1] = lower_left_corner.y;
    first_all_coordinates[i][2] = upper_right_corner.x;
    first_all_coordinates[i][3] = upper_right_corner.y;
    first_sum_area += shape[i]->getArea();
    double mv_dx = frame_rect.pos.x - scale_point.x;
    double mv_dy = frame_rect.pos.y - scale_point.y;
    shape[i]->move(scale_point);
    shape[i]->scale(k);
    second_sum_area += shape[i]->getArea();
    mv_dx *= k;
    mv_dy *= k;
    shape[i]->move(mv_dx, mv_dy);
    frame_rect = shape[i]->getFrameRect();
    lower_left_corner = { (frame_rect.pos.x - (frame_rect.width / 2)), (frame_rect.pos.y - (frame_rect.height / 2)) };
    upper_right_corner = { (frame_rect.pos.x + (frame_rect.width / 2)), (frame_rect.pos.y + (frame_rect.height / 2)) };
    second_all_coordinates[i][0] = lower_left_corner.x;
    second_all_coordinates[i][1] = lower_left_corner.y;
    second_all_coordinates[i][2] = upper_right_corner.x;
    second_all_coordinates[i][3] = upper_right_corner.y;
  }
  std::cout << first_sum_area;
  for (size_t i = 0; i < count; i++)
  {
    std::cout << " " << first_all_coordinates[i][0];
    for (size_t j = 1; j < 4; j++)
    {
      std::cout << " " << first_all_coordinates[i][j];
    }
  }
  std::cout << "\n";
  std::cout << second_sum_area;
  for (size_t i = 0; i < count; i++)
  {
    std::cout << " " << second_all_coordinates[i][0];
    for (size_t j = 1; j < 4; j++)
    {
      std::cout << " " << second_all_coordinates[i][j];
    }
  }
  std::cout << "\n";
}
