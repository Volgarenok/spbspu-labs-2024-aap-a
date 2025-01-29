#include "input.hpp"
#include <iostream>
#include <string>
#include <limits>
#include "shape.hpp"
#include "triangle.hpp"
#include "rectangle.hpp"
#include "polygon.hpp"

bool karnauhova::input_rectangle(std::istream & in, CompositeShape& shaps)
{
  point_t x_y[2] = {};
  double x = 0, y = 0;
  for (size_t i = 0; i < 2; i++)
  {
    in >> x;
    in >> y;
    if (in)
    {
      x_y[i].x = x;
      x_y[i].y = y;
    }
    else
    {
      return false;
    }
  }
  shaps.push_back(new Rectangle(x_y[0], x_y[1]));
  return true;
}

bool karnauhova::input_triangle(std::istream & in, CompositeShape& shaps)
{
  point_t x_y[3] = {};
  double x = 0, y = 0;
  for (size_t i = 0; i < 3; i++)
  {
    in >> x;
    in >> y;
    if (in)
    {
      x_y[i].x = x;
      x_y[i].y = y;
    }
    else
    {
      return false;
    }
  }
  shaps.push_back(new Triangle(x_y[0], x_y[1], x_y[2]));
  return true;
}

bool karnauhova::input_scale(std::istream & in, point_t& point, double& k)
{
  double x_y[40000] = {};
  double x = 0;
  size_t count = 0;
  while (in >> x)
  {
    x_y[count] = x;
    count++;
  }
  if (!(count == 3))
  {
    return false;
  }
  point.x = x_y[0];
  point.y = x_y[1];
  k = x_y[2];
  return true;
}

bool karnauhova::input_polygon(std::istream & in, CompositeShape& shaps)
{
  size_t size = 1;
  point_t* x_y = new point_t[size];
  double x = 0;
  double y = 0;
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
    in >> y;
    x_y[count].x = x;
    x_y[count].y = y;
    count += 1;
  }
  in.clear();
  shaps.push_back(new Polygon(x_y, count));
  return true;
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

bool karnauhova::fabric_input(std::istream & in, CompositeShape& shaps, size_t& count_error, point_t& point, double& k)
{
  std::string names[10000] = {};
  std::string name = "uwu";
  while (in >> name && !in.eof())
  {
    if (name == "RECTANGLE")
    {
      try
      {
        if (!karnauhova::input_rectangle(in, shaps))
        {
          in.clear();
          shaps.pop_back();
          count_error++;
        }
        else
        {
          names[shaps.size() - 1] = name;
        }
      }
      catch (const std::exception& e)
      {
        count_error++;
      }
    }
    else if (name == "TRIANGLE")
    {
      try
      {
        if (!karnauhova::input_triangle(in, shaps))
        {
          in.clear();
          shaps.pop_back();
          count_error++;
        }
        else
        {
          names[shaps.size() - 1] = name;
        }
      }
      catch (const std::exception& e)
      {
        count_error++;
      }
    }
    else if (name == "SCALE")
    {
      if (!karnauhova::input_scale(std::cin, point, k))
      {
        in.clear();
        count_error++;
      }
      else
      {
        names[shaps.size()] = name;
      }
    }
    else if (name == "POLYGON")
    {
      try
      {
        if (!karnauhova::input_polygon(in, shaps))
        {
          shaps.pop_back();
          count_error++;
        }
        else
        {
          names[shaps.size() - 1] = name;
         }
      }
      catch (const std::exception& e)
      {
        count_error++;
      }
    }
    else
    {
      count_error++;
    }
  }
  if (names[0] == "SCALE" || names[0].empty() || shaps.size() == 0)
  {
    std::cerr << "Error: empty input\n";
    return 1;
  }
  if (names[shaps.size()] != "SCALE" || k <= 0)
  {
    std::cerr << "Error: scale input\n";
    return 1;
  }
  return 0;
}
