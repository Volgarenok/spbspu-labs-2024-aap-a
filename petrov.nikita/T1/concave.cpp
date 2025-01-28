#include "concave.hpp"
#include <cmath>
#include <algorithm>
#include <stdexcept>
#include <iostream>
petrov::Concave::Concave(point_t p1, point_t p2, point_t p3, point_t p4):
  triangle_1_(p2, { (p2.x + p1.x) / 2, (p2.y + p1.y) / 2 }, p4),
  triangle_2_(p1, { (p2.x + p1.x) / 2, (p2.y + p1.y) / 2 }, p4),
  triangle_3_(p1, { (p3.x + p1.x) / 2, (p3.y + p1.y) / 2 }, p4),
  triangle_4_(p3, { (p3.x + p1.x) / 2, (p3.y + p1.y) / 2 }, p4)
{
  if ( (p1.x == p4.x && p1.y == p4.y)
           || (p2.x == p4.x && p2.y == p4.y)
               || (p3.x == p4.x && p3.y == p4.y) )
  {
    throw std::invalid_argument("NOTE: Scaling of some figures skipped due to their invalid description\n");
  }
  double a = std::sqrt(std::pow((p1.x - p2.x), 2) + std::pow((p1.y - p2.y), 2));
  double b = std::sqrt(std::pow((p3.x - p2.x), 2) + std::pow((p3.y - p2.y), 2));
  double c = std::sqrt(std::pow((p1.x - p3.x), 2) + std::pow((p1.y - p3.y), 2));
  if (a + b <= c || a + c <= b || b + c <= a)
  {
    throw std::invalid_argument("NOTE: Scaling of some figures skipped due to their invalid description\n");
  }
  double p = (a + b + c) / 2;
  double area_of_triangle = std::sqrt(p * (p - a) * (p - b) * (p - c));
  double area_1 = getAreaOfComponent(p2, p3, p4);
  double area_2 = getAreaOfComponent(p1, p2, p4);
  double area_3 = getAreaOfComponent(p1, p3, p4);
  if (std::round(area_of_triangle) / 10 != std::round(area_1 + area_2 + area_3) / 10)
  {
    throw std::invalid_argument("NOTE: Scaling of some figures skipped due to their invalid description\n");
  }
}

double petrov::Concave::getArea() const
{
  return triangle_1_.getArea() + triangle_2_.getArea()
            + triangle_3_.getArea() + triangle_4_.getArea();
}

double petrov::Concave::getAreaOfComponent(point_t p1, point_t p2, point_t p3) const
{
  double a = std::sqrt(std::pow((p1.x - p2.x), 2) + std::pow((p1.y - p2.y), 2));
  double b = std::sqrt(std::pow((p3.x - p2.x), 2) + std::pow((p3.y - p2.y), 2));
  double c = std::sqrt(std::pow((p1.x - p3.x), 2) + std::pow((p1.y - p3.y), 2));
  double p = (a + b + c) / 2;
  return std::sqrt(p * (p - a) * (p - b) * (p - c));
}

petrov::rectangle_t petrov::Concave::getFrameRect() const
{
  rectangle_t tr_fr_r[4] = { triangle_1_.getFrameRect(), triangle_2_.getFrameRect(),
                             triangle_3_.getFrameRect(), triangle_4_.getFrameRect() };
  double xmax = tr_fr_r[0].pos.x + tr_fr_r[0].width / 2.0;
  double xmin = tr_fr_r[0].pos.x - tr_fr_r[0].width / 2.0;
  double ymax = tr_fr_r[0].pos.y + tr_fr_r[0].height / 2.0;
  double ymin = tr_fr_r[0].pos.y - tr_fr_r[0].height / 2.0;
  for (size_t i = 1; i < 4; i++)
  {
    double new_xmax = tr_fr_r[i].pos.x + tr_fr_r[i].width / 2.0;
    double new_xmin = tr_fr_r[i].pos.x - tr_fr_r[i].width / 2.0;
    double new_ymax = tr_fr_r[i].pos.y + tr_fr_r[i].height / 2.0;
    double new_ymin = tr_fr_r[i].pos.y - tr_fr_r[i].height / 2.0;
    xmax = new_xmax > xmax ? new_xmax : xmax;
    xmin = new_xmin < xmin ? new_xmin : xmin;
    ymax = new_ymax > ymax ? new_ymax : ymax;
    ymin = new_ymin < ymin ? new_ymin : ymin;
  }
  rectangle_t frame_rect = {};
  frame_rect.width = xmax - xmin;
  frame_rect.height = ymax - ymin;
  frame_rect.pos = { ((2 * xmin + xmax - xmin) / 2.0), ((2 * ymin + ymax - ymin) / 2.0) };
  return frame_rect;
}

void petrov::Concave::move(point_t concrete_point)
{
  rectangle_t frame_rect = getFrameRect();
  double dx = concrete_point.x - frame_rect.pos.x;
  double dy = concrete_point.y - frame_rect.pos.y;
  this->move(dx, dy);
}

void petrov::Concave::move(double dx, double dy)
{
  Triangle * triangles[4] = { &triangle_1_, &triangle_2_, &triangle_3_, &triangle_4_ };
  for (size_t i = 0; i < 4; i++)
  {
    triangles[i]->move(dx, dy);
  }
}

void petrov::Concave::scale(double k)
{
  rectangle_t frame_rect = getFrameRect();
  rectangle_t tr_fr_r[4] = { triangle_1_.getFrameRect(), triangle_2_.getFrameRect(),
                             triangle_3_.getFrameRect(), triangle_4_.getFrameRect() };
  Triangle * triangles[4] = { &triangle_1_, &triangle_2_, &triangle_3_, &triangle_4_ };
  for (size_t i = 0; i < 4; i++)
  {
    double dx_unique = tr_fr_r[i].pos.x - frame_rect.pos.x;
    double dy_unique = tr_fr_r[i].pos.y - frame_rect.pos.y;
    triangles[i]->scale(k);
    triangles[i]->move(dx_unique, dy_unique);
  }
}

petrov::Shape * petrov::Concave::clone() const
{
  return new Concave(*this);
}
