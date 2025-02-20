#include <iomanip>
#include <iostream>
#include <string>
#include "../common/input_string.hpp"
#include "base-types.hpp"
#include "circle.hpp"
#include "make_shape.hpp"
#include "rectangle.hpp"
#include "regular.hpp"
#include "ring.hpp"
#include "shape.hpp"
#include "specific_output.hpp"

namespace evstyunichev
{
  void destroy_shapes(Shape **, size_t);
  void makeScale(Shape **shapes, std::istream &in, size_t done, double &totalSquare);
}

void evstyunichev::makeScale(Shape **shapes, std::istream &in, size_t done, double &totalSquare)
{
  double x = 0, y = 0, k = 0;
  in >> x >> y >> k;
  if (k < 0)
  {
    destroy_shapes(shapes, done);
    throw std::invalid_argument("negative k!");
  }
  if (!done)
  {
    throw std::logic_error("Nothing to scale!\n");
  }
  point_t O{x, y};
  std::cout << std::fixed << std::setprecision(1) << totalSquare << ' ';
  framesOut(shapes, done) << '\n' << totalSquare * k * k << ' ';
  for (size_t i = 0; i < done; i++)
  {
    point_t old = shapes[i]->getFrameRect().pos;
    shapes[i]->move(O);
    point_t cur = shapes[i]->getFrameRect().pos;
    shapes[i]->scale(k);
    shapes[i]->move(-(cur.x - old.x) * k, -(cur.y - old.y) * k);
  }
  framesOut(shapes, done) << '\n';
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
  using namespace evstyunichev;
  Shape *shapes[10000]{};
  std::string s;
  double totalSquare = 0;
  bool scaleFlag = 0, errorFlag = 0;
  size_t done = 0;
  while (std::cin >> s)
  {
    Shape *cur = nullptr;
    try
    {
      cur = make_shape(std::cin, s);
    }
    catch(const std::invalid_argument& e)
    {
      errorFlag = 1;
    }
    if (cur)
    {
      shapes[done] = cur;
      totalSquare += shapes[done]->getArea();
      done++;
    }
    else if (s == "SCALE")
    {
      scaleFlag = 1;
      makeScale(shapes, std::cin, done, totalSquare);
      if (errorFlag)
      {
        std::cout << "input errors!\n";
      }
    }
    else
    {
      skip_to_sign(std::cin, '\n');
    }
  }
  evstyunichev::destroy_shapes(shapes, done);
  if (!(done && scaleFlag))
  {
    std::cout << "((\n";
    return 1;
  }
  return 0;
}
