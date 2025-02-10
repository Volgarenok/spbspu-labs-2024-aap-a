#include "outputFunctions.hpp"
#include <iomanip>
#include <cmath>
#include "exception"
#include "rectangle.hpp"
#include "circle.hpp"
#include "ring.hpp"
#include "ellipse.hpp"
#include "square.hpp"
#include "triangle.hpp"
#include "complexquad.hpp"

using asafov::point_t;
using asafov::rectangle_t;
using asafov::Shape;

Shape* asafov::ShapeFactory(std::string shapename, std::istream& in)
{
  if (shapename == "RECTANGLE")
  {
    double temp = 0;
    point_t a = {};
    point_t b = {};
    in >> temp;
    a.x = temp;
    in >> temp;
    a.y = temp;
    in >> temp;
    b.x = temp;
    in >> temp;
    b.y = temp;
    if (a.x > b.x || a.y > b.y)
    {
      throw std::logic_error("incorrect figure");
    }
    Rectangle* rect = new Rectangle(a, b);
    return rect;
  }
  else if (shapename == "CIRCLE")
  {
    double temp = 0;
    point_t a = {};
    in >> temp;
    a.x = temp;
    in >> temp;
    a.y = temp;
    in >> temp;
    if (temp <= 0.0)
    {
        throw std::logic_error("incorrect figure");
    }
    Circle* circ = new Circle(a, temp);
    return circ;
  }
  else if (shapename == "RING") {
    double temp = 0;
    point_t a = {};
    in >> temp;
    a.x = temp;
    in >> temp;
    a.y = temp;
    in >> temp;
    double temp2 = 0;
    in >> temp2;
    Ring* ring = new Ring(a, temp, temp2);
    return ring;
  }
  else if (shapename == "ELLIPSE")
  {
    double temp = 0;
    point_t a = {};
    in >> temp;
    a.x = temp;
    in >> temp;
    a.y = temp;
    in >> temp;
    double temp2 = 0;
    in >> temp2;
    if (temp <= 0.0 || temp2 <= 0.0)
    {
        throw std::logic_error("incorrect figure");
    }
    Ellipse* elli = new Ellipse(a, temp, temp2);
    return elli;
  }
  else if (shapename == "SQUARE")
  {
      double temp = 0;
      point_t lb = {};
      in >> temp;
      lb.x = temp;
      in >> temp;
      lb.y = temp;
      in >> temp;
      if (temp <= 0.0)
      {
          throw std::logic_error("incorrect figure");
      }
      Square* squa = new Square(lb, temp);
      return squa;
  }
  else if (shapename == "TRIANGLE")
  {
    double temp = 0;
    point_t a = {};
    point_t b = {};
    point_t c = {};
    in >> temp;
    a.x = temp;
    in >> temp;
    a.y = temp;
    in >> temp;
    b.x = temp;
    in >> temp;
    b.y = temp;
    in >> temp;
    c.x = temp;
    in >> temp;
    c.y = temp;
    double sidea = std::pow(std::pow((a.x - b.x), 2.0) + std::pow((a.y - b.y), 2.0), 0.5);
    double sideb = std::pow(std::pow((b.x - c.x), 2.0) + std::pow((b.y - c.y), 2.0), 0.5);
    double sidec = std::pow(std::pow((a.x - c.x), 2.0) + std::pow((a.y - c.y), 2.0), 0.5);
    temp = (a.x - b.x + a.y - b.y) * (a.x - c.x + a.y - c.y) * (b.x - c.x + b.y - c.y);
    if (temp == 0 || sidea + sideb == sidec || sidea + sidec == sideb || sideb + sidec == sidea)
    {
        throw std::logic_error("incorrect figure");
    }
    Triangle* tria = new Triangle(a, b, c);
    return tria;
  }
  else if (shapename == "COMPLEXQUAD")
  {
    double temp = 0;
    point_t a = {};
    point_t b = {};
    point_t c = {};
    point_t d = {};
    in >> temp;
    a.x = temp;
    in >> temp;
    a.y = temp;
    in >> temp;
    b.x = temp;
    in >> temp;
    b.y = temp;
    in >> temp;
    c.x = temp;
    in >> temp;
    c.y = temp;
    in >> temp;
    d.x = temp;
    in >> temp;
    d.y = temp;
    if ((a.x-b.x+a.y-b.y)*(a.x-c.x+a.y-c.y)*(a.x-d.x+a.y-d.y)*
      (b.x-c.x+b.y-c.y)*(b.x-d.x+b.y-d.y)*(c.x-d.x+c.y-d.y)==0)
    {
        throw std::logic_error("incorrect figure");
    }
    Complexquad* comp = new Complexquad(a, b, c, d);
    return comp;
  }
  double temp = 0;
  point_t a = {};
  Circle* circ = new Circle(a, temp);
  return circ;
}

void asafov::isotropicScale(Shape* sh, point_t pos, double scale)
{
  point_t centr = sh->getFrameRect().pos;
  sh->move(pos);
  double vectorx = scale * centr.x - scale * sh->getFrameRect().pos.x;
  double vectory = scale * centr.y - scale * sh->getFrameRect().pos.y;
  sh->scale(scale);
  sh->move(vectorx, vectory);
}

std::string asafov::getName(std::istream& in)
{
  std::string str = {};
  in >> str;
  if (in.fail() || in.eof())
  {
    str[0] = 0;
  }
  return str;
}

void asafov::scaleShapes(Shape** shapes, unsigned long long count, point_t pos, double scale, std::ostream& out)
{
  out << std::fixed << std::setprecision(1);
  if (count == 0)
  {
    throw std::logic_error("");
  }
  rectangle_t rect = {};
  double area = 0.0;
  for (unsigned long long i = 0; i < count; i++)
  {
    area += shapes[i]->getArea();
  }
  out << std::fixed << std::setprecision(1);
  out << area;
  for (unsigned long long i = 0; i < count; i++)
  {
    rect = shapes[i]->getFrameRect();
    out << ' ' << rect.pos.x - rect.width / 2;
    out << ' ' << rect.pos.y - rect.height / 2;
    out << ' ' << rect.pos.x + rect.width / 2;
    out << ' ' << rect.pos.y + rect.height / 2;
    isotropicScale(shapes[i], pos, scale);
  }
  area = 0;
  for (unsigned long long i = 0; i < count; i++)
  {
    area += shapes[i]->getArea();
  }
  out << '\n';
  out << std::fixed << std::setprecision(1);
  out << area;
  for (unsigned long long i = 0; i < count; i++)
  {
      rect = shapes[i]->getFrameRect();
    out << ' ' << rect.pos.x - rect.width / 2;
    out << ' ' << rect.pos.y - rect.height / 2;
    out << ' ' << rect.pos.x + rect.width / 2;
    out << ' ' << rect.pos.y + rect.height / 2;
  }
  out << '\n';
}

void deleteShapes(Shape** shapes, size_t count)
{
  for (size_t i = 0; i < count; i++)
  {
    delete shapes[i];
  }
  delete[] shapes;
}
