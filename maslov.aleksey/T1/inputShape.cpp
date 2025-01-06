#include "inputShape.hpp"
#include <string>
#include "rectangle.hpp"
#include "regular.hpp"
#include "parallelogram.hpp"
#include "shapeManipulator.hpp"

namespace
{
  maslov::Rectangle * makeRectangle(std::istream & in);
  maslov::Regular * makeRegular(std::istream & in);
  maslov::Parallelogram * makeParallelogram(std::istream & in);
}
size_t maslov::inputShapes(std::istream & in, maslov::Shape ** shapes)
{
  size_t count = 0;
  bool incorrectedFlag = false;
  std::string name;
  while (in >> name)
  {
    if (name == "SCALE")
    {
      break;
    }
    else if (name == "RECTANGLE")
    {
      try
      {
        shapes[count] = makeRectangle(in);
        count++;
      }
      catch (const std::invalid_argument & e)
      {
        incorrectedFlag = true;
      }
      catch (const std::bad_alloc & e)
      {
        maslov::destroyShapes(shapes, count);
        throw;
      }
    }
    else if (name == "REGULAR")
    {
      try
      {
        shapes[count] = makeRegular(in);
        count++;
      }
      catch (const std::invalid_argument & e)
      {
        incorrectedFlag = true;
      }
      catch (const std::bad_alloc & e)
      {
        maslov::destroyShapes(shapes, count);
        throw;
      }
    }
    else if (name == "PARALLELOGRAM")
    {
      try
      {
        shapes[count] = makeParallelogram(in);
        count++;
      }
      catch (const std::invalid_argument & e)
      {
        incorrectedFlag = true;
      }
      catch (const std::bad_alloc & e)
      {
        maslov::destroyShapes(shapes, count);
        throw;
      }
    }
  }
  if (in.eof())
  {
    maslov::destroyShapes(shapes, count);
    throw std::runtime_error("Error: EOF encountered before SCALE command");
  }
  if (incorrectedFlag)
  {
    std::cerr << "There were wrong shapes\n";
  }
  if (count == 0)
  {
    maslov::destroyShapes(shapes, count);
    throw std::runtime_error("There are no shapes");
  }
  return count;
}

namespace {
  maslov::Rectangle * makeRectangle(std::istream & in)
  {
    double x1 = 0, x2 = 0, y1 = 0, y2 = 0;
    in >> x1 >> y1 >> x2 >> y2;
    if (x2 <= x1 || y2 <= y1)
    {
      throw std::invalid_argument("Rectangle has incorrect parameters");
    }
    maslov::Rectangle * rectangle = nullptr;
    try
    {
      rectangle = new maslov::Rectangle({x1, y1}, {x2, y2});
    }
    catch (const std::bad_alloc & e)
    {
      throw;
    }
    return rectangle;
  }
  maslov::Regular * makeRegular(std::istream & in)
  {
    double x1 = 0, y1 = 0, x2 = 0, y2 = 0 , x3 = 0, y3 = 0;
    in >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    maslov::Regular * regular = nullptr;
    try
    {
      regular = new maslov::Regular({x1, y1}, {x2, y2}, {x3, y3});
    }
    catch (...)
    {
      throw;
    }
    return regular;
  }
  maslov::Parallelogram * makeParallelogram(std::istream & in)
  {
    double x1 = 0, y1 = 0, x2 = 0, y2 = 0 , x3 = 0, y3 = 0;
    in >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    if ((y1 != y2 && y2 != y3) || (y1 == y3))
    {
      throw std::invalid_argument("Parallelogram is not parallel");
    }
    if (y2 == y3)
    {
      std::swap(y1, y3);
      std::swap(x1, x3);
    }
    maslov::Parallelogram * parallelogram = nullptr;
    try
    {
      parallelogram = new maslov::Parallelogram({x1, y1}, {x2, y2}, {x3, y3});
    }
    catch (const std::bad_alloc & e)
    {
      throw;
    }
    return parallelogram;
  }
}
