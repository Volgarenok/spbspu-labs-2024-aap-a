#include "rectangle.hpp"
#include <stdexcept>

lanovenko::Rectangle::Rectangle(point_t p1, point_t p2) : leftlower(p1), rightupper(p2)
{
  if (leftlower.x >= rightupper.x && leftlower.y >= rightupper.y)
  {
    throw std::invalid_argument("Wrong rectangle parametrs!\n");
  }
}

double lanovenko::Rectangle::getArea() const
{
  double width = std::abs(rightupper.x - leftlower.x);
  double height = std::abs(rightupper.y - leftlower.y);
  return width * height;
}

lanovenko::rectangle_t lanovenko::Rectangle::getFrameRect() const
{
  double width = std::abs(rightupper.x - leftlower.x);
  double height = std::abs(rightupper.y - leftlower.y);
  point_t center = { (rightupper.x + leftlower.x) / 2, (rightupper.y + leftlower.y) / 2 };
  return { width, height, center };
}

void lanovenko::Rectangle::move(point_t p)
{
  point_t center = { (rightupper.x + leftlower.x) / 2, (rightupper.y + leftlower.y) / 2 };
  double center_bias_x = p.x - center.x;
  double center_bias_y = p.y - center.y;
  this->move(center_bias_x, center_bias_y);
}

void lanovenko::Rectangle::move(double dx, double dy)
{
  point_t center = { (rightupper.x + leftlower.x) / 2, (rightupper.y + leftlower.y) / 2 };
  center.x += dx;
  center.y += dy;
  point_t* points[] = { &leftlower, &rightupper };
  for (size_t i = 0; i < 2; i++)
  {
    points[0]->x += dx;
    points[0]->y += dy;
  }
}

void::lanovenko::Rectangle::unsScale(double k)
{
  double width = std::abs(rightupper.x - leftlower.x);
  double height = std::abs(rightupper.y - leftlower.y);
  double new_width = width * k;
  double new_height = height * k;
  double bias_x = (new_width - width) / 2;
  double bias_y = (new_height - height) / 2;
  leftlower.x -= bias_x;
  leftlower.y -= bias_y;
  rightupper.x += bias_x;
  rightupper.y += bias_y;
}
