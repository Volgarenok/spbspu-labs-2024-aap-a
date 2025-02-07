#include <stdexcept>
#include <iostream>
#include "shape.hpp"
#include "getline_string_to_doubles.hpp"

int main()
{
  maslevtsov::Shape* shapes[10'000]{};
  std::size_t shapeIndex = 0;
  bool isIgnoredShapes = false, isImplementedShapes = false, isScale = false;
  std::string argument = "";
  double scalePntX = 0, scalePntY = 0, scaleK = 0;

  while (std::cin >> argument && !std::cin.eof())
  {
    if (argument == "SCALE")
    {
      isScale = true;
      std::cin >> scalePntX >> scalePntY >> scaleK;
      continue;
    }
    std::string argStr = "";
    double* arguments = nullptr;
    maslevtsov::Shape* shape = nullptr;
    std::size_t read = 0;
    try
    {
      arguments = maslevtsov::getlineStringToDoubles(std::cin, read);
      shape = maslevtsov::makeShape(argument, arguments, read);
    }
    catch (const std::bad_alloc& e)
    {
      maslevtsov::clearShapes(shapes, shapeIndex);
      delete[] arguments;
      std::cerr << "Error: fail in memory allocation\n";
      return 1;
    }
    catch (const std::logic_error& e)
    {
      isIgnoredShapes = true;
      delete[] arguments;
      continue;
    }
    shapes[shapeIndex++] = shape;
    isImplementedShapes = true;
    delete[] arguments;
  }

  if (isIgnoredShapes)
  {
    std::cerr << "Some shapes were ignored\n";
  }
  if (isImplementedShapes)
  {
    maslevtsov::outputShapesData(std::cout, shapes, shapeIndex);
    std::cout << '\n';
    try
    {
      maslevtsov::scaleShapes(shapes, {scalePntX, scalePntY}, scaleK, shapeIndex);
    }
    catch (const std::invalid_argument& e)
    {
      std::cerr << "Error: fail in scaling\n";
      maslevtsov::clearShapes(shapes, shapeIndex);
      return 1;
    }
    maslevtsov::outputShapesData(std::cout, shapes, shapeIndex);
    std::cout << '\n';
  }
  else if (isScale)
  {
    std::cerr << "Error: nothing to scale\n";
    maslevtsov::clearShapes(shapes, shapeIndex);
    return 1;
  }

  maslevtsov::clearShapes(shapes, shapeIndex);
}
