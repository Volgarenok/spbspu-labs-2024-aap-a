#include <iostream>
#include <string>
#include <iomanip>
#include <getString.hpp>
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "square.hpp"
#include "complexquad.hpp"
#include "shape_transformations.hpp"

int main()
{
  abramov::Shape *shapes[10000] = {};
  abramov::rectangle_t rects[10000] = {};
  size_t i = 0;
  double k = 0;
  double x = 0;
  double y = 0;
  bool wrong_figure = false;
  try
  {
    while (std::cin)
    {
      std::string s1;
      std::cin >> s1;
      double x1 = 0;
      double x2 = 0;
      double y1 = 0;
      double y2 = 0;
      if (s1 == "RECTANGLE")
      {
        std::cin >> x1 >> y1 >> x2 >> y2;
        abramov::point_t p1;
        p1.x = x1;
        p1.y = y1;
        abramov::point_t p2;
        p2.x = x2;
        p2.y = y2;
        try
        {
          shapes[i++] = new abramov::Rectangle(p1, p2);
        }
        catch (const std::logic_error &e)
        {
          wrong_figure = true;
        }
      }
      if (s1 == "SQUARE")
      {
        double len = 0;
        std::cin >> x1 >> y1 >> len;
        if (len <= 0)
        {
          wrong_figure = true;
        }
        else
        {
          abramov::point_t p;
          p.x = x1;
          p.y = y1;
          shapes[i++] = new abramov::Square(p, len);
        }
      }
      if (s1 == "COMPLEXQUAD")
      {
        double x3 = 0;
        double y3 = 0;
        double x4 = 0;
        double y4 = 0;
        std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        abramov::point_t p1;
        abramov::point_t p2;
        abramov::point_t p3;
        abramov::point_t p4;
        p1.x = x1;
        p1.y = y1;
        p2.x = x2;
        p2.y = y2;
        p3.x = x3;
        p3.y = y3;
        p4.x = x4;
        p4.y = y4;
        shapes[i++] = new abramov::ComplexQuad(p1, p2, p3, p4);
      }
      if (s1 == "SCALE")
      {
        std::cin >> x >> y >> k;
        if (k <= 0)
        {
          std::cerr << "Wrong scale command\n";
          return 1;
        }
      }
    }
  }
  catch (const std::bad_alloc &e)
  {
    std::cerr << "Memory fail\n";
    return 2;
  }
  if (k <= 0)
  {
    std::cerr << "There is no scale command\n";
    return 1;
  }
  double s = 0;
  std::cout << std::fixed << std::setprecision(1);
  for (size_t j = 0; j < i; ++j)
  {
    s += shapes[j]->getArea();
    rects[j] = shapes[j]->getFrameRect();
  }
  std::cout << s << " ";
  abramov::point_t p;
  p.x = x;
  p.y = y;
  for (size_t j = 0; j < i; ++j)
  {
    abramov::printFrameRectCoords(rects[j]);
    abramov::scaleFigure(shapes[j], p, k);
  }
  std::cout << "\n";
  s = 0;
  for (size_t j = 0; j < i; ++j)
  {
    s += shapes[j]->getArea();
    rects[j] = shapes[j]->getFrameRect();
  }
  std::cout << s << " ";
  for (size_t j = 0; j < i; ++j)
  {
    abramov::printFrameRectCoords(rects[j]);
  }
  std::cout << "\n";
  if (wrong_figure == true)
  {
    std::cerr << "There was bad figure\n";
  }
  for (size_t j = 0; j < i; ++j)
  {
    delete shapes[j];
  }
}
