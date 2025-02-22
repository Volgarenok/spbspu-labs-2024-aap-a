#include "makeShapes.hpp"
#include <cmath>
#include <istream>
#include <stdexcept>
#include "complexquad.hpp"
#include "diamond.hpp"
#include "rectangle.hpp"
#include "shape.hpp"
namespace
{
  void createPoint(std::istream& input, size_t size, kiselev::point_t* arr)
  {
    double coordX = 0;
    double coordY = 0;
    for (size_t i = 0; i < size; ++i)
    {
      input >> coordX >> coordY;
      arr[i] = { coordX, coordY };
    }
  }
  kiselev::Rectangle* makeRectangle(std::istream& input)
  {
    constexpr size_t quantity = 2;
    kiselev::point_t arrPoint[quantity] = {};
    createPoint(input, quantity, arrPoint);
    return new kiselev::Rectangle(arrPoint[0], arrPoint[1]);
  }
  kiselev::Diamond* makeDiamond(std::istream& input)
  {
    constexpr size_t quantity = 3;
    kiselev::point_t arrPoint[quantity] = {};
    createPoint(input, quantity, arrPoint);
    return new kiselev::Diamond(arrPoint[0], arrPoint[1], arrPoint[2]);
  }
  kiselev::Complexquad* makeComplexquad(std::istream& input)
  {
    constexpr size_t quantity = 4;
    kiselev::point_t arrPoint[quantity] = {};
    createPoint(input, quantity, arrPoint);
    return new kiselev::Complexquad(arrPoint[0], arrPoint[1], arrPoint[2], arrPoint[3]);
  }
}
kiselev::point_t kiselev::makeScale(std::istream& input)
{
  constexpr size_t quantity = 1;
  point_t point[1] = {};
  createPoint(input, quantity, point);
  return point[0];
}
kiselev::Shape* kiselev::makeShape(std::istream& input, const std::string& str)
{
  Shape* shape = nullptr;
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
    return shape;
  }
  catch (const std::invalid_argument&)
  {
    return nullptr;
  }
}
