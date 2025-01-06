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
  Rectangle * makeRectangle(std::istream & in)
  {
    double x1 = 0, x2 = 0, y1 = 0, y2 = 0;
    in >> x1 >> y1 >> x2 >> y2;
    Rectangle * rectangle = new Rectangle({x1, y1}, {x2, y2});
    return rectangle;
  }
  Regular * makeRegular(std::istream & in)
  {
    double x1 = 0, y1 = 0, x2 = 0, y2 = 0 , x3 = 0, y3 = 0;
    in >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    Regular * regular = new Regular({x1, y1}, {x2, y2}, {x3, y3});
    return regular;
  }
  Parallelogram * makeParallelogram(std::istream & in)
  {
    double x1 = 0, y1 = 0, x2 = 0, y2 = 0 , x3 = 0, y3 = 0;
    in >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    Parallelogram * parallelogram = new Parallelogram({x1, y1}, {x2, y2}, {x3, y3});
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
