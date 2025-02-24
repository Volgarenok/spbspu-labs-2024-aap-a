#include "outputFigures.hpp"

std::ostream& dirti::outputFigures(Shape** shapes, std::ostream& out)
{
  for (size_t i = 0; shapes[i] != nullptr; ++i)
  {
    rectangle_t frameRect = shapes[i]->getFrameRect();
    point_t pos_ = frameRect.pos;
    point_t left = { pos_.x - frameRect.width / 2, pos_.y - frameRect.height / 2 };
    point_t right = { pos_.x + frameRect.width / 2, pos_.y + frameRect.height / 2 };
    out << left.x << " " << left.y << " " << right.x << " " << right.y;
    if (shapes[i + 1] != nullptr)
    {
      out << " ";
    }
  }
  return out;
}