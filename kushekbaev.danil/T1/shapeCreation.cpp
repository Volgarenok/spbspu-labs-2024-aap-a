#include "shapeCreation.hpp"
#include <iomanip>
#include "shapeBreeding.hpp"
#include "shapeManipulations.hpp"

namespace kushekbaev
{
  std::string shapeName;
  bool therewasascale = false;

  void createShape(std::istream& input, Shape** capacity, size_t& shapeCounter, point_t& scalePoint, double& scaleCoeff)
  {
    try
    {
      while (input >> shapeName)
      {
        if (shapeName == "RECTANGLE")
        {
          capacity[shapeCounter++] = kushekbaev::makeRectangle(input);
        }
          else if (shapeName == "CONCAVE")
        {
          capacity[shapeCounter++] = kushekbaev::makeConcave(input);
        }
        else if (shapeName == "PARALLELOGRAM")
        {
          capacity[shapeCounter++] = kushekbaev::makeParallelogram(input);
        }
        else if (shapeName == "DIAMOND")
        {
          capacity[shapeCounter++] = kushekbaev::makeDiamond(input);
        }
        else if (shapeName == "SCALE")
        {
          try
          {
            scalePoint = kushekbaev::makeScale(input);
            input >> scaleCoeff;
          }
          catch (const std::out_of_range& e)
          {
            throw std::out_of_range("ERROR: Incorrect scale coefficient\n");
          }
          therewasascale = true;
          break;
        }
      }
    }
    catch (const std::invalid_argument& e)
    {
      throw std::invalid_argument("Some of inputed shapes were incorrectly inputed\n");
    }
    catch (const std::bad_alloc& e)
    {
      std::cerr << "ERROR: Bad allocation\n";
      kushekbaev::clearMemory(capacity, shapeCounter);
    }

    if (!therewasascale)
    {
      throw std::length_error("ERROR: there was no scale\n");
    }
    if (shapeCounter == 0)
    {
      throw std::underflow_error("Shapeless input\n");
    }
  }
}
