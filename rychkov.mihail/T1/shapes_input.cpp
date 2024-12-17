#include "shapes_input.hpp"

#include <iostream>
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
  point_t p1, p2;
  if (!(in >> p1.x >> p1.y >> p2.x >> p2.y))
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
    return new (result) Rectangle(p1, p2);
  }
  catch (...)
  {
    free(result);
    return nullptr;
  }
}
rychkov::Shape* rychkov::getRegular(std::istream& in)
{
  point_t p1, p2, p3;
  if (in >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y)
  {
    Regular* result = static_cast< Regular* >(malloc(sizeof(Regular)));
    if (!result)
    {
      return nullptr;
    }
    try
    {
      return new (result) Regular(p1, p2, p3);
    }
    catch (...)
    {
      free(result);
      return nullptr;
    }
  }
  return nullptr;
}
rychkov::Shape* rychkov::getPolygon(std::istream& in)
{
  size_t nAllocated = 8, used = 0;
  point_t* points = static_cast< point_t* >(malloc(nAllocated * sizeof(point_t)));
  if (!points)
  {
    return nullptr;
  }

  while (in >> points[used].x)
  {
    if (!(in >> points[used].y))
    {
      free(points);
      return nullptr;
    }
    if (used >= nAllocated)
    {
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
    used++;
  }
  std::cin.clear();
  Polygon* result = static_cast< Polygon* >(malloc(sizeof(Polygon)));
  if (!result)
  {
    return nullptr;
  }
  try
  {
    return new (result) Polygon(points, used);
  }
  catch (...)
  {
    free(result);
    return nullptr;
  }
  return nullptr;
}
