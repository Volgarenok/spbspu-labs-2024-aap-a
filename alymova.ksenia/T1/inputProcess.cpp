#include "inputProcess.hpp"
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "base-types.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

void alymova::makeShape(std::istream& in, CompositeShape& shapes, bool& wrong_shape_flag, double* scale_params)
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
        shapes.push_back(makeRectangle(in));
      }
      else if (type == "CIRCLE")
      {
        shapes.push_back(makeCircle(in));
      }
      else if (type == "REGULAR")
      {
        shapes.push_back(makeRegular(in));
      }
    }
    catch (...)
    {
      wrong_shape_flag = true;
    }
    if (type == "SCALE")
    {
      readParameters(in, scale_params, 3);
      scale_flag = true;
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
      throw std::logic_error("Input shape parameters error");
    }
  }
}
void alymova::print(std::ostream& out, Shape* shape)
{
  rectangle_t rect = shape->getFrameRect();
  out << " " << getLowLeftFrameRect(rect).x;
  out << " " << getLowLeftFrameRect(rect).y;
  out << " " << getUppRightFrameRect(rect).x;
  out << " " << getUppRightFrameRect(rect).y;
}
void alymova::print(std::ostream& out, CompositeShape& shapes)
{
  size_t size = shapes.size();
  double area = shapes.getArea();
  out << std::setprecision(1) << std::fixed;
  out << area;
  for (size_t i = 0; i < size; i++)
  {
    print(out, shapes[i]);
  }
}
void alymova::clear(Shape** shapes)
{
  for(size_t i = 0; shapes[i] != nullptr; i++)
  {
    delete shapes[i];
  }
}
