#include "input.hpp"
#include <iostream>
#include <string>
#include <limits>
#include "shape.hpp"

void karnauhova::eat_trash(std::istream & in)
{
  in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool karnauhova::input_rectangle(std::istream & in, Shape* shaps, size_t count_shaps)
{
  point_t x4{0,0};
  point_t x2{0,0};
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
  x4.x = all_points[0];
  x4.y = all_points[1];
  x2.x = all_points[2];
  x2.y = all_points[3];
  Rectangle shape_rec(x4, x2);
  shaps[count_shaps] = shape_rec;
  return true;
}

bool karnauhova::input_triangle(std::istream & in, Shape* shaps, size_t count_shaps)
{
  point_t x1{0,0};
  point_t x2{0,0};
  point_t x3{0,0};
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
  x1{x_y[0], x_y[1]};
  x2{x_y[2], x_y[3]};
  x2{x_y[4], x_y[5]};
  Triangle shape_tri(x1, x2, x3);
  shaps[count_shaps] = shape_tri;
  return true;
}

bool karnauhova::input_scale(std::istream & in, Shape* shaps, point_t point, double k)
{
  double x_y[3] = 0;
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
  point {x_y[0], x_y[1]};
  k = x_y[2];
  return true;
}

bool karnauhova::input_polygon(std::istream & in, Shape* shaps, size_t count_shaps)
{
  point_t x_y[10000] = {};
  double x = 0;
  double y = 0;
  size_t count = 0;
  while (in.peek() != '\n' && in.peek() != EOF)
  {
    if (!(in >> x))
    {
      eat_trash(in);
      return false;
    }
    if (!(in >> y))
    {
      eat_trash(in);
      return false;
    }
    polygon[count] {x,y};
    count += 1;
  }
  Polygon shape_pol(polygon, count);
  shaps[count_shaps] = shape_pol;
  return true;
}

void karnauhova::fabric_input(std::istream & in, Shape* shaps, size_t count_error, point_t point, double k)
{
  std::string names[10000] = {};
  size_t count_shape = 0;
  std::string name = "uwu";
  while (in >> name && !in.eof())
  {
    if (!name.empty())
    {
      if (name == "RECTANGLE")
      {
        try
        {
          if (!karnauhova::input_rectangle(in, shaps, count_shape))
          {
            in.clear();
            count_error++;
          }
          else
          {
            if (karnauhova::same_rectangle(shaps))
            {
              names[count_shape] = name;
              count_shape++;
            }
            else
            {
              count_error++;
            }
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
            count_error++;
          }
          else
          {
            if (karnauhova::same_triangle(shaps))
            {
              names[count_shape] = name;
              count_shape++;
            }
            else
            {
              count_error++;
            }
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
            count_error++;
          }
          else
          {
            if (karnauhova::same_polygon(shaps))
            {
              names[count_shape] = name;
              count_shape++;
            }
            else
            {
              count_error++;
            }
           }
        }
        catch (const std::exception& e)
        {
          count_error++;
        }
      }
      else
      {
        karnauhova::eat_trash(std::cin);
        count_error++;
      }
    }
  }
  if (names[0] == "SCALE" || names[0].empty())
  {
    std::cerr << "Error: empty input\n";
    return 1;
  }
  if (names[count_shape - 1] != "SCALE")
  {
    std::cerr << "Error: scale input\n";
    return 1;
  }
  return 0;
}
