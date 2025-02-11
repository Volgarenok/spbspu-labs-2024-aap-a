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


int main()
{
  using namespace sharifullina;
  Shape * shapes[10000] = {};
  size_t count = 0;
  std::string shapeType;
  bool flag = false;
  double scaleK = 0.0;
  point_t scaleCenter = {0.0, 0.0};
  while (std::cin >> shapeType && shapeType != "SCALE")
  {
    try
    {
      shapes[count] = createShape(std::cin, shapeType);
      count++;
    }
    catch (const std::bad_alloc&)
    {
      std::cerr << "Out of memory\n";
      destroyShapes(shapes, count);
      return 1;
    }
    catch (const std::invalid_argument&)
    {
      flag = true;
    }
  }
  double p1 = 0.0;
  double p2 = 0.0;
  if (!(std::cin >> p1 >> p2 >> scaleK) || scaleK <= 0)
  {
    std::cerr << "Incorrect scale\n";
    destroyShapes(shapes, count);
    return 1;
  }
  scaleCenter = {p1, p2};
  if (count == 0)
  {
    std::cerr << "There are no shapes\n";
    return 1;
  }
  std::cout << std::fixed;
  std::cout.precision(1);
  std::cout << getSumArea(shapes, count) << " ";
  printCoorRect(std::cout, shapes, count);
  std::cout << '\n';
  scaleOfShapes(shapes, count, scaleCenter, scaleK);
  std::cout << getSumArea(shapes, count) << " ";
  printCoorRect(std::cout, shapes, count);
  std::cout << '\n';
  destroyShapes(shapes, count);
  if (flag)
  {
    std::cerr << "There is an incorrect shape\n";
  }
}
