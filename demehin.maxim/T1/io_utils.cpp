#include "io_utils.hpp"
#include <iostream>
#include "rectangle.hpp"
#include "ring.hpp"
#include "polygon.hpp"

namespace
{
  demehin::Rectangle* createRect(std::istream& in)
  {
    double lbx = 0, lby = 0;
    double rtx = 0, rty = 0;
    in >> lbx >> lby >> rtx >> rty;
    demehin::point_t left_bot;
    left_bot.x = lbx;
    left_bot.y = lby;
    demehin::point_t right_top;
    right_top.x = rtx;
    right_top.y = rty;
    return new demehin::Rectangle(left_bot, right_top);
  }

  demehin::Ring* createRing(std::istream& in)
  {
    double cent_x = 0, cent_y = 0, out_r = 0, in_r = 0;
    in >> cent_x >> cent_y >> out_r >> in_r;
    demehin::point_t center;
    center.x = cent_x;
    center.y = cent_y;
    return new demehin::Ring(center, out_r, in_r);
  }

  demehin::point_t* inputPolygonCords(std::istream& in, size_t max_size, size_t& cord_cnt)
  {
    demehin::point_t* pts = new demehin::point_t[max_size];
    size_t size = 0;
    while (in.peek() != '\n')
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
          delete[] pts;
          throw;
        }
        for (size_t i = 0; i < size; i++)
        {
          new_pts[i] = pts[i];
        }
        delete[] pts;
        pts = new_pts;
      }
      demehin::point_t vrt;
      in >> vrt.x >> vrt.y;
      pts[size++] = vrt;
      cord_cnt++;
    }
    return pts;
  }

  demehin::Polygon* createPolygon(std::istream& in)
  {
    constexpr size_t max_size = 100;
    size_t cord_cnt = 0;
    demehin::point_t* vrt = inputPolygonCords(in, max_size, cord_cnt);
    return new demehin::Polygon(cord_cnt, vrt);
  }
}

namespace demehin
{
  void createShape(const std::string& shp_name, Shape** shapes, size_t& shp_cnt)
  {
    if (shp_name == "RECTANGLE")
    {
      shapes[shp_cnt++] = createRect(std::cin);
    }

    else if (shp_name == "RING")
    {
      shapes[shp_cnt++] = createRing(std::cin);
    }

    else if (shp_name == "POLYGON")
    {
      shapes[shp_cnt++] = createPolygon(std::cin);
    }
  }
}
