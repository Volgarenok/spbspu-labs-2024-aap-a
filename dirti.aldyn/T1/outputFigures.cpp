#include "outputFigures.hpp"
#include "rectangle.hpp"
#include "square.hpp"
#include "parallelogram.hpp"

std::ostream& dirti::outputFigures(const Shape* const* shapes, std::ostream& out)
{
  rectangle_t frameRect = shapes[0]->getFrameRect();
  point_t pos_ = frameRect.pos;
  point_t left = { pos_.x - frameRect.width / 2, pos_.y - frameRect.height / 2 };
  point_t right = { pos_.x + frameRect.width / 2, pos_.y + frameRect.height / 2 };
  out << left.x << " " << left.y << " " << right.x << " " << right.y;
  for (size_t i = 1; shapes[i] != nullptr; ++i)
  {
    frameRect = shapes[i]->getFrameRect();
    pos_ = frameRect.pos;
    left = { pos_.x - frameRect.width / 2, pos_.y - frameRect.height / 2 };
    right = { pos_.x + frameRect.width / 2, pos_.y + frameRect.height / 2 };
    out << " " << left.x << " " << left.y << " " << right.x << " " << right.y;
  }
  return out;
}
