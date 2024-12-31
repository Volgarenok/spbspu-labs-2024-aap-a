#include <stdexcept>
#include <getline.hpp>
#include "shape.hpp"
#include "split.hpp"

int main()
{
  maslevtsov::Shape* shapes[10'000]{nullptr};
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
    std::size_t splitted = 0;
    try
    {
      argStr = maslevtsov::getline(std::cin);
      arguments = maslevtsov::split(argStr, splitted);
      shape = maslevtsov::makeShape(argument, arguments, splitted);
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
      delete[] argStr;
      delete[] arguments;
      continue;
    }
    shapes[shapeIndex++] = shape;
    isImplementedShapes = true;
    delete[] argStr;
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
