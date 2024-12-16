#include "output.hpp"
#include "shape.hpp"
#include <iostream>
#include <iomanip>
#include "rectangle.hpp"
#include "triangle.hpp"
#include "polygon.hpp"
void karnauhova::output(std::ostream & out, double* all_points, double* polygon, std::string* names, size_t c_points, size_t c_shape)
{
  size_t k = 0, m = 0, c_polygon = 0;
  point_t centr_scale;
  centr_scale.x = all_points[c_points - 3];
  centr_scale.y = all_points[c_points - 2];
  double sum1 = 0, sum2 = 0;
  double out1[10000] = {};
  double out2[10000] = {};
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
      shape_tri.scale(centr_scale, all_points[c_points - 1]);
      sum2 += shape_tri.getArea();
      rectangle_t tri2 = shape_tri.getFrameRect();
      out2[m] = tri2.pos.x - (tri2.width / 2);
      out2[m + 1] = tri2.pos.y - (tri2.height / 2);
      out2[m + 2] = tri2.pos.x + (tri2.width / 2);
      out2[m + 3] = tri2.pos.y + (tri2.height / 2);
      k += 6;
      m += 4;
    }
    else if (names[i] == "POLYGON")
    {
      point_t points_polygon[10000] = {};
      size_t j = 0;
      if (all_points[k] < 6)
      {
        k += 1;
        continue;
      }
      for (size_t i = 0; i < all_points[k]; i += 2)
      {
        point_t point;
        point.x = polygon[c_polygon + i];
        point.y = polygon[c_polygon + i + 1];
        points_polygon[j] = point;
        j++;
      }
      Polygon shape_pol(points_polygon, j);
      sum1 += shape_pol.getArea();
      rectangle_t pol1 = shape_pol.getFrameRect();
      out1[m] = pol1.pos.x - (pol1.width / 2);
      out1[m + 1] = pol1.pos.y - (pol1.height / 2);
      out1[m + 2] = pol1.pos.x + (pol1.width / 2);
      out1[m + 3] = pol1.pos.y + (pol1.height / 2);
      shape_pol.scale(centr_scale, all_points[c_points - 1]);
      sum2 += shape_pol.getArea();
      rectangle_t pol2 = shape_pol.getFrameRect();
      out2[m] = pol2.pos.x - (pol2.width / 2);
      out2[m + 1] = pol2.pos.y - (pol2.height / 2);
      out2[m + 2] = pol2.pos.x + (pol2.width / 2);
      out2[m + 3] = pol2.pos.y + (pol2.height / 2);
      m += 4;
      c_polygon += all_points[k];
      k += 1;
      out << "\n";
    }
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
