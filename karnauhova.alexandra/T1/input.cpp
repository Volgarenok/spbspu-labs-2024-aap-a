#include "input.hpp"
#include <iostream>
#include <string>
#include <limits>
#include "shape.hpp"

void karnauhova::eat_trash(std::istream & in)
{
  in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool karnauhova::input_rectangle(std::istream & in, double* x_y, size_t j)
{
  double x = 0;
  for (size_t i = 0; i < 4; i++)
  {
    if (!(in >> x))
    {
      karnauhova::eat_trash(in);
      for (size_t n = 0; n < i; n++)
      {
        x_y[j + n] = 0;
      }
      return false;
    }
    x_y[j + i] = x;
  }
  if (in.peek() != '\n' && in.peek() != EOF)
  {
    karnauhova::eat_trash(in);
    return false;
  }
  return true;
}

bool karnauhova::input_triangle(std::istream & in, double* x_y, size_t j)
{
  double x = 0;
  for (size_t i = 0; i < 6; i++)
  {
    if (!(in >> x))
    {
      karnauhova::eat_trash(in);
      for (size_t n = 0; n < i; n++)
      {
        x_y[j + n] = 0;
      }
      return false;
    }
    x_y[j + i] = x;
  }
  if (in.peek() != '\n' && in.peek() != EOF)
  {
    karnauhova::eat_trash(in);
    return false;
  }
  return true;
}

bool karnauhova::input_scale(std::istream & in, double* x_y, size_t j)
{
  double x = 0;
  for (size_t i = 0; i < 3; i++)
  {
    if (!(in >> x))
    {
      karnauhova::eat_trash(in);
      for (size_t n = 0; n < i; n++)
      {
        x_y[j + n] = 0;
      }
      return false;
    }
    x_y[j + i] = x;
  }
  if (in.peek() != '\n' && in.peek() != EOF)
  {
    karnauhova::eat_trash(in);
    return false;
  }
  return true;
}

size_t karnauhova::input_polygon(std::istream & in, double* polygon, size_t count_polygon)
{
  double x = 0;
  double y = 0;
  size_t count = 0;
  while (in.peek() != '\n' && in.peek() != EOF)
  {
    if (!(in >> x))
    {
      karnauhova::eat_trash(in);
      for (size_t n = 0; n < count; n++)
      {
        polygon[count_polygon + n] = 0;
      }
      return 0;
    }
    if (!(in >> y))
    {
      karnauhova::eat_trash(in);
      for (size_t n = 0; n < count; n++)
      {
        polygon[count_polygon + n] = 0;
      }
      return 0;
    }
    polygon[count_polygon + count] = x;
    polygon[count_polygon + count + 1] = y;
    count += 2;
  }
  return count;
}
