#include "inputProcess.hpp"
#include <iostream>
#include <iomanip>
alymova::Shape* alymova::makeShape(std::istream& in, Shape** shapes)
{
  std::string type;
  in >> type;
  if (type == "RECTANGLE")
  {
    double x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    std::cin >> x1 >> y1 >> x2 >> y2;
    return makeRectangle(x1, y1, x2, y2);
  }
  return nullptr;
}
alymova::Rectangle* alymova::makeRectangle(double x1, double y1, double x2, double y2)
{
  Rectangle* r = new Rectangle(point_t(x1, y1), point_t(x2, y2));
  return r;
}
void alymova::clear(Shape** shapes)
{
  for(size_t i = 0; shapes[i] != nullptr; i++)
  {
    delete shapes[i];
  }
}
void alymova::print(std::ostream& out, Shape** shapes)
{
  double area = 0, low_left_x = 0, low_left_y = 0, upp_right_x = 0, upp_right_y = 0;
  for(size_t i = 0; shapes[i] != nullptr; i++)
  {
    area += shapes[i]->getFrameRect().getArea();
    low_left_x += shapes[i]->getFrameRect().getLowLeft().getX();
    low_left_y += shapes[i]->getFrameRect().getLowLeft().getY();
    upp_right_x += shapes[i]->getFrameRect().getUppRight().getX();
    upp_right_y += shapes[i]->getFrameRect().getUppRight().getY();
  }
  out << std::setprecision(1) << std::fixed;
  out << area << " " << low_left_x << " " << low_left_y << " " << upp_right_x << " " << upp_right_y;
}
void alymova::scale(Shape** shapes, point_t s, double ratio)
{
  if (ratio <= 0)
  {
    throw std::logic_error("The scale ratio should be positive");
  }
  if (ratio == 1)
  {
    return;
  }
  for (size_t i = 0; shapes[i] != nullptr; i++)
  {
    shapes[i]->move(s);
    point_t shift_point(shapes[i]->getFrameRect().getShift());
    shapes[i]->scale(ratio);
    shift_point *= ratio;
    shapes[i]->move(-shift_point.getX(), -shift_point.getY());
  }
}
