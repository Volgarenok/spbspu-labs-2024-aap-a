#include "shape_actions.hpp"
#include <iomanip>
#include <iostream>
#include "base-types.hpp"
#include "specific_output.hpp"

void evstyunichev::makeScale(Shape **shapes, std::istream &in, size_t done, double &totalSquare)
{
  double x = 0, y = 0, k = 0;
  in >> x >> y >> k;
  if (k < 0)
  {
    throw std::logic_error("negative k!");
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
    shapes[i]->move(-k * (cur.x - old.x), -k * (cur.y - old.y));
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
