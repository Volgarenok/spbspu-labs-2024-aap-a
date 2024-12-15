#include "fabric.hpp"
#include <iostream>
#include <cmath>
#include <string>
#include "shape.hpp"
#include "rectangle.hpp"
#include "diamond.hpp"
#include "triangle.hpp"
nikonov::Shape* nikonov::make_shape(std::string name, double  nums[])
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
    return make_triangle(nums);
  }
  else
  {
    return nullptr;
  }
}
nikonov::Rectangle* nikonov::make_rectangle(double  nums[])
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
nikonov::Diamond* nikonov::make_diamond(double  nums[])
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
nikonov::Triangle* nikonov::make_triangle(double  nums[])
{
  double  AB = std::sqrt(std::pow(nums[2] - nums[0], 2) + std::pow(nums[3] - nums[1], 2));
  double  BC = std::sqrt(std::pow(nums[4] - nums[2], 2) + std::pow(nums[5] - nums[3], 2));
  double  CA = std::sqrt(std::pow(nums[4] - nums[0], 2) + std::pow(nums[5] - nums[1], 2));
  if (!((AB + BC > CA) && (AB + CA > BC) && (CA + BC > AB)))
  {
    return nullptr;
  }
  point_t A(nums[0], nums[1]);
  point_t B(nums[2], nums[3]);
  point_t C(nums[4], nums[5]);
  Triangle* result = new Triangle(A, B, C);
  return result;
}
