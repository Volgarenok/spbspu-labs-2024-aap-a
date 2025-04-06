#include "rectangle.hpp"
#include <stdexcept>
#include "base-types.hpp"
#include "shape.hpp"
#include "triangle.hpp"
constexpr size_t cnt_trg = 8;
komarova::Rectangle::Rectangle(point_t low_left, point_t up_right):
  low_left_(low_left),
  up_right_(up_right),
  triangles_(new Shape*[cnt_trg]{})
{
  try
  {
    if (low_left_.x >= up_right_.x || low_left_.y >= up_right_.y)
    {
      throw std::logic_error("incorrect coordinates");
    }
    double width = up_right_.x - low_left_.x;
    double height = up_right_.y - low_left_.y;
    point_t up_left_ = {low_left_.x, up_right_.y};
    point_t low_right_ = {up_right_.x, low_left_.y};
    point_t center = {(low_left_.x + width / 2.0), (low_left_.y + height / 2.0)};
    triangles_[0] = new Triangle(up_right_, center, {up_right_.x - width / 2.0, up_right_.y});
    triangles_[1] = new Triangle(up_left_, center, {up_right_.x - width / 2.0, up_right_.y});
    triangles_[2] = new Triangle(up_left_, center, {low_left_.x, low_left_.y + height / 2.0});
    triangles_[3] = new Triangle(low_left_, center, {low_left_.x, low_left_.y + height / 2.0});
    triangles_[4] = new Triangle(low_left_, center, {low_left_.x + width / 2.0, low_left_.y});
    triangles_[5] = new Triangle(low_right_, center, {low_left_.x + width / 2.0, low_left_.y});
    triangles_[6] = new Triangle(low_right_, center, {low_right_.x, low_right_.y + height / 2.0});
    triangles_[7] = new Triangle(up_right_, center, {low_right_.x, low_right_.y + height / 2.0});
  }
  catch(const std::exception& e)
  {
    clear();
    throw;
  }
}
komarova::Rectangle::~Rectangle()
{
  clear();
}
double komarova::Rectangle::getArea() const
{
  double sum = 0;
  for (size_t i = 0; i < cnt_trg; i++)
  {
    sum += triangles_[i]->getArea();
  }
  return sum;
  /*double width_ = up_right_.x - low_left_.x;
  double height_ = up_right_.y - low_left_.y;
  return (width_ * height_);*/
}
komarova::rectangle_t komarova::Rectangle::getFrameRect() const
{
  double width_ = up_right_.x - low_left_.x;
  double height_ = up_right_.y - low_left_.y;
  point_t pos_ = {(low_left_.x + width_ / 2.0), (low_left_.y + height_ / 2.0)};
  return {width_, height_, pos_};
}
void komarova::Rectangle::move(point_t point)
{
  for (size_t i = 0; i < cnt_trg; i++)
  {
    triangles_[i]->move(point);
  }
  /*double dx = point.x - getFrameRect().pos.x;
  double dy = point.y - getFrameRect().pos.y;
  low_left_ = {low_left_.x + dx, low_left_.y + dy};
  up_right_ = {up_right_.x + dx, up_right_.y + dy};*/
}
void komarova::Rectangle::move(double dx, double dy)
{
  for (size_t i = 0; i < cnt_trg; i++)
  {
    triangles_[i]->move(dx, dy);
  }
  /*low_left_ = {low_left_.x + dx, low_left_.y + dy};
  up_right_ = {up_right_.x + dx, up_right_.y + dy};*/
}
void komarova::Rectangle::scale(double coef)
{
  if (coef <= 0)
  {
    throw std::logic_error("incorrect coef");
  }
  for (size_t i = 0; i < cnt_trg; i++)
  {
    //point_t center = triangles_[i]->getFrameRect().pos;
    triangles_[i]->scale(coef);
    /*low_left_.x = center.x + (low_left_.x - center.x) * coef;
    low_left_.y = center.y + (low_left_.y - center.y) * coef;
    up_right_.x = center.x + (up_right_.x - center.x) * coef;
    up_right_.y = center.y + (up_right_.y - center.y) * coef;*/
  }
}
void komarova::Rectangle::clear()
{
  for (size_t i = 0; i < cnt_trg; i++)
  {
    delete triangles_[i];
  }
  delete[] triangles_;
}
