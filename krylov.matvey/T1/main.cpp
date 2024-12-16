#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include "rectangle.hpp"
#include "ring.hpp"
#include "triangle.hpp"

void processShapes();

int main()
{
  try
  {
    processShapes();
    return 0;
  }
  catch (const std::exception& e)
  {
    std::cerr << "Error: " << e.what() << '\n';
    return 1;
  }
}

void processShapes()
{
  krylov::Shape* shapes[10000] = {nullptr};
  size_t shapeCount = 0;
  bool scaleCommandProcessed = false;
  bool invalidDescriptions = false;
  std::string line = "";
  while (std::getline(std::cin, line))
  {
    if (line.empty())
    {
      continue;
    }
    std::istringstream stream(line);
    std::string shapeType = "";
    stream >> shapeType;
    try
    {
      if (shapeType == "RECTANGLE")
      {
        double x1, y1, x2, y2;
        stream >> x1 >> y1 >> x2 >> y2;
        shapes[shapeCount++] = new krylov::Rectangle({x1, y1}, {x2, y2});
      }
      else if (shapeType == "RING")
      {
        double x, y, outerRadius, innerRadius;
        stream >> x >> y >> outerRadius >> innerRadius;
        shapes[shapeCount++] = new krylov::Ring({x, y}, outerRadius, innerRadius);
      }
      else if (shapeType == "TRIANGLE")
      {
        double x1, y1, x2, y2, x3, y3;
        stream >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        shapes[shapeCount++] = new krylov::Triangle({x1, y1}, {x2, y2}, {x3, y3});
      }
      else if (shapeType == "SCALE")
      {
        double x, y, factor;
        stream >> x >> y >> factor;
        if (factor <= 0)
        {
          throw std::invalid_argument("Invalid scale command");
        }
        double totalAreaBefore = 0.0;
        for (size_t i = 0; i < shapeCount; ++i)
        {
          totalAreaBefore += shapes[i]->getArea();
        }
        std::cout << std::fixed << std::setprecision(1) << totalAreaBefore << ' ';
        for (size_t i = 0; i < shapeCount; ++i)
        {
          totalAreaBefore += shapes[i]->getArea();
          krylov::rectangle_t frame = shapes[i]->getFrameRect();
          std::cout << std::fixed << std::setprecision(1) << frame.pos.x - frame.width / 2 << ' ';
          std::cout << std::fixed << std::setprecision(1) << frame.pos.y - frame.height / 2 << ' ';
          std::cout << std::fixed << std::setprecision(1) << frame.pos.x + frame.width / 2 << ' ';
          if (i == shapeCount - 1)
          {
            std::cout << std::fixed << std::setprecision(1) << frame.pos.y + frame.height / 2 << '\n';
          }
          else
          {
            std::cout << std::fixed << std::setprecision(1) << frame.pos.y + frame.height / 2 << ' ';
          }
        }
        std::cout << "\n";
        for (size_t i = 0; i < shapeCount; ++i)
        {
          krylov::point_t shapeCenter = shapes[i]->getFrameRect().pos;
          shapes[i]->move({x - shapeCenter.x, y - shapeCenter.y});
          shapes[i]->scale(factor);
          shapes[i]->move({shapeCenter.x - x,shapeCenter.y - y});
        }
        double totalAreaAfter = 0.0;
        for (size_t i = 0; i < shapeCount; ++i)
        {
          totalAreaAfter += shapes[i]->getArea();
        }
        std::cout << std::fixed << std::setprecision(1) << totalAreaAfter << ' ';
        for (size_t i = 0; i < shapeCount; ++i)
        {
          totalAreaAfter += shapes[i]->getArea();
          krylov::rectangle_t frame = shapes[i]->getFrameRect();
          std::cout << std::fixed << std::setprecision(1) << frame.pos.x - frame.width / 2 << ' ';
          std::cout << std::fixed << std::setprecision(1) << frame.pos.y - frame.height / 2 << ' ';
          std::cout << std::fixed << std::setprecision(1) << frame.pos.x + frame.width / 2 << ' ';
          if (i == shapeCount - 1)
          {
            std::cout << std::fixed << std::setprecision(1) << frame.pos.y + frame.height / 2 << '\n';
          }
          else
          {
            std::cout << std::fixed << std::setprecision(1) << frame.pos.y + frame.height / 2 << ' ';
          }
        }
        std::cout << "\n";
        scaleCommandProcessed = true;
        break;
      }
      else
      {
        invalidDescriptions = true;
      }
    }
    catch (...)
    {
      invalidDescriptions = true;
    }
  }
  if (!scaleCommandProcessed)
  {
    if (std::cin.eof())
    {
      for (size_t i = 0; i < shapeCount; ++i)
      {
      delete shapes[i];
      }
      throw std::invalid_argument("Missing SCALE before EOF\n");
    }
    for (size_t i = 0; i < shapeCount; ++i)
    {
      delete shapes[i];
    }
    throw std::invalid_argument("Missing or invalid SCALE command");
  }
  if (invalidDescriptions)
  {
    std::cerr << "Warning: Some shapes had invalid descriptions\n";
  }
  for (size_t i = 0; i < shapeCount; ++i)
  {
    delete shapes[i];
  }
}
