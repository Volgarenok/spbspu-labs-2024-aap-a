#include <iostream>
#include <iomanip>
#include <cstddef>
#include <stdexcept>
#include <string>
#include <getLine.hpp>
#include "createShapes.hpp"
#include "actionsWithShapes.hpp"
#include "shape.hpp"
#include "auxiliaryFunctions.hpp"

int main()
{
  lebedev::Shape* shps[10000] = {};
  size_t count = 0;
  std::string shapeName;
  bool isIncorrectSize = false;
  lebedev::point_t scalePoint;
  double k = 0;

  while (std::cin >> shapeName)
  {
    if (std::cin.eof())
    {
      std::cerr << "Eof before scale command!\n";
      lebedev::deleteShapePtr(shps, count);
      return 1;
    }
    
    try
    {
      if (shapeName == "RECTANGLE")
      {
        shps[count] = lebedev::createRectangle(std::cin);
        count++;
      }
      else if (shapeName == "DIAMOND")
      {
        shps[count] = lebedev::createDiamond(std::cin);
        count++;
      }
      else if (shapeName == "CONCAVE")
      {
        shps[count] = lebedev::createConcave(std::cin);
        count++;
      }
    }
    catch (const std::bad_alloc& e)
    {
      lebedev::deleteShapePtr(shps, count);
      std::cerr << "Memory allocation error!\n";
      return 2;
    }
    catch (const std::invalid_argument& e)
    {
      isIncorrectSize = true;
    }

    if (shapeName == "SCALE")
    {
      scalePoint = lebedev::chooseScalePoint(std::cin);
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
  lebedev::printFrameCoordinates(shps, count, std::cout);
  lebedev::scaleForShapes(shps, count, scalePoint, k);
  std::cout << lebedev::getSumArea(shps, count);
  lebedev::printFrameCoordinates(shps, count, std::cout);
  lebedev::deleteShapePtr(shps, count);
}
