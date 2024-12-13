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
          point_t p1;
          p1.x = x1;
          p1.y = y1;
          point_t p2;
          p2.x = x2;
          p2.y = y2;
          try
          {
            shapes[i] = new Rectangle(p1, p2);
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
          point_t p;
          p.x = x1;
          p.y = y1;
          try
          {
            shapes[i] = new Square(p, len);
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
          point_t p1;
          point_t p2;
          point_t p3;
          point_t p4;
          p1.x = x1;
          p1.y = y1;
          p2.x = x2;
          p2.y = y2;
          p3.x = x3;
          p3.y = y3;
          p4.x = x4;
          p4.y = y4;
          try
          {
            shapes[i] = new ComplexQuad(p1, p2, p3, p4);
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
          if (k <= 0)
          {
            deleteShapes(shapes, i);
            std::cerr << "Wrong scale command\n";
          }
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
    double x1 = r.pos.x - r.width / 2;
    double y1 = r.pos.y - r.height / 2;
    double x2 = r.pos.x + r.width / 2;
    double y2 = r.pos.y + r.height / 2;
    std::cout << x1 << " " << y1 << " ";
    std::cout << x2 << " " << y2;
  }

  void scaleFigure(Shape *r, point_t p, double k)
  {
    point_t pos1 = r->getFrameRect().pos;
    r->move(p);
    point_t pos2 = r->getFrameRect().pos;
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
}
