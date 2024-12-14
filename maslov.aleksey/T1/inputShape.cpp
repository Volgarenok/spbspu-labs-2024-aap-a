#include "inputShape.hpp"
#include <cstring>

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
        shapes[count] = maslov::makeRectangle(in);
        count++;
      }
      catch(const std::invalid_argument & e)
      {
        incorrectedFlag = true;
      }
    }
  }
  if (in.eof())
  {
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

maslov::Rectangle * maslov::makeRectangle(std::istream & in)
{
  double x1 = 0, x2 = 0, y1 = 0, y2 = 0;
  in >> x1 >> y1 >> x2 >> y2;
  if (x2 <= x1 || y2 <= y1)
  {
    throw std::invalid_argument("Incorrect parameters");
  }
  Rectangle * rectangle = new Rectangle({x1, y1}, {x2, y2});
  return rectangle;
}
