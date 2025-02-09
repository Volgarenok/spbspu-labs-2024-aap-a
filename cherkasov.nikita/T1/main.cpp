#include <iostream>
#include <iomanip>
#include <string>
#include "rectangle.hpp"
#include "square.hpp"
#include "parallelogram.hpp"
#include "diamond.hpp"
#include "procesShape.hpp"
#include "makesShape.hpp"
#include "shapeFactory.hpp"

int main()
{
  cherkasov::Shape* shapes[1000] = {};
  std::string inputCommand;
  size_t shapeCount = 0;
  bool invalidInput = false;
  cherkasov::point_t p = {0.0, 0.0};
  double scalingFactor = 0.0;
  bool scalingRequested = false;
  while (std::cin >> inputCommand)
  {
    if (inputCommand == "SCALE")
    {
      scalingRequested = true;
      std::cin >> p.x >> p.y >> scalingFactor;
       break;
    }
    else
    {
      try
      {
        shapes[shapeCount] = cherkasov::ShapeFactory::createShape(inputCommand, std::cin);
        if (shapes[shapeCount])
        {
          shapeCount++;
        }
        else
        {
          invalidInput = true;
        }
      }
      catch (const std::invalid_argument&)
      {
        invalidInput = true;
      }
    }
  }
  if (std::cin.eof())
  {
    cherkasov::deleteShapes(shapes, shapeCount);
    std::cerr << "EOF encountered\n";
    return 1;
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
  std::cout << cherkasov::calculArea(shapes, shapeCount) << std::endl;
  cherkasov::outputFrameCoordinates(shapes, shapeCount);
  cherkasov::scaling(shapes, shapeCount, p, scalingFactor);
  std::cout << cherkasov::calculArea(shapes, shapeCount) << std::endl;
  cherkasov::outputFrameCoordinates(shapes, shapeCount);
  cherkasov::deleteShapes(shapes, shapeCount);
  return 0;
}
