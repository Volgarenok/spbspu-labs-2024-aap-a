#include "output.hpp"
#include <iostream>
#include <iomanip>
#include "shape.hpp"
void karnauhova::output(std::ostream & out, CompositeShape& shaps, point_t point, double k)
{
  output_sum(out, shaps);
  output_points(out, shaps);
  for (size_t i = 0; i < shaps.size(); i++)
  {
    scale_point(shaps[i], point, k);
  }
  output_sum(out, shaps);
  output_points(out, shaps);
}

void karnauhova::output_sum(std::ostream & out, CompositeShape& shaps)
{
  double sum = 0;
  for (size_t i = 0; i < shaps.size(); i++)
  {
    sum += shaps[i]->getArea();
  }
  out << sum << " ";
}

void karnauhova::output_points(std::ostream & out, CompositeShape& shaps)
{
  for (size_t i = 0; i < shaps.size(); i++)
  {
    rectangle_t rec = shaps[i]->getFrameRect();
    out << std::fixed;
    out << std::setprecision(1) << rec.pos.x - (rec.width / 2) << " " << rec.pos.y - (rec.height / 2) << " ";
    out << std::setprecision(1) << rec.pos.x + (rec.width / 2) << " " << rec.pos.y + (rec.height / 2) << "\n";
  }
}

void karnauhova::scale_point(Shape* object, point_t t, double k)
{
  point_t centr_rec1 = object->getFrameRect().pos;
  object->move(t);
  point_t centr_rec2 = object->getFrameRect().pos;
  double x = centr_rec2.x - centr_rec1.x;
  double y = centr_rec2.y - centr_rec1.y;
  object->scale(k);
  object->move(-(x * k), -(y * k));
}
