#include <iostream>
#include <cctype>
#include <iomanip>
#include <string>
#include "shape.hpp"
#include "make_Shapes.hpp"

int main()
{
  constexpr size_t capacity = 10000;
  guseynov::Shape *Shapes[capacity];
  std::string str = "";
  size_t current = 0;
  double k = 0;
  bool isScale = false;
  guseynov::point_t p = {0, 0};
  try
  {
    while (std::cin >> str)
    {
      if (str == "RECTANGLE")
      {
        Shapes[current] = guseynov::makeRectangle(std::cin);
        current++;
      }
      else if (str == "SQUARE")
      {
        Shapes[current] = guseynov::makeSquare(std::cin);
        current++;
      }
      else if (str == "PARALLELOGRAM")
      {
        Shapes[current] = guseynov::makeParallelogram(std::cin);
        current++;
      }
      else if (str == "SCALE")
      {
        std::cin >> p.x;
        std::cin >> p.y;
        std::cin >> k;
        isScale = true;
        if (k <= 0)
        {
          std::cerr << "Uncorrect scale coefficient!\n";
          guseynov::clearShapes(Shapes, current);
          return 1;
        }
        if (current == 0)
        {
          return 1;
        }
        std::cout << std::fixed << std::setprecision(1) << guseynov::getAreaSum(Shapes, current);
        guseynov::printFrRectCords(std::cout, Shapes, current);
        guseynov::scaleAllRelativeTo(Shapes, current, p, k);
        std::cout << std::fixed << std::setprecision(1) << guseynov::getAreaSum(Shapes, current);
        guseynov::printFrRectCords(std::cout, Shapes, current);
        break;
      }
      else if (std::cin.eof())
      {
        std::cerr << "Error: EOF\n";
        guseynov::clearShapes(Shapes, current);
        return 1;
      }
      if (current == capacity)
      {
        std::cerr << "ERROR: Memory full\n";
        guseynov::clearShapes(Shapes, current);
        return 1;
      }
    }
  }
  catch(...)
  {
    guseynov::clearShapes(Shapes, current);
    return 1;
  }
  if (!isScale)
  {
    std::cerr << "no scale!\n";
    guseynov::clearShapes(Shapes, current);
    return 1;
  }
  guseynov::clearShapes(Shapes, current);
}
