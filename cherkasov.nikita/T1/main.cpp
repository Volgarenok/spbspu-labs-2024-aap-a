#include <iostream>
#include <iomanip>
#include <cstddef>
#include <stdexcept>
#include <string>
#include "rectangle.h"
#include "square.h"
#include "parallelogram.h"
#include "diamond.h"
#include "deleteShapes.h"
#include "calculArea.h"
#include "outputFrameCoordinates.h"
#include "scaling.h"

constexpr size_t maxShapes = 10000;
int main()
{
  cherkasov::Shape* shapes[maxShapes] = {nullptr};
  size_t shapeCount = 0;
  bool invalidInput = false;
  std::string inputCommand;
  cherkasov::point_t isoCenter;
  double scalingFactor = 0;
  bool scalingRequested = false;
  while (std::cin >> inputCommand)
  {
  if (inputCommand == "RECTANGLE")
  {
    double x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    if (x1 > x2 || y1 > y2)
    {
      invalidInput = true;
    }
    else
    {
      shapes[shapeCount++] = new cherkasov::Rectangle({x1, y1}, {x2, y2});
    }
  }
  else if (inputCommand == "SQUARE")
  {
    double x1, y1, length;
    std::cin >> x1 >> y1 >> length;
    if (length <= 0)
    {
      invalidInput = true;
    }
    else
    {
      shapes[shapeCount++] = new cherkasov::Square({x1, y1}, length);
    }
  }
  else if (inputCommand == "PARALLELOGRAM")
  {
    double x1, y1, x2, y2, x3, y3;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    if ((x1 == x2 && y1 == y2) || (x1 == x3 && y1 == y3))
    {
      invalidInput = true;
    }
    else
    {
      shapes[shapeCount++] = new cherkasov::Parallelogram({x1, y1}, {x2, y2}, {x3, y3});
    }
  }
  else if (inputCommand == "DIAMOND")
  {
    double x1, y1, x2, y2, x3, y3;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    if ((x1 == x2 && y1 == y2) || (x1 == x3 && y1 == y3))
    {
      invalidInput = true;
    }
    else
    {
      shapes[shapeCount++] = new cherkasov::Diamond({x1, y1}, {x2, y2}, {x3, y3});
    }
  }
  else if (inputCommand == "SCALE")
  {
    scalingRequested = true;
    std::cin >> isoCenter.x >> isoCenter.y >> scalingFactor;
    if (scalingFactor <= 0)
    {
      std::cerr << "Scaling factor must be positive\n";
      cherkasov::deleteShapes(shapes, shapeCount);
      return 1;
    }
  }
  else if (std::cin.eof())
  {
    std::cerr << "EOF encountered\n";
    cherkasov::deleteShapes(shapes, shapeCount);
    return 1;
  }
  }
  if (shapeCount == 0)
  {
    std::cerr << "No shapes or scaling not specified\n";
    return 1;
  }
  if (!scalingRequested)
  {
    std::cerr << "Scaling was not specified\n";
    cherkasov::deleteShapes(shapes, shapeCount);
    return 1;
  }
  if (invalidInput)
  {
    std::cerr << "Invalid input encountered\n";
    return 1;
  }
  std::cout << std::fixed << std::setprecision(1);
  std::cout << "Total area before scaling: " << cherkasov::calculArea(shapes, shapeCount) << "\n";
  std::cout << "Frame rectangles before scaling:\n";
  cherkasov::outputFrameCoordinates(shapes, shapeCount);
  cherkasov::scaling(shapes, shapeCount, scalingFactor);
  std::cout << "Total area after scaling: " << cherkasov::calculArea(shapes, shapeCount) << "\n";
  std::cout << "Frame rectangles after scaling:\n";
  cherkasov::outputFrameCoordinates(shapes, shapeCount);
  cherkasov::deleteShapes(shapes, shapeCount);
  return 0;
}
