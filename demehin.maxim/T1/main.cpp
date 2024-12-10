#include <iostream>
#include <string>
#include <iomanip>
#include "rectangle.hpp"
#include "shape.hpp"
#include "base-types.hpp"
#include "ring.hpp"
#include "polygon.hpp"

namespace
{
  void makeIsoScale(demehin::Shape** shapes, size_t shp_cnt, double scale_k, demehin::point_t& scale_pt)
  {
    for (size_t i = 0; i < shp_cnt; i++)
    {
        demehin::point_t orig_pt = shapes[i]->getFrameRect().pos;
        shapes[i]->move(scale_pt);
        demehin::point_t new_pt = shapes[i]->getFrameRect().pos;
        demehin::point_t move_vector;
        move_vector.x = (new_pt.x - orig_pt.x) * scale_k;
        move_vector.y = (new_pt.y - orig_pt.y) * scale_k;
        shapes[i]->scale(scale_k);
        shapes[i]->move(move_vector.x * -1, move_vector.y * -1);
    }
  }

  double getAreaSum(demehin::Shape** shapes, size_t shp_cnt)
  {
    double area_sum = 0;
    for (size_t i = 0; i < shp_cnt; i++)
    {
      area_sum += shapes[i]->getArea();
    }
    return area_sum;
  }

  void getFrRectCords(demehin::rectangle_t& fr_rect, double& lbx, double& lby, double& rtx, double& rty)
  {
    lbx = fr_rect.pos.x - fr_rect.width / 2;
    lby = fr_rect.pos.y - fr_rect.height / 2;
    rtx = fr_rect.pos.x + fr_rect.width / 2;
    rty = fr_rect.pos.y + fr_rect.height / 2;
  }

  void printFrRectCords(std::ostream& out, demehin::Shape** shapes, size_t shp_cnt)
  {
    for (size_t i = 0; i < shp_cnt; i++)
    {
      double lbx = 0, lby = 0, rtx = 0, rty = 0;
      demehin::rectangle_t fr_rect = shapes[i]->getFrameRect();
      getFrRectCords(fr_rect, lbx, lby, rtx, rty);
      out << " " << lbx << " " << lby << " " << rtx << " " << rty;
    }
    out << "\n";
  }

  void free_shapes(demehin::Shape** shapes, size_t shp_cnt)
  {
    for (size_t i = 0; i < shp_cnt; i++)
    {
      delete shapes[i];
    }
  }

  bool areEqualPts(demehin::point_t p1, demehin::point_t p2)
  {
    return p1.x == p2.x && p1.y == p2.y;
  }

  bool hasSameVertex(size_t n, demehin::point_t* vertex)
  {
    for (size_t i = 0; i < n; i++)
    {
      for (size_t j = i + 1; j < n; j++)
      {
        if (areEqualPts(vertex[i], vertex[j]))
        {
          return true;
        }
      }
    }
    return false;
  }

  void inputPolygonCords(std::istream& in, demehin::point_t** pts, size_t max_size, size_t& cord_cnt)
  {
    *pts = new demehin::point_t[max_size];
    size_t size = 0;
    while (std::cin.peek() != '\n')
    {
      if (size >= max_size)
      {
        max_size *= 2;
        demehin::point_t* new_pts = nullptr;
        try
        {
          new_pts = new demehin::point_t[size];
        }
        catch (std::bad_alloc& e)
        {
          delete[] *pts;
          throw;
        }
        for (size_t i = 0; i < size; i++)
        {
          new_pts[i].x = (*pts)[i].x;
          new_pts[i].y = (*pts)[i].y;
        }
        delete[] *pts;
        *pts = new_pts;
      }
      demehin::point_t vrt;
      in >> vrt.x >> vrt.y;
      (*pts)[size++] = vrt;
      cord_cnt++;
    }
  }

}

int main()
{
  demehin::Shape* shapes[10000] = {};
  size_t shp_cnt = 0;
  double scale_k = 0;
  demehin::point_t scale_pt;
  bool is_incorrect_shp = false;
  constexpr size_t max_size = 100;

  std::string shape_name;
  while (true)
  {
    std::cin >> shape_name;
    if (std::cin.eof())
    {
      std::cerr << "error: eof\n";
      free_shapes(shapes, shp_cnt);
      return 1;
    }
    if (shape_name == "RECTANGLE")
    {
      double lbx = 0, lby = 0;
      double rtx = 0, rty = 0;
      std::cin >> lbx;
      std::cin >> lby;
      std::cin >> rtx;
      std::cin >> rty;
      if (lbx >= rtx || lby >= rty)
      {
        is_incorrect_shp = true;
        continue;
      }

      try
      {
        shapes[shp_cnt++] = new demehin::Rectangle(lbx, lby, rtx, rty);
      }
      catch (std::bad_alloc& e)
      {
        free_shapes(shapes, shp_cnt);
        std::cerr << "bad alloc\n";
        return 1;
      }
      shape_name = "";
    }

    else if (shape_name == "RING")
    {
      double cent_x = 0, cent_y = 0, out_r = 0, in_r = 0;
      std::cin >> cent_x >> cent_y >> out_r >> in_r;
      if (out_r < in_r || out_r <= 0 || in_r <= 0)
      {
        is_incorrect_shp = true;
        continue;
      }

      try
      {
        shapes[shp_cnt++] = new demehin::Ring(cent_x, cent_y, out_r, in_r);
      }
      catch (std::bad_alloc& e)
      {
        free_shapes(shapes, shp_cnt);
        std::cerr << "bad alloc\n";
        return 1;
      }

      shape_name = "";
    }

    else if (shape_name == "POLYGON")
    {
      demehin::point_t* vrt = nullptr;
      size_t cord_cnt = 0;
      try
      {
        inputPolygonCords(std::cin, &vrt, max_size, cord_cnt);
      }
      catch (std::bad_alloc& e)
      {
        free_shapes(shapes, shp_cnt);
        std::cerr << "bad alloc\n";
        return 1;
      }
      bool isBadPolygon = cord_cnt < 3 || hasSameVertex(cord_cnt, vrt);
      if (isBadPolygon)
      {
        is_incorrect_shp = true;
        delete[] vrt;
        continue;
      }
      try
      {
        shapes[shp_cnt++] = new demehin::Polygon(cord_cnt, vrt);
      }
      catch (std::bad_alloc& e)
      {
        free_shapes(shapes, shp_cnt);
        delete[] vrt;
        std::cerr << "bad alloc\n";
        return 1;
      }
      shape_name = "";
      delete[] vrt;
    }

    else if (shape_name == "SCALE")
    {
      double x = 0;
      double y = 0;
      std::cin >> x;
      std::cin >> y;
      std::cin >> scale_k;
      if (scale_k < 0)
      {
        std::cerr << "Incorrect scale\n";
        free_shapes(shapes, shp_cnt);
        return 1;
      }
      scale_pt.x = x;
      scale_pt.y = y;
      break;
    }
    shape_name = "";
  }

  if (shp_cnt == 0)
  {
    std::cerr << "no shapes\n";
    return 1;
  }

  if (is_incorrect_shp)
  {
    std::cerr << "Incorrect shape\n";
  }


  double sum_area = getAreaSum(shapes, shp_cnt);
  std::cout << std::fixed << std::setprecision(1) << sum_area;
  printFrRectCords(std::cout, shapes, shp_cnt);

  makeIsoScale(shapes, shp_cnt, scale_k, scale_pt);

  sum_area = getAreaSum(shapes, shp_cnt);
  std::cout << sum_area;
  printFrRectCords(std::cout, shapes, shp_cnt);

  free_shapes(shapes, shp_cnt);
}
