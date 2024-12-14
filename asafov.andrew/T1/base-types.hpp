#pragma once
class point_t
{
  point_t(double x, double y):
  x(x), y(y)
  {};
public:
  double x;
  double y;
};

class rectangle_t
{
public:
  double width;
  double height;
  point_t pos;
};
