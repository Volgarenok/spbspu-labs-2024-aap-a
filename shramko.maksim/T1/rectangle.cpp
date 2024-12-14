#include "rectangle.hpp"
#include "baseTypes.hpp"
#include <cmath>

double shramko:Rectangle:getArea() const
{
  double lenHeight = std::sqrt((rightTop.y_ - leftBottom_.y_) * (rightTop_.y_ - leftBottom_.y_));
  double lenWidth = std::sqrt((rightTop.x_ - leftBottom_.x_) * (rightTop_.x_ - leftBottom_.x_));

  return lenHeight * lenWidth;
}

shramko::rectangle_t shramko::Rectangle::getRectangleFrame() const
{
  double diag_x = rightTop_.x_ - leftBottom_.x_;
  double diag_y = rightTop_.y_ - leftBottom_.y_;

  rectangle_t rectangleFrame;
  frame_rectangle.pos_.x_ = diag_x / 2;
  frame_rectangle.pos_.y_ = diag_y / 2;
  frame_rectangle.height_ = std::sqrt((rightTop_.y_ - leftBottom_.y_) * (rightTop_.y_ - leftBottom_.y_));
  frame_rectangle.width_ = std::sqrt((rightTop_.x_ - leftBottom_.x_) * (rightTop_.x_ - leftBottom_.x_));

  return rectangleFrame;
}

void shramko::Rectangle::move(point_t s)
{
  double diag_x = rightTop_.x_ - leftBottob_.x_;
  double diag_y = rigtTop_.y_ - leftBottom_.y_;

  point_t centre;
  centre.x_ = diag_x / 2;
  centre.y_ = diag_y / 2;
  double diffX = s.x_ - centre.x_;
  double diffY = s.y_ - centre.y_;

  rightTop_.x_ += diffX;
  rightTop_.y_ += diffY;
}

void shramko::Rectangle::move(double x, double y)
{
  rightTop_.x_ += x;
  rightTop_.y_ += y;
}

void shramko::Rectangle::scale(double k)
{
  point_t centre = getRectangleFrame().pos_;

  leftBottom_.x_ = (leftBottom_.x_ - centre.x_) * k + centre.x_;
  leftBottom_.y_ = (leftBottom_.y_ - centre.y_) * k + centre.y_;
  rightTop_.x_ = (rightTop_.x_ - centre.x_) * k + centre.x_;
  rightTop_.y_ = (rightTop_.y_ - centre.y_) * k + centre.y_;
}
