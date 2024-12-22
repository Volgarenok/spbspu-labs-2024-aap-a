#include <iostream>
#include <iomanip>
#include <string>
#include "InputHandler.h"
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
    if (inputCommand == "SCALE")
    {
      scalingRequested = true;
      if (!cherkasov::parseScalingInput(isoCenter.x, isoCenter.y, scalingFactor))
      {
        std::cerr << "Scaling factor must be positive\n";
        cherkasov::deleteShapes(shapes, shapeCount);
        return 1;
      }
      break;
    }
    else
    {
      cherkasov::Shape* shape = parseShapeInput(inputCommand, invalidInput);
      if (invalidInput || shape == nullptr)
      {
        std::cerr << "Invalid shape input\n";
        invalidInput = false;
        continue;
      }
      shapes[shapeCount++] = shape;
    }
  }
  if (std::cin.eof())
  {
    std::cerr << "eof false\n";
    cherkasov::deleteShapes(shapes, shapeCount);
    return 1;
  }
  if (shapeCount == 0)
  {
    std::cerr << "No shapes specified\n";
    return 1;
  }
  if (!scalingRequested)
  {
    std::cerr << "Scaling was not specified\n";
    cherkasov::deleteShapes(shapes, shapeCount);
    return 1;
  }
  std::cout << std::fixed << std::setprecision(1);
  cherkasov::calculArea(shapes, shapeCount);
  cherkasov::outputFrameCoordinates(shapes, shapeCount);
  cherkasov::scaling(shapes, shapeCount, scalingFactor);
  std::cout << "\n";
  std::cout << cherkasov::calculArea(shapes, shapeCount);
  cherkasov::outputFrameCoordinates(shapes, shapeCount);
  std::cout << "\n";
  cherkasov::deleteShapes(shapes, shapeCount);
  return 0;
}
