#include "inputShape.hpp"
#include <string>
#include <stringInput.hpp>

size_t maslov::inputShape(std::istream & in, maslov::Shape ** shapes)
{
  bool flag = true;
  size_t count = 0;
  bool incorrectedFlag = false;
  while (flag)
  {
    std::string name = maslov::inputLine(in, ' ');
    if (name.empty() && !in.eof())
    {
      continue;
    }
    if (name == "SCALE")
    {
      flag = false;
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
    if (in.eof())
    {
      throw std::runtime_error("Error: EOF encountered before SCALE command");
    }
    in.get();
  }
  if (incorrectedFlag)
  {
    std::cerr << "ERROR\n";
  }
  return count;
}

maslov::Rectangle * maslov::makeRectangle(std::istream & in)
{
  double x1 = 0, x2 = 0, y1 = 0, y2 = 0;
  in >> x1 >> y1 >> x2 >> y2;
  if (x2 <= x1 || y1 >= y2)
  {
    throw std::invalid_argument("Incorrect parameters");
  }
  return new maslov::Rectangle({x1, y1}, {x2, y2});
}
