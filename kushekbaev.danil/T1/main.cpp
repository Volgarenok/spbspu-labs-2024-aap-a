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

  try
  {
    kushekbaev::createShape(std::cin, capacity, shapeCounter, scalePoint, scaleCoeff);
  }

  catch (const std::invalid_argument& e)
  {
    std::cerr << "Some of inputed shapes were inputed wrong\n";
  }

  catch (const std::out_of_range& e)
  {
    std::cerr << "incorrect scale coefficient\n";
    kushekbaev::clearMemory(capacity, shapeCounter);
    return 1;
  }

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

  return 0;
}
