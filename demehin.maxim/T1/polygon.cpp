#include "polygon.hpp"
#include <cmath>
#include <stdexcept>

namespace
{
  bool areEqualPts(const demehin::point_t p1, const demehin::point_t p2)
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
}

demehin::Polygon::~Polygon()
{
  delete[] vertex_;
}

demehin::Polygon::Polygon(size_t vrtx_cnt, const point_t* vertex):
  vrtx_cnt_(vrtx_cnt),
  vertex_(new point_t[vrtx_cnt])
{
  for (size_t i = 0; i < vrtx_cnt; i++)
  {
    vertex_[i] = vertex[i];
  }

  if (hasSameVertex(vrtx_cnt, vertex_) || vrtx_cnt < 3)
  {
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
    min_x = (min_x < vertex_[i].x) ? min_x : vertex_[i].x;
    max_x = (max_x > vertex_[i].x) ? max_x : vertex_[i].x;
    min_y = (min_y < vertex_[i].y) ? min_y : vertex_[i].y;
    max_y = (max_y > vertex_[i].y) ? max_y : vertex_[i].y;
  }


  double fr_rect_h = max_y - min_y;
  double fr_rect_w = max_x - min_x;
  double pos_x = (max_x + min_x) / 2;
  double pos_y = (max_y + min_y) / 2;
  point_t fr_rect_pos;
  fr_rect_pos.x = pos_x;
  fr_rect_pos.y = pos_y;
  rectangle_t fr_rect;
  fr_rect.height = fr_rect_h;
  fr_rect.width = fr_rect_w;
  fr_rect.pos = fr_rect_pos;
  return fr_rect;
}

void demehin::Polygon::move(point_t s)
{
  point_t plg_centre;
  plg_centre.x = 0;
  plg_centre.y = 0;
  for (size_t i = 0; i < vrtx_cnt_; i++)
  {
    plg_centre.x += vertex_[i].x;
    plg_centre.y += vertex_[i].y;
  }

  plg_centre.x /= vrtx_cnt_;
  plg_centre.y /= vrtx_cnt_;
  double difference_x = s.x - plg_centre.x;
  double difference_y = s.y - plg_centre.y;

  this->move(difference_x, difference_y);
}

void demehin::Polygon::move(double x, double y)
{
  for (size_t i = 0; i < vrtx_cnt_; i++)
  {
    vertex_[i].x += x;
    vertex_[i].y += y;
  }
}

void demehin::Polygon::scale(double k)
{
  point_t plg_centre;
  plg_centre.x = 0;
  plg_centre.y = 0;
  for (size_t i = 0; i < vrtx_cnt_; i++)
  {
    plg_centre.x += vertex_[i].x;
    plg_centre.y += vertex_[i].y;
  }

  plg_centre.x /= vrtx_cnt_;
  plg_centre.y /= vrtx_cnt_;

  for (size_t i = 0; i < vrtx_cnt_; i++)
  {
    double dx = vertex_[i].x - plg_centre.x;
    double dy = vertex_[i].y - plg_centre.y;

    dx *= k;
    dy *= k;

    vertex_[i].x = plg_centre.x + dx;
    vertex_[i].y = plg_centre.y + dy;
  }

}
