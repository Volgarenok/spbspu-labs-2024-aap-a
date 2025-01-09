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

Shape* asafov::ShapeFactory(unsigned long long hash, std::istream& in)
{
  if (hash == 'R' * 'E' * 'C' * 'T')
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
      throw std::logic_error("");
    }
    Rectangle* rect = new Rectangle(a, b);
    return rect;
  }
  else if (hash == 'C' * 'I' * 'R' * 'C')
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
        throw std::logic_error("");
    }
    Circle* circ = new Circle(a, temp);
    return circ;
  }
  else if (hash == 'R' * 'I' * 'N' * 'G') {
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
  else if (hash == 'E' * 'L' * 'L' * 'I')
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
        throw std::logic_error("");
    }
    Ellipse* elli = new Ellipse(a, temp, temp2);
    return elli;
  }
  else if (hash == 'S' * 'Q' * 'U' * 'A')
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
          throw std::logic_error("");
      }
      Square* squa = new Square(lb, temp);
      return squa;

  }
  else if (hash == 'T' * 'R' * 'I' * 'A')
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
    double sidea = pow(pow((a.x - b.x), 2.0) + pow((a.y - b.y), 2.0), 0.5);
    double sideb = pow(pow((b.x - c.x), 2.0) + pow((b.y - c.y), 2.0), 0.5);
    double sidec = pow(pow((a.x - c.x), 2.0) + pow((a.y - c.y), 2.0), 0.5);
    if ((a.x - b.x + a.y - b.y) * (a.x - c.x + a.y - c.y) *
    (b.x - c.x + b.y - c.y) == 0 || sidea + sideb == sidec || sidea +
    sidec == sideb || sideb + sidec == sidea)
    {
        throw std::logic_error("");
    }
    Triangle* tria = new Triangle(a, b, c);
    return tria;
  }
  else if (hash == 'P' * 'A' * 'R' * 'A')
  {

  }
  else if (hash == 'D' * 'I' * 'A' * 'M')
  {

  }
  else if (hash == 'R' * 'E' * 'G' * 'U')
  {

  }
  else if (hash == 'P' * 'O' * 'L' * 'Y')
  {

  }
  else if (hash == 'C' * 'O' * 'N' * 'C')
  {

  }
  else if (hash == 'C' * 'O' * 'M' * 'P')
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
        throw std::logic_error("");
    }
    Complexquad* comp = new Complexquad(a, b, c, d);
    return comp;
  }
  double temp = 0;
  point_t a = {};
  Circle* circ = new Circle(a, temp);
  return circ;
}

unsigned long asafov::getHash(std::istream& in)
{
  std::string str = {};
  in >> str;
  if (str[0] == '\0' || in.fail() || in.eof())
  {
    throw std::logic_error("");
  }
  unsigned long hash = 1;
  for (unsigned long long i = 0; i < 4; i++)
  {
    hash = hash * str[i];
  }
  return hash;
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
    area += shapes[i][0].getArea();
  }
  out << std::fixed << std::setprecision(1);
  out << area;
  for (unsigned long long i = 0; i < count; i++)
  {
    rect = shapes[i][0].getFrameRect();
    out << ' ' << rect.pos.x - rect.width / 2;
    out << ' ' << rect.pos.y - rect.height / 2;
    out << ' ' << rect.pos.x + rect.width / 2;
    out << ' ' << rect.pos.y + rect.height / 2;
    isotropicScale(shapes[i], pos, scale);
  }
  area = 0;
  for (unsigned long long i = 0; i < count; i++)
  {
    area += shapes[i][0].getArea();
  }
  out << '\n';
  out << std::fixed << std::setprecision(1);
  out << area;
  for (unsigned long long i = 0; i < count; i++)
  {
      rect = shapes[i][0].getFrameRect();
    out << ' ' << rect.pos.x - rect.width / 2;
    out << ' ' << rect.pos.y - rect.height / 2;
    out << ' ' << rect.pos.x + rect.width / 2;
    out << ' ' << rect.pos.y + rect.height / 2;
  }
  out << '\n';
}

void asafov::isotropicScale(Shape* sh, point_t pos, double scale)
{
  point_t centr = sh[0].getFrameRect().pos;
  sh[0].move(pos);
  sh[0].scale(scale);
  sh[0].move((double)(scale * centr.x - scale * sh[0].getFrameRect().pos.x),
    (double)(scale * centr.y - scale * sh[0].getFrameRect().pos.y));
}
