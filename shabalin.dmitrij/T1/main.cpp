#include <iostream>
#include <stdexcept>
#include <cstring>
#include <inputOfString.hpp>
#include "shape.hpp"
#include "base-types.hpp"
#include "ioOperations.hpp"
#include "scaleOperations.hpp"
#include "creatingOfShape.hpp"
#include "rectangle.hpp"
#include "diamond.hpp"
#include "parallelogram.hpp"

int main()
{
  using namespace shabalin;
  size_t maxShapesCount = 1000;
  size_t currentShapesCount = 0;
  shabalin::Shape **myShapes = new shabalin::Shape *[maxShapesCount]{nullptr};

  bool errorsFlagShapes = false;
  bool errorsFlagScale = false;

  shabalin::point_t scalePoint = {0.0, 0.0};
  double scaleK = 0;
  const char *targetWordScale = "SCALE";

  char *string = nullptr;

  bool scaleEntered = false;

  while (!scaleEntered)
  {
    if (!std::cin.good())
    {
      shabalin::freeMem(myShapes, currentShapesCount);
      std::cerr << "Somthing went wrong with input, might be EOF!\n";
      return 1;
    }
    const char end = '\n';
    try
    {
      string = shabalin::inputOfString(std::cin, end);
    }
    catch (const std::exception &e)
    {
      shabalin::freeMem(myShapes, currentShapesCount);
      std::cerr << "Error: " << e.what() << "\n";
      return 1;
    }

    const char * foundScale = std::strstr(string, targetWordScale);
    if (foundScale != nullptr)
    {
      shabalin::inputScale(string, scalePoint, scaleK);
      try
      {
        shabalin::scaleFunction(myShapes, currentShapesCount, scalePoint, scaleK, std::cout);
      }
      catch (const std::logic_error &e)
      {
        errorsFlagScale = true;
      }
      scaleEntered = true;
    }
    else
    {
      try
      {
        if (string[0] != '\0')
        {
          shabalin::defineAndCreateShape(myShapes, currentShapesCount, string);
        }
      }
      catch (const std::logic_error &e)
      {
        errorsFlagShapes = true;
      }

      if (myShapes[currentShapesCount] != nullptr)
      {
        currentShapesCount++;
      }
    }
    free(string);
  }

  if (errorsFlagShapes)
  {
    std::cerr << "\nSomething went wrong with shapes creation!\n";
  }
  if (errorsFlagScale)
  {
    std::cerr << "Something went wrong with scale process, might be incorrect k of scale!\n";
    shabalin::freeMem(myShapes, currentShapesCount);
    return 2;
  }

  if (currentShapesCount == 0)
  {
    std::cerr << "\nNothing to scale!\n";
    shabalin::freeMem(myShapes, currentShapesCount);
    return 2;
  }
  shabalin::freeMem(myShapes, currentShapesCount);
  return 0;
}
