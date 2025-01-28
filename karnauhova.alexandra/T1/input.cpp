#include "input.hpp"
#include <iostream>
#include <string>
#include <limits>
#include "shape.hpp"
#include "triangle.hpp"
#include "rectangle.hpp"
#include "polygon.hpp"
#include "check.hpp"
void karnauhova::eat_trash(std::istream & in)
{
  in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool karnauhova::input_rectangle(std::istream & in, Shape** shaps, size_t count_shaps)
{
  double x_y[4] = {};
  double x = 0;
  for (size_t i = 0; i < 4; i++)
  {
    if (!(in >> x))
    {
      eat_trash(in);
      return false;
    }
    x_y[i] = x;
  }
  if (in.peek() != '\n' && in.peek() != EOF)
  {
    eat_trash(in);
    return false;
  }
  point_t x4{x_y[0], x_y[1]};
  point_t x2{x_y[2], x_y[3]};
  shaps[count_shaps] = new Rectangle(x4, x2);
  return true;
}

bool karnauhova::input_triangle(std::istream & in, Shape** shaps, size_t count_shaps)
{
  double x_y[6] = {};
  double x = 0;
  for (size_t i = 0; i < 6; i++)
  {
    if (!(in >> x))
    {
      eat_trash(in);
      return false;
    }
    x_y[i] = x;
  }
  if (in.peek() != '\n' && in.peek() != EOF)
  {
    eat_trash(in);
    return false;
  }
  point_t x1{x_y[0], x_y[1]};
  point_t x2{x_y[2], x_y[3]};
  point_t x3{x_y[4], x_y[5]};
  shaps[count_shaps] = new Triangle(x1, x2, x3);
  return true;
}

bool karnauhova::input_scale(std::istream & in, point_t& point, double& k)
{
  double x_y[3] = {};
  double x = 0;
  for (size_t i = 0; i < 3; i++)
  {
    if (!(in >> x))
    {
      eat_trash(in);
      return false;
    }
    x_y[i] = x;
  }
  if (in.peek() != '\n' && in.peek() != EOF)
  {
    eat_trash(in);
    return false;
  }
  point.x = x_y[0];
  point.y = x_y[1];
  k = x_y[2];
  return true;
}

bool karnauhova::input_polygon(std::istream & in, Shape** shaps, size_t count_shaps)
{
  size_t size = 1;
  point_t* x_y = new point_t[size];
  double x = 0;
  double y = 0;
  size_t count = 0;
  while (!in.fail() && in >> x)
  //while (in.peek() != '\n' && in.peek() != EOF)
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
    //if (!(in >> x))
    //{
      //eat_trash(in);
      //return false;
    //}
    if (in >> y)
    {
    //if (!(in >> y))
    //{
     // return false;
    //}
      std::cout << x << " " << y << "\n";
      x_y[count].x = x;
      x_y[count].y = y;
      count += 1;
    }
  }
  shaps[count_shaps] = new Polygon(x_y, count);
  delete[] x_y;
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

bool karnauhova::fabric_input(std::istream & in, Shape** shaps, size_t& count_error, point_t& point, double& k, size_t& count_shape)
{
  std::string names[10000] = {};
  std::string name = "uwu";
  while (in >> name && !in.eof())
  {
    if (name == "RECTANGLE")
    {
      try
      {
        if (!karnauhova::input_rectangle(in, shaps, count_shape))
        {
          in.clear();
          delete shaps[count_shape];
          count_error++;
        }
        else
        {
          names[count_shape] = name;
          count_shape++;
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
        if (!karnauhova::input_triangle(in, shaps, count_shape))
        {
          in.clear();
          delete shaps[count_shape];
          count_error++;
        }
        else
        {
          names[count_shape] = name;
          count_shape++;
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
        names[count_shape] = name;
        count_shape++;
      }
    }
    else if (name == "POLYGON")
    {
      try
      {
        if (!karnauhova::input_polygon(in, shaps, count_shape))
        {
          in.clear();
          delete shaps[count_shape];
          count_error++;
        }
        else
        {
          in.clear();
          names[count_shape] = name;
          count_shape++;
         }
      }
      catch (const std::exception& e)
      {
        count_error++;
      }
    }
  }
  if (names[0] == "SCALE" || names[0].empty() || count_shape == 0)
  {
    std::cerr << "Error: empty input\n";
    return 1;
  }
  if (names[count_shape - 1] != "SCALE" || k <= 0)
  {
    std::cerr << "Error: scale input\n";
    return 1;
  }
  count_shape -= 1;
  return 0;
}
