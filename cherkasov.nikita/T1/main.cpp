#include <iostream>
#include <iomanip>
#include <string>
#include "rectangle.hpp"
#include "square.hpp"
#include "parallelogram.hpp"
#include "diamond.hpp"
#include "procesShape.hpp"
#include "makesShape.hpp"

int main()
{
  cherkasov::Shape* shapes[10000] = {};
  size_t shapeCount = 0;
  bool invalidInput = false;
  std::string inputCommand;
  cherkasov::point_t p = {0.0, 0.0};
  double scalingFactor = 0;
  bool scalingRequested = false;
  while (std::cin >> inputCommand)
  {
    if (inputCommand == "RECTANGLE")
    {
      try
      {
        shapes[shapeCount] = cherkasov::getRectangle(std::cin);
        shapeCount++;
      }
      catch (const std::invalid_argument& e)
      {
        invalidInput = true;
      }
    }
    else if (inputCommand == "SQUARE")
    {
      try
      {
        shapes[shapeCount] = cherkasov::getSquare(std::cin);
        shapeCount++;
      }
      catch (const std::invalid_argument& e)
      {
        invalidInput = true;
      }
    }
    else if (inputCommand == "PARALLELOGRAM")
    {
      try
      {
        shapes[shapeCount] = cherkasov::getParallelogram(std::cin);
        shapeCount++;
      }
      catch (const std::invalid_argument& e)
      {
        invalidInput = true;
      }
    }
    else if (inputCommand == "DIAMOND")
    {
      try
      {
        shapes[shapeCount] = cherkasov::getDiamond(std::cin);
        shapeCount++;
      }
      catch (const std::invalid_argument& e)
      {
        invalidInput = true;
      }
    }
    else if (inputCommand == "SCALE")
    {
      scalingRequested = true;
      std::cin >> p.x >> p.y >> scalingFactor;
      if (scalingFactor <= 0)
      {
        cherkasov::deleteShapes(shapes, shapeCount);
        std::cerr << "scaling factor must  positive\n";
        return 1;
      }
      break;
    }
    else if (std::cin.eof())
    {
      deleteShapes(shapes, shapeCount);
      std::cerr << "EOF encountered\n";
      return 1;
    }
  }
  if (shapeCount == 0)
  {
    std::cerr << "no shapes specified\n";
    return 1;
  }
  if (!scalingRequested)
  {
    cherkasov::deleteShapes(shapes, shapeCount);
    std::cerr << "scaling was not specified\n";
    return 1;
  }
  if (invalidInput)
  {
    std::cerr << "invalid input encountered\n";
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
