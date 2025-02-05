#include "rectangle.hpp"
#include <stdlib.h>
#include <stdexcept>
#include <cmath>

double third_point_y(bocharov::point_t leftDown, bocharov::point_t rightUp)
{
  double AD = rightUp.x - leftDown.x;
  double AB = rightUp.y - leftDown.y;
  double BD = sqrt(pow(AB, AB) + pow(AD, AD));
  double AK = (AB * AD) / BD;
  double BK = sqrt(pow(AB, AB) - pow(AK, AK));
  double KD = BD - BK;
  double KH = (AK * KD) / AD;
  return KH;
}

double third_point_x(bocharov::point_t leftDown, bocharov::point_t rightUp)
{
  double AD = rightUp.x - leftDown.x;
  double AB = rightUp.y - leftDown.y;
  double BD = sqrt(pow(AB, AB) + pow(AD, AD));
  double AK = (AB * AD) / BD;
  double KH = third_point_y(leftDown, rightUp);
  double AH = sqrt(pow(AK, AK) - pow(KH, KH));
  return AH;
}

bocharov::Rectangle::Rectangle(point_t leftDown, point_t rightUp):
  a_(Triangle{leftDown, point_t{rightUp.x, leftDown.y},
    point_t{leftDown.x + third_point_x(leftDown, rightUp), leftDown.y + third_point_y(leftDown, rightUp)}}),
  b_(Triangle{leftDown, point_t{leftDown.x, rightUp.y},
    point_t{leftDown.x + third_point_x(leftDown, rightUp), leftDown.y + third_point_y(leftDown, rightUp)}}),
  c_(Triangle{point_t{leftDown.x, rightUp.y}, rightUp,
    point_t{rightUp.x - third_point_x(leftDown, rightUp), rightUp.y - third_point_y(leftDown, rightUp)}}),
  d_(Triangle{rightUp, point_t{rightUp.x, leftDown.y},
    point_t{rightUp.x - third_point_x(leftDown, rightUp), rightUp.y - third_point_y(leftDown, rightUp)}}),
  leftDown_({0.0L, 0.0L}),
  rightUp_({0.0L, 0.0L})
{
  if (leftDown.x < rightUp.x && leftDown.y < rightUp.y)
  {
    rightUp_.x = rightUp.x;
    rightUp_.y = rightUp.y;
    leftDown_.x = leftDown.x;
    leftDown_.y = leftDown.y;
  }
  else
  {
    throw std::invalid_argument("error with rectangle size\n");
  }
}

double bocharov::Rectangle::getArea() const
{
  return a_.getArea() + b_.getArea() + c_.getArea() + d_.getArea();
}

bocharov::rectangle_t bocharov::Rectangle::getFrameRect() const
{
  rectangle_t result;
  result.height = rightUp_.y - leftDown_.y;
  result.width = rightUp_.x - leftDown_.x;
  result.pos.x = leftDown_.x + (result.width / 2.0L);
  result.pos.y = leftDown_.y + (result.height / 2.0L);
  return result;
}

void bocharov::Rectangle::move(double x, double y)
{
  leftDown_.x += x;
  leftDown_.y += y;
  rightUp_.x += x;
  rightUp_.y += y;
}

void bocharov::Rectangle::move(point_t centerP)
{
  point_t pos = getFrameRect().pos;
  double moveX = centerP.x - pos.x;
  double moveY = centerP.y - pos.y;
  move(moveX, moveY);
}

void bocharov::Rectangle::scale(double ratio)
{
  rectangle_t fremRect = getFrameRect();
  point_t pos = fremRect.pos;
  rightUp_.x = pos.x + (rightUp_.x - pos.x) * ratio;
  rightUp_.y = pos.y + (rightUp_.y - pos.y) * ratio;
  leftDown_.x = pos.x + (leftDown_.x - pos.x) * ratio;
  leftDown_.y = pos.y + (leftDown_.y - pos.y) * ratio;
}
