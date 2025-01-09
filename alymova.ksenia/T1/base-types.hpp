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
  bool operator<(point_t point1, point_t point2);

  struct rectangle_t final
  {
  public:
    /*rectangle_t() = default;
    rectangle_t(point_t low_left, point_t upp_right);
    rectangle_t(const rectangle_t& rect);
    rectangle_t(const rectangle_t&& rect);
    rectangle_t operator=(const rectangle_t& rect);*/
    //point_t low_left_, upp_right_;
    double width, height;
    point_t pos;
    //point_t shift_point_;
  };
  double getAreaFrameRect(rectangle_t rect);
  void moveFrameRect(rectangle_t& rect, double shift_x, double shift_y);
  void scaleFrameRect(rectangle_t& rect, double ratio);
  point_t getShiftFrameRect(rectangle_t rect1, rectangle_t rect2);
  point_t getLowLeftFrameRect(rectangle_t rect);
  point_t getUppRightFrameRect(rectangle_t rect);
}
#endif
