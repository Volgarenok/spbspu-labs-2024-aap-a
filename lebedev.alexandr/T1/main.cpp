#include <iostream>
#include <iomanip>
#include <cstddef>
#include <stdexcept>
#include <string>
#include <getLine.hpp>
#include "createShapes.hpp"
#include "actionsWithShapes.hpp"
#include "shape.hpp"

int main()
{
  lebedev::Shape* shps[10000] = {};
  size_t count = 0;
  std::string shapeName;
  bool isIncorrectSize = false;
  lebedev::point_t scalePoint;
  double k = 0;

  try
  {
    while (std::cin >> shapeName)
    {
      if (shapeName == "RECTANGLE")
      {
        try
        {
          shps[count] = lebedev::createRectangle(std::cin);
          count++;
        }
        catch (const std::invalid_argument& e)
        {
          isIncorrectSize = true;
        }
      }

      else if (shapeName == "DIAMOND")
      {
        try
        {
          shps[count] = lebedev::createDiamond(std::cin);
          count++;
        }
        catch (const std::invalid_argument& e)
        {
          isIncorrectSize = true;
        }
      }

      else if (shapeName == "CONCAVE")
      {
        try
        {
          shps[count] = lebedev::createConcave(std::cin);
          count++;
        }
        catch (const std::invalid_argument& e)
        {
          isIncorrectSize = true;
        }
      }

      else if (std::cin.eof())
      {
        std::cerr << "Eof before scale command!\n";
        lebedev::deleteShapePtr(shps, count);
        return 1;
      }

      else if (shapeName == "SCALE")
      {
        scalePoint = lebedev::createScalePoint(std::cin);
        std::cin >> k;
        if (k <= 0)
        {
          std::cerr << "Incorrect scale coefficient!\n";
          lebedev::deleteShapePtr(shps, count);
          return 1;
        }
        break;
      }
    }

    if (isIncorrectSize)
    {
      std::cerr << "Incorrect shape size was entered!\n";
    }

    if (count == 0)
    {
      std::cerr << "No supported shapes were found!\n";
      return 1;
    }

    std::cout << std::setprecision(1);
    std::cout << std::fixed << lebedev::getSumArea(shps, count);
    lebedev::printFrameCoordinates(shps, count);
    lebedev::scaleForShapes(shps, count, scalePoint, k);
    std::cout << lebedev::getSumArea(shps, count);
    lebedev::printFrameCoordinates(shps, count);
    lebedev::deleteShapePtr(shps, count);
  }
  catch (const std::logic_error& e)
  {
    std::cerr << e.what() << '\n';
    lebedev::deleteShapePtr(shps, count);
    return 2;
  }
}
