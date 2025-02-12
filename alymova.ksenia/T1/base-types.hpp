#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP
namespace alymova
{
  struct point_t
  {
    double x, y;
  };
  point_t operator+=(point_t& point, const point_t& shift_point);
  point_t operator*=(point_t& point, double ratio);
  bool operator<(const point_t& point1, const point_t& point2);

  struct rectangle_t
  {
    double width, height;
    point_t pos;
  };
  point_t getShiftFrameRect(const rectangle_t& rect1, const rectangle_t& rect2) noexcept;
  point_t getLowLeftFrameRect(const rectangle_t& rect) noexcept;
  point_t getUppRightFrameRect(const rectangle_t& rect) noexcept;
}
#endif
