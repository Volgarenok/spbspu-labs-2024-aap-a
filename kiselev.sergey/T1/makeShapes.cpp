#include "makeShapes.hpp"
#include <cmath>
#include <cstddef>
#include <iostream>
#include <istream>
#include "base-types.hpp"
#include "complexquad.hpp"
#include "diamond.hpp"
#include "rectangle.hpp"
namespace
{
  void inputCoordinates(std::istream& input, double* arr, size_t size)
  {
    for (size_t i = 0; i < size; ++i)
    {
      input >> arr[i];
    }
  }
  kiselev::Rectangle* makeRectangle(std::istream& input)
  {
    const size_t quantity = 4;
    double arrCoordinates[quantity] = {};
    inputCoordinates(input, arrCoordinates, quantity);
    kiselev::point_t left = { arrCoordinates[0], arrCoordinates[1] };
    kiselev::point_t right = { arrCoordinates[2], arrCoordinates[3] };
    return new kiselev::Rectangle(left, right);
  }
  kiselev::Diamond* makeDiamond(std::istream& input)
  {
    const size_t quantity = 6;
    double arrCoordinates[quantity] = {};
    inputCoordinates(input, arrCoordinates, quantity);
    kiselev::point_t p1 = { arrCoordinates[0], arrCoordinates[1] };
    kiselev::point_t p2 = { arrCoordinates[2], arrCoordinates[3] };
    kiselev::point_t p3 = { arrCoordinates[4], arrCoordinates[5] };
    return new kiselev::Diamond(p1, p2, p3);
  }
  kiselev::Complexquad* makeComplexquad(std::istream& input)
  {
    const size_t quantity = 8;
    double arrCoordinates[quantity] = {};
    inputCoordinates(input, arrCoordinates, quantity);
    kiselev::point_t p1 = { arrCoordinates[0], arrCoordinates[1] };
    kiselev::point_t p2 = { arrCoordinates[2], arrCoordinates[3] };
    kiselev::point_t p3 = { arrCoordinates[4], arrCoordinates[5] };
    kiselev::point_t p4 = { arrCoordinates[6], arrCoordinates[7] };
    return new kiselev::Complexquad(p1, p2, p3, p4);
  }
}
kiselev::point_t kiselev::makeScale(std::istream& input)
{
  const size_t quantity = 2;
  double arrCoordinates[quantity] = {};
  inputCoordinates(input, arrCoordinates, quantity);
  return { arrCoordinates[0], arrCoordinates[1] };
}
bool kiselev::makeShape(std::istream& input, std::string& str, kiselev::CompositeShape& compShp)
{
  kiselev::Shape * shape = nullptr;
  try
  {
    if (str == "RECTANGLE")
    {
      shape = makeRectangle(input);
    }
    else if (str == "DIAMOND")
    {
      shape = makeDiamond(input);
    }
    else if (str == "COMPLEXQUAD")
    {
      shape = makeComplexquad(input);
    }
    if (shape)
    {
      compShp.pushBack(shape);
    }
    return !str.empty() && str != "SCALE";
  }
  catch (...)
  {
    delete shape;
    throw;
  }
}
