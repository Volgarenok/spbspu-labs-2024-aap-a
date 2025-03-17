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
        if (shapeType == "RECTANGLE")
        {
          double x1 = 0.0, y1 = 0.0, x2 = 0.0, y2 = 0.0;
          if (!(std::cin >> x1 >> y1 >> x2 >> y2))
          {
            throw std::invalid_argument("Invalid RECTANGLE parameters");
          }
          shapes[shapeCount++] = new krylov::Rectangle({x1, y1}, {x2, y2});
        }
        else if (shapeType == "RING")
        {
          double x, y, outerRadius, innerRadius;
          if (!(std::cin >> x >> y >> outerRadius >> innerRadius))
          {
            throw std::invalid_argument("Invalid RING parameters");
          }
          shapes[shapeCount++] = new krylov::Ring({x, y}, outerRadius, innerRadius);
        }
        else if (shapeType == "TRIANGLE")
        {
          double x1 = 0.0, y1 = 0.0;
          double x2 = 0.0, y2 = 0.0;
          double x3 = 0.0, y3 = 0.0;
          if (!(std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3))
          {
            throw std::invalid_argument("Invalid TRIANGLE parameters");
          }
          shapes[shapeCount++] = new krylov::Triangle({x1, y1}, {x2, y2}, {x3, y3});
        }
        else if (shapeType == "COMPLEXQUAD")
        {
          double x1 = 0.0, y1 = 0.0;
          double x2 = 0.0, y2 = 0.0;
          double x3 = 0.0, y3 = 0.0;
          double x4 = 0.0, y4 = 0.0;
          if (!(std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4))
          {
            throw std::invalid_argument("Invalid COMPLEXQUAD parameters");
          }
          krylov::point_t a = {x1, y1};
          krylov::point_t b = {x2, y2};
          krylov::point_t c = {x3, y3};
          krylov::point_t d = {x4, y4};
          const krylov::point_t p = krylov::findIntersection(a, b, c, d);
          bool isComplexquad = (((a.x == b.x && a.y == b.y) || (b.x == c.x && b.y == c.y) || (c.x == d.x && c.y == d.y)
            || (a.x == c.x && a.y == c.y) || (a.x == d.x && a.y == d.y) || (b.x == d.x && b.y == d.y))
              && (!(krylov::isPointOnSegment(p, a, b) && krylov::isPointOnSegment(p, c, d))) && (!((p.x == a.x && p.y == a.y)
                || (p.x == b.x && p.y == b.y) || (p.x == c.x && p.y == c.y) || (p.x == d.x && p.y == d.y))));
          if (isComplexquad)
          {
            std::cout << "error\n";
            throw std::invalid_argument("Invalid complexquad coordinates");
          }
          shapes[shapeCount++] = new krylov::Complexquad({x1, y1}, {x2, y2}, {x3, y3}, {x4, y4});
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



