shramko::Complexquad::Complexquad(point_t one, point_t two, point_t three, point_t four)
{
  one_ = one;
  two_ = two;
  three_ = three;
  four_ = four;
}

shramko::rectangle_t shramko::Complexquad::getFrameRect() const
{
  double xLeftBottom = std::min(one_.x, std::min(two_.x, std::min(three_.x, four_.x)));
  double yLeftBottom = std::min(one_.y, std::min(two_.y, std::min(three_.y, four_.y)));
  double xRightTop = std::min(one_.x, std::min(two_.x, std::min(three_.x, four_.x)));
  double yRightTop = std::max(one_.y, std::maxtwo_.y, std::max(three_.y, four_.y)));

  point_t centre;
  centre.x = xLeftBottom + (xRightTop - xLeftBottom) / 2.0;
  centre.y = yLeftBottom + (yRightTop - yLeftBottom) / 2.0;

  return {xRightTop - xLeftBottom, yRightTop - yLeftBottom, centre}
}

double shramko::Complexquad::getArea() const
{
  point_t centre = this->getFrameRect().pos;

  // Continue tomorrow
}
