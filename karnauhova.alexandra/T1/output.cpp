#include "output.hpp"
#include <iostream>
#include <iomanip>
#include "shape.hpp"
void karnauhova::output(std::ostream& out, CompositeShape& shaps, const point_t& point, double k)
{
  output_sum(out, shaps);
  output_points(out, shaps);
  out << "\n";
  scale_shapes_without_check(shaps, point, k);
  output_sum(out, shaps);
  output_points(out, shaps);
  out << "\n";
}

void karnauhova::output_sum(std::ostream& out, const CompositeShape& shaps)
{
  double sum = 0;
  for (size_t i = 0; i < shaps.size(); i++)
  {
    sum += shaps[i]->getArea();
  }
  out << std::fixed;
  out << std::setprecision(1) << sum;
}

void karnauhova::output_points(std::ostream& out, const CompositeShape& shaps)
{
  for (size_t i = 0; i < shaps.size(); i++)
  {
    rectangle_t rec = shaps[i]->getFrameRect();
    double x1 = rec.pos.x - (rec.width / 2);
    double y1 = rec.pos.y - (rec.height / 2);
    double x2 = rec.pos.x + (rec.width / 2);
    double y2 = rec.pos.y + (rec.height / 2);
    out << std::fixed;
    out << std::setprecision(1) << " " << x1 << " " << y1 << " " << x2 << " " << y2;
  }
}

void karnauhova::scale_shapes_without_check(CompositeShape& shaps, const point_t& point, double k)
{
  for (size_t i = 0; i < shaps.size(); i++)
  {
    scale_point(shaps[i], point, k);
  }
}

void karnauhova::scale_shapes_with_check(CompositeShape& shaps, const point_t& point, double k)
{
  if (k <= 0)
  {
    throw std::logic_error("Incorrect scale");
  }
  scale_shapes_without_check(shaps, point, k);
}




void karnauhova::scale_point(Shape* object, const point_t& t, double k)
{
  point_t centr_rec1 = object->getFrameRect().pos;
  object->move(t);
  point_t centr_rec2 = object->getFrameRect().pos;
  double x = centr_rec2.x - centr_rec1.x;
  double y = centr_rec2.y - centr_rec1.y;
  object->scale(k);
  object->move(-(x * k), -(y * k));
}
