#include "rectangle.hpp"
#include <stdexcept>
#include "base-types.hpp"
#include "shape.hpp"
#include "triangle.hpp"
constexpr size_t cnt_trg = 8;
komarova::Rectangle::Rectangle(point_t low_left, point_t up_right):
  //low_left_(low_left),
  //up_right_(up_right),
  triangles_(new Shape*[cnt_trg]{})
{
  try
  {
    if (low_left.x >= up_right.x || low_left.y >= up_right.y)
    {
      throw std::logic_error("incorrect coordinates");
    }
    double width = up_right.x - low_left.x;
    double height = up_right.y - low_left.y;
    point_t up_left = {low_left.x, up_right.y};
    point_t low_right = {up_right.x, low_left.y};
    point_t center = {(low_left.x + width / 2.0), (low_left.y + height / 2.0)};
    triangles_[0] = new Triangle(up_right, center, {up_right.x - width / 2.0, up_right.y});
    triangles_[1] = new Triangle(up_left, center, {up_right.x - width / 2.0, up_right.y});
    triangles_[2] = new Triangle(up_left, center, {low_left.x, low_left.y + height / 2.0});
    triangles_[3] = new Triangle(low_left, center, {low_left.x, low_left.y + height / 2.0});
    triangles_[4] = new Triangle(low_left, center, {low_left.x + width / 2.0, low_left.y});
    triangles_[5] = new Triangle(low_right, center, {low_left.x + width / 2.0, low_left.y});
    triangles_[6] = new Triangle(low_right, center, {low_right.x, low_right.y + height / 2.0});
    triangles_[7] = new Triangle(up_right, center, {low_right.x, low_right.y + height / 2.0});
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
  return triangles_[0]->getArea() * 8;
  /*double width_ = up_right_.x - low_left_.x;
  double height_ = up_right_.y - low_left_.y;
  return (width_ * height_);*/
}
komarova::rectangle_t komarova::Rectangle::getFrameRect() const
{
  rectangle_t tmp = triangles_[0]->getFrameRect();
  double width = tmp.width * 2;
  double height = tmp.height * 2;
  point_t pos = {(tmp.pos.x - tmp.width / 2.0), (tmp.pos.y - tmp.height / 2.0)};
  return {width, height, pos};
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
