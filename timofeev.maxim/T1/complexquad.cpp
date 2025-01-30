#include "complexquad.hpp"
#include "shapes_tools.hpp"
timofeev::Complexquad::Complexquad(point_t p1, point_t p2, point_t p3, point_t p4):
  p1_(p1),
  p2_(p2),
  p3_(p3),
  p4_(p4)
{
}

double timofeev::Complexquad::getArea() const
{
  point_t pos = timofeev::cross_point(p1_, p2_, p3_, p4_);
  double first_part = timofeev::triangle_area(p1_, p4_, pos);
  double second_part = timofeev::triangle_area(pos, p2_, p3_);
  return first_part + second_part;
}

timofeev::rectangle_t timofeev::Complexquad::getFrameRect() const
{
  double left_border = std::fmin(std::fmin(std::fmin(p1_.x, p2_.x), p3_.x), p4_.x);
  double right_border = std::fmax(std::fmax(std::fmax(p1_.x, p2_.x), p3_.x), p4_.x);
  double upper_border = std::fmax(std::fmax(std::fmax(p1_.y, p2_.y), p3_.y), p4_.y);
  double lower_border = std::fmin(std::fmin(std::fmin(p1_.y, p2_.y), p3_.y), p4_.y);
  double height = upper_border - lower_border;
  double width = right_border - left_border;
  double posx = left_border + width / 2;
  double posy = lower_border + height / 2;
  rectangle_t frame_rect{width, height, {posx, posy}};
  return frame_rect;
}

void timofeev::Complexquad::move(point_t new_pos)
{
  point_t pos_an = getFrameRect().pos;
  double move_x = new_pos.x - pos_an.x;
  double move_y = new_pos.y - pos_an.y;
  p1_.x += move_x;
  p1_.y += move_y;
  p2_.x += move_x;
  p2_.y += move_y;
  p3_.x += move_x;
  p3_.y += move_y;
  p4_.x += move_x;
  p4_.y += move_y;
}

void timofeev::Complexquad::move(double move_x, double move_y)
{
  p1_.x += move_x;
  p1_.y += move_y;
  p2_.x += move_x;
  p2_.y += move_y;
  p3_.x += move_x;
  p3_.y += move_y;
  p4_.x += move_x;
  p4_.y += move_y;
}
void timofeev::Complexquad::scale(double factor)
{
  point_t pos_an = getFrameRect().pos;
  p1_.x = pos_an.x - (pos_an.x - p1_.x) * factor;
  p1_.y = pos_an.y - (pos_an.y - p1_.y) * factor;
  p2_.x = pos_an.x - (pos_an.x - p2_.x) * factor;
  p2_.y = pos_an.y - (pos_an.y - p2_.y) * factor;
  p3_.x = pos_an.x - (pos_an.x - p3_.x) * factor;
  p3_.y = pos_an.y - (pos_an.y - p3_.y) * factor;
  p4_.x = pos_an.x - (pos_an.x - p4_.x) * factor;
  p4_.y = pos_an.y - (pos_an.y - p4_.y) * factor;
}
