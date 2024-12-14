#include "inputShape.hpp"
#include <string>
#include <stringInput.hpp>

void maslov::inputShape(std::istream & in, maslov::Shape ** shapes)
{
  bool flag = true;
  size_t count = 0;
  while (flag)
  {
    std::string name = maslov::inputLine(in, ' ');
    if (name == "SCALE")
    {
      std::cout << "SCALE\n";
      flag = false;
    }
    if (name == "RECTANGLE")
    {
      try
      {
        shapes[count] = maslov::makeRectangle(in);
        count++;
      }
      catch(...)
      {
        std::cerr << "error\n";
      }
    }
    if (in.eof())
    {
      flag = false;
    } 
  }
}

maslov::Rectangle * maslov::makeRectangle(std::istream & in)
{
  double x1 = 0, x2 = 0, y1 = 0, y2 = 0;
  in >> x1 >> x2 >> y1 >> y2;
  if (x1 > x2)
  {
    std::swap(x1, x2);
  }
  return new maslov::Rectangle({x1, y1}, {x2, y2});
}