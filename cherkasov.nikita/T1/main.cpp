#include <iostream>
#include <iomanip>
#include <string>
#include "InputHandler.h"
#include "ErrorHandler.h"
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
        cherkasov::handleError("Scaling factor must be positive");
        cherkasov::deleteShapes(shapes, shapeCount);
        return 1;
      }
    }
    else
    {
      cherkasov::Shape* shape = parseShapeInput(inputCommand, invalidInput);
      if (invalidInput || shape == nullptr)
      {
        cherkasov::handleError("Invalid shape input");
        cherkasov::deleteShapes(shapes, shapeCount);
        return 1;
      }
      shapes[shapeCount++] = shape;
    }
  }
  if (shapeCount == 0)
  {
    cherkasov::handleError("No shapes specified");
    return 1;
  }
  if (!scalingRequested)
  {
    cherkasov::handleError("Scaling was not specified");
    cherkasov::deleteShapes(shapes, shapeCount);
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
