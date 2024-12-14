#include "inputShape.hpp"
#include "scaleData.hpp"
#include <string>
#include <stringInput.hpp>

maslov::ScaleData maslov::inputShape(std::istream & in, maslov::Shape ** shapes)
{
  maslov::ScaleData scaleData = {{0.0, 0.0}, 0.0};
  bool flag = true;
  size_t count = 0;
  bool incorrectedFlag = false;
  while (flag)
  {
    std::string name = maslov::inputLine(in, ' ');
    if (name == "SCALE")
    {
      if (!(in >> scaleData.center.x >> scaleData.center.y >> scaleData.scaleFactor))
      {
        throw std::invalid_argument("Incorrect parameters");
      }
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
    std::cout << "ERROR";
  }
  return scaleData;
}

maslov::Rectangle * maslov::makeRectangle(std::istream & in)
{
  double x1 = 0, x2 = 0, y1 = 0, y2 = 0;
  if (!(in >> x1 >> x2 >> y1 >> y2))
  {
    throw std::invalid_argument("Incorrect parameters");
  }
  return new maslov::Rectangle({x1, y1}, {x2, y2});
}
