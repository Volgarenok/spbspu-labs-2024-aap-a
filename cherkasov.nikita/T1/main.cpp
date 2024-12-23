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
      std::cin >> isoCenter.x >> isoCenter.y >> scalingFactor;
      if (scalingFactor <= 0)
      {
        std::cerr << "Scaling factor must positive\n";
        cherkasov::deleteShapes(shapes, shapeCount);
        return 1;
      }
      break;
    }
    else
    {
      cherkasov::Shape* shape = parseShapeInput(inputCommand, std::cin, invalidInput);
      if (shape == nullptr)
      {
        std::cerr << "Invalid shape input\n";
        cherkasov::deleteShapes(shapes, shapeCount);
        return 1;
        for (size_t i = 0; i < shapeCount; ++i)
        {
          if (shapes[i] == shape)
          {
            std::cerr << "Duplicate shape detected at index " << i << "\n";
            delete shape;
            return 1;
          }
        }
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
  if (invalidInput)
  {
    std::cerr << "Invalid input encountered\n";
  }
  std::cout << std::fixed << std::setprecision(1);
  std::cout << cherkasov::calculArea(shapes, shapeCount);
  cherkasov::outputFrameCoordinates(shapes, shapeCount);
  cherkasov::scaling(shapes, shapeCount, isoCenter, scalingFactor);
  std::cout << cherkasov::calculArea(shapes, shapeCount);
  cherkasov::outputFrameCoordinates(shapes, shapeCount);
  cherkasov::deleteShapes(shapes, shapeCount);
  return 0;
}
