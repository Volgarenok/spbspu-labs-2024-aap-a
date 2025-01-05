#include "shapeCreation.hpp"
#include <iomanip>
#include "shapeBreeding.hpp"
#include "shapeManipulations.hpp"

namespace kushekbaev
{
  std::string shapeName;
  bool therewasascale = false;
  bool errorexit = false;

  void createShape(std::istream& input, Shape** capacity, size_t& shapeCounter, point_t& scalePoint, double& scaleCoeff
bool errorexit)
  {
    while (input >> shapeName)
    {
      try
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
          scalePoint = kushekbaev::makeScale(input);
          input >> scaleCoeff;
          if (scaleCoeff <= 0)
          {
            std::cerr << "ERROR: Incorrect scale coefficient\n";
            kushekbaev::clearMemory(capacity, shapeCounter);
            errorexit = true;
          }
          therewasascale = true;
          break;
        }
      }
      catch (const std::invalid_argument& e)
      {
        std::cerr << "Some of inputed shapes were incorrectly inputed\n";
      }
      catch (const std::bad_alloc& e)
      {
        std::cerr << "ERROR: Bad allocation\n";
        kushekbaev::clearMemory(capacity, shapeCounter);
        errorexit = true;
      }
    }
    if (!therewasascale)
    {
      std::cerr << "ERROR: there was no scale\n";
      kushekbaev::clearMemory(capacity, shapeCounter);
      errorexit = true;
    }
  }
}
