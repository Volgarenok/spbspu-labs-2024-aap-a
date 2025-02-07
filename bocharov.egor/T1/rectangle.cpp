#include "rectangle.hpp"
#include <stdlib.h>
#include <stdexcept>
#include <cmath>

double third_point_y(bocharov::point_t leftDown, bocharov::point_t rightUp)
{
  double ad = rightUp.x - leftDown.x;
  double ab = rightUp.y - leftDown.y;
  double bd = sqrt(pow(ab, 2) + pow(ad, 2));
  double ak = (ab * ad) / bd;
  double bk = sqrt(pow(ab, 2) - pow(ak, 2));
  double kd = bd - bk;
  double kh = (ak * kd) / ad;
  return kh;
}

double third_point_x(bocharov::point_t leftDown, bocharov::point_t rightUp)
{
  double ad = rightUp.x - leftDown.x;
  double ab = rightUp.y - leftDown.y;
  double bd = sqrt(pow(ab, 2) + pow(ad, 2));
  double ak = (ab * ad) / bd;
  double kh = third_point_y(leftDown, rightUp);
  double ah = sqrt(pow(ak, 2) - pow(kh, 2));
  return ah;
}

bocharov::Rectangle::Rectangle(point_t leftDown, point_t rightUp):
  ta_(Triangle{leftDown, point_t{rightUp.x, leftDown.y},
    point_t{leftDown.x + third_point_x(leftDown, rightUp), leftDown.y + third_point_y(leftDown, rightUp)}}),
  tb_(Triangle{leftDown, point_t{leftDown.x, rightUp.y},
    point_t{leftDown.x + third_point_x(leftDown, rightUp), leftDown.y + third_point_y(leftDown, rightUp)}}),
  tc_(Triangle{point_t{leftDown.x, rightUp.y}, rightUp,
    point_t{rightUp.x - third_point_x(leftDown, rightUp), rightUp.y - third_point_y(leftDown, rightUp)}}),
  td_(Triangle{rightUp, point_t{rightUp.x, leftDown.y},
    point_t{rightUp.x - third_point_x(leftDown, rightUp), rightUp.y - third_point_y(leftDown, rightUp)}})
{
  if (leftDown.x >= rightUp.x || leftDown.y >= rightUp.y)
  {
    throw std::invalid_argument("error with rectangle size\n");
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

