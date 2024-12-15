#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

namespace zholobov {

  struct point_t {
    float x;
    float y;
  };

  struct rectangle_t {
    float width;
    float height;
    point_t pos;
  };

}

#endif
