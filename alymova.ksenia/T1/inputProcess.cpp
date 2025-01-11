#include "inputProcess.hpp"
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "base-types.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
void alymova::makeShape(std::istream& in, Shape** shapes, size_t& shapes_now, bool& wrong_shape_flag, double* scale_params)
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
        shapes[shapes_now] = makeRectangle(in);
        shapes_now++;
      }
      else if (type == "CIRCLE")
      {
        shapes[shapes_now] = makeCircle(in);
        shapes_now++;
      }
      else if (type == "REGULAR")
      {
        shapes[shapes_now] = makeRegular(in);
        shapes_now++;
      }
      else if (type == "SCALE")
      {
        try
        {
          readParameters(in, scale_params, 3);
          scale_flag = true;
        }
        catch (const std::logic_error& e)
        {}
      }
    }
    catch (...)
    {
      wrong_shape_flag = true;
    }
  }
}
alymova::Shape* alymova::makeRectangle(std::istream& in)
{
  const size_t cnt_params = 4;
  double params[cnt_params] = {};
  Rectangle* shape = nullptr;
  try
  {
    readParameters(in, params, cnt_params);
    shape = new Rectangle(point_t{params[0], params[1]}, point_t{params[2], params[3]});
    return shape;
  }
  catch (const std::logic_error& e)
  {
    throw;
  }
  catch (const std::bad_alloc& e)
  {
    delete shape;
    throw;
  }
}
alymova::Shape* alymova::makeCircle(std::istream& in)
{
  const size_t cnt_params = 3;
  double params[cnt_params] = {};
  Circle* shape = nullptr;
  try
  {
    readParameters(in, params, cnt_params);
    shape = new Circle(point_t{params[0], params[1]}, params[2]);
    return shape;
  }
  catch (const std::logic_error& e)
  {
    throw;
  }
  catch (const std::bad_alloc& e)
  {
    delete shape;
    throw;
  }
}
alymova::Shape* alymova::makeRegular(std::istream& in)
{
  const size_t cnt_params = 6;
  double params[cnt_params] = {};
  Regular* shape = nullptr;
  try
  {
    readParameters(in, params, cnt_params);
    shape = new Regular(point_t{params[0], params[1]}, point_t{params[2], params[3]}, point_t{params[4], params[5]});
    return shape;
  }
  catch (const std::logic_error& e)
  {
    throw;
  }
  catch (const std::bad_alloc& e)
  {
    delete shape;
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
