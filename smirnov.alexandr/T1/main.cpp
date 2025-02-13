#include <iostream>
#include "rectangle.hpp"
#include "diamond.hpp"
#include "square.hpp"
#include "parallelogram.hpp"
#include "processShapes.hpp"
#include "createShapes.hpp"

int main()
{
  using namespace smirnov;
  Shape * shapes[10000] = {};
  std::string shapeType = "";
  size_t countShapes = 0;
  bool hasError = false;
  point_t centerPoint = {0.0, 0.0};
  double scaleFactor = 0.0;
  while (!std::cin.eof() && shapeType != "SCALE")
  {
    std::cin >> shapeType;
    if (std::cin.eof())
    {
      destroyShapes(shapes, countShapes);
      std::cerr << "EOF input\n";
      return 1;
    }
    try
    {
      Shape * shape = createShapes(std::cin, shapeType);
      if (shape)
      {
        shapes[countShapes] = shape;
        countShapes++;
      }
      else
      {
        hasError = true;
      }
    }
    catch (const std::invalid_argument & e)
    {
      hasError = true;
    }
    catch (const std::bad_alloc &)
    {
      std::cerr << "Out of memory\n";
      destroyShapes(shapes, countShapes);
      return 1;
    }
  }
  double xCoord = 0.0;
  double yCoord = 0.0;
  std::cin >> xCoord >> yCoord >> scaleFactor;
  centerPoint = {xCoord, yCoord};
  if (scaleFactor <= 0)
  {
    destroyShapes(shapes, countShapes);
    std::cerr << "Incorrect scaleFactor\n";
    return 1;
  }
  if (countShapes == 0)
  {
    std::cerr << "No figures found\n";
    return 1;
  }
  std::cout << std::fixed;
  std::cout.precision(1);
  std::cout << sumArea(shapes, countShapes) << " ";
  printFrameRect(shapes, countShapes, std::cout);
  std::cout << "\n";
  try
  {
    scaleShapes(shapes, countShapes, centerPoint, scaleFactor);
  }
  catch (const std::invalid_argument & e)
  {
    std::cerr << e.what() << '\n';
    destroyShapes(shapes, countShapes);
    return 1;
  }
  std::cout << sumArea(shapes, countShapes) << " ";
  printFrameRect(shapes, countShapes, std::cout);
  std::cout << "\n";
  destroyShapes(shapes, countShapes);
  if (hasError)
  {
    std::cerr << "Incorrect shape size\n";
  }
}
