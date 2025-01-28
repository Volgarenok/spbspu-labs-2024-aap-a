#include "check.hpp"
#include <cmath>
#include "shape.hpp"
#include "point.hpp"
#include "triangle.hpp"
#include "rectangle.hpp"
#include "polygon.hpp"
bool karnauhova::it_polygon(const point_t* points, size_t count)
{
  for (size_t i = 0; i < count; i ++)
  {
    for (size_t j = i + 1; j < count; j++)
    {
      if (isEqual(points[i], points[j]))
      {
        return false;
      }
    }
  }
  return true;
}
