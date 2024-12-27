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
            capacity[shapeCounter++] = makeRectangle(input);
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
            capacity[shapeCounter++] = makeConcave(input);
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
            capacity[shapeCounter++] = makeParallelogram(input);
          }

          catch (const std::invalid_argument& e)
          {
            incorrectShapeInput = true;
          }
        }

        else if (shapeName == "DIAMOND")
        {
          try
          {
            capacity[shapeCounter++] = makeDiamond(input);
          }

          catch (const std::invalid_argument& e)
          {
            incorrectShapeInput = true;
          }
        }

        else if (shapeName == "SCALE")
        {
          scalePoint = makeScale(std::cin);
          input >> scaleCoeff;
          break;
        }
      }

    if (shapeCounter == 0)
    {
      throw std::invalid_argument("Shapeless input\n");
    }
  }
}
