#include <iostream>
#include <iomanip>
#include <string>
#include "procesShape.hpp"
#include "makesShape.hpp"

int main()
{
  cherkasov::Shape* shapes[10000] = {};
  std::string inputCommand;
  size_t shapeCount = 0;
  bool invalidInput = false;
  cherkasov::point_t p = {0.0, 0.0};
  double scalingFactor = 0.0;
  while (std::cin >> inputCommand && inputCommand != "SCALE")
  {
    try
    {
      shapes[shapeCount] = cherkasov::createShape(inputCommand, std::cin);
    }
    catch (const std::invalid_argument& e)
    {
      invalidInput = true;
    }
    catch (const std::bad_alloc&)
    {
      std::cerr << "out memor\n";
      cherkasov::deleteShapes(shapes, shapeCount);
      return 1;
    }
    if (std::cin.eof())
    {
      cherkasov::deleteShapes(shapes, shapeCount);
      std::cerr << "EOF encountered\n";
      return 1;
    }
  }
  if (!(std::cin >> p.x >> p.y >> scalingFactor) || scalingFactor <= 0)
  {
    std::cerr << "incorrect scalingFator\n";
    cherkasov::deleteShapes(shapes, shapeCount);
    return 1;
  } 
  if (shapeCount == 0)
  {
    std::cerr << "no shapes specified\n";
    return 1;
  }
  std::cout << std::fixed << std::setprecision(1);
  std::cout << cherkasov::getSumArea(shapes, shapeCount);
  cherkasov::getCoordinates(shapes, shapeCount);
  cherkasov::getScaling(shapes, shapeCount, p, scalingFactor);
  std::cout << cherkasov::getSumArea(shapes, shapeCount);
  cherkasov::getCoordinates(shapes, shapeCount);
  cherkasov::deleteShapes(shapes, shapeCount);
  if (invalidInput)
  {
    std::cerr << "invalid input encountered\n";
  }
}
