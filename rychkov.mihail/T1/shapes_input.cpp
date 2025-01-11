#include "shapes_input.hpp"

#include <iostream>
#include <limits>
#include <string_comparison.hpp>
#include <memf.hpp>
#include "rectangle.hpp"
#include "regular.hpp"
#include "polygon.hpp"

namespace rychkov
{
  static const char* shapeTypes[] = {"RECTANGLE", "REGULAR", "POLYGON"};
  static Shape* (*shapeGetters[])(std::istream&) = {getRectangle, getRegular, getPolygon};
  static constexpr size_t shapeTypesCount = sizeof(shapeTypes) / sizeof(const char*);
}

rychkov::Shape* rychkov::getShape(const char* type, std::istream& in, bool& isUnknown)
{
  isUnknown = false;
  for (size_t i = 0; i < shapeTypesCount; i++)
  {
    if (cmpEnd(type, shapeTypes[i]) == 0)
    {
      return shapeGetters[i](in);
    }
  }
  isUnknown = true;
  return nullptr;
}
rychkov::Shape* rychkov::getRectangle(std::istream& in)
{
  point_t points[2];
  if (getPoints(in, points, 2) != 2)
  {
    return nullptr;
  }
  Rectangle* result = static_cast< Rectangle* >(malloc(sizeof(Rectangle)));
  if (!result)
  {
    return nullptr;
  }
  try
  {
    return new (result) Rectangle(points[0], points[1]);
  }
  catch (...)
  {
    free(result);
    return nullptr;
  }
}
rychkov::Shape* rychkov::getRegular(std::istream& in)
{
  point_t points[3];
  if (getPoints(in, points, 3) != 3)
  {
    return nullptr;
  }
  Regular* result = static_cast< Regular* >(malloc(sizeof(Regular)));
  if (!result)
  {
    return nullptr;
  }
  try
  {
    return new (result) Regular(points[0], points[1], points[2]);
  }
  catch (...)
  {
    free(result);
    return nullptr;
  }
}
rychkov::Shape* rychkov::getPolygon(std::istream& in)
{
  size_t nAllocated = 8, used = 0;
  point_t* points = static_cast< point_t* >(malloc(nAllocated * sizeof(point_t)));
  if (!points)
  {
    return nullptr;
  }

  bool lastWasRead = true;
  while (used += getPoints(in, points + used, nAllocated - used, &lastWasRead), nAllocated <= used)
  {
    if (!lastWasRead)
    {
      free(points);
      return nullptr;
    }

    char* temp = rychkov::realloc(reinterpret_cast< char* >(points), nAllocated * sizeof(point_t),
          used * 2 * sizeof(point_t));
    if (!temp)
    {
      free(points);
      return nullptr;
    }
    nAllocated = used * 2;
    points = reinterpret_cast< rychkov::point_t* >(temp);
  }
  in.clear();
  Polygon* result = static_cast< Polygon* >(malloc(sizeof(Polygon)));
  if (!result)
  {
    free(points);
    return nullptr;
  }
  try
  {
    return new (result) Polygon(points, used);
  }
  catch (...)
  {
    free(result);
    free(points);
    return nullptr;
  }
}

size_t rychkov::getPoints(std::istream& in, point_t* arr, size_t length, bool* lastWasRead)
{
  if (lastWasRead)
  {
    *lastWasRead = true;
  }
  for (size_t i = 0; i < length; i++)
  {
    arr[i].x = std::numeric_limits<double>::quiet_NaN();
    arr[i].y = std::numeric_limits<double>::quiet_NaN();
    if (!(in >> arr[i].x))
    {
      return i;
    }
    if (!(in >> arr[i].y))
    {
      if (lastWasRead)
      {
        *lastWasRead = false;
      }
      return i;
    }
  }
  return length;
}
