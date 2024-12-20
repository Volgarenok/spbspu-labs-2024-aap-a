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

int main()
{
  evstyunichev::Shape *shapes[10000]{};
  std::string s;
  size_t done = 0, non_empty = 0;
  double totalSquare = 0;
  std::cout.precision(1);
  std::cout << std::fixed;
  while (std::cin >> s)
  {
    non_empty++;
    if (s == "RECTANGLE")
    {
      shapes[done] = evstyunichev::make_rectangle(std::cin);
      if (shapes[done])
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
        std::cerr << "negative k!";
        return 1;
      }
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
  for (size_t i = 0; i < done; i++)
  {
    delete shapes[i];
  }
  if (!non_empty)
  {
    std::cout << "no input\n";
    return 1;
  }
  return 0;
}
