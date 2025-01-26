#include <iostream>
#include <string>
#include <memory>
#include "makeShape.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "ring.hpp"
#include "circle.hpp"
#include "ellipse.hpp"
#include "actionShapes.hpp"

using namespace sharifullina;

int main()
{
  Shape * shapes[1000] = {};
  size_t count = 0;
  std::string shapeType;
  bool flag = false;
  double scaleK = 0.0;
  point_t scaleCenter = {0.0, 0.0};
  while (shapeType != "SCALE")
  {
    if (std::cin.eof())
    {
      std::cerr << "Incorrect scale\n";
      destroyShapes(shapes, count);
      return 1;
    }
    std::cin >> shapeType;
    if (shapeType == "RECTANGLE")
    {
      try
      {
        shapes[count] = makeRectangle(std::cin);
        count++;
      }
      catch (const std::invalid_argument& e)
      {
        flag = true;
      }
    }
    else if (shapeType == "RING")
    {
      try
      {
        shapes[count] = makeRing(std::cin);
        count++;
      }
      catch (const std::invalid_argument& e)
      {
        flag = true;
      }
    }
    else if (shapeType == "CIRCLE")
    {
      try
      {
        shapes[count] = makeCircle(std::cin);
        count++;
      }
      catch (const std::bad_alloc& e)
      {
        std::cerr << "Out of memory\n";
        destroyShapes(shapes, count);
        return 1;
      }
      catch (const std::invalid_argument& e)
      {
        flag = true;
      }
    }
    else if (shapeType == "ELLIPSE")
    {
      try
      {
        shapes[count] = makeEllipse(std::cin);
        count++;
      }
      catch (const std::invalid_argument&)
      {
        flag = true;
      }
    }
    else if (shapeType == "SCALE")
    {
      double p1 = 0.0;
      double p2 = 0.0;
      std::cin >> p1 >> p2;
      scaleCenter = {p1, p2};
      std::cin >> scaleK;
      break;
    }
  }
  if (scaleK <= 0)
  {
    std::cerr << "Incorrect scale\n";
    destroyShapes(shapes, count);
    return 1;
  }
  if (count == 0)
  {
    std::cerr << "There are no shapes\n";
    return 1;
  }
  std::cout << std::fixed;
  std::cout.precision(1);
  std::cout << getSumArea(shapes, count);
  printCoorRect(std::cout, shapes, count);
  scaleOfShapes(shapes, count, scaleCenter, scaleK);
  std::cout << getSumArea(shapes, count);
  printCoorRect(std::cout, shapes, count);
  destroyShapes(shapes, count);
  if (flag)
  {
    std::cerr << "There is an incorrect shape\n";
  }
}
