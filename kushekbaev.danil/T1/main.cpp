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

  while (true)
  {
    try
    {
      kushekbaev::createShape(std::cin, capacity, shapeCounter, scalePoint, scaleCoeff);
      break;
    }

    catch (const std::invalid_argument& e)
    {
      std::cerr << "Some of inputed shapes were inputed incorrectly\n";
    }

    catch (const std::out_of_range& e)
    {
      std::cerr << "Bad SCALE command\n";
      kushekbaev::clearMemory(capacity, shapeCounter);
      return 1;
    }

    catch (const std::length_error& e)
    {
      std::cerr << "There was no SCALE command\n";
      kushekbaev::clearMemory(capacity, shapeCounter);
      return 1;
    }

    catch (const std::underflow_error& e)
    {
      std::cerr << "Shapeless input\n";
      return 1;
    }
  }

  try
  {
    std::cout << std::fixed << std::setprecision(1) << kushekbaev::getTotalArea(capacity, shapeCounter);

    kushekbaev::coordOutput(capacity, shapeCounter, std::cout);
    std::cout << "\n";

    kushekbaev::totalScaling(capacity, shapeCounter, scalePoint, scaleCoeff);
    std::cout << kushekbaev::getTotalArea(capacity, shapeCounter);

    kushekbaev::coordOutput(capacity, shapeCounter, std::cout);
    std::cout << "\n";

    kushekbaev::clearMemory(capacity, shapeCounter);
  }

  catch (const std::out_of_range& e)
  {
    std::cerr << "Scale coefficient must be greater than zero\n";
    kushekbaev::clearMemory(capacity, shapeCounter);
    return 1;
  }
  return 0;
}
