#include <stdexcept>
#include <cstring>
#include <getline.hpp>
#include "rectangle.hpp"

namespace maslevtsov
{
  double* split(char* str);
}

double* maslevtsov::split(char* str)
{
  double* result = new double[8];
  str = std::strtok(str, " ");
  std::size_t argumentIndex = 0;

  while (str != nullptr)
  {
    result[argumentIndex] = std::atof(str);
    ++argumentIndex;
    str = std::strtok(nullptr, " ");
  }

  return result;
}

int main()
{
  maslevtsov::Shape* shapes[10'000] = {nullptr};
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
    char* argStr = nullptr;
    double* arguments = nullptr;
    maslevtsov::Shape* shape = nullptr;
    try
    {
      argStr = maslevtsov::getline(std::cin);
      arguments = maslevtsov::split(argStr);
      shape = maslevtsov::makeShape(argument, arguments);
    }
    catch (const std::bad_alloc& e)
    {
      maslevtsov::clearShapes(shapes, shapeIndex);
      delete[] arguments;
      delete[] argStr;
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
    delete[] arguments;
    delete[] argStr;
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
    catch (const std::logic_error& e)
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
