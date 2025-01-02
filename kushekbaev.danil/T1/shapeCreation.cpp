#include "shapeCreation.hpp"
#include <iomanip>
#include "shapeBreeding.hpp"
#include "shapeManipulations.hpp"

namespace kushekbaev
{
  std::string shapeName;
  bool incorrectShapeInput = false;

  void createShape(std::istream& input, Shape** capacity, size_t& shapeCounter, point_t& scalePoint, double& scaleCoeff)
  {
    while (input >> shapeName)
    {
      if (shapeName == "RECTANGLE")
        {
          try
          {
            capacity[shapeCounter++] = kushekbaev::makeRectangle(input);
            std::cout << "rectangle\n";
          }

          catch (const std::invalid_argument& e)
          {
            incorrectShapeInput = true;
          }
        }

        else if (shapeName == "CONCAVE")
        {
          try
          {
            capacity[shapeCounter++] = kushekbaev::makeConcave(input);
            std::cout << "concave\n";
          }

          catch (const std::invalid_argument& e)
          {
            incorrectShapeInput = true;
          }
        }

        else if (shapeName == "PARALLELOGRAM")
        {
          try
          {
            capacity[shapeCounter++] = kushekbaev::makeParallelogram(input);
            std::cout << "parallelogram\n";
          }

          catch (const std::invalid_argument& e)
          {
            incorrectShapeInput = true;
            std::cerr << e.what();
          }
        }

        else if (shapeName == "DIAMOND")
        {
          try
          {
            capacity[shapeCounter++] = kushekbaev::makeDiamond(input);
            std::cout << "diamond\n";
          }

          catch (const std::invalid_argument& e)
          {
            incorrectShapeInput = true;
            std::cerr << e.what();
          }
        }

        else if (shapeName == "SCALE")
        {
          scalePoint = kushekbaev::makeScale(input);
          input >> scaleCoeff;
          if (scaleCoeff <= 0)
          {
            std::cerr << "Incorrect scaleCoeff" << "\n";
            kushekbaev::clearMemory(capacity, shapeCounter);
          }
          break;
        }
    }

    if (incorrectShapeInput)
    {
      throw std::invalid_argument("Some of inputed shapes were incorrectly inputed\n");
    }

    if (shapeCounter == 0)
    {
      std::cerr << "Shapeless input" << "\n";
    }
  }
}
