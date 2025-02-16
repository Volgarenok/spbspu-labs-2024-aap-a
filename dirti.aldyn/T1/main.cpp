#include <iostream>
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "inputFigures.hpp"

int main()
{
  using namespace dirti;
  Shape * shapes[10000] = {};
  std::string figure = "a";
  size_t num = 0;
  while (s != "SCALE")
  {
    std::cin >> s;
    if (s == "RECTANGLE")
    {
      try
      {
        shapes[num] = makeRectangle(std::cin);
      }
      catch (std::bad_alloc & e)
      {
        std::cerr << "Error" << "\n";
      }
    }
    num++;
    if (s == "SCALE")
    {
      point_t scale_pos = {};
      double koef = 0.0;
      std::cin >> pos.x >> pos.y >> koef;
      if (koef <= 0)
      {
        std::cerr << "Error" << "\n";
        return 1;
        clearShapes();
      }
      num--;
    }
  }
  for (size_t i = 0; i < num; ++i)
  {
    std::cout << shapes[i].getArea() << "\n";
  }
}
