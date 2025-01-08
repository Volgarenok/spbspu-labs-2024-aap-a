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

void komarova::make_shapes(std::istream& input, Shape** shapes, bool& wrong_shape, int& count, double& x_sc, double& y_sc, double& coef)
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
        point_t a;
        point_t b;
        input >> a.x >> a.y >> b.x >> b.y;
        try
        {
          shapes[count] = new Rectangle(a, b);
          count++;
        }
        catch (const std::logic_error& e)
        {
          delete shapes[count];
          wrong_shape = true;
        }
      }
      else if (figure == "CIRCLE")
      {
        point_t point_c;
        double radius;
        input >> point_c.x >> point_c.y >> radius;
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
      else if (figure == "TRIANGLE")
      {
        point_t a;
        point_t b;
        point_t c;
        input >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
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
      else if (figure == "SQUARE")
      {
        double len;
        point_t low_left;
        input >> low_left.x >> low_left.y >> len;
        try
        {
          shapes[count] = new Square(low_left, len);
          count++;
        }
        catch (const std::logic_error& e)
        {
          delete shapes[count];
          wrong_shape = true;
        }
      }
      else if (figure == "SCALE")
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
