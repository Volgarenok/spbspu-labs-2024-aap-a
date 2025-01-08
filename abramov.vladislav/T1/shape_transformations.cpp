#include "shape_transformations.hpp"
#include <iostream>
#include <limits>

namespace abramov
{
  using CS = CompositeShape;

  void getShapes(std::istream &in, CS &shapes, point_t &p, double &k, bool &flag)
  {
    while (in)
    {
      std::string s1;
      in >> s1;
      try
      {
        if (s1 == "RECTANGLE")
        {
          Rectangle *rect = makeRectangle(in);
          shapes.push_back(rect);
        }
        else if (s1 == "SQUARE")
        {
          Square *square = makeSquare(in);
          shapes.push_back(square);
        }
        else if (s1 == "COMPLEXQUAD")
        {
          ComplexQuad *cq = makeComplexQuad(in);
          shapes.push_back(cq);
        }
      }
      catch (const std::logic_error &e)
      {
        flag = true;
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

  void getArray(std::istream &in, double *x, size_t k)
  {
    for (size_t i = 0; i < k; ++i)
    {
      in >> x[i];
    }
  }

  Rectangle *makeRectangle(std::istream &in)
  {
    constexpr size_t k = 4;
    double arr[k] = {};
    getArray(in, arr, k);
    return new Rectangle({arr[0], arr[1]}, {arr[2], arr[3]});
  }

  Square *makeSquare(std::istream &in)
  {
    constexpr size_t k = 3;
    double arr[k] = {};
    getArray(in, arr, k);
    return new Square({arr[0], arr[1]}, arr[2]);
  }

  ComplexQuad *makeComplexQuad(std::istream &in)
  {
    constexpr size_t k = 8;
    double x[k] = {};
    getArray(in, x, k);
    return new ComplexQuad({x[0], x[1]}, {x[2], x[3]}, {x[4], x[5]}, {x[6], x[7]});
  }

  void printFrameRectCoords(const rectangle_t &r)
  {
    const double x1 = r.pos.x - r.width / 2;
    const double y1 = r.pos.y - r.height / 2;
    const double x2 = r.pos.x + r.width / 2;
    const double y2 = r.pos.y + r.height / 2;
    std::cout << x1 << " " << y1 << " ";
    std::cout << x2 << " " << y2;
  }

  void scaleFigure(Shape *s, point_t p, double k)
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

  void deleteShapes(Shape **x, size_t i)
  {
    for (size_t j = 0; j < i; ++j)
    {
      delete x[j];
    }
  }

  void printShapes(std::ostream &out, CS &shapes, point_t p, double k, size_t i)
  {
    out << std::fixed << std::setprecision(1);
    double s = shapes.getArea();
    out << s << " ";
    for (size_t j = 0; j < i - 1; ++j)
    {
      printFrameRectCoords(shapes.getFrameRect(j));
      out << " ";
      scaleFigure(shapes[j], p, k);
    }
    printFrameRectCoords(shapes.getFrameRect(i - 1));
    scaleFigure(shapes[i - 1], p, k);
    out << "\n";
    s = shapes.getArea();
    std::cout << s << " ";
    for (size_t j = 0; j < i - 1; ++j)
    {
      printFrameRectCoords(shapes.getFrameRect(j));
      out << " ";
    }
    printFrameRectCoords(shapes.getFrameRect(i - 1));
    out << "\n";
  }
}
