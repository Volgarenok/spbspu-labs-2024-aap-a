#include "shapes_input.hpp"

#include <iostream>
#include <string_comparison.hpp>
#include "rectangle.hpp"
#include "regular.hpp"

namespace rychkov
{
  static const char* shapeTypes[] = {"RECTANGLE", "REGULAR"};
  static Shape* (*shapeGetters[])(std::istream&) = {getRectangle, getRegular};
  static constexpr size_t shapeTypesCount = sizeof(shapeTypes) / sizeof(const char*);
}

rychkov::Shape* rychkov::getShape(const char* type, std::istream& in)
{
  for (size_t i = 0; i < shapeTypesCount; i++)
  {
    if (cmpEnd(type, shapeTypes[i]) == 0)
    {
      return shapeGetters[i](in);
    }
  }
  return nullptr;
}
rychkov::Shape* rychkov::getRectangle(std::istream& in)
{
  point_t p1, p2;
  if (in >> p1.x >> p1.y >> p2.x >> p2.y)
  {
    Rectangle* result = static_cast< Rectangle* >(malloc(sizeof(Rectangle)));
    try
    {
      new (result) Rectangle(p1, p2);
      return result;
    }
    catch (...)
    {
      free(result);
      return nullptr;
    }
  }
  return nullptr;
}
rychkov::Shape* rychkov::getRegular(std::istream& in)
{
  point_t p1, p2, p3;
  if (in >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y)
  {
    Regular* result = static_cast< Regular* >(malloc(sizeof(Regular)));
    try
    {
      new (result) Regular(p1, p2, p3);
      return result;
    }
    catch (...)
    {
      free(result);
      return nullptr;
    }
  }
  return nullptr;
}
