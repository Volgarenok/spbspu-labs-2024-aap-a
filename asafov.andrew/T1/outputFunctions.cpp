#include "outputFunctions.hpp"
#include <iomanip>
#include <cmath>
#include <exception>
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
    point_t lb;
    point_t rt;
    in >> lb.x;
    in >> lb.y;
    in >> rt.x;
    in >> rt.y;
    if (lb.x > rt.x || lb.y > rt.y)
    {
      throw std::logic_error("incorrect figure");
    }
    Rectangle* rectangle = new Rectangle(lb, rt);
    return rectangle;
  }
  else if (shapename == "CIRCLE")
  {
    point_t a;
    in >> a.x;
    in >> a.y;
    double r1 = 0;
    in >> r1;
    if (r1 <= 0.0)
    {
        throw std::logic_error("incorrect figure");
    }
    Circle* circ = new Circle(a, r1);
    return circ;
  }
  else if (shapename == "RING") {
    point_t a;
    in >> a.x;
    in >> a.y;
    double r1 = 0;
    in >> r1;
    double r2 = 0;
    in >> r2;
    Ring* ring = new Ring(a, r1, r2);
    return ring;
  }
  else if (shapename == "ELLIPSE")
  {
    point_t a;
    in >> a.x;
    in >> a.y;
    double r1 = 0;
    in >> r1;
    double r2 = 0;
    in >> r2;
    if (r1 <= 0.0 || r2 <= 0.0)
    {
        throw std::logic_error("incorrect figure");
    }
    Ellipse* ellipse = new Ellipse(a, r1, r2);
    return ellipse;
  }
  else if (shapename == "SQUARE")
  {
      point_t lb;
      in >> lb.x;
      in >> lb.y;
      double side = 0;
      in >> side;
      if (side <= 0.0)
      {
          throw std::logic_error("incorrect figure");
      }
      Square* square = new Square(lb, side);
      return square;
  }
  else if (shapename == "TRIANGLE")
  {
    point_t a;
    point_t b;
    point_t c;
    in >> a.x;
    in >> a.y;
    in >> b.x;
    in >> b.y;
    in >> c.x;
    in >> c.y;
    double sidea = std::pow(std::pow((a.x - b.x), 2.0) + std::pow((a.y - b.y), 2.0), 0.5);
    double sideb = std::pow(std::pow((b.x - c.x), 2.0) + std::pow((b.y - c.y), 2.0), 0.5);
    double sidec = std::pow(std::pow((a.x - c.x), 2.0) + std::pow((a.y - c.y), 2.0), 0.5);
    double temp = (a.x - b.x + a.y - b.y) * (a.x - c.x + a.y - c.y) * (b.x - c.x + b.y - c.y);
    if (temp == 0 || sidea + sideb == sidec || sidea + sidec == sideb || sideb + sidec == sidea)
    {
        throw std::logic_error("incorrect figure");
    }
    Triangle* triangle = new Triangle(a, b, c);
    return triangle;
  }
  else if (shapename == "COMPLEXQUAD")
  {
    point_t a;
    point_t b;
    point_t c;
    point_t d;
    in >> a.x;
    in >> a.y;
    in >> b.x;
    in >> b.y;
    in >> c.x;
    in >> c.y;
    in >> d.x;
    in >> d.y;
    if ((a.x - b.x + a.y - b.y) * (a.x - c.x + a.y - c.y) * (a.x - d.x + a.y - d.y) *
      (b.x - c.x + b.y - c.y) * (b.x - d.x + b.y - d.y) * (c.x - d.x + c.y - d.y) == 0)
    {
        throw std::logic_error("incorrect figure");
    }
    Complexquad* complexquad = new Complexquad(a, b, c, d);
    return complexquad;
  }
  else
  {
    throw std::logic_error("incorrect name");
  }
}

static void isotropicScale(Shape* sh, point_t pos, double scale)
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

static void outputFrameRect(Shape* shape, std::ostream& out)
{
  rectangle_t rect = shape->getFrameRect();
  out << ' ' << rect.pos.x - rect.width / 2;
  out << ' ' << rect.pos.y - rect.height / 2;
  out << ' ' << rect.pos.x + rect.width / 2;
  out << ' ' << rect.pos.y + rect.height / 2;
}

void asafov::scaleShapes(Shape** shapes, unsigned long long count, point_t pos, double scale, std::ostream& out)
{
  out << std::fixed << std::setprecision(1);
  if (count == 0)
  {
    throw std::logic_error("nothing to scale");
  }
  double area = 0.0;
  for (size_t i = 0; i < count; i++)
  {
    area += shapes[i]->getArea();
  }
  out << area;
  for (size_t i = 0; i < count; i++)
  {
    outputFrameRect(shapes[i], out);
    isotropicScale(shapes[i], pos, scale);
  }
  area = 0.0;
  for (size_t i = 0; i < count; i++)
  {
    area += shapes[i]->getArea();
  }
  out << '\n' << area;
  for (size_t i = 0; i < count; i++)
  {
    outputFrameRect(shapes[i], out);
  }
  out << '\n';
}

void asafov::deleteShapes(Shape** shapes, size_t count)
{
  for (size_t i = 0; i < count; i++)
  {
    delete shapes[i];
  }
  delete[] shapes;
}
