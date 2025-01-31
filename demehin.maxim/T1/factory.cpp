#include "factory.hpp"
#include <iostream>
#include "rectangle.hpp"
#include "ring.hpp"
#include "creating_utils.hpp"

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

  demehin::point_t* inputPolygonCords(std::istream& in, size_t capacity, size_t& cord_cnt)
  {
    demehin::point_t* pts = new demehin::point_t[capacity];
    size_t size = 0;
    double vrt_x = 0, vrt_y = 0;
    while (in >> vrt_x >> vrt_y)
    {
      if (size >= capacity)
      {
        capacity *= 2;
        demehin::point_t* new_pts = nullptr;
        try
        {
          new_pts = demehin::details::copyCords(pts, capacity);
        }
        catch (const std::bad_alloc&)
        {
          delete[] pts;
          throw;
        }
        delete[] pts;
        pts = new_pts;
      }

      pts[size++] = {vrt_x, vrt_y};
      cord_cnt++;
    }
    in.clear();
    return pts;
  }

  demehin::Polygon* createPolygon(std::istream& in)
  {
    constexpr size_t capacity = 128;
    size_t cord_cnt = 0;
    demehin::point_t* vrt = inputPolygonCords(in, capacity, cord_cnt);
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

demehin::Shape* demehin::createShape(std::istream& in, const std::string& shp_name)
{
  if (shp_name == "RECTANGLE")
  {
    return createRect(in);
  }

  else if (shp_name == "RING")
  {
    return createRing(in);
  }

  else if (shp_name == "POLYGON")
  {
    return createPolygon(in);
  }
  return nullptr;
}

