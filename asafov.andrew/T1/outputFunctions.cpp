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
#include "supportFunctions.hpp"

asafov::Shape* asafov::ShapeFactory(std::string shapename, std::istream& in)
{
  if (shapename == "RECTANGLE")
  {
    point_t lb = getPoint(in);
    point_t rt = getPoint(in);
    Rectangle* rectangle = new Rectangle(lb, rt);
    return rectangle;
  }
  else if (shapename == "CIRCLE")
  {
    point_t a = getPoint(in);
    double r1 = 0;
    in >> r1;
    Circle* circ = new Circle(a, r1);
    return circ;
  }
  else if (shapename == "RING")
  {
    point_t a = getPoint(in);
    double r1 = 0;
    in >> r1;
    double r2 = 0;
    in >> r2;
    Ring* ring = new Ring(a, r1, r2);
    return ring;
  }
  else if (shapename == "ELLIPSE")
  {
    point_t a = getPoint(in);
    double r1 = 0;
    in >> r1;
    double r2 = 0;
    in >> r2;
    Ellipse* ellipse = new Ellipse(a, r1, r2);
    return ellipse;
  }
  else if (shapename == "SQUARE")
  {
    point_t lb = getPoint(in);
    double side = 0;
    in >> side;
    Square* square = new Square(lb, side);
    return square;
  }
  else if (shapename == "TRIANGLE")
  {
    point_t points[3];
    getPoints(points, 3, in);
    Triangle* triangle = new Triangle(points[0], points[1], points[2]);
    return triangle;
  }
  else if (shapename == "COMPLEXQUAD")
  {
    point_t points[4];
    getPoints(points, 4, in);
    Complexquad* complexquad = new Complexquad(points[0], points[1], points[2], points[3]); 
    return complexquad;
  }
  else
  {
    throw std::logic_error("incorrect name");
  }
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

void asafov::scaleShapes(Shape** shapes, size_t count, point_t pos, double scale, std::ostream& out)
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
    out << ' ';
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
    out << ' ';
    outputFrameRect(shapes[i], out);
  }
  std::cout << 123;
  std::ios::Init();
  std::cout << 123;

}

void asafov::deleteShapes(Shape** shapes, size_t count)
{
  for (size_t i = 0; i < count; i++)
  {
    delete shapes[i];
  }
  delete[] shapes;
}
