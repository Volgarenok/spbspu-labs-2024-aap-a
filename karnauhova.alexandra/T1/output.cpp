#include "output.hpp"
#include <iostream>
#include <iomanip>
#include "shape.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "polygon.hpp"
void karnauhova::output(std::ostream & out, Shape** shaps, point_t point, double k, double c_shape)
{
  std::cout << "lol";
  size_t m = 0;
  double sum1 = 0, sum2 = 0;
  double out1[10000] = {};
  double out2[10000] = {};
  for (size_t i = 0; i < c_shape; i++)
  {
    sum1 += (*shaps[i]).getArea();
    rectangle_t rec1 = (*shaps[i]).getFrameRect();
    out1[m] = rec1.pos.x - (rec1.width / 2);
    out1[m + 1] = rec1.pos.y - (rec1.height / 2);
    out1[m + 2] = rec1.pos.x + (rec1.width / 2);
    out1[m + 3] = rec1.pos.y + (rec1.height / 2);
    scale_point(*shaps[i], point, k);
    sum2 += (*shaps[i]).getArea();
    rectangle_t rec2 = (*shaps[i]).getFrameRect();
    out2[m] = rec2.pos.x - (rec2.width / 2);
    out2[m + 1] = rec2.pos.y - (rec2.height / 2);
    out2[m + 2] = rec2.pos.x + (rec2.width / 2);
    out2[m + 3] = rec2.pos.y + (rec2.height / 2);
    m += 4;
  }
  out << std::fixed;
  out << std::setprecision(1) << sum1;
  for (size_t i = 0; i < m; i++)
  {
    out << std::setprecision(1) << " " << out1[i];
  }
  out << "\n";
  out << std::setprecision(1) << sum2;
  for (size_t i = 0; i < m; i++)
  {
    out << std::setprecision(1) << " " << out2[i];
  }
  out << "\n";
}

void karnauhova::scale_point(Shape& object, point_t t, double k)
{
  point_t centr_rec1 = object.getFrameRect().pos;
  object.move(t);
  point_t centr_rec2 = object.getFrameRect().pos;
  double x = centr_rec2.x - centr_rec1.x;
  double y = centr_rec2.y - centr_rec1.y;
  object.scale(k);
  object.move(-(x * k), -(y * k));
}
