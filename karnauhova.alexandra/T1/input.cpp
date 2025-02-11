#include "input.hpp"
#include <iostream>
#include <string>
#include <limits>
#include "shape.hpp"
#include "triangle.hpp"
#include "rectangle.hpp"
#include "polygon.hpp"

karnauhova::Shape* karnauhova::input_rectangle(std::istream& in)
{
  point_t x_y[2] = {};
  input_points(in, x_y, 2);
  Rectangle* rect = new Rectangle(x_y[0], x_y[1]);
  return rect;
}

karnauhova::Shape* karnauhova::input_triangle(std::istream& in)
{
  point_t x_y[3] = {};
  input_points(in, x_y, 3);
  Triangle* triangle = new Triangle(x_y[0], x_y[1], x_y[2]);
  return triangle;
}

void karnauhova::input_points(std::istream& in, point_t* point, size_t count)
{
  for (size_t i = 0; i < count; i++)
  {
    in >> point[i].x >> point[i].y;
    if (!in)
    {
      throw std::logic_error("Incorrect points");
    }
  }
}

void karnauhova::input_scale(std::istream& in, point_t& point, double& k)
{
  in >> point.x >> point.y >> k;
  if (!in)
  {
    throw std::logic_error("Incorrect points");
  }
}

karnauhova::Shape* karnauhova::input_polygon(std::istream& in)
{
  size_t size = 1;
  double x = 0;
  point_t* x_y = new point_t[size];
  size_t count = 0;
  while (in >> x)
  {
    if (count >= size)
    {
      point_t* a = nullptr;
      try
      {
        a = expand(x_y, size, size + 1);
      }
      catch (const std::bad_alloc& e)
      {
        delete[] x_y;
        throw;
      }
      delete[] x_y;
      x_y = a;
      size++;
    }
    x_y[count].x = x;
    in >> x_y[count].y;
    if (!in)
    {
      delete[] x_y;
      throw std::logic_error("Incorrect points");
    }
    count += 1;
  }
  in.clear();
  Polygon* new_polygon = nullptr;
  try
  {
    new_polygon = new Polygon(x_y, count);
  }
  catch (const std::exception& e)
  {
    delete[] x_y;
    throw;
  }
  delete[] x_y;
  return new_polygon;
}

karnauhova::point_t* karnauhova::expand(point_t* a, size_t old, size_t dl)
{
  point_t* newm = new point_t[dl];
  for (size_t i = 0; i < old; i++)
  {
    newm[i] = a[i];
  }
  return newm;
}

void karnauhova::fabric_input(std::istream& in, CompositeShape& shaps, point_t& point, double& k, std::string name)
{
  Shape* shape = nullptr;
  if (name == "RECTANGLE")
  {
    shape = input_rectangle(in);
  }
  else if (name == "TRIANGLE")
  {
    shape = input_triangle(in);
  }
  else if (name == "SCALE")
  {
    input_scale(in, point, k);
  }
  else if (name == "POLYGON")
  {
    shape = input_polygon(in);
  }
  else
  {
    throw std::logic_error("Incorrect name");
  }
  if (name != "SCALE")
  {
    try
    {
      shaps.push_back(shape);
    }
    catch (const std::bad_alloc& e)
    {
      delete shape;
      throw;
    }
  }
}
