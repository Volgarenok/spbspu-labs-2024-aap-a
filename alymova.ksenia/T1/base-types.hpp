#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP
struct point_t
{
    point_t(double x, double y):
        x_(x),
        y_(y)
    {}
    point_t(const point_t& point)
    {
        x_ = point.x_;
        y_ = point.y_;
    }
    point_t(point_t&& point)
    {
        x_ = point.x_;
        y_ = point.y_;
    }
    double getX()
    {
        return x_;
    }
    double getY()
    {
        return y_;
    }
    point_t operator+=(point_t shift_point)
    {
        x_ += shift_point.x_;
        y_ += shift_point.y_;
        return *this;
    }
private:
    double x_, y_;
};
struct rectangle_t
{
    rectangle_t(double w, double h):
        width_(w),
        height_(h),
        pos_(point_t(width_ / 2, height_ / 2))
    {}
private:
    double width_, height_;
    point_t pos_;
};
#endif