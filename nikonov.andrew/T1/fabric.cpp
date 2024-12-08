#include "fabric.hpp"
#include <iostream>
#include <string>
#include "shape.hpp"
#include "rectangle.hpp"
nikonov::Shape* nikonov::make_shape(std::string name, float nums[])
{
  if (name == "RECTANGLE")
  {
    return make_rectangle(nums);
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