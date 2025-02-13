#include <iostream>
#include <stdexcept>
#include <iomanip>
#include "processShapes.hpp"
#include "rectangle.hpp"
#include "ring.hpp"
#include "triangle.hpp"
#include "complexquad.hpp"
#include "processLine.hpp"

int main()
{
  try
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
          shapes[shapeCount++] = krylov::createRectangle(std::cin);
        }
        else if (shapeType == "RING")
        {
          shapes[shapeCount++] = krylov::createRing(std::cin);
        }
        else if (shapeType == "TRIANGLE")
        {
          shapes[shapeCount++] = krylov::createTriangle(std::cin);
        }
        else if (shapeType == "COMPLEXQUAD")
        {
          shapes[shapeCount++] = krylov::createComplexquad(std::cin);
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
            throw std::invalid_argument("Invalid SCALE parameters");
          }
          if (factor <= 0)
          {
            throw std::invalid_argument("Scale factor must be positive");
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
          skippedLines = krylov::inputLine(std::cin);
        }
      }
      catch (const std::bad_alloc& e)
      {
        krylov::deleteShapes(shapes, shapeCount);
        throw std::bad_alloc();
      }
      catch (const std::exception& e)
      {
        invalidDescriptions = true;
        std::string skippedLines = "";
        skippedLines = krylov::inputLine(std::cin);
      }
    }

    if (!scaleCommandProcessed)
    {
      krylov::deleteShapes(shapes, shapeCount);
      throw std::invalid_argument("Missing or invalid SCALE command");
    }

    if (invalidDescriptions)
    {
      std::cerr << "Warning: Some shapes had invalid descriptions\n";
    }
    krylov::deleteShapes(shapes, shapeCount);
    return 0;
  }
  catch (const std::exception& e)
  {
    std::cerr << "Error: " << e.what() << '\n';
    return 1;
  }
}



