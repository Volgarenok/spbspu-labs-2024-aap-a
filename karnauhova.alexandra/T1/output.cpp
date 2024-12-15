#include "output.hpp"
#include "shape.hpp"
#include <iostream>
#include "rectangle.hpp"
#include "triangle.hpp"

void karnauhova::output_all_shape(std::ostream & out, double* all_points, double* polygon, std::string* names, size_t c_points, size_t c_shape)
{
  size_t k = 0, m = 0;
  point_t centr_scale;
  centr_scale.x = all_points[c_points - 3];
  centr_scale.y = all_points[c_points - 2];
  double sum1 = 0, sum2 = 0;
  double out1[10000] = {};
  double out2[10000] = {};
  out << centr_scale.x << centr_scale.y << "\n";
  for (size_t i = 0; i < c_shape; i++)
  {
    if (names[i] == "RECTANGLE")
    {
      point_t x4, x2;
      x4.x = all_points[k];
      x4.y = all_points[k + 1];
      x2.x = all_points[k + 2];
      x2.y = all_points[k + 3];
      Rectangle shape_rec(x4, x2);
      sum1 += shape_rec.getArea();
      rectangle_t rec1 = shape_rec.getFrameRect();
      out1[m] = rec1.pos.x - (rec1.width / 2);
      out1[m + 1] = rec1.pos.y - (rec1.height / 2);
      out1[m + 2] = rec1.pos.x + (rec1.width / 2);
      out1[m + 3] = rec1.pos.y + (rec1.height / 2);
      shape_rec.scale(centr_scale, all_points[c_points - 1]);
      sum2 += shape_rec.getArea();
      out << sum2 << "\n";
      rectangle_t rec2 = shape_rec.getFrameRect();
      out2[m] = rec2.pos.x - (rec2.width / 2);
      out2[m + 1] = rec2.pos.y - (rec2.height / 2);
      out2[m + 2] = rec2.pos.x + (rec2.width / 2);
      out2[m + 3] = rec2.pos.y + (rec2.height / 2);
      k += 4;
      m += 4;
    }
    else if (names[i] == "TRIANGLE")
    {
      point_t x1, x2, x3;
      x1.x = all_points[k];
      x1.y = all_points[k + 1];
      x2.x = all_points[k + 2];
      x2.y = all_points[k + 3];
      x3.x = all_points[k + 4];
      x3.y = all_points[k + 5];
      Triangle shape_tri(x1, x2, x3);
      sum1 += shape_tri.getArea();
      rectangle_t tri1 = shape_tri.getFrameRect();
      out1[m] = tri1.pos.x - (tri1.width / 2);
      out1[m + 1] = tri1.pos.y - (tri1.height / 2);
      out1[m + 2] = tri1.pos.x + (tri1.width / 2);
      out1[m + 3] = tri1.pos.y + (tri1.height / 2);
      shape_tri.scale(centr_scale, all_points[k - 1]);
      sum2 += shape_tri.getArea();
      rectangle_t tri2 = shape_tri.getFrameRect();
      out2[m] = tri2.pos.x - (tri2.width / 2);
      out2[m + 1] = tri2.pos.y - (tri2.height / 2);
      out2[m + 2] = tri2.pos.x + (tri2.width / 2);
      out2[m + 3] = tri2.pos.y + (tri2.height / 2);
      k += 6;
      m += 4;
    }
  }
  polygon[0] = 0;
  out << sum1;
  for (size_t i = 0; i < k; i++)
  {
    out << " " << out1[i];
  }
  out << "\n";
  out << sum2;
  for (size_t i = 0; i < k; i++)
  {
    out << " " << out2[i];
  }
  out << "\n";
}
Rectangle getrectangle(point_t x4, point_t x2)
{
  Rectangle t(x4,x2);
  return t;
}
