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

int main()
{
  using namespace finaev;
  constexpr size_t capacity = 10000;
  Shape* shapes[capacity] = {};
  std::string str = "";
  size_t size = 0;
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
      isScale = 1;
      break;
    }
    try
    {
      shapes[size++] = makeShapes(std::cin, str);
    }
    catch (const std::invalid_argument&)
    {
      isCorrect = true;
    }
    catch (const std::bad_alloc&)
    {
      deleteShapes(shapes, size);
      std::cerr << "No memory\n";
      return 1;
    }
  }
  if (!isScale)
  {
    std::cerr << "no scale!\n";
    deleteShapes(shapes, size);
    return 1;
  }
  double scaleX = 0.0;
  double scaleY = 0.0;
  std::cin >> scaleX;
  std::cin >> scaleY;
  point_t scaleCenter = {scaleX, scaleY};
  double k = 0.0;
  std::cin >> k;
  if (k <= 0)
  {
    std::cerr << "Uncorrect scale coefficient!\n";
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
