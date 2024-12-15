#include "rectangle.h"
#include <cmath>

timofeev::Rectangle::Rectangle(double ldx, double ldy, double rux, double ruy)
{
  ld_.x = ldx;
  ld_.y = ldy;
  ru_.x = rux;
  ru_.y = ruy;
}

double timofeev::Rectangle::get_area() const {
  return (ld_.x - ru_.x) * (ld_.y - ru_.y);
}

timofeev::rectangle_t timofeev::Rectangle::get_frame_rect() const {
  timofeev::rectangle_t frame_rect;
  frame_rect.height = (ld_.y - ru_.y);
  frame_rect.width = (ld_.x - ru_.x);
  frame_rect.pos.x = ld_.x + (frame_rect.width / 2);
  frame_rect.pos.y = ld_.y + (frame_rect.height / 2);
  return frame_rect;
}

void timofeev::Rectangle::move(timofeev::point_t new_pos)
{
  timofeev::point_t pos_an = get_frame_rect().pos;
  double move_x = new_pos.x - pos_an.x;
  double move_y = new_pos.y - pos_an.y;
  ld_.x = ld_.x + move_x;
  ru_.x = ru_.x + move_x;
  ld_.y = ld_.y + move_y;
  ru_.y = ru_.y + move_y;
}

void timofeev::Rectangle::move(double move_x, double move_y)
{
  ld_.x = ld_.x + move_x;
  ru_.x = ru_.x + move_x;
  ld_.y = ld_.y + move_y;
  ru_.y = ru_.y + move_y;
}

void timofeev::Rectangle::scale(double factor) {
  timofeev::point_t pos_an = get_frame_rect().pos;
  ld_.x = pos_an.x - (pos_an.x - ld_.x) * factor;
  ru_.x = pos_an.x + (ru_.x - pos_an.x) * factor;
  ld_.y = pos_an.y - (pos_an.y - ld_.y) * factor;
  ru_.y = pos_an.y + (ld_.y - pos_an.y) * factor;
}
