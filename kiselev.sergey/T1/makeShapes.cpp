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
  void createPoint(size_t size, const double* arrCoord, kiselev::point_t* arr)
  {
    size_t j = 0;
    for (size_t i = 0; i < size; i++)
    {
      arr[j] = { arrCoord[i], arrCoord[++i] };
      j++;
    }
  }
  kiselev::Rectangle* makeRectangle(std::istream& input)
  {
    const size_t quantity = 4;
    double arrCoordinates[quantity] = {};
    kiselev::point_t arrPoint[quantity / 2] = {};
    inputCoordinates(input, arrCoordinates, quantity);
    createPoint(quantity, arrCoordinates, arrPoint);
    return new kiselev::Rectangle(arrPoint[0], arrPoint[1]);
  }
  kiselev::Diamond* makeDiamond(std::istream& input)
  {
    const size_t quantity = 6;
    double arrCoordinates[quantity] = {};
    kiselev::point_t arrPoint[quantity / 2] = {};
    inputCoordinates(input, arrCoordinates, quantity);
    createPoint(quantity, arrCoordinates, arrPoint);
    return new kiselev::Diamond(arrPoint[0], arrPoint[1], arrPoint[2]);
  }
  kiselev::Complexquad* makeComplexquad(std::istream& input)
  {
    const size_t quantity = 8;
    double arrCoordinates[quantity] = {};
    inputCoordinates(input, arrCoordinates, quantity);
    kiselev::point_t arrPoint[quantity / 2] = {};
    createPoint(quantity, arrCoordinates, arrPoint);
    return new kiselev::Complexquad(arrPoint[0], arrPoint[1], arrPoint[2], arrPoint[3]);
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
