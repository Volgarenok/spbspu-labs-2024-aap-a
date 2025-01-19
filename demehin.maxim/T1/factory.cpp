#include "factory.hpp"
#include <iostream>
#include "rectangle.hpp"
#include "ring.hpp"
#include "polygon.hpp"

namespace
{
  demehin::Rectangle* createRect(std::istream& in)
  {
    demehin::point_t points[2] = {};
    for (size_t i = 0; i < 2; i++)
    {
      in >> points[i].x >> points[i].y;
    }
    return new demehin::Rectangle(points[0], points[1]);
  }

  demehin::Ring* createRing(std::istream& in)
  {
    double ringParams[4] = {};
    for (size_t i = 0; i < 4; i++)
    {
      in >> ringParams[i];
    }

    demehin::point_t center = {ringParams[0], ringParams[1]};
    return new demehin::Ring(center, ringParams[2], ringParams[3]);
  }

  void inputPolygonCords(std::istream& in, demehin::point_t** pts, size_t capacity, size_t& cord_cnt)
  {
    *pts = new demehin::point_t[capacity];
    size_t size = 0;
    demehin::point_t vrt = {0, 0};
    while (in >> vrt.x >> vrt.y)
    {
      if (size >= capacity)
      {
        capacity *= 2;
        demehin::point_t* new_pts = nullptr;
        try
        {
          new_pts = new demehin::point_t[capacity];
        }
        catch (const std::bad_alloc& e)
        {
          delete[] *pts;
          throw e;
        }
        for (size_t i = 0; i < size; i++)
        {
          new_pts[i] = (*pts)[i];
        }
        delete[] *pts;
        *pts = new_pts;
      }
      (*pts)[size++] = vrt;
      cord_cnt++;
    }
    in.clear();
  }

  demehin::Polygon* createPolygon(std::istream& in)
  {
    constexpr size_t capacity = 128;
    size_t cord_cnt = 0;
    demehin::point_t* vrt = nullptr;
    inputPolygonCords(in, &vrt, capacity, cord_cnt);
    demehin::Polygon* plg = nullptr;
    try
    {
      plg = new demehin::Polygon(cord_cnt, vrt);
    }
    catch (const std::exception&)
    {
      delete[] vrt;
      throw;
    }
   // catch (const std::logic_error&)
    //{
      //delete[] vrt;
      //throw;
    //}
    delete[] vrt;
    return plg;
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
