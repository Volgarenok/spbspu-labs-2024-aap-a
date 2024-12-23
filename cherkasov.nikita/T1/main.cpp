#include <iostream>
#include <iomanip>
#include <string>
#include "InputHandler.hpp"
#include "deleteShapes.hpp"
#include "calculArea.hpp"
#include "outputFrameCoordinates.hpp"
#include "scaling.hpp"

constexpr size_t maxShapes = 10000;
int main()
{
  cherkasov::Shape* shapes[maxShapes] = {nullptr};
  size_t shapeCount = 0;
  bool invalidInput = false;
  std::string inputCommand;
  cherkasov::point_t p;
  double scalingFactor = 0;
  bool scalingRequested = false;
  while (std::cin >> inputCommand)
  {
    if (inputCommand == "SCALE")
    {
      scalingRequested = true;
      std::cin >> p.x >> p.y >> scalingFactor;
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
  cherkasov::scaling(shapes, shapeCount, p, scalingFactor);
  std::cout << cherkasov::calculArea(shapes, shapeCount);
  cherkasov::outputFrameCoordinates(shapes, shapeCount);
  cherkasov::deleteShapes(shapes, shapeCount);
  return 0;
}
