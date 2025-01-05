#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

namespace duhanina
{
  class Rectangle final: public Shape
  {
  public:
    Rectangle(const point_t& lt, const point_t& rt);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& newPos) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
    Shape** fillWithEllipses();

  private:
    point_t lt_;
    point_t rt_;
  };
}

#endif
