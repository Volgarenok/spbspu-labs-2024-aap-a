#include "inputProcess.hpp"
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "base-types.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
void alymova::makeShape(std::istream& in, Shape** shapes, int& shapes_now, bool& wrong_shape_flag,
  double& scale_x, double& scale_y, double& scale_ratio)
{
  bool scale_flag = false;
  while (!scale_flag)
  {
    if (in.eof())
    {
      clear(shapes);
      throw std::logic_error("Command SCALE must be described");
    }
    std::string type;
    in >> type;
    try
    {
      if (type == "RECTANGLE")
      {
        double x1 = 0, y1 = 0, x2 = 0, y2 = 0;
        in >> x1 >> y1 >> x2 >> y2;
        shapes[shapes_now] = new Rectangle(point_t(x1, y1), point_t(x2, y2));
        shapes_now++;
      }
      if (type == "CIRCLE")
      {
        double x = 0, y = 0, radius = 0;
        in >> x >> y >> radius;
        try
        {
          shapes[shapes_now] = new Circle(point_t(x, y), radius);
          shapes_now++;
        }
        catch (const std::logic_error& e)
        {
          delete shapes[shapes_now];
          wrong_shape_flag = true;
        }
      }
      if (type == "SCALE")
      {
        scale_flag = true;
        in >> scale_x >> scale_y >> scale_ratio;
      }
    }
    catch (const std::bad_alloc& e)
    {
      clear(shapes);
      throw;
    }
  }
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
