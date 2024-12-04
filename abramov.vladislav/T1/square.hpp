#ifndef SQUARE_HPP
#define SQUARE_HPP
namespace abramov
{
  struct Square: Shape
  {
    Square(double x, double y, double len);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t p) override;
    void (move double dx, double dy) override;
    void scale(double k) override;
  private:
    point_t pLeftLower;
    double len;
  }
}
#endif

