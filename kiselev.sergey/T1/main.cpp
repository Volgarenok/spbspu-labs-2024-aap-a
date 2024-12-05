#include <iostream>
#include <string>
#include <inputString.h>
#include "base-types.hpp"
#include "makeShapes.hpp"
#include "shape.hpp"
int main()
{
  kiselev::Shape* shapes[1000] = {};
  size_t countShape = 0;
  std::string titleShape;
  while (std::cin >> titleShape)
  {
    if (titleShape == "RECTANGLE")
    {
      shapes[countShape++] = kiselev::make_rectangle(std::cin);
      titleShape = "";
    }
    else if (titleShape == "SCALE")
    {
      kiselev::point_t scale = kiselev::make_scale(std::cin);
      double ratio = 0;
      std::cin >> ratio;
    }
  }
  for (size_t i = 0; i < countShape; ++i)
  {
    delete shapes[i];
  }
  return 0;
}
