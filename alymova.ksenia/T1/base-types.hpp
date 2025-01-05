#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP
namespace alymova
{
  struct point_t
  {
  public:
    point_t() = default;
    point_t(const point_t& point);
    point_t(const point_t&& point);
    point_t(double x, double y);
    point_t operator=(const point_t& point);
    point_t operator+=(point_t shift_point);
    point_t operator*=(double ratio);
    bool operator<(point_t p2);
    double getX() const;
    double getY() const;
    double x, y;
  };
  struct rectangle_t
  {
  public:
    rectangle_t() = default;
    rectangle_t(point_t low_left, point_t upp_right);
    rectangle_t operator=(const rectangle_t& rect);
    double getArea() const;
    void move(double shift_x, double shift_y);
    point_t getShift() const;
    void scale(double ratio);
    point_t getLowLeft() const;
    point_t getUppRight() const;
    point_t low_left_, upp_right_;
    double width, height;
    point_t pos, shift_point_;
  };
}
#endif
