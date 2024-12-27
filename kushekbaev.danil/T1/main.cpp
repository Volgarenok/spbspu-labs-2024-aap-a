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
  bool incorrectShapeInput = false;
  kushekbaev::point_t scalePoint { 0, 0 };
  double scaleCoeff = 0;

  try
  {
    kushekbaev::createShape(std::cin, capacity, shapeCounter, scalePoint, scaleCoeff);
  }

  catch (const std::bad_alloc& e)
  {
    std::cerr << "bad alloc";
    kushekbaev::clearMemory(capacity, shapeCounter);
    return 1;
  }

  catch (const std::logic_error& e)
  {
    std::cerr << e.what();
    kushekbaev::clearMemory(capacity, shapeCounter);
    return 1;
  }

  if (incorrectShapeInput)
  {
    std::cerr << "Some of inputed shapes were incorrectly inputed\n";
  }

  std::cout << std::fixed << std::setprecision(1) << kushekbaev::getTotalArea(capacity, shapeCounter);

  kushekbaev::coordOutput(capacity, shapeCounter, std::cout);
  std::cout << "\n";

  kushekbaev::scaleEverything(capacity, shapeCounter, scalePoint, scaleCoeff);
  std::cout << kushekbaev::getTotalArea(capacity, shapeCounter);

  kushekbaev::coordOutput(capacity, shapeCounter, std::cout);
  std::cout << "\n";

  kushekbaev::clearMemory(capacity, shapeCounter);
  return 0;
}
