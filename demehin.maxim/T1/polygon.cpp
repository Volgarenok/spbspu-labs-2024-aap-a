#include "polygon.hpp"
#include <cmath>

demehin::Polygon::~Polygon()
{
  delete[] vertex_;
}

demehin::Polygon::Polygon(size_t vrtx_cnt, point_t* vertex):
  vrtx_cnt_(vrtx_cnt), vertex_(vertex)
{}

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

  rectangle_t fr_rect;
  fr_rect.height = max_y - min_y;
  fr_rect.width = max_x - min_x;
  fr_rect.pos.x = (max_x + min_x) / 2;
  fr_rect.pos.y = (max_y + min_y) / 2;

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

  for (size_t i = 0; i < vrtx_cnt_; i++)
  {
    vertex_[i].x += difference_x;
    vertex_[i].y += difference_y;
  }

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
