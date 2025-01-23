#include "polygon.hpp"
#include <cmath>
#include <stdexcept>
#include <algorithm>

namespace
{
  bool areEqualPts(const demehin::point_t& p1, const demehin::point_t& p2)
  {
    return p1.x == p2.x && p1.y == p2.y;
  }

  bool hasSameVertex(size_t n, const demehin::point_t* vertex)
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

  demehin::point_t getDifferenceCords(const demehin::point_t& pt1, const demehin::point_t& pt2)
  {
    double difference_x = pt1.x - pt2.x;
    double difference_y = pt1.y - pt2.y;

    return {difference_x, difference_y};
  }

  demehin::point_t sumPointsCords(const demehin::point_t& pt1, const demehin::point_t& pt2)
  {
    return {pt1.x + pt2.x, pt1.y + pt2.y};
  }

  demehin::point_t* copyCords(const demehin::point_t* vertex, size_t vrt_cnt)
  {
    demehin::point_t* vrt = new demehin::point_t[vrt_cnt];
    for (size_t i = 0; i < vrt_cnt; i++)
    {
      vrt[i] = vertex[i];
    }
    return vrt;
  }

}

demehin::Polygon::~Polygon()
{
  delete[] vertex_;
}

demehin::Polygon::Polygon(size_t vrtx_cnt, const point_t* vertex):
  vrtx_cnt_(vrtx_cnt),
  vertex_(copyCords(vertex, vrtx_cnt))
{
  if (vrtx_cnt < 3 || hasSameVertex(vrtx_cnt, vertex))
  {
    delete[] vertex_;
    throw std::logic_error("incorrect_shape");
  }
}

double demehin::Polygon::getArea() const
{
  double area = 0;
  for (size_t i = 0; i < vrtx_cnt_; i++)
  {
    size_t j = (i + 1) % vrtx_cnt_;
    area += (vertex_[i].x * vertex_[j].y - vertex_[j].x * vertex_[i].y);
  }
  return std::abs(area) / 2.0;
}

demehin::rectangle_t demehin::Polygon::getFrameRect() const
{
  double min_x = vertex_[0].x, max_x = vertex_[0].x;
  double min_y = vertex_[0].y, max_y = vertex_[0].y;

  for (size_t i = 0; i < vrtx_cnt_; i++)
  {
    min_x = std::min(min_x, vertex_[i].x);
    max_x = std::max(max_x, vertex_[i].x);
    min_y = std::min(min_y, vertex_[i].y);
    max_y = std::max(max_y, vertex_[i].y);
  }

  double fr_rect_h = max_y - min_y;
  double fr_rect_w = max_x - min_x;
  double pos_x = (max_x + min_x) / 2;
  double pos_y = (max_y + min_y) / 2;
  point_t fr_rect_pos = {pos_x, pos_y};

  return {fr_rect_w, fr_rect_h, fr_rect_pos};
}

void demehin::Polygon::move(point_t s)
{
  point_t plg_center = getCenter();
  point_t difference_cords = getDifferenceCords(s, plg_center);
  move(difference_cords.x, difference_cords.y);
}

void demehin::Polygon::move(double x, double y)
{
  point_t move_cords = {x, y};
  for (size_t i = 0; i < vrtx_cnt_; i++)
  {
    vertex_[i] = sumPointsCords(vertex_[i], move_cords);
  }
}

void demehin::Polygon::scale(double k)
{
  point_t plg_center = getCenter();

  for (size_t i = 0; i < vrtx_cnt_; i++)
  {
    point_t difference_cords = getDifferenceCords(vertex_[i], plg_center);
    vertex_[i] = sumPointsCords(plg_center, {difference_cords.x * k, difference_cords.y * k});
  }
}

demehin::point_t demehin::Polygon::getCenter() const
{
  demehin::point_t plg_center = {0, 0};
  for (size_t i = 0; i < vrtx_cnt_; i++)
  {
    plg_center = sumPointsCords(plg_center, vertex_[i]);
  }

  return {plg_center.x / vrtx_cnt_, plg_center.y / vrtx_cnt_};
}
