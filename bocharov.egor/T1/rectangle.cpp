#include "rectangle.hpp"
#include <stdexcept>
#include <cmath>

double third_point_y(bocharov::point_t leftDown, bocharov::point_t rightUp)
{
  const double ad = rightUp.x - leftDown.x;
  const double ab = rightUp.y - leftDown.y;
  const double bd = std::sqrt(std::pow(ab, 2) + std::pow(ad, 2));
  const double ak = (ab * ad) / bd;
  const double bk = std::sqrt(std::pow(ab, 2) - std::pow(ak, 2));
  const double kd = bd - bk;
  const double kh = (ak * kd) / ad;
  return kh;
}

double third_point_x(bocharov::point_t leftDown, bocharov::point_t rightUp)
{
  const double ad = rightUp.x - leftDown.x;
  const double ab = rightUp.y - leftDown.y;
  const double bd = std::sqrt(std::pow(ab, 2) + std::pow(ad, 2));
  const double ak = (ab * ad) / bd;
  const double kh = third_point_y(leftDown, rightUp);
  const double ah = std::sqrt(pow(ak, 2) - std::pow(kh, 2));
  return ah;
}

bocharov::point_t first_coordinate(bocharov::point_t leftDown, bocharov::point_t rightUp)
{
  return {leftDown.x + third_point_x(leftDown, rightUp), leftDown.y + third_point_y(leftDown, rightUp)};
}

bocharov::point_t second_coordinate(bocharov::point_t leftDown, bocharov::point_t rightUp)
{
  return {rightUp.x - third_point_x(leftDown, rightUp), rightUp.y - third_point_y(leftDown, rightUp)};
}

bocharov::Rectangle::Rectangle(point_t leftDown, point_t rightUp):
  ta_(leftDown, point_t{rightUp.x, leftDown.y}, first_coordinate(leftDown, rightUp)),
  tb_(leftDown, point_t{leftDown.x, rightUp.y}, first_coordinate(leftDown, rightUp)),
  tc_(rightUp, point_t{leftDown.x, rightUp.y}, second_coordinate(leftDown, rightUp)),
  td_(rightUp, point_t{rightUp.x, leftDown.y}, second_coordinate(leftDown, rightUp))
{
  if (leftDown.x >= rightUp.x || leftDown.y >= rightUp.y)
  {
    throw std::invalid_argument("error with rectangle size");
  }
}

double bocharov::Rectangle::getArea() const
{
  return ta_.getArea() + tb_.getArea() + tc_.getArea() + td_.getArea();
}

bocharov::rectangle_t bocharov::Rectangle::getFrameRect() const
{
  point_t pos2 = {ta_.getFrameRect().pos.x, (ta_.getFrameRect().pos.y + tc_.getFrameRect().pos.y) / 2};
  double width2 = ta_.getFrameRect().width;
  double height2 = tb_.getFrameRect().height;
  return {width2, height2, pos2};
}

void bocharov::Rectangle::move(double x, double y)
{
  ta_.move(x, y);
  tb_.move(x, y);
  tc_.move(x, y);
  td_.move(x, y);
}

void bocharov::Rectangle::move(point_t centerP)
{
  ta_.move(centerP);
  tb_.move(centerP);
  tc_.move(centerP);
  td_.move(centerP);
}

void bocharov::Rectangle::scale(double ratio)
{
  ta_.scale(ratio);
  tb_.scale(ratio);
  tc_.scale(ratio);
  td_.scale(ratio);
}

