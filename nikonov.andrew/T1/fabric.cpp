#include "fabric.hpp"
#include <string>
#include <exception>
#include "shape.hpp"
#include "rectangle.hpp"
#include "additional-utilities.hpp"
#include "diamond.hpp"
#include "triangle.hpp"
nikonov::Shape *nikonov::make_shape(const std::string &name, double nums[])
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
nikonov::Rectangle *nikonov::make_rectangle(double nums[])
{
  point_t lbp({ nums[0], nums[1] });
  point_t rtp({ nums[2], nums[3] });
  Rectangle *result = nullptr;
  try
  {
    result = new Rectangle(lbp, rtp);
  }
  catch (const std::logic_error &e)
  {
    return nullptr;
  }
  catch (const std::bad_alloc &e)
  {
    throw;
  }
  return result;
}
nikonov::Diamond *nikonov::make_diamond(double nums[])
{
  point_t p1({ nums[0], nums[1] });
  point_t p2({ nums[2], nums[3] });
  point_t p3({ nums[4], nums[5] });
  Diamond *result = nullptr;
  try
  {
    result = new Diamond(p1, p2, p3);
  }
  catch (const std::logic_error &e)
  {
    return nullptr;
  }
  catch (const std::bad_alloc &e)
  {
    throw;
  }
  return result;
}
nikonov::Triangle *nikonov::make_triangle(double nums[])
{
  point_t a({ nums[0], nums[1] });
  point_t b({ nums[2], nums[3] });
  point_t c({ nums[4], nums[5] });
  Triangle *result = nullptr;
  try
  {
    result = new Triangle(a, b, c);
  }
  catch (const std::logic_error &e)
  {
    return nullptr;
  }
  catch (const std::bad_alloc &e)
  {
    throw;
  }
  return result;
}
