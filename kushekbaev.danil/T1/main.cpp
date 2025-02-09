#include <iomanip>
#include <iostream>
#include "shapeManipulations.hpp"
#include "shapeBreeding.hpp"
#include "shape.hpp"
#include "shapeCreation.hpp"
#include "composite-shape.hpp"

int main()
{
  using namespace kushekbaev;
  CompositeShape compShape[10000];
  size_t shapeCounter = 0;
  std::string shapeName;
  point_t scalePoint;
  Shape* shape = nullptr;
  double scaleCoeff = 0;
  bool invalid_argument = false;

  while (std::cin >> shapeName) //подумать откуда тут вообще цикл, вроде все и без него должно быть
  {
    if (std::cin.eof())
    {
      std::cerr << "EOF!\n";
      return 1;
    }

    try
    {
      if (shapeName == "SCALE")
      {
        try
        {
          scalePoint = makeScale(std::cin);
          std::cin >> scaleCoeff;
        }
        catch (const std::logic_error&)
        {
          throw std::logic_error("ERROR: Incorrect scale coefficient\n");
        }
        break;
      }

      shape = createShape(std::cin, shapeName);

      if (!shape)
      {
        invalid_argument = true;
        continue;
      }
    }

    catch (const std::invalid_argument&)
    {
      invalid_argument = true;
    }

    try
    {
      compShape->push_back(shape);
    }
    catch (const std::bad_alloc&)
    {
      delete[] shape;
      std::cerr << "Bad allocation\n";
    }

    catch (const std::runtime_error&)
    {
      std::cerr << "Shapeless input\n";
      return 1;
    }
  }

  kushekbaev::CompositeShape* compShapePtr = compShape;
  kushekbaev::CompositeShape** compShapePtrPtr = &compShapePtr;


  try
  {
    std::cout << std::fixed << std::setprecision(1) << getTotalArea(shapeCounter, compShapePtrPtr);

    outputCoord(shapeCounter, std::cout, compShapePtrPtr);
    std::cout << "\n";

    scaleAll(shapeCounter, scalePoint, scaleCoeff, compShapePtrPtr);
    std::cout << getTotalArea(shapeCounter, compShapePtrPtr);

    outputCoord(shapeCounter, std::cout, compShapePtrPtr);
    std::cout << "\n";

    clearMemory(shapeCounter, compShapePtrPtr);
  }

  catch (const std::logic_error&)
  {
    std::cerr << "Scale coefficient must be greater than zero\n";
    clearMemory(shapeCounter, compShapePtrPtr);
    return 1;
  }

  if (invalid_argument)
  {
    std::cerr << "Some of inputed shapes were inputed incorrectly\n";
  }
  return 0;
}
