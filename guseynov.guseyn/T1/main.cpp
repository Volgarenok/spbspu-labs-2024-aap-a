#include <iostream>
#include <cctype>
#include <iomanip>
#include <workWithString.hpp>

#include "shape.hpp"
#include "make_Shapes.hpp"

int main()
{
  constexpr size_t capacity = 10000;
  char *line = nullptr;
  guseynov::Shape * Shapes[capacity];
  size_t sch = 0;
  size_t current = 0;
  double k = 0;
  bool flag = false;
  guseynov::point_t p = {0, 0};
  while (true)
  {
    free(line);
    line = guseynov::getLine(std::cin);
    if (line == nullptr)
    {
      std::cerr << "Error: unread line\n";
      guseynov::clearShapes(Shapes, current);
      return 1;
    }
    if (std::cin.eof())
    {
      std::cerr << "Error: EOF\n";
      guseynov::clearShapes(Shapes, current);
      free(line);
      return 1;
    }
    size_t f = 0;
    try
    {
      f = guseynov::makeShape(line, Shapes, current, p, k);
      sch++;
      if (f == 1)
      {
        if (!current)
        {
          free(line);
          std::cerr << "Error: empty shapes";
          return 1;
        }
        std::cout << std::fixed << std::setprecision(1) << guseynov::getAreaSum(Shapes, current);
        guseynov::printFrRectCords(std::cout, Shapes, current);
        guseynov::scaleAllRelativeTo(Shapes, current, p, k);
        std::cout << std::fixed << std::setprecision(1) << guseynov::getAreaSum(Shapes, current);
        guseynov::printFrRectCords(std::cout, Shapes, current);
        free(line);
        break;
      }
    }
    catch (...)
    {
      guseynov::clearShapes(Shapes, current);
      free(line);
      return 1;
    }
    if (sch == capacity)
    {
      std::cerr << "ERROR: Memory full\n";
      guseynov::clearShapes(Shapes, current);
      free(line);
      return 1;
    }
    flag = (f == 2) ? true : flag;
  }
  guseynov::clearShapes(Shapes, current);
  if (flag)
  {
    std::cerr << "WARNING: incorect Shapes\n";
  }
}
