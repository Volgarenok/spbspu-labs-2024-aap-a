#include <iostream>
#include <iomanip>
#include "geomFun.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "complexQuad.hpp"
#include "triangle.hpp"

using namespace maslovskiy;

int main()
{
  Shape *shapeArray[10000];
  std::string inputCommand;
  size_t shapeCount = 0;
  bool invalidInput = false;
  point_t isoCenter;
  double scalingFactor;
  bool scalingRequested = false;
  while (std::cin >> inputCommand)
  {
    if (inputCommand == "RECTANGLE")
    {
      double x1, y1, x2, y2;
      std::cin >> x1 >> y1 >> x2 >> y2;
      if (x1 >= x2 || y1 >= y2)
      {
        invalidInput = true;
      }
      else
      {
        shapeArray[shapeCount++] = new Rectangle(x1, y1, x2, y2);
      }
    }
    else if (inputCommand == "COMPLEXQUAD")
    {
      double x1, y1, x2, y2, x3, y3, x4, y4;
      std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
      point_t intersectionPoint = findIntersectionPoint({x1, y1}, {x2, y2}, {x3, y3}, {x4, y4});
      if (!isPointInQuad({x1, y1}, {x2, y2}, {x3, y3}, {x4, y4}, intersectionPoint))
      {
        invalidInput = true;
      }
      else
      {
        shapeArray[shapeCount++] = new ComplexQuad({x1, y1}, {x2, y2}, {x3, y3}, {x4, y4});
      }
    }
    else if (inputCommand == "TRIANGLE")
    {
      double x1, y1, x2, y2, x3, y3;
      std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
      if (!isCorrectTriangle({x1, y1}, {x2, y2}, {x3, y3}))
      {
        invalidInput = true;
      }
      else
      {
        shapeArray[shapeCount++] = new Triangle({x1, y1}, {x2, y2}, {x3, y3});
      }
    }
    else if (inputCommand == "SCALE")
    {
      scalingRequested = true;
      std::cin >> isoCenter.x >> isoCenter.y >> scalingFactor;

      if (scalingFactor <= 0)
      {
        std::cerr << "Scaling factor must be positive\n";
        deleteShapes(shapeArray, shapeCount);
        return 1;
      }
      break;
    }
    else if (std::cin.eof())
    {
      std::cerr << "EOF encountered :(\n";
      deleteShapes(shapeArray, shapeCount);
      return 1;
    }
  }
  if (!scalingRequested)
  {
    std::cerr << "Scaling was not specified\n";
    deleteShapes(shapeArray, shapeCount);
    return 1;
  }
  if (shapeCount == 0)
  {
    std::cerr << "No shapes were created\n";
    return 1;
  }
  if (invalidInput)
  {
    std::cerr << "Invalid input encountered\n";
  }
  std::cout << std::fixed << std::setprecision(1) << calculateTotalArea(shapeArray, shapeCount);
  outputFrameCoordinates(shapeArray, shapeCount);
  applyIsoScaling(shapeArray, shapeCount, isoCenter, scalingFactor);
  std::cout << "\n";
  std::cout << calculateTotalArea(shapeArray, shapeCount);
  outputFrameCoordinates(shapeArray, shapeCount);
  std::cout << "\n";
  deleteShapes(shapeArray, shapeCount);
  return 0;
}
