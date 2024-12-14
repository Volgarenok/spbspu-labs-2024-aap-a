#pragma once
class Shape
{
public:
  virtual double getArea();
  virtual rectangle_t getFrameRect();
  virtual void move(point_t pos);
  virtual void move(double x, double y);
  virtual void scale(double scale);
};
