#include "inputShape.hpp"
#include <string>
#include "rectangle.hpp"
#include "regular.hpp"
#include "parallelogram.hpp"
#include "shapeManipulator.hpp"

namespace
{
  maslov::Shape * makeShape(std::istream & in, const std::string & name);
}

void maslov::inputShapes(std::istream & in, maslov::CompositeShape & compositeShape)
{
  using namespace maslov;
  bool incorrectedFlag = false;
  std::string name;
  while (!std::cin.eof() && name != "SCALE")
  {
    std::cin >> name;
    if (name == "SCALE")
    {
      break;
    }
    Shape * shape = nullptr;
    try
    {
      shape = makeShape(std::cin, name);
      compositeShape.push_back(shape);
    }
    catch (const std::invalid_argument &)
    {
      incorrectedFlag = true;
    }
    catch (const std::exception &)
    {
      delete shape;
      throw;
    }
  }
  if (in.eof())
  {
    throw std::runtime_error("Error: EOF encountered before SCALE command");
  }
  if (compositeShape.empty())
  {
    throw std::runtime_error("There are no shapes");
  }
  if (incorrectedFlag)
  {
    std::cerr << "There were wrong shapes\n";
  }
}

namespace
{
  void inputArray(std::istream & in, maslov::point_t * coordinates, size_t count)
  {
    for (size_t i = 0; i < count; ++i)
    {
      in >> coordinates[i].x >> coordinates[i].y;
    }
  }
  maslov::Rectangle * makeRectangle(std::istream & in)
  {
    constexpr size_t numberOfCoordinates = 2;
    maslov::point_t coordinates[numberOfCoordinates] = {};
    inputArray(in, coordinates, numberOfCoordinates);
    return new maslov::Rectangle(coordinates[0], coordinates[1]);
  }
  maslov::Regular * makeRegular(std::istream & in)
  {
    constexpr size_t numberOfCoordinates = 3;
    maslov::point_t coordinates[numberOfCoordinates] = {};
    inputArray(in, coordinates, numberOfCoordinates);
    return new maslov::Regular(coordinates[0], coordinates[1], coordinates[2]);
  }
  maslov::Parallelogram * makeParallelogram(std::istream & in)
  {
    constexpr size_t numberOfCoordinates = 3;
    maslov::point_t coordinates[numberOfCoordinates] = {};
    inputArray(in, coordinates, numberOfCoordinates);
    if (coordinates[1].y == coordinates[2].y)
    {
      std::swap(coordinates[0].y, coordinates[2].y);
      std::swap(coordinates[0].x, coordinates[2].x);
    }
    return new maslov::Parallelogram(coordinates[0], coordinates[1], coordinates[2]);
  }
  maslov::Shape * makeShape(std::istream & in, const std::string & name)
  {
    if (name == "RECTANGLE")
    {
      return makeRectangle(in);
    }
    else if (name == "REGULAR")
    {
      return makeRegular(in);
    }
    else if (name == "PARALLELOGRAM")
    {
      return makeParallelogram(in);
    }
    throw std::runtime_error("Incorrect shape name");
  }
}
