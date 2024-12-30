#ifndef KIZHIN_T1_BASE_TYPES_HPP
#define KIZHIN_T1_BASE_TYPES_HPP

namespace kizhin {
  struct point_t;
  struct rectangle_t;
}

struct kizhin::point_t
{
  double x;
  double y;
};

struct kizhin::rectangle_t
{
  double width;
  double height;
  point_t pos;
};

#endif
