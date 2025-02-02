#include "shape_transformations.hpp"
#include <limits>

namespace
{
  void getArray(std::istream &in, double *x, size_t k)
  {
    for (size_t i = 0; i < k; ++i)
    {
      in >> x[i];
    }
  }

  void printFrameRectCoords(const abramov::rectangle_t &r)
  {
    const double x1 = r.pos.x - r.width / 2;
    const double y1 = r.pos.y - r.height / 2;
    const double x2 = r.pos.x + r.width / 2;
    const double y2 = r.pos.y + r.height / 2;
    std::cout << x1 << " " << y1 << " ";
    std::cout << x2 << " " << y2;
  }

  void printShapes(std::ostream &out, const abramov::Composite &shapes, abramov::point_t p, double k, size_t i)
  {
    out << std::fixed << std::setprecision(1);
    double s = shapes.getArea();
    out << s << " ";
    for (size_t j = 0; j < i - 1; ++j)
    {
      printFrameRectCoords(shapes[j]->getFrameRect());
      out << " ";
    }
    printFrameRectCoords(shapes[i - 1]->getFrameRect());
    out << "\n";
    out.copyfmt(std::ios(NULL));
  }

  void scaleFigures(abramov::Composite &shapes, abramov::point_t p, double k, size_t i)
  {
    for (size_t j = 0; j < i; ++j)
    {
      scaleFigure(shapes[j], p, k);
    }
  }

  void printScaledShapes(std::ostream &out, const abramov::Composite &shapes, abramov::point_t p, double k, size_t i)
  {
    out << std::fixed << std::setprecision(1);
    s = shapes.getArea();
    std::cout << s << " ";
    for (size_t j = 0; j < i - 1; ++j)
    {
      printFrameRectCoords(shapes[j]->getFrameRect());
      out << " ";
    }
    printFrameRectCoords(shapes[i - 1]->getFrameRect());
    out << "\n";
    out.copyfmt(std::ios(NULL));
  }
}

void abramov::getShapes(std::istream &in, Composite &shapes, point_t &p, double &k, bool &flag)
{
  while (in)
  {
    std::string s1;
    in >> s1;
    Shape *figure = nullptr;
    try
    {
      if (s1 == "RECTANGLE")
      {
        figure = makeRectangle(in);
        shapes.push_back(figure);
      }
      else if (s1 == "SQUARE")
      {
        figure = makeSquare(in);
        shapes.push_back(figure);
      }
      else if (s1 == "COMPLEXQUAD")
      {
        figure = makeComplexQuad(in);
        shapes.push_back(figure);
      }
    }
    catch (const std::logic_error &)
    {
      flag = true;
    }
    catch (const std::bad_alloc &)
    {
      delete figure;
    }
    if (s1 == "SCALE")
    {
      in >> p.x >> p.y >> k;
    }
    else
    {
      in.ignore(std::numeric_limits< std::streamsize >::max(), '\n');
    }
  }
}

abramov::Rectangle *abramov::makeRectangle(std::istream &in)
{
  constexpr size_t k = 4;
  double arr[k] = {};
  getArray(in, arr, k);
  return new Rectangle({arr[0], arr[1]}, {arr[2], arr[3]});
}

abramov::Square *abramov::makeSquare(std::istream &in)
{
  constexpr size_t k = 3;
  double arr[k] = {};
  getArray(in, arr, k);
  return new Square({arr[0], arr[1]}, arr[2]);
}

abramov::ComplexQuad *abramov::makeComplexQuad(std::istream &in)
{
  constexpr size_t k = 8;
  double x[k] = {};
  getArray(in, x, k);
  return new ComplexQuad({x[0], x[1]}, {x[2], x[3]}, {x[4], x[5]}, {x[6], x[7]});
}

void abramov::scaleFigure(Shape *s, point_t p, double k)
{
  const point_t pos1 = s->getFrameRect().pos;
  s->move(p);
  const point_t pos2 = s->getFrameRect().pos;
  double dx = pos2.x - pos1.x;
  double dy = pos2.y - pos1.y;
  s->doScale(k);
  dx *= -1 * k;
  dy *= -1 * k;
  s->move(dx, dy);
}

void abramov::unsafeScaleFigure(Shape *s, point_t p, double k)
{
  const point_t pos1 = s->getFrameRect().pos;
  s->move(p);
  const point_t pos2 = s->getFrameRect().pos;
  double dx = pos2.x - pos1.x;
  double dy = pos2.y - pos1.y;
  s->scale(k);
  dx *= -1 * k;
  dy *= -1 * k;
  s->move(dx, dy);
}

void abramov::printAllShapes(std::ostream &out, abramov::Composite &shapes, abramov::point_t p, double k, size_t i)
{
  printShapes(out, shapes, p, k, i);
  scaleFigures(shapes, p, k, i);
  printScaledShapes(out, shapes, p, k, i);
}
