#include <iostream>
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "inputFigures.hpp"

void clearShapes(dirti::Shape** shapes, size_t num)
{
  for (size_t i = 0; i < num; ++i)
  {
    delete shapes[i];
  }
}

int main()
{
  using namespace dirti;
  Shape* shapes[10000] = {};
  std::string figure = "a";
  size_t num = 0;
  while (figure != "SCALE")
  {
    std::cin >> figure;
    if (figure == "RECTANGLE")
    {
      try
      {
        shapes[num] = makeRectangle(std::cin);
        num++;
      }
      catch (std::logic_error&)
      {
        std::cerr << "Wrong shape" << "\n";
      }
      catch (std::bad_alloc)
      {
        std::cerr << "Error" << "\n";
      }
    }
    if (figure == "SCALE")
    {
      point_t scale_pos = {};
      double koef = 0.0;
      std::cin >> scale_pos.x >> scale_pos.y >> koef;
      if (koef <= 0)
      {
        std::cerr << "Error" << "\n";
        return 1;
        clearShapes(shapes, num);
      }
    }
  }
  for (size_t i = 0; i < num; ++i)
  {
    std::cout << shapes[i]->getArea() << "\n";
  }
}
