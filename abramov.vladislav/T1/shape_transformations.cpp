#include "shape_transformations.hpp"
#include <iostream>

namespace abramov
{
  void getShapes(std::istream &in, Shape **shapes, size_t &i, double &x, double &y, double &k, bool &flag)
  {
    try
    {
      while (in)
      {
        std::string s1;
        in >> s1;
        double x1 = 0;
        double x2 = 0;
        double y1 = 0;
        double y2 = 0;
        if (s1 == "RECTANGLE")
        {
          in >> x1 >> y1 >> x2 >> y2;
          try
          {
            shapes[i] = new Rectangle({x1, y1}, {x2, y2});
            ++i;
          }
          catch (const std::logic_error &e)
          {
            flag = true;
          }
        }
        if (s1 == "SQUARE")
        {
          double len = 0;
          in >> x1 >> y1 >> len;
          try
          {
            shapes[i] = new Square({x1, y1}, len);
            ++i;
          }
          catch (const std::logic_error &e)
          {
            flag = true;
          }
        }
        if (s1 == "COMPLEXQUAD")
        {
          double x3 = 0;
          double y3 = 0;
          double x4 = 0;
          double y4 = 0;
          in >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
          try
          {
            shapes[i] = new ComplexQuad({x1, y1}, {x2, y2}, {x3, y3}, {x4, y4});
            ++i;
          }
          catch (const std::logic_error &e)
          {
            flag = true;
          }
        }
        if (s1 == "SCALE")
        {
          in >> x >> y >> k;
        }
      }
    }
    catch (const std::bad_alloc &e)
    {
      deleteShapes(shapes, i);
      std::cerr << "Memory fail\n";
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

  void scaleFigure(Shape *r, point_t p, double k)
  {
    const point_t pos1 = r->getFrameRect().pos;
    r->move(p);
    const point_t pos2 = r->getFrameRect().pos;
    double dx = pos2.x - pos1.x;
    double dy = pos2.y - pos1.y;
    r->scale(k);
    dx *= -1 * k;
    dy *= -1 * k;
    r->move(dx, dy);
  }

  void deleteShapes(Shape **x, size_t i)
  {
    for (size_t j = 0; j < i; ++j)
    {
      delete x[j];
    }
  }

  void printShapes(std::ostream &out, Shape **shapes, rectangle_t *rects, size_t i, double &x, double &y, double k)
  {
    out << std::fixed << std::setprecision(1);
    double s = 0;
    for (size_t j = 0; j < i; ++j)
    {
      s += shapes[j]->getArea();
      rects[j] = shapes[j]->getFrameRect();
    }
    out << s << " ";
    point_t p;
    p.x = x;
    p.y = y;
    for (size_t j = 0; j < i - 1; ++j)
    {
      printFrameRectCoords(rects[j]);
      out << " ";
      scaleFigure(shapes[j], p, k);
    }
    printFrameRectCoords(rects[i - 1]);
    scaleFigure(shapes[i - 1], p, k);
    out << "\n";
    s = 0;
    for (size_t j = 0; j < i; ++j)
    {
      s += shapes[j]->getArea();
      rects[j] = shapes[j]->getFrameRect();
    }
    std::cout << s << " ";
    for (size_t j = 0; j < i - 1; ++j)
    {
      printFrameRectCoords(rects[j]);
      out << " ";
    }
    printFrameRectCoords(rects[i - 1]);
    out << "\n";
  }
}
