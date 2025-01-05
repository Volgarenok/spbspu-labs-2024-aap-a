#include "fabric.hpp"
#include <string>
#include <exception>
#include "rectangle.hpp"
#include "additional-utilities.hpp"
#include "diamond.hpp"
#include "triangle.hpp"
nikonov::Shape *nikonov::make_shape(std::istream &input, const std::string &name)
{
  if (name == "RECTANGLE")
  {
    return make_rectangle(input);
  }
  else if (name == "DIAMOND")
  {
    return make_diamond(input);
  }
  else if (name == "TRIANGLE")
  {
    return make_triangle(input);
  }
  else
  {
    throw std::runtime_error("RE:noncorrect figure name");
  }
}
nikonov::Rectangle *nikonov::make_rectangle(std::istream &input)
{
  constexpr size_t rectangleParametersNum = 4;
  double nums[rectangleParametersNum] = {};
  for (size_t i = 0; i < rectangleParametersNum; ++i)
  {
    input >> nums[i];
  }
  if (!input)
  {
    throw std::runtime_error("RE:noncorrect rectangle parameters");
  }
  point_t lbp({ nums[0], nums[1] });
  point_t rtp({ nums[2], nums[3] });
  return new Rectangle(lbp, rtp);
}
nikonov::Diamond *nikonov::make_diamond(std::istream &input)
{
  constexpr size_t diamondParametersNum = 6;
  double nums[diamondParametersNum] = {};
  for (size_t i = 0; i < diamondParametersNum; ++i)
  {
    input >> nums[i];
  }
  if (!input)
  {
    throw std::runtime_error("RE:noncorrect diamond parameters");
  }
  point_t p1({ nums[0], nums[1] });
  point_t p2({ nums[2], nums[3] });
  point_t p3({ nums[4], nums[5] });
  return new Diamond(p1, p2, p3);
}
nikonov::Triangle *nikonov::make_triangle(std::istream &input)
{
  constexpr size_t triangleParametersNum = 6;
  double nums[triangleParametersNum] = {};
  for (size_t i = 0; i < triangleParametersNum; ++i)
  {
    input >> nums[i];
  }
  if (!input)
  {
    throw std::runtime_error("RE:noncorrect triangle parameters");
  }
  point_t a({ nums[0], nums[1] });
  point_t b({ nums[2], nums[3] });
  point_t c({ nums[4], nums[5] });
  return new Triangle(a, b, c);
}
