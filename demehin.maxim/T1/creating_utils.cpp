#include "creating_utils.hpp"

demehin::point_t* demehin::details::copyCords(const point_t* vertex, size_t vrt_cnt)
{
  point_t* vrt = new point_t[vrt_cnt];
  for (size_t i = 0; i < vrt_cnt; i++)
  {
    vrt[i] = vertex[i];
  }
  return vrt;
}
