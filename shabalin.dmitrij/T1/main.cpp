#include <iostream>
#include <stdexcept>
#include <cstring>
//#include <inputOfString.hpp>
#include "input.hpp"
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
  Shape **myShapes = new Shape *[maxShapesCount]{nullptr};

  bool errorsFlagShapes = false;
  bool errorsFlagScale = false;

  point_t scalePoint = {0.0, 0.0};
  double scaleK = 0;
  const char *targetWordScale = "SCALE";

  char *string = nullptr;

  bool scaleEntered = false;
  //const char end = '\n';

  while (!scaleEntered)
  {
    if (!std::cin.good())
    {
      freeMem(myShapes, currentShapesCount);
      std::cerr << "Something went wrong with input, might be EOF!\n";
      return 1;
    }

    try
    {
      string = shabalin::inputLine(std::cin);
      if (string == nullptr)
      {
        throw std::runtime_error("Input error: string is null.");
      }

      const char *foundScale = std::strstr(string, targetWordScale);
      if (foundScale != nullptr)
      {
        inputScale(string, scalePoint, scaleK);
        scaleFunction(myShapes, currentShapesCount, scalePoint, scaleK, std::cout);
        scaleEntered = true;
      }
      else
      {
        if (string[0] != '\0')
        {
          defineAndCreateShape(myShapes, currentShapesCount, string);
          if (currentShapesCount < maxShapesCount && myShapes[currentShapesCount] != nullptr)
          {
            currentShapesCount++;
          }
        }
      }
    }
    catch (const std::logic_error &e)
    {
      if (scaleEntered)
      {
        errorsFlagScale = true;
      }
      else
      {
        errorsFlagShapes = true;
      }
    }
    catch (const std::exception &e)
    {
      freeMem(myShapes, currentShapesCount);
      std::cerr << "Error: " << e.what() << "\n";
      return 1;
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
    freeMem(myShapes, currentShapesCount);
    return 2;
  }

  if (currentShapesCount == 0)
  {
    std::cerr << "\nNothing to scale!\n";
    freeMem(myShapes, currentShapesCount);
    return 2;
  }

  freeMem(myShapes, currentShapesCount);
  return 0;
}
