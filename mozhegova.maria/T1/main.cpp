#include <string>
#include "shape.hpp"
#include "rectangle.hpp"
#include "diamond.hpp"
#include "polygon.hpp"
#include "shapeManipulator.hpp"
#include "makeShape.hpp"

int main()
{
  mozhegova::Shape * shapes[1000] = {};
  size_t count = 0;
  std::string shapeName = "";
  bool flag = false;
  double scaleCoef = 0.0;
  mozhegova::point_t scaleCenter = {0.0, 0.0};
  while (true)
  {
    if (std::cin.eof())
    {
      std::cerr << "Incorrect scale\n";
      mozhegova::destroy(shapes, count);
      return 1;
    }
    std::cin >> shapeName;

    double * num = nullptr;
    size_t len = 0;

    if (shapeName == "RECTANGLE")
    {
      try
      {
        shapes[count++] = mozhegova::makeRectangle(std::cin);
      }
      catch (const std::exception& e)
      {
        flag = true;
      }
    }
    else if (shapeName == "DIAMOND")
    {
      try
      {
        shapes[count++] = mozhegova::makeDiamond(std::cin);
      }
      catch (const std::exception& e)
      {
        flag = true;
      }
    }
    else if (shapeName == "POLYGON")
    {
      try
      {
        shapes[count++] = mozhegova::makeDiamond(std::cin);
      }
      catch (const std::bad_alloc& e)
      {
        std::cerr << "Out of memory\n";
        mozhegova::destroy(shapes, count);
        return 1;
      }
      catch (const std::invalid_argument& e)
      {
        flag = true;
      }
    }
    else if (shapeName == "SCALE")
    {
      double p1 = 0.0;
      double p2 = 0.0;
      std::cin >> p1 >> p2;
      scaleCenter = {p1, p2};
      std::cin >> scaleCoef;
      break;
    }
  }
  if (scaleCoef <= 0)
  {
    std::cerr << "Incorrect scale\n";
    mozhegova::destroy(shapes, count);
    return 1;
  }
  if (count == 0)
  {
    std::cerr << "There are no shapes\n";
    return 1;
  }
  std::cout << std::fixed;
  std::cout.precision(1);
  std::cout << mozhegova::sumArea(shapes, count);
  mozhegova::printCoorRect(shapes, count);
  mozhegova::scaleShapes(shapes, count, scaleCenter, scaleCoef);
  std::cout << mozhegova::sumArea(shapes, count);
  mozhegova::printCoorRect(shapes, count);
  mozhegova::destroy(shapes, count);
  if (flag)
  {
    std::cerr << "There is an incorrect shape\n";
  }
}
