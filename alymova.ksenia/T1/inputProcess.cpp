#include "inputProcess.hpp"
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "base-types.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
void alymova::makeShape(std::istream& in, Shape** shapes, size_t& shapes_now, bool& wrong_shape_flag,
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
        try
        {
          shapes[shapes_now] = makeRectangle(in);
          shapes_now++;
        }
        catch (...)
        {
          wrong_shape_flag = true;
        }
        /*double x1 = 0, y1 = 0, x2 = 0, y2 = 0;
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
        }*/
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
alymova::Shape* alymova::makeRectangle(std::istream& in)
{
  double params[4] = {};
  Rectangle* rect = nullptr;
  try
  {
    readParameters(in, params, 4);
    rect = new Rectangle(point_t{params[0], params[1]}, point_t{params[2], params[3]});
    return rect;
  }
  catch (const std::logic_error& e)
  {
    throw;
  }
  catch (const std::bad_alloc& e)
  {
    delete rect;
    throw;
  }
}
void alymova::readParameters(std::istream& in, double* params, size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    if (!(in >> params[i]))
    {
      throw std::logic_error("Input shape error");
    }
  }
}
void alymova::print(std::ostream& out, const Shape* const* shapes, size_t size)
{
  double area = 0;
  for(size_t i = 0; i < size; i++)
  {
    area += shapes[i]->getArea();
  }
  out << std::setprecision(1) << std::fixed;
  out << area;
  for (size_t i = 0; i < size; i++)
  {
    rectangle_t rect = shapes[i]->getFrameRect();
    out << " " << getLowLeftFrameRect(rect).x;
    out << " " << getLowLeftFrameRect(rect).y;
    out << " " << getUppRightFrameRect(rect).x;
    out << " " << getUppRightFrameRect(rect).y;
  }
}
void alymova::clear(Shape** shapes)
{
  for(size_t i = 0; shapes[i] != nullptr; i++)
  {
    delete shapes[i];
  }
}
