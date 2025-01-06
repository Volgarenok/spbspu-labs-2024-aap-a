#include "inputShape.hpp"
#include <string>
#include "rectangle.hpp"
#include "regular.hpp"
#include "parallelogram.hpp"
#include "shapeManipulator.hpp"

namespace
{
  using namespace maslov;
  Shape * makeShape(std::istream & in, std::string name);
}

size_t maslov::inputShapes(std::istream & in, maslov::Shape ** shapes)
{
  using namespace maslov;
  size_t count = 0;
  bool incorrectedFlag = false;
  std::string name;
  while (!std::cin.eof() && name != "SCALE")
  {
    std::cin >> name;
    try
    {
      shapes[count] = makeShape(std::cin, name);
      if (shapes[count])
      {
        count++;
      }
    }
    catch (const std::invalid_argument & e)
    {
      incorrectedFlag = true;
    }
    catch (const std::bad_alloc & e)
    {
      destroyShapes(shapes, count);
      throw;
    }
    if (name == "SCALE")
    {
      break;
    }
  }
  if (in.eof())
  {
    destroyShapes(shapes, count);
    throw std::runtime_error("Error: EOF encountered before SCALE command");
  }
  if (incorrectedFlag)
  {
    std::cerr << "There were wrong shapes\n";
  }
  if (count == 0)
  {
    throw std::runtime_error("There are no shapes");
  }
  return count;
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
  Rectangle * makeRectangle(std::istream & in)
  {
    constexpr size_t numberOfCoordinates = 4;
    double coordinates[numberOfCoordinates] = {};
    inputArray(in, coordinates, numberOfCoordinates);
    point_t firstPoint = {coordinates[0], coordinates[1]};
    point_t secondPoint = {coordinates[2], coordinates[3]};
    Rectangle * rectangle = new Rectangle(firstPoint, secondPoint);
    return rectangle;
  }
  Regular * makeRegular(std::istream & in)
  {
    constexpr size_t numberOfCoordinates = 6;
    double coordinates[numberOfCoordinates] = {};
    inputArray(in, coordinates, numberOfCoordinates);
    point_t firstPoint = {coordinates[0], coordinates[1]};
    point_t secondPoint = {coordinates[2], coordinates[3]};
    point_t thirdPoint = {coordinates[4], coordinates[5]};
    Regular * regular = new Regular(firstPoint, secondPoint, thirdPoint);
    return regular;
  }
  Parallelogram * makeParallelogram(std::istream & in)
  {
    constexpr size_t numberOfCoordinates = 6;
    double coordinates[numberOfCoordinates] = {};
    inputArray(in, coordinates, numberOfCoordinates);
    point_t firstPoint = {coordinates[0], coordinates[1]};
    point_t secondPoint = {coordinates[2], coordinates[3]};
    point_t thirdPoint = {coordinates[4], coordinates[5]};
    Parallelogram * parallelogram = new Parallelogram(firstPoint, secondPoint, thirdPoint);
    return parallelogram;
  }
  Shape * makeShape(std::istream & in, std::string name)
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
