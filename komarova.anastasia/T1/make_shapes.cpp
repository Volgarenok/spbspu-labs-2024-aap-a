#include "make_shapes.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"
#include "square.hpp"

void komarova::make_shapes(std::istream& input, Shape** shapes, int& count, bool& wrong_shape, double& x_sc, double& y_sc, double& coef)
{
  bool sc_flag = false;
  while (!sc_flag)
  {
    if (input.eof())
    {
      throw std::logic_error("SCALE Error");
    }
    std::string figure;
    input >> figure;
    try
    {
      if (figure == "RECTANGLE")
      {
        double x1 = 0.0, y1 = 0.0, x2 = 0.0, y2 = 0.0;
        input >> x1 >> y1 >> x2 >> y2;
        try
        {
          shapes[count] = new Rectangle(point_t(x1, y1), point_t(x2, y2));
          count++;
        }
        catch (const std::logic_error& e)
        {
          delete shapes[count];
          wrong_shape = true;
        }
      }
      if (figure == "CIRCLE")
      {
        double x = 0.0, y = 0.0, radius = 0.0;
        input >> x >> y >> radius;
        point_t point_c(x, y);
        try
        {
          shapes[count] = new Circle(point_c, radius);
          count++;
        }
        catch (const std::logic_error& e)
        {
          delete shapes[count];
          wrong_shape = true;
        }
      }
      if (figure == "TRIANGLE")
      {
        double x1 = 0.0, y1 = 0.0, x2 = 0.0, y2 = 0.0, x3 = 0.0, y3 = 0.0;
        input >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        point_t a(x1, y1);
        point_t b(x2, y2);
        point_t c(x3, y3);
        try
        {
          shapes[count] = new Triangle(a, b, c);
          count++;
        }
        catch (const std::logic_error& e)
        {
          delete shapes[count];
          wrong_shape = true;
        }
      }
      if (figure == "SQUARE")
      {
        double x = 0.0, y = 0.0, len = 0.0;
        input >> x >> y >> len;
        try
        {
          shapes[count] = new Square(point_t(x, y), len);
          count++;
        }
        catch (const std::logic_error& e)
        {
          delete shapes[count];
          wrong_shape = true;
        }
      }
      if (figure == "SCALE")
      {
        sc_flag = true;
        input >> x_sc >> y_sc >> coef;
      }
    }
    catch (const std::bad_alloc& e)
    {
      count = 0;
      delete_shapes(shapes);
      throw;
    }
  }
}

void komarova::area_sum(std::ostream& output, Shape** shapes)
{
  double sum = 0.0;
  for (size_t i = 0; shapes[i] != nullptr; i++)
  {
    sum += shapes[i]->getArea();
  }
  output << sum;
}

void komarova::frame_rect_xy(std::ostream& output, Shape** shapes)
{
  for (size_t i =0; shapes[i] != nullptr; i++)
  {
    rectangle_t frame_rect = shapes[i]->getFrameRect();
    output << " " << frame_rect.pos.x - (frame_rect.width / 2.0);
    output << " " << frame_rect.pos.y - (frame_rect.height / 2.0);
    output << " " << frame_rect.pos.x + (frame_rect.width / 2.0);
    output << " " << frame_rect.pos.y + (frame_rect.height / 2.0);
  }
}

void komarova::delete_shapes(Shape** shapes)
{
  for (size_t i = 0; shapes[i] != nullptr; i++)
  {
    delete shapes[i];
  }
}
