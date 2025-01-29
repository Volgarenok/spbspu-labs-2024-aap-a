#include "inputProcess.hpp"
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "base-types.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "fabrics.hpp"
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
        CreatorRectangle crt = CreatorRectangle();
        Creator* creator = &crt;
        shapes.push_back(creator->create(in));
      }
      else if (type == "CIRCLE")
      {
        CreatorCircle crt = CreatorCircle();
        Creator* creator = &crt;
        shapes.push_back(creator->create(in));
      }
      else if (type == "REGULAR")
      {
        CreatorRegular crt = CreatorRegular();
        Creator* creator = &crt;
        shapes.push_back(creator->create(in));
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
void alymova::print(std::ostream& out, const Shape* shape)
{
  rectangle_t rect = shape->getFrameRect();
  out << " " << getLowLeftFrameRect(rect).x;
  out << " " << getLowLeftFrameRect(rect).y;
  out << " " << getUppRightFrameRect(rect).x;
  out << " " << getUppRightFrameRect(rect).y;
}
void alymova::print(std::ostream& out, const CompositeShape& shapes)
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
