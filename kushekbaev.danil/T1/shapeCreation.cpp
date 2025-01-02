#include "shapeCreation.hpp"
#include <iomanip>

namespace kushekbaev
{
  std::string shapeName;
  bool incorrectShapeInput = false;

  void createShape(std::istream& input, Shape** capacity, size_t& shapeCounter, point_t& scalePoint, double& scaleCoeff)
  {
    while (std::cin >> shapeName)
    {
      if (shapeName == "RECTANGLE")
        {
          try
          {
            capacity[shapeCounter++] = kushekbaev::makeRectangle(std::cin);
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
            capacity[shapeCounter++] = kushekbaev::makeConcave(std::cin);
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
            capacity[shapeCounter++] = kushekbaev::makeParallelogram(std::cin);
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
            capacity[shapeCounter++] = kushekbaev::makeDiamond(std::cin);
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
          scalePoint = kushekbaev::makeScale(std::cin);
          std::cin >> scaleCoeff;
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
