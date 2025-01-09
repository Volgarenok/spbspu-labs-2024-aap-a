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
        try
        {
          shapes[shapes_now] = new Rectangle(point_t{x1, y1}, point_t{x2, y2});
          shapes_now++;
        }
        catch (const std::logic_error& e)
        {
          delete shapes[shapes_now];
          wrong_shape_flag = true;
        }
      }
      if (type == "CIRCLE")
      {
        double x = 0, y = 0, radius = 0;
        in >> x >> y >> radius;
        try
        {
          shapes[shapes_now] = new Circle(point_t{x, y}, radius);
          shapes_now++;
        }
        catch (const std::logic_error& e)
        {
          delete shapes[shapes_now];
          wrong_shape_flag = true;
        }
      }
      if (type == "REGULAR")
      {
        double x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0;
        in >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        point_t pos{x1, y1};
        point_t top{x2, y2};
        point_t other{x3, y3};
        try
        {
          shapes[shapes_now] = new Regular(pos, top, other);
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
      shapes_now = 0;
      clear(shapes);
      throw;
    }
  }
}
void alymova::print(std::ostream& out, Shape** shapes)
{
  double area = 0;
  for(size_t i = 0; shapes[i] != nullptr; i++)
  {
    area += shapes[i]->getArea();
  }
  out << std::setprecision(1) << std::fixed;
  out << area;
  for (size_t i = 0; shapes[i] != nullptr; i++)
  {
    out << " " << shapes[i]->getFrameRect().getLowLeft().x;
    out << " " << shapes[i]->getFrameRect().getLowLeft().y;
    out << " " << shapes[i]->getFrameRect().getUppRight().x;
    out << " " << shapes[i]->getFrameRect().getUppRight().y;
  }
}
void alymova::clear(Shape** shapes)
{
  for(size_t i = 0; shapes[i] != nullptr; i++)
  {
    delete shapes[i];
  }
}
