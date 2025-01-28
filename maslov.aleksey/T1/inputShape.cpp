#include "inputShape.hpp"
#include <string>
#include "rectangle.hpp"
#include "regular.hpp"
#include "parallelogram.hpp"
#include "shapeManipulator.hpp"

namespace
{
  maslov::Shape * makeShape(std::istream & in, std::string name);
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
    try
    {
      Shape * shape = makeShape(std::cin, name);
      if (shape)
      {
        compositeShape.push_back(shape);
      }
    }
    catch (const std::invalid_argument & e)
    {
      incorrectedFlag = true;
    }
    catch (const std::bad_alloc & e)
    {
      destroyShapes(compositeShape);
      throw;
    }
  }
  if (in.eof())
  {
    destroyShapes(compositeShape);
    throw std::runtime_error("Error: EOF encountered before SCALE command");
  }
  if (incorrectedFlag)
  {
    std::cerr << "There were wrong shapes\n";
  }
  if (compositeShape.size() == 0)
  {
    throw std::runtime_error("There are no shapes");
  }
}

namespace
{
  void inputArray(std::istream & in, double * coordinates, size_t count)
  {
    for (size_t i = 0; i < count; ++i)
    {
      in >> coordinates[i];
    }
  }
  maslov::Rectangle * makeRectangle(std::istream & in)
  {
    constexpr size_t numberOfCoordinates = 4;
    double coordinates[numberOfCoordinates] = {};
    inputArray(in, coordinates, numberOfCoordinates);
    maslov::point_t firstPoint = {coordinates[0], coordinates[1]};
    maslov::point_t secondPoint = {coordinates[2], coordinates[3]};
    maslov::Rectangle * rectangle = new maslov::Rectangle(firstPoint, secondPoint);
    return rectangle;
  }
  maslov::Regular * makeRegular(std::istream & in)
  {
    constexpr size_t numberOfCoordinates = 6;
    double coordinates[numberOfCoordinates] = {};
    inputArray(in, coordinates, numberOfCoordinates);
    maslov::point_t firstPoint = {coordinates[0], coordinates[1]};
    maslov::point_t secondPoint = {coordinates[2], coordinates[3]};
    maslov::point_t thirdPoint = {coordinates[4], coordinates[5]};
    maslov::Regular * regular = new maslov::Regular(firstPoint, secondPoint, thirdPoint);
    return regular;
  }
  maslov::Parallelogram * makeParallelogram(std::istream & in)
  {
    constexpr size_t numberOfCoordinates = 6;
    double coordinates[numberOfCoordinates] = {};
    inputArray(in, coordinates, numberOfCoordinates);
    maslov::point_t firstP = {coordinates[0], coordinates[1]};
    maslov::point_t secondP = {coordinates[2], coordinates[3]};
    maslov::point_t thirdP = {coordinates[4], coordinates[5]};
    maslov::Parallelogram * parallelogram = new maslov::Parallelogram(firstP, secondP, thirdP);
    return parallelogram;
  }
  maslov::Shape * makeShape(std::istream & in, std::string name)
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
    return nullptr;
  }
}
