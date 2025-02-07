#include "input.hpp"
#include <iostream>
#include <string>
#include <limits>
#include "shape.hpp"
#include "triangle.hpp"
#include "rectangle.hpp"
#include "polygon.hpp"

void karnauhova::input_rectangle(std::istream & in, CompositeShape& shaps)
{
  point_t x_y[2] = {};
  input_points(in, x_y, 2);
  shaps.push_back(new Rectangle(x_y[0], x_y[1]));
}

void karnauhova::input_triangle(std::istream & in, CompositeShape& shaps)
{
  point_t x_y[3] = {};
  input_points(in, x_y, 3);
  shaps.push_back(new Triangle(x_y[0], x_y[1], x_y[2]));
}

void karnauhova::input_points(std::istream & in, point_t* point, size_t count)
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

void karnauhova::input_scale(std::istream & in, point_t& point, double& k)
{
  in >> point.x >> point.y >> k;
  if (!in)
  {
    throw std::logic_error("Incorrect points");
  }
}

void karnauhova::input_polygon(std::istream & in, CompositeShape& shaps)
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
    shaps.push_back(new_polygon);
  }
  catch (const std::exception& e)
  {
    delete[] x_y;
    delete new_polygon;
    throw;
  }
  delete[] x_y;
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

void karnauhova::fabric_input(std::istream & in, CompositeShape& shaps, size_t& count_error, point_t& point, double& k, std::string name)
{
  if (name == "RECTANGLE")
  {
    input_rectangle(in, shaps);
  }
  else if (name == "TRIANGLE")
  {
    input_triangle(in, shaps);
  }
  else if (name == "SCALE")
  {
    input_scale(in, point, k);
  }
  else if (name == "POLYGON")
  {
    input_polygon(in, shaps);
  }
  else
  {
    count_error++;
  }
}

void karnauhova::input(std::istream & in, CompositeShape& shaps, point_t& point, double& k)
{
  std::string name = "uwu";
  size_t count_error = 0;
  while (in >> name && !in.eof())
  {
    try
    {
      fabric_input(in, shaps, count_error, point, k, name);
    }
    catch (const std::logic_error& e)
    {
      in.clear();
      count_error++;
    }
    catch (const std::bad_alloc& e)
    {
      throw;
    }
  }
  if (shaps.size() == 0)
  {
    std::cerr << "Error: empty input\n";
    throw std::logic_error("Empty input");
  }
  if (k <= 0)
  {
    std::cerr << "Error: scale input\n";
    throw std::logic_error("Incorrect scale");
  }
  if (count_error > 0)
  {
    throw std::invalid_argument("Incorrect argument");
  }
}
