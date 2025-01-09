#include <iostream>
#include <stdexcept>
#include <string>
#include <iomanip>
#include <cstddef>
#include "shape.hpp"
#include "base-types.hpp"
#include "rectangle.hpp"
#include "makeShapes.hpp"
#include "countFinalResults.hpp"
#include "scale.hpp"

using namespace finaev;
int main()
{
  constexpr size_t capacity = 10000;
  Shape* shapes[capacity] = {};
  std::string str = "";
  size_t size = 0;
  double k = 0.0;
  point_t scaleCenter = {0, 0};
  std::string coordinates = "";
  bool isCorrect = false;
  bool isScale = false;
  while (std::cin >> str && !std::cin.eof() && !isScale)
  {
    if (size == capacity)
    {
      std::cerr << "Error. There is no scale!\n";
      return 1;
    }
    else if (std::cin.eof())
    {
      deleteShapes(shapes, size);
      std::cerr << "the program is completed by eof, but scale not described\n";
      return 1;
    }
    else if (str == "SCALE")
    {
      isScale = true;
      std::cin >> scaleCenter.x;
      std::cin >> scaleCenter.y;
      std::cin >> k;
      if (k <= 0)
      {
        std::cerr << "Uncorrect scale coefficient!\n";
        deleteShapes(shapes, size);
        return 1;
      }
      break;
    }
    try
    {
      if (shapes[size] != nullptr)
      {
        shapes[size] = makeShapes(std::cin, str);
        size++;
      }
    }
    catch (std::logic_error& e)
    {
      isCorrect = true;
    }
    catch (std::exception& e)
    {
      deleteShapes(shapes, size);
    }
  }
  if (!isScale)
  {
    std::cerr << "no scale!\n";
    deleteShapes(shapes, size);
    return 1;
  }
  if (isCorrect)
  {
    std::cerr << "Input has uncorrects figures!\n";
  }
  if (size == 0)
  {
    std::cerr << "No figures!\n";
    return 1;
  }
  std::cout << std::fixed << std::setprecision(1) << getSumArea(shapes, size) << " ";
  printFrameRect(std::cout, shapes, size);
  std::cout << "\n";
  scale(shapes, size, scaleCenter, k);
  std::cout << std::fixed << std::setprecision(1) << getSumArea(shapes, size) << " ";
  printFrameRect(std::cout, shapes, size);
  std::cout << "\n";
  deleteShapes(shapes, size);
  return 0;
}


