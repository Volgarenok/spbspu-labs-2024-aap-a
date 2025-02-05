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
  for (size_t i = 0; i < 2; i++)
  {
    in >> x_y[i].x >> x_y[i].y;
    if (!in)
    {
      throw std::logic_error("Incorrect points");
    }
  }
  shaps.push_back(new Rectangle(x_y[0], x_y[1]));
}

void karnauhova::input_triangle(std::istream & in, CompositeShape& shaps)
{
  point_t x_y[3] = {};
  for (size_t i = 0; i < 3; i++)
  {
    in >> x_y[i].x >> x_y[i].y;
    if (!in)
    {
      throw std::logic_error("Incorrect points");
    }
  }
  shaps.push_back(new Triangle(x_y[0], x_y[1], x_y[2]));
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
        a = expansion(x_y, size, size + 1);
      }
      catch (const std::bad_alloc& e)
      {
        delete[] x_y;
        throw;
      }
      x_y = a;
      size++;
    }
    x_y[count].x = x;
    in >> x_y[count].y;
    if (!in)
    {
      throw std::logic_error("Incorrect points");
    }
    count += 1;
  }
  in.clear();
  Polygon* new_polygon = new Polygon(x_y, count);
  try
  {
    shaps.push_back(new_polygon);
  }
  catch (const std::exception& e)
  {
    delete new_polygon;
    throw;
  }
}

karnauhova::point_t* karnauhova::expansion(point_t* a, size_t old, size_t dl)
{
  point_t* newm = new point_t[dl];
  for (size_t i = 0; i < old; i++)
  {
    newm[i] = a[i];
  }
  delete[] a;
  return newm;
}

void karnauhova::fabric_input(std::istream & in, CompositeShape& shaps, size_t& count_error, point_t& point, double& k, std::string name)
{
  if (name == "RECTANGLE")
  {
    karnauhova::input_rectangle(in, shaps);
  }
  else if (name == "TRIANGLE")
  {
    karnauhova::input_triangle(in, shaps);
  }
  else if (name == "SCALE")
  {
    karnauhova::input_scale(in, point, k);
  }
  else if (name == "POLYGON")
  {
    karnauhova::input_polygon(in, shaps);
  }
  else
  {
    count_error++;
  }
}

bool karnauhova::input(std::istream & in, CompositeShape& shaps, size_t& count_error, point_t& point, double& k)
{
  std::string name = "uwu";
  while (in >> name && !in.eof())
  {
    try
    {
      karnauhova::fabric_input(in, shaps, count_error, point, k, name);
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
    return 1;
  }
  if (k <= 0)
  {
    std::cerr << "Error: scale input\n";
    return 1;
  }
  return 0;
}
