#include "factory.hpp"
#include <iostream>
#include "rectangle.hpp"
#include "ring.hpp"
#include "polygon.hpp"

namespace
{

  void inputParameters(std::istream& in, double* cords, size_t cords_cnt)
  {
    for (size_t i = 0; i < cords_cnt; i++)
    {
      in >> *(cords + i);
    }
  }

  demehin::Rectangle* createRect(std::istream& in)
  {
    double rectCords[4] = {};
    inputParameters(in, rectCords, 4);

    demehin::point_t left_bot = {rectCords[0], rectCords[1]};
    demehin::point_t right_top = {rectCords[2], rectCords[3]};

    return new demehin::Rectangle(left_bot, right_top);
  }

  demehin::Ring* createRing(std::istream& in)
  {
    double ringParams[4] = {};
    inputParameters(in, ringParams, 4);

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
        catch (const std::bad_alloc&)
        {
          delete[] *pts;
          throw;
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
    inputPolygonCords(in, std::addressof(vrt), capacity, cord_cnt);
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
    delete[] vrt;
    return plg;
  }
}

namespace demehin
{
  void createShape(std::istream& in, const std::string& shp_name, Shape** shapes, size_t& shp_cnt)
  {
    if (shp_name == "RECTANGLE")
    {
      shapes[shp_cnt++] = createRect(in);
    }

    else if (shp_name == "RING")
    {
      shapes[shp_cnt++] = createRing(in);
    }

    else if (shp_name == "POLYGON")
    {
      shapes[shp_cnt++] = createPolygon(in);
    }
  }
}
