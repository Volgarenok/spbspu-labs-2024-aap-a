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
  size_t capacity = 10000;
  CompositeShape* compShape = new CompositeShape(capacity);
  size_t shapeCounter = 0;
  std::string shapeName;
  point_t scalePoint;
  Shape* shape = nullptr;
  double scaleCoeff = 0;
  bool invalid_argument = false;
  bool scaleCommandFound = false;

  while (std::cin >> shapeName)
  {
    if (std::cin.eof())
    {
      std::cerr << "EOF!\n";
      delete compShape;
      return 1;
    }

    if (shapeName == "SCALE")
    {
      scaleCommandFound = true;
      try
      {
        scalePoint = makeScale(std::cin);
        std::cin >> scaleCoeff;
        if (scaleCoeff <= 0)
        {
          throw std::logic_error("ERROR: Incorrect scale coefficient\n");
        }
      }
      catch (const std::logic_error&)
      {
        std::cerr << "ERROR: Incorrect scale coefficient\n";
        delete compShape;
        return 1;
      }
      break;
    }

    shape = createShape(std::cin, shapeName);

    if (!shape)
    {
      invalid_argument = true;
      continue;
    }

    try
    {
      compShape->push_back(shape);
    }
    catch (const std::bad_alloc&)
    {
      delete shape;
      std::cerr << "Bad allocation\n";
    }

    catch (const std::runtime_error&)
    {
      std::cerr << "Shapeless input\n";
      delete compShape;
      return 1;
    }
  }

  if (!scaleCommandFound)
  {
    std::cerr << "ERROR: No SCALE command found\n";
    delete compShape;
    return 1;
  }

  if (compShape->empty())
  {
    std::cerr << "ERROR: No shapes to scale\n";
    delete compShape;
    return 1;
  }

  kushekbaev::CompositeShape* compShapePtr = compShape;

  try
  {
    std::cout << std::fixed << std::setprecision(1) << compShape->getArea();

    std::cout << " ";
    printFrameCoordinates(std::cout, compShape);
    std::cout << "\n";

    compShape->scaleEverything(*compShape, scalePoint, scaleCoeff);
    std::cout << compShape->getArea();

    std::cout << " ";
    printFrameCoordinates(std::cout, compShape);
    std::cout << "\n";

    clearMemory(shapeCounter, &compShapePtr);
    delete compShape;
  }

  catch (const std::logic_error&)
  {
    std::cerr << "Scale coefficient must be greater than zero\n";
    clearMemory(shapeCounter, &compShapePtr);
    delete compShape;
    return 1;
  }

  if (invalid_argument)
  {
    std::cerr << "Some of inputed shapes were inputed incorrectly\n";
  }
  return 0;
}
