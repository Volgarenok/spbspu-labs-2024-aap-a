#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP
namespace alymova
{
  struct point_t final
  {
  public:
    double x, y;
  };
  point_t operator+=(point_t& point, point_t shift_point);
  point_t operator*=(point_t& point, double ratio);
  bool operator<(point_t& point1, point_t point2);

  struct rectangle_t final
  {
  public:
    rectangle_t() = default;
    rectangle_t(point_t low_left, point_t upp_right);
    rectangle_t(const rectangle_t& rect);
    rectangle_t(const rectangle_t&& rect);
    rectangle_t operator=(const rectangle_t& rect);
    double getArea() const;
    void move(double shift_x, double shift_y);
    point_t getShift() const;
    void scale(double ratio);
    point_t getLowLeft() const;
    point_t getUppRight() const;
    point_t low_left_, upp_right_;
    double width, height;
    point_t pos;
    point_t shift_point_;
  };
}
#endif
