#include <iomanip>
#include <iostream>
#include "shapeManipulations.hpp"
#include "shapeBreeding.hpp"
#include "shape.hpp"
#include "shapeCreation.hpp"

int main()
{
  kushekbaev::Shape* capacity[10000]{};
  size_t shapeCounter = 0;
  std::string shapeName;
  kushekbaev::point_t scalePoint;
  double scaleCoeff = 0;
  bool errorexit = false;
  bool incorrectShapeInput = false;

  try
  {
    kushekbaev::createShape(std::cin, capacity, shapeCounter, scalePoint, scaleCoeff);

    if (shapeCounter == 0)
    {
      std::cerr << "Shapeless input" << "\n";
      return 1;
    }

    std::cout << std::fixed << std::setprecision(1) << kushekbaev::getTotalArea(capacity, shapeCounter);

    kushekbaev::coordOutput(capacity, shapeCounter);
    std::cout << "\n";

    kushekbaev::scaleEverything(capacity, shapeCounter, scalePoint, scaleCoeff);
    std::cout << kushekbaev::getTotalArea(capacity, shapeCounter);

    kushekbaev::coordOutput(capacity, shapeCounter);
    std::cout << "\n";

    kushekbaev::clearMemory(capacity, shapeCounter);
  }

  catch (const std::logic_error& e)
  {
    std::cerr << e.what();
    kushekbaev::clearMemory(capacity, shapeCounter);
    return 1;
  }

  catch (const std::bad_alloc& e)
  {
    std::cerr << "Bad alloc" << "\n";
    kushekbaev::clearMemory(capacity, shapeCounter);
    return 1;
  }

  if (incorrectShapeInput)
  {
    std::cerr << "Some of inputed shapes were incorrectly inputed";
    return 0;
  }

  if (errorexit)
  {
    return 1;
  }

  return 0;
}
