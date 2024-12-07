#include <iomanip>
#include <stdexcept>
#include "rectangle.hpp"

int main()
{
  maslevtsov::Shape* shapes[10'000] = {nullptr};
  std::size_t shapeIndex = 0;
  bool isIgnoredShapes = false, isImplementedShapes = false, isScale = false;
  std::string argument = "";
  // double* arguments = new double[8];
  double scalePntX = 0, scalePntY = 0, scaleK = 0;

  while (std::cin >> argument && !std::cin.eof())
  {
    if (argument == "SCALE")
    {
      isScale = true;
      std::cin >> scalePntX >> scalePntY >> scaleK;
      continue;
    }
    maslevtsov::Shape* shape = nullptr;
    try
    {
      // shape = maslevtsov::makeShape(argument, arguments);
      shape = maslevtsov::makeShape(std::cin, argument);
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
    // delete[] arguments;
  }

  if (isIgnoredShapes)
  {
    std::cerr << "Some shapes were ignored\n";
  }
  if (isImplementedShapes)
  {
    std::cout << std::fixed << std::setprecision(1);
    maslevtsov::outputAreaSum(std::cout, shapes, shapeIndex);
    std::cout << ' ';
    maslevtsov::outputShapes(std::cout, shapes, shapeIndex);
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
    maslevtsov::outputAreaSum(std::cout, shapes, shapeIndex);
    std::cout << ' ';
    maslevtsov::outputShapes(std::cout, shapes, shapeIndex);
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
