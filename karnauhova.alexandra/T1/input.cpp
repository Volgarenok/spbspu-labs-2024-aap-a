#include "input.hpp"
#include "shape.hpp"
#include "count_point.hpp"
#include <iostream>
#include <string>
#include <limits>

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
      in.clear();
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
      in.clear();
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
