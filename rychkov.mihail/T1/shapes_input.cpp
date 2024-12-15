#include "shapes_input.hpp"

#include <iostream>
#include <string_comparison.hpp>
#include "rectangle.hpp"

namespace rychkov
{
  static const char* shapeTypes[] = {"RECTANGLE"};
  static Shape* (*shapeGetters[])(std::istream&) = {getRectangle};
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
  rychkov::point_t p1, p2;
  if (std::cin >> p1.x >> p1.y >> p2.x >> p2.y)
  {
    return new rychkov::Rectangle(p1, p2);
  }
  return nullptr;
}
