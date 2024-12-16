#include <iomanip>
#include <iostream>
#include "shapeManipulations.hpp"
#include "shapeBreeding.hpp"
#include "shape.hpp"
#include "shapeManipulations.cpp"

int main()
{
  kushekbaev::Shape* capacity[10000]{};
  size_t shapeCounter = 0;
  std::string shapeName;
  bool incorrectRectangleInput = false;
  bool incorrectConcaveInput = false;
  bool incorrectParallelogramInput = false;
  kushekbaev::point_t scalePoint;
  double scaleCoeff = 0;

  try
  {
    while (std::cin >> shapeName)
    {
      if (shapeName == "RECTANGLE")
      {
        try
        {
          capacity[shapeCounter++] = kushekbaev::makeRectangle(std::cin);
        }

        catch (const std::invalid_argument& e)
        {
          incorrectRectangleInput = true;
        }
      }

      else if (shapeName == "CONCAVE")
      {
        try
        {
          capacity[shapeCounter++] = kushekbaev::makeConcave(std::cin);
        }

        catch (const std::invalid_argument& e)
        {
          incorrectConcaveInput = true;
        }
      }

      else if (shapeName == "PARALLELOGRAM")
      {
        try
        {
          capacity[shapeCounter++] = kushekbaev::makeParallelogram(std::cin);
        }

        catch (const std::invalid_argument& e)
        {
          incorrectParallelogramInput = true;
        }
      }

      else if (shapeName == "SCALE")
      {
        scalePoint = kushekbaev::makeScale(std::cin);
        std::cin >> scaleCoeff;
        if (scaleCoeff <= 0)
        {
          std::cerr << "Incorrect scaleCoeff" << "\n";
          kushekbaev::clearMemory(capacity, shapeCounter);
          return 1;
        }
        break;
      }
    }

    if (incorrectRectangleInput)
    {
      std::cerr << "Some of inputed rectangles were incorrectly inputed" << "\n";
    }

    if (incorrectConcaveInput)
    {
      std::cerr << "Some of inputed concaves were incorrectly inputed" << "\n";
    }

    if (incorrectParallelogramInput)
    {
      std::cerr << "Some of inputed parallelograms were incorrectly inputed" << "\n";
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
}
