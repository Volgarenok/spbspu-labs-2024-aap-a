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
  using namespace lebedev;
  Shape* shps[10000] = {};
  size_t count = 0;
  std::string shapeName;
  bool isIncorrectSize = false, thereIsScaleCommand = false;
  point_t scalePoint;
  double k = 0;

  while (std::cin >> shapeName && shapeName != "SCALE")
  {
    try
    {
      if (shapeName == "RECTANGLE")
      {
        shps[count] = createRectangle(std::cin);
        count++;
      }
      else if (shapeName == "DIAMOND")
      {
        shps[count] = createDiamond(std::cin);
        count++;
      }
      else if (shapeName == "CONCAVE")
      {
        shps[count] = createConcave(std::cin);
        count++;
      }
    }
    catch (const std::bad_alloc& e)
    {
      deleteShapePtr(shps, count);
      std::cerr << "Memory allocation error!\n";
      return 2;
    }
    catch (const std::invalid_argument& e)
    {
      isIncorrectSize = true;
    }
  }

  if (shapeName == "SCALE")
  {
    scalePoint = chooseScalePoint(std::cin);
    std::cin >> k;
    if (k <= 0)
    {
      std::cerr << "Incorrect scale coefficient!\n";
      deleteShapePtr(shps, count);
      return 1;
    }
    thereIsScaleCommand = true;
  }

  if (std::cin.eof() && !thereIsScaleCommand)
  {
    std::cerr << "Eof before scale command!\n";
    deleteShapePtr(shps, count);
    return 1;
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
  std::cout << std::fixed << getSumArea(shps, count);
  printFrameCoordinates(shps, count, std::cout);
  scaleForShapes(shps, count, scalePoint, k);
  std::cout << getSumArea(shps, count);
  printFrameCoordinates(shps, count, std::cout);
  deleteShapePtr(shps, count);
  return 0;
}
