#include <iostream>
#include <iomanip>
#include "rectangle.hpp"

int main()
{
  maslevtsov::Shape* shapes[10'000] = {nullptr};
  std::size_t shapeIndex = 0;
  bool isIgnoredShapes = false;
  bool isImplementedShapes = false;

  while (!std::cin.eof())
  {
    maslevtsov::Shape* shape = nullptr;
    try
    {
      shape = maslevtsov::makeShape(std::cin);
    }
    catch (const std::bad_alloc& e)
    {
      maslevtsov::clearShapes(shapes, shapeIndex);
      std::cerr << "Error: fail in memory allocation\n";
      return 1;
    }
    catch (const std::logic_error& e)
    {
      isIgnoredShapes = true;
      continue;
    }
    shapes[shapeIndex++] = shape;
    isImplementedShapes = true;
  }

  if (isIgnoredShapes)
  {
    std::cerr << "Some unsupported shapes has been ignored\n";
  }
  if (isImplementedShapes)
  {
    std::cout << std::fixed << std::setprecision(1);
    maslevtsov::outputAreaSum(std::cout, shapes, shapeIndex);
    std::cout << ' ';
    maslevtsov::outputShapes(std::cout, shapes, shapeIndex);
    std::cout << '\n';
    maslevtsov::scale(shapes[0], {0.0, 0.0}, 2.0);
    maslevtsov::outputAreaSum(std::cout, shapes, shapeIndex);
    std::cout << ' ';
    maslevtsov::outputShapes(std::cout, shapes, shapeIndex);
    std::cout << '\n';
  }
}
