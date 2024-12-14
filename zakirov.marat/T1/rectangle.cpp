#include "shape.hpp"
namespace zakirov
{
  class Rectangle : public Shape
  {
    public:
      virtual double getArea();
      virtual rectangle_t getFrameRect();
      virtual void move(point_t target);
      virtual void move(double bias_x, double bias_y);
      virtual void scale(double k);
    private:
      point_t bottom_left;
      point_t top_right;
  };
}
