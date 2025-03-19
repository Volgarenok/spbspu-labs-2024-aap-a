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
  try
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
            throw std::logic_error("Nothing to scale");
          }
          double x = 0.0, y = 0.0, factor = 0.0;
          if (!(std::cin >> x >> y >> factor))
          {
            throw std::invalid_argument("Invalid SCALE parameters");
          }
          double totalAreaBefore = 0.0;
          for (size_t i = 0; i < shapeCount; ++i)
          {
            if (shapes[i] == nullptr)
            {
              std::cout << "ERROR\n";
            }
            else
            {
              totalAreaBefore += shapes[i]->getArea();
            }
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



