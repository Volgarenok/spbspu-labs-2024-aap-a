#include "make_Shapes.hpp"

#include <string>

#include "shape.hpp"
#include "rectangle.hpp"
#include "square.hpp"
#include "parallelogram.hpp"
#include "diamond.hpp"

namespace
{
  guseynov::Shape* makeShape(std::istream & in, const std::string & name);
}

void guseynov::inputShapes(std::istream & in, guseynov::CompositeShape & compositeShape)
{
  using namespace guseynov;
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
  void inputArray(std::istream & in, guseynov::point_t * coordinates, size_t count)
  {
    for (size_t i = 0; i < count; ++i)
    {
      in >> coordinates[i].x >> coordinates[i].y;
    }
  }

  guseynov::Rectangle* makeRectangle(std::istream& in)
  {
    using namespace guseynov;
    constexpr size_t numberOfCoordinates = 2;
    point_t coordinates[numberOfCoordinates] = {};
    inputArray(in, coordinates, numberOfCoordinates);
    if (coordinates[0].x >= coordinates[1].x || coordinates[0].y >= coordinates[1].y)
    {
      throw std::invalid_argument("Rectangle has incorrect parameters");
    }
    point_t leftLowP, rightHighP;
    leftLowP.x = coordinates[0].x;
    leftLowP.y = coordinates[0].y;
    rightHighP.x = coordinates[1].x;
    rightHighP.y = coordinates[1].y;
    return new Rectangle(leftLowP, rightHighP);
  }

  guseynov::Square* makeSquare(std::istream& in)
  {
    using namespace guseynov;
    double length;
    constexpr size_t numberOfCoordinates = 1;
    point_t coordinates[numberOfCoordinates] = {};
    inputArray(in, coordinates, numberOfCoordinates);
    in >> length;
    if (length <= 0)
    {
      throw std::invalid_argument("Square length is incorrect");
    }
    point_t leftLowP;
    leftLowP.x = coordinates[0].x;
    leftLowP.y = coordinates[0].y;
    return new Square(leftLowP, length);
  }

  guseynov::Parallelogram* makeParallelogram(std::istream& in)
  {
    using namespace guseynov;
    constexpr size_t numberOfCoordinates = 3;
    point_t coordinates[numberOfCoordinates] = {};
    inputArray(in, coordinates, numberOfCoordinates);
    bool f1 = coordinates[0].y == coordinates[1].y;
    bool f2 = coordinates[0].y != coordinates[2].y;
    bool f3 = coordinates[1].y == coordinates[2].y;
    bool f4 = coordinates[0].y != coordinates[1].y;
    if (!(((f1) && (f2)) || ((f3) && (f4))))
    {
      throw std::invalid_argument("Parallelogram is not parallel");
    }
    point_t leftLowP, leftHighP, rightLowP;
    leftLowP.x = coordinates[0].x;
    leftLowP.y = coordinates[0].y;
    leftHighP.x = coordinates[2].x;
    leftHighP.y = coordinates[2].y;
    rightLowP.x = coordinates[1].x;
    rightLowP.y = coordinates[1].y;
    return new Parallelogram(leftLowP, rightLowP, leftHighP);
  }

  guseynov::Diamond* makeDiamond(std::istream& in)
  {
    using namespace guseynov;
    constexpr size_t numberOfCoordinates = 3;
    point_t coordinates[numberOfCoordinates] = {};
    inputArray(in, coordinates, numberOfCoordinates);
    return new Diamond(coordinates[0], coordinates[1], coordinates[2]);
  }
  guseynov::Shape* makeShape(std::istream & in, const std::string & name)
  {
    if (name == "RECTANGLE")
    {
      return makeRectangle(in);
    }
    else if (name == "DIAMOND")
    {
      return makeDiamond(in);
    }
    else if (name == "PARALLELOGRAM")
    {
      return makeParallelogram(in);
    }
    else if (name == "SQUARE")
    {
       return makeSquare(in);
    }
    throw std::runtime_error("Incorrect shape name");
  }
}
