#include <iostream>
#include <stdexcept>
#include <limits>
#include "processShapes.hpp"

int main()
{
  krylov::Shape* shapes[10000] = {nullptr};
  size_t shapeCount = 0;
  bool scaleCommandProcessed = false;
  bool invalidDescriptions = false;
  while (!std::cin.eof() && !scaleCommandProcessed)
  {
    std::string shapeType = "";
    std::cin >> shapeType;
    if (std::cin.eof())
    {
      krylov::deleteShapes(shapes, shapeCount);
      std::cerr << "Missing SCALE before EOF\n";
      return 1;
    }
    if (shapeType == "SCALE")
    {
      scaleCommandProcessed = true;
      break;
    }
    try
    {
      krylov::Shape* newShape = krylov::makeShape(shapeType, std::cin);
      shapes[shapeCount++] = newShape;
    }
    catch (const std::exception& e)
    {
      invalidDescriptions = true;
      std::cin.ignore(std::numeric_limits< std::streamsize >::max(), '\n');
    }
  }
  if (shapeCount == 0)
  {
    std::cerr << "Error: Nothing to scale\n";
    return 1;
  }
  krylov::printInfoAboutShapes(shapes, shapeCount);
  try
  {
    krylov::isoScale(std::cin, shapes, shapeCount);
  }
  catch (const std::invalid_argument& e)
  {
    krylov::deleteShapes(shapes, shapeCount);
    std::cerr << e.what() << "\n";
    return 1;
  }
  krylov::printInfoAboutShapes(shapes, shapeCount);
  if (invalidDescriptions)
  {
    std::cerr << "Warning: Some shapes had invalid descriptions\n";
  }
  krylov::deleteShapes(shapes, shapeCount);
  return 0;
}
