#include "shapes_tools.hpp"
#include "shape.hpp"
#include <iostream>

bool timofeev::correct_triangle(point_t p1, point_t p2, point_t p3)
{
  double side1 = std::sqrt(std::pow((p2.x - p1.x), 2) + std::pow((p2.y - p1.y), 2));
  double side2 = std::sqrt(std::pow((p2.x - p3.x), 2) + std::pow((p2.y - p3.y), 2));
  double side3 = std::sqrt(std::pow((p3.x - p1.x), 2) + std::pow((p3.y - p1.y), 2));
  if (side1 + side2 > side3 && side1 + side3 > side2 && side3 + side2 > side1)
  {
    return true;
  }
  return false;
}

double timofeev::triangle_area(point_t p1, point_t p2, point_t p3)
{
  double side1 = std::sqrt(std::pow((p2.x - p1.x), 2) + std::pow((p2.y - p1.y), 2));
  double side2 = std::sqrt(std::pow((p2.x - p3.x), 2) + std::pow((p2.y - p3.y), 2));
  double side3 = std::sqrt(std::pow((p3.x - p1.x), 2) + std::pow((p3.y - p1.y), 2));
  double p = (side1 + side2 + side3) / 2;
  return std::sqrt(p * (p - side1) * (p - side2) * (p - side3));
}

bool timofeev::is_point_in_triangle(point_t p1, point_t p2, point_t p3, point_t p4)
{
  int check1 = (p1.x - p4.x) * (p2.y - p1.y) - (p2.x - p1.x) * (p1.y - p4.y);
  int check2 = (p2.x - p4.x) * (p3.y - p2.y) - (p3.x - p2.x) * (p2.y - p4.y);
  int check3 = (p3.x - p4.x) * (p1.y - p3.y) - (p1.x - p3.x) * (p3.y - p4.y);
  if (check1 > 0 && check2 > 0 && check3 > 0)
  {
    return true;
  }
  else if (check1 < 0 && check2 < 0 && check3 < 0)
  {
    return true;
  }
  return false;
}

bool timofeev::is_point_in_quad(point_t p1, point_t p2, point_t p3, point_t p4, point_t pos)
{
  int check1 = (p1.x - pos.x) * (p4.y - p1.y) - (p4.x - p1.x) * (p1.y - pos.y);
  int check2 = (p4.x - pos.x) * (p2.y - p4.y) - (p2.x - p4.x) * (p4.y - pos.y);
  int check3 = (p2.x - pos.x) * (p3.y - p2.y) - (p3.x - p2.x) * (p2.y - pos.y);
  int check4 = (p3.x - pos.x) * (p1.y - p3.y) - (p1.x - p3.x) * (p3.y - pos.y);
  if (check1 > 0 && check2 > 0 && check3 > 0 && check4 > 0)
  {
    return true;
  }
  else if (check1 < 0 && check2 < 0 && check3 < 0 && check4 < 0)
  {
    return true;
  }
  return false;
}

double timofeev::print_sum_area(Shape** shapes, size_t count)
{
  double summa = 0;
  for (size_t i = 0; i < count; i++)
  {
    summa += shapes[i]->getArea();
  }
  return summa;
}

timofeev::point_t timofeev::cross_point(point_t p1, point_t p2, point_t p3, point_t p4)
{
  double a1 = p2.y - p1.y;
  double b1 = p1.x - p2.x;
  double c1 = a1 * p1.x + b1 * p1.y;
  double a2 = p4.y - p3.y;
  double b2 = p3.x - p4.x;
  double c2 = a2 * p3.x + b2 * p3.y;

  double det = a1 * b2 - a2 * b1;
  double x = (b2 * c1 - b1 * c2) / det;
  double y = (a1 * c2 - a2 * c1) / det;
  return {x, y};
}

void timofeev::print_frame_rect(Shape** shapes, size_t count)
{
  for (size_t i = 0; i < count; i++)
  {
    timofeev::rectangle_t frame_rect;
    frame_rect = shapes[i]->getFrameRect();
    std::cout << " " << frame_rect.pos.x - frame_rect.width / 2 << " " << frame_rect.pos.y - frame_rect.height / 2;
    std::cout << " " << frame_rect.pos.x + frame_rect.width / 2 << " " << frame_rect.pos.y + frame_rect.height / 2;
  }
}
void timofeev::isoscale(Shape** shapes, size_t count, point_t iso_pos, double factor)
{
  for (size_t i = 0; i < count; ++i)
  {
    timofeev::point_t start = shapes[i]->getFrameRect().pos;
    shapes[i]->move(iso_pos);
    timofeev::point_t result = shapes[i]->getFrameRect().pos;
    timofeev::point_t vector;
    vector.x = (result.x - start.x);
    vector.y = (result.y - start.y);
    shapes[i]->scale(factor);
    vector.x *= factor;
    vector.y *= factor;
    shapes[i]->move(-vector.x, -vector.y);
  }
}
void timofeev::shape_delete(Shape** shapes, size_t count)
{
  for (size_t i = 0; i < count; i++)
  {
    delete shapes[i];
  }
}
