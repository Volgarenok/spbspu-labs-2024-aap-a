#include "shapeBreeding.hpp"
#include "base-types.hpp"
#include <stdexcept>

namespace kushekbaev
{
  bool isTriangle(point_t first, point_t second, point_t third)
  {
    if ((getLineLength(first, second) > getLineLength(second, third) + getLineLength(first, third))
       || (getLineLength(second, third) > (getLineLength(first, second) + getLineLength(first, third)))
       || (getLineLength(first, third) > getLineLength(first, second) + getLineLength(second, third)))
    {
      return false;
    }
    else
    {
      return true;
    }
  }

  Rectangle* makeRectangle(std::istream& input)
  {
    double x1 = 0;
    double y1 = 0;
    double x2 = 0;
    double y2 = 0;
    input >> x1 >> y1 >> x2 >> y2;
    if (x1 >= x2 || y1 >= y2)
    {
      throw std::invalid_argument("Left point values should be less than right point values\n");
    }
    return new Rectangle({ x1, y1 }, { x2, y2 });
  }

  Concave* makeConcave(std::istream& input)
  {
    point_t first { 0, 0 };
    point_t second { 0, 0 };
    point_t third { 0, 0 };
    point_t final { 0, 0 };
    input >> first.x >> first.y >> second.x >> second.y >> third.x >> third.y >> final.x >> final.y;
    if (!isTriangle(first, second, final))
    {
      throw std::invalid_argument("First two + final points wouldnt make a triangle\n");
    }

    if (!isTriangle(second, third, final))
    {
      throw std::invalid_argument("First + two last points wouldnt make a triangle\n");
    }
    return new Concave({ first, second, third, final });
  }

  Parallelogram* makeParallelogram(std::istream& input)
  {
    point_t first { 0, 0 };
    point_t second { 0, 0 };
    point_t third { 0, 0 };
    input >> first.x >> first.y >> second.x >> second.y >> third.x >> third.y;
    if (!isTriangle(first, second, third))
    {
      throw std::invalid_argument("First three points wouldnt make a triangle\n");
    }
    return new Parallelogram({ first, second, third });
  }

  Diamond* makeDiamond(std::istream& input)
  {
    point_t first { 0, 0 };
    point_t second { 0, 0 };
    point_t third { 0, 0 };
    input >> first.x >> first.y >> second.x >> second.y >> third.x >> third.y;
    if (!isTriangle(first, second, third))
    {
      throw std::invalid_argument("First three points wouldnt make a triangle\n");
    }
    return new Diamond({ first, second, third });
  }

  point_t makeScale(std::istream& input)
  {
    double x = 0;
    double y = 0;
    input >> x >> y;
    return { x, y };
  }
}
