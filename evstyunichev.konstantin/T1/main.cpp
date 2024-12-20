#include <iostream>
#include <string>
#include "base-types.hpp"
#include "make_shape.hpp"
#include "rectangle.hpp"
#include "shape.hpp"
#include "specific_output.hpp"

namespace evstyunichev
{
  void skip_to_sign(std::istream &, char end = '\n');
  void destroy_shapes(Shape **, size_t);
}

void evstyunichev::skip_to_sign(std::istream &in, char end)
{
  std::noskipws(in);
  unsigned char c = (end + 1) % 256;
  while (c != end)
  {
    in >> c;
  }
  return;
}

void evstyunichev::destroy_shapes(Shape **shapes, size_t n)
{
  for (size_t i = 0; i < n; i++)
  {
    delete shapes[i];
  }
  return;
}

int main()
{
  evstyunichev::Shape *shapes[10000]{};
  std::string s;
  size_t done = 0, non_empty = 0;
  double totalSquare = 0;
  std::cout.precision(1);
  std::cout << std::fixed;
  bool noInputErrors = 1, scaleFlag = 0;
  while (std::cin >> s)
  {
    non_empty++;
    if (s == "RECTANGLE")
    {
      shapes[done] = evstyunichev::make_rectangle(std::cin);
      if (!shapes[done])
      {
        noInputErrors = 0;
      }
      else
      {
        totalSquare += shapes[done]->getArea();
        done++;
      }
    }
    else if (s == "SCALE")
    {
      evstyunichev::point_t mid{};
      double k{};
      std::cin >> mid.x >> mid.y >> k;
      if (k < 0)
      {
        evstyunichev::destroy_shapes(shapes, done);
        std::cerr << "negative k!\n";
        return 1;
      }
      if (!done)
      {
        std::cerr << "Nothing to scale!\n";
        return 1;
      }
      scaleFlag = 1;
      std::cout << evstyunichev::roundToOneSign(totalSquare) << ' ';
      evstyunichev::frameOutput(shapes[0]->getFrameRect());
      for (size_t i = 1; i < done; i++)
      {
        std::cout << ' ';
        evstyunichev::frameOutput(shapes[i]->getFrameRect());
      }
      std::cout << '\n' << evstyunichev::roundToOneSign(totalSquare) * k * k << ' ';
      for (size_t i = 0; i < done; i++)
      {
        evstyunichev::point_t old = shapes[i]->getFrameRect().pos;
        shapes[i]->move(mid);
        evstyunichev::point_t cur = shapes[i]->getFrameRect().pos;
        shapes[i]->scale(k);
        evstyunichev::point_t v{};
        v.x = (cur.x - old.x) * k;
        v.y = (cur.y - old.y) * k;
        shapes[i]->move(-v.x, -v.y);
      }
      evstyunichev::frameOutput(shapes[0]->getFrameRect());
      for (size_t i = 1; i < done; i++)
      {
        std::cout << ' ';
        evstyunichev::frameOutput(shapes[i]->getFrameRect());
      }
      std::cout << '\n';
    }
    else
    {
      evstyunichev::skip_to_sign(std::cin, '\n');
    }
  }
  evstyunichev::destroy_shapes(shapes, done);
  if (!(non_empty * scaleFlag))
  {
    std::cout << "((\n";
    return 1;
  }
  if (!noInputErrors)
  {
    std::cerr << "something went wrong\n";
  }
  return 0;
}
