#include "fabric.hpp"
#include <iostream>
#include <string>
#include "shape.hpp"
#include "rectangle.hpp"
#include "diamond.hpp"
#include "triangle.hpp"
nikonov::Shape* nikonov::make_shape(std::string name, float nums[])
{
  if (name == "RECTANGLE")
  {
    return make_rectangle(nums);
  }
  else if (name == "DIAMOND")
  {
    return make_diamond(nums);
  }
  else if (name == "TRIANGLE")
  {
    return nullptr;
  }
  else
  {
    return nullptr;
  }
}
nikonov::Rectangle* nikonov::make_rectangle(float nums[])
{
  if (nums[0] >= nums[2] || nums[1] >= nums[3])
  {
    return nullptr;
  }
  point_t lbp(nums[0], nums[1]);
  point_t rtp(nums[2], nums[3]);
  Rectangle* result = new Rectangle(lbp, rtp);
  return result;
}
nikonov::Diamond* nikonov::make_diamond(float nums[])
{
  if (nums[0] >= nums[2] || nums[1] <= nums[3] || nums[0] <= nums[4] ||
    nums[1] <= nums[5] || nums[2] <= nums[4] || nums[3] <= nums[5])
  {
    return nullptr;
  }
  point_t topP(nums[0], nums[1]);
  point_t rightP(nums[2], nums[3]);
  point_t midP(nums[4], nums[5]);
  Diamond* result = new Diamond(topP, rightP, midP);
  return result;
}
nikonov::Triangle* nikonov::make_triangle(float nums[])
{
  if (!isCorrectTriangle(nums))
  {
    return nullptr;
  }
  point_t A(nums[0], nums[1]);
  point_t B(nums[2], nums[3]);
  point_t C(nums[4], nums[5]);
  Triangle* result = new Triangle(A, B, C);
  return result;
}
namespace
{
  float posPow(float op, size_t n)
  {
    float res = 1;
    for (size_t i = 0; i < n; ++i)
    {
      res *= op;
    }
    return res;
  }
  bool isCorrectTriangle(float nums[])
  {
    float AB = posPow(nums[2] - nums[0], 2) + posPow(nums[3] - nums[1], 2);
    float BC = posPow(nums[4] - nums[2], 2) + posPow(nums[5] - nums[3], 2);
    float CD = posPow(nums[0] - nums[4], 2) + posPow(nums[1] - nums[5], 2);
    return (AB + BC > CD) && (AB + CD > BC) && (CD + BC > AB);
  }
}