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

void komarova::make_shapes(std::istream& input, Shape** shapes, bool& wrong_shape)
{
  int count = 0;
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
        try
        {
          shapes[count] = make_rect(input);
          count++;
        }
        catch (const std::logic_error& e)
        {
          wrong_shape = true;
        }
      }
      else if (figure == "CIRCLE")
      {
        try
        {
          shapes[count] = make_circ(input);
          count++;
        }
        catch (const std::logic_error& e)
        {
          wrong_shape = true;
        }
      }
      else if (figure == "TRIANGLE")
      {
        try
        {
          shapes[count] = make_tri(input);
          count++;
        }
        catch (const std::logic_error& e)
        {
          wrong_shape = true;
        }
      }
      else if (figure == "SQUARE")
      {
        try
        {
          shapes[count] = make_sqr(input);
          count++;
        }
        catch (const std::logic_error& e)
        {
          wrong_shape = true;
        }
      }
      else if (figure == "SCALE")
      {
        double x_sc = 0.0;
        double y_sc = 0.0;
        double coef = 0.0;
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

void komarova::scale(Shape** shapes, point_t point, double coef)
{
  if (coef <= 0.0)
  {
    throw std::logic_error("incorrect coefficient");
  }
  for (size_t i = 0; shapes[i] != nullptr; i++)
  {
    point_t p = shapes[i]->getFrameRect().pos;
    shapes[i]->move(point);
    shapes[i]->scale(coef);
    point_t new_p = shapes[i]->getFrameRect().pos;
    point_t vector = {(new_p.x - p.x) * coef, (new_p.y - p.y) * coef};
    shapes[i]->move(-vector.x, -vector.y);
  }
}

void komarova::delete_shapes(Shape** shapes)
{
  for (size_t i = 0; shapes[i] != nullptr; i++)
  {
    delete shapes[i];
  }
}

komarova::Rectangle* komarova::make_rect(std::istream& input)
{
  point_t low_left;
  point_t up_right;
  if (!(input >> low_left.x >> low_left.y >> up_right.x >> up_right.y))
  {
    throw std::logic_error("incorrect input");
  }
  return new Rectangle(low_left, up_right);
}

komarova::Circle* komarova::make_circ(std::istream& input)
{
  point_t point_c;
  double radius;
  if (!(input >> point_c.x >> point_c.y >> radius))
  {
    throw std::logic_error("incorrect input");
  }
  return new Circle(point_c, radius);
}

komarova::Triangle* komarova::make_tri(std::istream& input)
{
  point_t a;
  point_t b;
  point_t c;
  if (!(input >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y))
  {
    throw std::logic_error("incorrect input");
  }
  return new Triangle(a, b, c);
}

komarova::Square* komarova::make_sqr(std::istream& input)
{
  point_t low_left;
  double len;
  if (!(input >> low_left.x >> low_left.y >> len))
  {
    throw std::logic_error("incorrect input");
  }
  return new Square(low_left, len);
}
