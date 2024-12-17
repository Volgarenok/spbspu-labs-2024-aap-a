#include "scale_isotropically.hpp"
#include "base-types.hpp"
#include "shape.hpp"
#include <iostream>
void petrov::scaleIsotropicallyAndOutputData(point_t scale_point, double k, Shape ** shape, size_t count)
{
  double first_sum_area = 0.0;
  double second_sum_area = 0.0;
  double first_all_coordinates[10000][4] = { 0 };
  double second_all_coordinates[10000][4] = { 0 };
  for (size_t i = 0; i < count; i++)
  {
    rectangle_t frame_rect = (*shape)[i].getFrameRect();
    point_t lower_left_corner = { (frame_rect.pos_.x_ - (frame_rect.width_ / 2)), (frame_rect.pos_.y_ - (frame_rect.height_ / 2)) };
    point_t upper_right_corner = { (frame_rect.pos_.x_ + (frame_rect.width_ / 2)), (frame_rect.pos_.y_ + (frame_rect.height_ / 2)) };
    first_all_coordinates[i][0] = lower_left_corner.x_;
    first_all_coordinates[i][1] = lower_left_corner.y_;
    first_all_coordinates[i][2] = upper_right_corner.x_;
    first_all_coordinates[i][3] = upper_right_corner.y_;
    first_sum_area += (*(shape[i])).getArea();
    double mv_dx = frame_rect.pos_.x_ - scale_point.x_;
    double mv_dy = frame_rect.pos_.y_ - scale_point.y_;
    (*(shape[i])).move(scale_point);
    (*(shape[i])).scale(k);
    second_sum_area += (*(shape[i])).getArea();
    mv_dx *= k;
    mv_dy *= k;
    (*(shape[i])).move(mv_dx, mv_dy);
    frame_rect = (*shape)[i].getFrameRect();
    lower_left_corner = { (frame_rect.pos_.x_ - (frame_rect.width_ / 2)), (frame_rect.pos_.y_ - (frame_rect.height_ / 2)) };
    upper_right_corner = { (frame_rect.pos_.x_ + (frame_rect.width_ / 2)), (frame_rect.pos_.y_ + (frame_rect.height_ / 2)) };
    second_all_coordinates[i][0] = lower_left_corner.x_;
    second_all_coordinates[i][1] = lower_left_corner.y_;
    second_all_coordinates[i][2] = upper_right_corner.x_;
    second_all_coordinates[i][3] = upper_right_corner.y_;
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
