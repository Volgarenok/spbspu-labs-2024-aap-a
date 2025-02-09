#include "rectangle.hpp"
#include <cmath>

timofeev::Rectangle::Rectangle(point_t ld, point_t ru):
  ld_(ld),
  ru_(ru)
{
}

double timofeev::Rectangle::getArea() const
{
  return (ru_.x - ld_.x) * (ru_.y - ld_.y);
}

timofeev::rectangle_t timofeev::Rectangle::getFrameRect() const
{
  double height = (ru_.y - ld_.y);
  double width = (ru_.x - ld_.x);
  double posx = ld_.x + (width / 2);
  double posy = ld_.y + (height / 2);
  timofeev::rectangle_t frame_rect{width, height, {posx, posy}};
  return frame_rect;
}

void timofeev::Rectangle::move(timofeev::point_t new_pos)
{
  timofeev::point_t pos_an = getFrameRect().pos;
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

void timofeev::Rectangle::scale(double factor)
{
  point_t pos_an = getFrameRect().pos;
  ld_.x = pos_an.x - (pos_an.x - ld_.x) * factor;
  ru_.x = pos_an.x + (ru_.x - pos_an.x) * factor;
  ld_.y = pos_an.y - (pos_an.y - ld_.y) * factor;
  ru_.y = pos_an.y + (ru_.y - pos_an.y) * factor;
}
