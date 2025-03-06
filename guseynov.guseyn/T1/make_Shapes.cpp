#include "make_Shapes.hpp"

#include <string>

#include "shape.hpp"
#include "rectangle.hpp"
#include "square.hpp"
#include "parallelogram.hpp"
#include "diamond.hpp"

namespace
{
  void rakirovka(double& x, double& x2, double& y, double& y2)
  {
    double timeX, timeY;
    timeX = x2;
    x2 = x;
    x = timeX;
    timeY = y2;
    y2 = y;
    y = timeY;
  }
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
  guseynov::Rectangle* makeRectangle(std::istream& in)
  {
    using namespace guseynov;
    double x0 = 0, y0 = 0, x1 = 0, y1 = 0;
    in >> x0 >> y0 >> x1 >> y1;
    if (x0 >= x1 || y0 >= y1)
    {
      return nullptr;
    }
    point_t leftLowP, rightHighP;
    leftLowP.x = x0;
    leftLowP.y = y0;
    rightHighP.x = x1;
    rightHighP.y = y1;
    Rectangle *rectangle = new Rectangle(leftLowP, rightHighP);
    return rectangle;
  }

  guseynov::Square* makeSquare(std::istream& in)
  {
    using namespace guseynov;
    double x0, y0, length;
    in >> x0 >> y0 >> length;
    if (length <= 0)
    {
      return nullptr;
    }
    point_t leftLowP;
    leftLowP.x = x0;
    leftLowP.y = y0;
    Square *square = new Square(leftLowP, length);
    return square;
  }

  guseynov::Parallelogram* makeParallelogram(std::istream& in)
  {
    using namespace guseynov;
    double x0, y0, x1, y1, x2, y2;
    in >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;
    if (!(((y0 == y1) && (y0 != y2)) || ((y1 == y2) && (y0 != y1))))
    {
      return nullptr;
    }
    point_t leftLowP, leftHighP, rightLowP;
    leftLowP.x = x0;
    leftLowP.y = y0;
    leftHighP.x = x2;
    leftHighP.y = y2;
    rightLowP.x = x1;
    rightLowP.y = y1;
    Parallelogram *parallelogram = new Parallelogram(leftLowP, rightLowP, leftHighP);
    return parallelogram;
  }

  guseynov::Diamond* makeDiamond(std::istream& in)
  {
    using namespace guseynov;
    double x0, y0, x1, y1, x2, y2;
    in >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;
    if (x0 == x1)
    {
     if (y0 > y1)
      {
        rakirovka(x1, x2, y1, y2);
      }
      else if (y1 > y0)
      {
        rakirovka(x1, x2, y1, y2);
        rakirovka(x0, x2, y0, y2);
      }
      else
      {
        return nullptr;
      }
    }
    else if (x1 == x2)
    {
      if (y1 > y2)
      {
        rakirovka(x0, x1, y0, y1);
      }
      else if (y2 > y1)
      {
        rakirovka(x1, x2, y1, y2);
        rakirovka(x0, x1, y0, y1);
      }
      else
      {
        return nullptr;
      }
    }
    else if (x0 != x2)
    {
      return nullptr;
    }
    point_t highP, rightP, center;
    highP.x = x0;
    highP.y = y0;
    rightP.x = x1;
    rightP.y = y1;
    center.x = x2;
    center.y = y2;
    Diamond *diamond = new Diamond(highP, rightP, center);
    return diamond;
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
