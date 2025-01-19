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
  bool success = false;
  bool invalid_argument = false;

  while (!success)
  {
    try
    {
      kushekbaev::createShape(std::cin, capacity, shapeCounter, scalePoint, scaleCoeff);
      success = true;
    }

    catch (const std::invalid_argument&)
    {
      invalid_argument = true;
    }

    catch (const std::domain_error&)
    {
      std::cerr << "Bad SCALE command\n";
      kushekbaev::clearMemory(capacity, shapeCounter);
      return 1;
    }

    catch (const std::runtime_error&)
    {
      std::cerr << "Shapeless input\n";
      return 1;
    }
  }

  try
  {
    std::cout << std::fixed << std::setprecision(1) << kushekbaev::getTotalArea(capacity, shapeCounter);

    kushekbaev::outputCoord(capacity, shapeCounter, std::cout);
    std::cout << "\n";

    kushekbaev::scaleTotal(capacity, shapeCounter, scalePoint, scaleCoeff);
    std::cout << kushekbaev::getTotalArea(capacity, shapeCounter);

    kushekbaev::outputCoord(capacity, shapeCounter, std::cout);
    std::cout << "\n";

    kushekbaev::clearMemory(capacity, shapeCounter);
  }

  catch (const std::out_of_range&)
  {
    std::cerr << "Scale coefficient must be greater than zero\n";
    kushekbaev::clearMemory(capacity, shapeCounter);
    return 1;
  }

  if (invalid_argument)
  {
    std::cerr << "Some of inputed shapes were inputed incorrectly\n";
  }
  return 0;
}
