#include <iostream>
#include <stdexcept>
#include <iomanip>
#include "processShapes.hpp"
#include "rectangle.hpp"
#include "ring.hpp"
#include "triangle.hpp"
#include "complexquad.hpp"

int main()
{
  krylov::Shape* shapes[10000] = {nullptr};
  size_t shapeCount = 0;
  bool scaleCommandProcessed = false;
  bool invalidDescriptions = false;
  while (!std::cin.eof())
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
      if (shapeType == "RECTANGLE")
      {
        shapes[shapeCount++] = krylov::createRectangle();
      }
      else if (shapeType == "RING")
      {
        shapes[shapeCount++] = krylov::createRing();
      }
      else if (shapeType == "TRIANGLE")
      {
        shapes[shapeCount++] = krylov::createTriangle();
      }
      else if (shapeType == "COMPLEXQUAD")
      {
        shapes[shapeCount++] = krylov::createComplexquad();
      }
      else if (shapeType == "SCALE")
      {
        if (shapeCount == 0)
        {
          throw std::logic_error("Nothing to scale");
        }
        double x = 0.0, y = 0.0, factor = 0.0;
        if (!(std::cin >> x >> y >> factor))
        {
          krylov::deleteShapes(shapes, shapeCount);
          std::cerr << "Invalid SCALE parameters\n";
          return 1;
        }
        if (factor <= 0)
        {
          krylov::deleteShapes(shapes, shapeCount);
          std::cerr << "Scale factor must be positive\n";
          return 1;
        }

        double totalAreaBefore = 0.0;
        for (size_t i = 0; i < shapeCount; ++i)
        {
          totalAreaBefore += shapes[i]->getArea();
        }
        krylov::printAreaAndFrameCoords(shapes, shapeCount, totalAreaBefore);
        std::cout << '\n';

        krylov::point_t scaleCenter = {x, y};
        for (size_t i = 0; i < shapeCount; ++i)
        {
          krylov::rectangle_t frameBefore = shapes[i]->getFrameRect();
          shapes[i]->move(scaleCenter);
          shapes[i]->scale(factor);
          krylov::rectangle_t frameAfter = shapes[i]->getFrameRect();
          shapes[i]->move((frameBefore.pos.x - frameAfter.pos.x) * factor, (frameBefore.pos.y - frameAfter.pos.y) * factor);
        }

        double totalAreaAfter = 0.0;
        for (size_t i = 0; i < shapeCount; ++i)
        {
          totalAreaAfter += shapes[i]->getArea();
        }
        krylov::printAreaAndFrameCoords(shapes, shapeCount, totalAreaAfter);
        std::cout << '\n';

        scaleCommandProcessed = true;
        break;
      }
      else
      {
        std::string skippedLines = "";
        std::getline(std::cin, skippedLines);
      }
    }
    catch (const std::exception& e)
    {
      invalidDescriptions = true;
      std::string skippedLines = "";
      std::getline(std::cin, skippedLines);
    }
  }

  if (!scaleCommandProcessed)
  {
    krylov::deleteShapes(shapes, shapeCount);
    std::cerr << "Missing or invalid SCALE command\n";
    return 1;
  }

  if (invalidDescriptions)
  {
    std::cerr << "Warning: Some shapes had invalid descriptions\n";
  }
  krylov::deleteShapes(shapes, shapeCount);
}



