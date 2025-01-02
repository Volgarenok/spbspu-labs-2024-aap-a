#include "outputFunctions.hpp"
#include <iomanip>
#include "exception"
#include "rectangle.hpp"
#include "circle.hpp"
#include "ring.hpp"
#include "ellipse.hpp"
#include "square.hpp"
#include "triangle.hpp"
#include "complexquad.hpp"

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
  rectangle_t rect = {};
  for (unsigned long long i = 0; i < count; i++)
  {
    rect = shapes[i][0].getFrameRect();
    out << std::setprecision(2) << std::fixed << shapes[i][0].getArea();
    out << std::setprecision(2) << std::fixed << ' ' << rect.pos.x - rect.width / 2;
    out << std::setprecision(2) << std::fixed << ' ' << rect.pos.y - rect.height / 2;
    out << std::setprecision(2) << std::fixed << ' ' << rect.pos.x + rect.width / 2;
    out << std::setprecision(2) << std::fixed << ' ' << rect.pos.y + rect.height / 2 << '\n';
    shapes[i][0].scale(pos, scale);
    rect = shapes[i][0].getFrameRect();
    out << std::setprecision(2) << std::fixed << shapes[i][0].getArea();
    out << std::setprecision(2) << std::fixed << ' ' << rect.pos.x - rect.width / 2;
    out << std::setprecision(2) << std::fixed << ' ' << rect.pos.y - rect.height / 2;
    out << std::setprecision(2) << std::fixed << ' ' << rect.pos.x + rect.width / 2;
    out << std::setprecision(2) << std::fixed << ' ' << rect.pos.y + rect.height / 2 << '\n';
  }
}
