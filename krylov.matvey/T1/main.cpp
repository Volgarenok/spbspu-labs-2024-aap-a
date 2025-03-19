#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <limits>
#include "processShapes.hpp"
#include "rectangle.hpp"
#include "ring.hpp"
#include "triangle.hpp"
#include "complexquad.hpp"
#include "processLine.hpp"

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
    try
    {
      if (shapeType == "RING" || shapeType == "TRIANGLE" || shapeType == "COMPLEXQUAD" || shapeType == "RECTANGLE")
      {
        krylov::Shape* newShape = krylov::makeShape(shapeType, std::cin);
        shapes[shapeCount++] = newShape;
      }
      else if (shapeType == "SCALE")
      {
        if (shapeCount == 0)
        {
          std::cerr << "Error: Nothing to scale\n";
          return 1;
        }
        krylov::printInfoAboutShapes(shapes, shapeCount);
        krylov::isoScale(std::cin, shapes, shapeCount);
        krylov::printInfoAboutShapes(shapes, shapeCount);
        scaleCommandProcessed = true;
        break;
      }
      else
      {
        std::cin.ignore(std::numeric_limits< std::streamsize >::max(), '\n');
      }
    }
    catch (const std::exception& e)
    {
      invalidDescriptions = true;
      std::cin.ignore(std::numeric_limits< std::streamsize >::max(), '\n');
    }
  }

  if (!scaleCommandProcessed)
  {
    krylov::deleteShapes(shapes, shapeCount);
    std::cerr << "Error: Missing or invalid SCALE command\n";
    return 1;
  }

  if (invalidDescriptions)
  {
    std::cerr << "Warning: Some shapes had invalid descriptions\n";
  }
  krylov::deleteShapes(shapes, shapeCount);
  return 0;
}



