#include "check.hpp"
#include <cmath>
#include "shape.hpp"

bool karnauhova::it_triangle(double* points, size_t c_points)
{
  point_t x1{points[c_points - 6], points[c_points - 5]};
  point_t x2{points[c_points - 4], points[c_points - 3]};
  point_t x3{points[c_points - 2], points[c_points - 1]};
  double len_x1 = x1.x - x2.x;
  double len_y1 = x1.y - x2.y;
  double len_1 = std::sqrt(len_x1 * len_x1 + len_y1 * len_y1);
  double len_x2 = x2.x - x3.x;
  double len_y2 = x2.y - x3.y;
  double len_2 = std::sqrt(len_x2 * len_x2 + len_y2 * len_y2);
  double len_x3 = x3.x - x1.x;
  double len_y3 = x3.y - x1.y;
  double len_3 = std::sqrt(len_x3 * len_x3 + len_y3 * len_y3);
  return (len_1 < (len_2 + len_3) && len_2 < (len_1 + len_3) && len_3 < (len_2 + len_1));
}

bool karnauhova::it_polygon(double* polygon, size_t max_count, size_t count)
{
  for (size_t i = 0; i < count; i += 2)
  {
    for (size_t j = i + 2; j < count; j++)
    {
      if (polygon[max_count + i] == polygon[max_count + j])
      {
        if (polygon[max_count + i + 1] == polygon[max_count + j + 1])
        {
          return false;
        }
      }
    }
  }
  return true;
}

bool karnauhova::same_rectangle(double* points, std::string* names, size_t c_names, size_t c_points)
{
  size_t k = 0;
  for (size_t i = 0; i < (c_names - 1); i++)
  {
    if (names[i] == "RECTANGLE")
    {
      if (points[c_points - 4] == points[k] && points[c_points - 3] == points[k + 1])
      {
        if (points[c_points - 2] == points[k + 2] && points[c_points - 1] == points[k + 3])
        {
          return false;
        }
      }
      else if (points[c_points - 2] == points[k] && points[c_points - 1] == points[k + 1])
      {
        if (points[c_points - 4] == points[k + 2] && points[c_points - 3] == points[k + 3])
        {
          return false;
        }
      }
      k += 4;
    }
    else if (names[i] == "TRIANGLE")
    {
      k += 6;
    }
    else if (names[i] == "POLYGON")
    {
      k += 1;
    }
  }
  return true;
}

bool karnauhova::same_triangle(double* points, std::string* names, size_t c_names, size_t c_points)
{
  size_t k = 0;
  for (size_t i = 0; i < (c_names - 1); i++)
  {
    if (names[i] == "RECTANGLE")
    {
      k += 4;
    }
    else if (names[i] == "TRIANGLE")
    {
      point_t x1{points[c_points - 6], points[c_points - 5]};
      point_t x2{points[c_points - 4], points[c_points - 3]};
      point_t x3{points[c_points - 2], points[c_points - 1]};
      point_t old_x1{points[k], points[k + 1]};
      point_t old_x2{points[k + 2], points[k + 3]};
      point_t old_x3{points[k + 4], points[k + 5]};
      if (x1.x == old_x1.x && x1.y == old_x1.x)
      {
        if (x2.x == old_x2.x && x2.y == old_x2.x)
        {
          if (x3.x == old_x3.x && x3.y == old_x3.x)
          {
            return false;
          }
        }
        else if (x2.x == old_x3.x && x2.y == old_x3.x)
        {
          if (x3.x == old_x2.x && x3.y == old_x2.x)
          {
            return false;
          }
        }
      }
      else if (x1.x == old_x2.x && x1.y == old_x2.x)
      {
        if (x2.x == old_x1.x && x2.y == old_x1.x)
        {
          if (x3.x == old_x3.x && x3.y == old_x3.x)
          {
            return false;
          }
        }
        else if (x2.x == old_x3.x && x2.y == old_x3.x)
        {
          if (x3.x == old_x1.x && x3.y == old_x1.x)
          {
            return false;
          }
        }
      }
      else if (x1.x == old_x3.x && x1.y == old_x3.x)
      {
        if (x2.x == old_x1.x && x2.y == old_x1.x)
        {
          if (x3.x == old_x2.x && x3.y == old_x2.x)
          {
            return false;
          }
        }
        else if (x2.x == old_x2.x && x2.y == old_x2.x)
        {
          if (x3.x == old_x1.x && x3.y == old_x1.x)
          {
            return false;
          }
        }
      }
      k += 6;
    }
    else if (names[i] == "POLYGON")
    {
      k += 1;
    }
  }
  return true;
}
bool karnauhova::same_pol(double* pol, size_t end, std::string* names, size_t c_names, size_t c_points, double* points)
{
  size_t k = 0;
  size_t c_polygon = 0;
  for (size_t i = 0; i < (c_names - 1); i++)
  {
    if (names[i] == "RECTANGLE")
    {
      k += 4;
    }
    else if (names[i] == "TRIANGLE")
    {
      k += 6;
    }
    else if (names[i] == "POLYGON")
    {
      if (points[k] != points[c_points - 1])
      {
        continue;
      }
      size_t y = 0;
      for (size_t j = 0; j < points[k]; j += 2)
      {
        if (pol[c_polygon + j] == pol[end - static_cast< int >(points[c_points - 1])])
        {
          if (pol[c_polygon + j + 1] == pol[end - static_cast< int >(points[c_points - 1]) + 1])
          {
            y++;
          }
        }
      }
      if (y == points[c_points - 1])
      {
        return false;
      }
      k += 1;
    }
  }
  return true;
}
