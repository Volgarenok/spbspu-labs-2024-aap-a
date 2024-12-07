#include "polygon.hpp"
#include <cmath>
#include "base-types.hpp"

demehin::Polygon::Polygon(size_t vrtx_cnt, const point_t* vertex):
  vrtx_cnt_(vrtx_cnt)
{
  for (size_t i = 0; i < vrtx_cnt; i++)
  {
    vertex_[i] = vertex[i];
  }
}

double demehin::Polygon::getArea() const
{
  const double PI = 3.1415;
  point_t side_vector;
  side_vector.x_ = vertex_[1].x_ - vertex_[0].x_;
  side_vector.y_ = vertex_[1].y_ - vertex_[0].y_;
  double side  = sqrt(side_vector.x_ * side_vector.x_ + side_vector.y_ * side_vector.y_);
  double area = vrtx_cnt_ * side * side / (4 * std::tan(180 * PI / vrtx_cnt_));
  return area;
}

demehin::rectangle_t demehin::Polygon::getFrameRect() const
{
  double min_x = vertex_[0].x_, max_x = vertex_[0].x_;
  double min_y = vertex_[0].y_, max_y = vertex_[0].y_;

  for (size_t i = 0; i < vrtx_cnt_; i++)
  {
    min_x = (min_x < vertex_[i].x_) ? min_x : vertex_[i].x_;
    max_x = (max_x > vertex_[i].x_) ? max_x : vertex_[i].x_;
    min_y = (min_y < vertex_[i].y_) ? min_y : vertex_[i].y_;
    max_y = (max_y > vertex_[i].y_) ? max_y : vertex_[i].y_;
  }

  rectangle_t fr_rect;
  fr_rect.height_ = max_y - min_y;
  fr_rect.width_ = max_x - min_x;
  fr_rect.pos_.x_ = (max_x + min_x) / 2;
  fr_rect.pos_.y_ = (max_y + min_y) / 2;

  return fr_rect;
}

void demehin::Polygon::move(point_t s)
{
  point_t plg_centre;
  plg_centre.x_ = 0;
  plg_centre.y_ = 0;
  for (size_t i = 0; i < vrtx_cnt_; i++)
  {
    plg_centre.x_ += vertex_[i].x_;
    plg_centre.y_ += vertex_[i].y_;
  }

  plg_centre.x_ /= vrtx_cnt_;
  plg_centre.y_ /= vrtx_cnt_;
  double difference_x = s.x_ - plg_centre.x_;
  double difference_y = s.y_ - plg_centre.y_;

  for (size_t i = 0; i < vrtx_cnt_; i++)
  {
    vertex_[i].x_ += difference_x;
    vertex_[i].y_ += difference_y;
  }

}

void demehin::Polygon::move(double x, double y)
{
  for (size_t i = 0; i < vrtx_cnt_; i++)
  {
    vertex_[i].x_ += x;
    vertex_[i].y_ += y;
  }
}

void demehin::Polygon::scale(double k)
{
  point_t plg_centre;
  plg_centre.x_ = 0;
  plg_centre.y_ = 0;
  for (size_t i = 0; i < vrtx_cnt_; i++)
  {
    plg_centre.x_ += vertex_[i].x_;
    plg_centre.y_ += vertex_[i].y_;
  }

  plg_centre.x_ /= vrtx_cnt_;
  plg_centre.y_ /= vrtx_cnt_;

  for (size_t i = 0; i < vrtx_cnt_; i++)
  {
    double dx = vertex_[i].x_ - plg_centre.x_;
    double dy = vertex_[i].y_ - plg_centre.y_;

    dx *= k;
    dy *= k;

    vertex_[i].x_ = plg_centre.x_ + dx;
    vertex_[i].y_ = plg_centre.y_ + dy;
  }

}
