class Rectangle
{
public:
  Rectangle(point_t x1, point_t x4): x1_(x1), x4_(x4)
  {
    x2_.x = x4_.x;
    x2_.y = x1_.y;
    x3_.x = x1_.x;
    x3_.y = x4_.y;
  }
  
  ~Rectangle(){}
private:
  point_t x1_;
  point_t x2_;
  point_t x3_;
  point_t x4_;
};
