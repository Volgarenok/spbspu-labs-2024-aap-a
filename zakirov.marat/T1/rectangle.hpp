#include "shape.hpp"

namespace zakirov
{
  class Rectangle : public Shape
  {
    public:
      virtual double getArea() const override;
      virtual rectangle_t getFrameRect() const override;
      virtual void move(point_t target) override;
      virtual void move(double bias_x, double bias_y) override;
      virtual void scale(double k) override;
    private:
      point_t bottom_left;
      point_t top_right;
  };
}
