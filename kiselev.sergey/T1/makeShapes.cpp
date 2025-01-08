#include "makeShapes.hpp"
#include <cmath>
#include <iostream>
#include <istream>
#include "base-types.hpp"
#include "complexquad.hpp"
#include "diamond.hpp"
namespace
{
  void inputCoordinates(std::istream& input, double* arr, size_t size)
  {
    for (size_t i = 0; i < size; ++i)
    {
      input >> arr[i];
    }
  }
}
kiselev::Rectangle* kiselev::makeRectangle(std::istream& input)
{
  const size_t quantity = 4;
  double arrCoordinates[quantity] = {};
  inputCoordinates(input, arrCoordinates, quantity);
  point_t left = { arrCoordinates[0], arrCoordinates[1] };
  point_t right = { arrCoordinates[2], arrCoordinates[3] };
  return new Rectangle(left, right);
}
kiselev::point_t kiselev::makeScale(std::istream& input)
{
  double x = 0;
  double y = 0;
  input >> x >> y;
  return { x, y };
}
kiselev::Diamond* kiselev::makeDiamond(std::istream& input)
{
  const size_t quantity = 6;
  double arrCoordinates[6] = {};
  inputCoordinates(input, arrCoordinates, quantity);
  point_t p1 = { arrCoordinates[0], arrCoordinates[1] };
  point_t p2 = { arrCoordinates[2], arrCoordinates[3] };
  point_t p3 = { arrCoordinates[4], arrCoordinates[5] };
  return new Diamond(p1, p2, p3);
}
kiselev::Complexquad* kiselev::makeComplexquad(std::istream& input)
{
  const size_t quantity = 8;
  double arrCoordinates[quantity] = {};
  inputCoordinates(input, arrCoordinates, quantity);
  point_t p1 = { arrCoordinates[0], arrCoordinates[1] };
  point_t p2 = { arrCoordinates[2], arrCoordinates[3] };
  point_t p3 = { arrCoordinates[4], arrCoordinates[5] };
  point_t p4 = { arrCoordinates[6], arrCoordinates[7] };
  return new Complexquad(p1, p2, p3, p4);
}
void kiselev::makeShape(std::string & str, CompositeShape & compShp, bool& isUnknown)
{
  Shape * shape = nullptr;
  try
  {
    if (str == "RECTANGLE")
    {
      shape = makeRectangle(std::cin);
      compShp.push_back(shape);
    }
    else if (str == "DIAMOND")
    {
      shape = makeDiamond(std::cin);
      compShp.push_back(shape);
    }
    else if (str == "COMPLEXQUAD")
    {
      shape = makeComplexquad(std::cin);
      compShp.push_back(shape);
    }
    else
    {
      isUnknown = true;
    }
  }
  catch (...)
  {
    delete shape;
    throw;
  }
}
