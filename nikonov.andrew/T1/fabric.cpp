#include "fabric.hpp"
#include <iostream>
#include <cmath>
#include <string>
#include <exception>
#include "shape.hpp"
#include "rectangle.hpp"
#include "additional-utilities.hpp"
#include "diamond.hpp"
#include "triangle.hpp"
namespace 
{
  nikonov::point_t findTop(nikonov::point_t p1, nikonov::point_t p2, nikonov::point_t p3);
  nikonov::point_t findMid(nikonov::point_t p1, nikonov::point_t p2, nikonov::point_t p3, nikonov::point_t topP);
  bool isEqualPoint(const nikonov::point_t &p1, const nikonov::point_t &p2);
}
nikonov::Shape *nikonov::make_shape(std::string name, double nums[])
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
  if (nums[0] >= nums[2] || nums[1] >= nums[3])
  {
    return nullptr;
  }
  point_t lbp({ nums[0], nums[1] });
  point_t rtp({ nums[2], nums[3] });
  Rectangle *result = new Rectangle(lbp, rtp);
  return result;
}
nikonov::Diamond *nikonov::make_diamond(double nums[])
{
  point_t p1({ nums[0], nums[1] });
  point_t p2({ nums[2], nums[3] });
  point_t p3({ nums[4], nums[5] });
  point_t topP({ 0, 0 });
  point_t edgeP({ 0, 0 });
  point_t midP({ 0, 0 });
  try
  {
    topP = findTop(p1, p2, p3);
  }
  catch (const std::exception &e)
  {
    return nullptr;
  }
  try
  {
    midP = findMid(p1, p2, p3, topP);
  }
  catch (const std::exception &e)
  {
    return nullptr;
  }
  if (!isEqualPoint(p1, topP) && !isEqualPoint(p1, midP))
  {
    edgeP = p1;
  }
  else if (!isEqualPoint(p2, topP) && !isEqualPoint(p2, midP))
  {
    edgeP = p2;
  }
  else
  {
    edgeP = p3;
  }
  if (edgeP.x < midP.x)
  {
    edgeP.x = 2 * midP.x - edgeP.x;
  }
  if (!(topP.x == midP.x && edgeP.y == midP.y))
  {
    return nullptr;
  }
  Diamond *result = new Diamond(topP, midP, edgeP);
  return result;
}
nikonov::Triangle *nikonov::make_triangle(double nums[])
{
  double AB = std::sqrt(std::pow(nums[2] - nums[0], 2) + std::pow(nums[3] - nums[1], 2));
  double BC = std::sqrt(std::pow(nums[4] - nums[2], 2) + std::pow(nums[5] - nums[3], 2));
  double CA = std::sqrt(std::pow(nums[4] - nums[0], 2) + std::pow(nums[5] - nums[1], 2));
  if (!((AB + BC > CA) && (AB + CA > BC) && (CA + BC > AB)))
  {
    return nullptr;
  }
  point_t A({ nums[0], nums[1] });
  point_t B({ nums[2], nums[3] });
  point_t C({ nums[4], nums[5] });
  Triangle *result = new Triangle(A, B, C);
  return result;
}

namespace 
{
  nikonov::point_t findTop(nikonov::point_t p1, nikonov::point_t p2, nikonov::point_t p3)
  {
    if (p1.y > p2.y && p1.y > p3.y)
    {
      return p1;
    }
    else if (p2.y > p1.y && p2.y > p3.y)
    {
      return p2;
    }
    else if (p3.y > p1.y && p3.y > p2.y)
    {
      return p3;
    }
    else
    {
      throw std::logic_error("non-correct parameters\n");
    }
  }
  nikonov::point_t findMid(nikonov::point_t p1, nikonov::point_t p2, nikonov::point_t p3, nikonov::point_t topP)
  {
    if (p1.y < topP.y && p1.x == topP.x)
    {
      return p1;
    }
    else if (p2.y < topP.y && p2.x == topP.x)
    {
      return p2;
    }
    else if (p3.y < topP.y && p3.x == topP.x)
    {
      return p3;
    }
    else
    {
      throw std::exception();
    }
  }
  bool isEqualPoint(const nikonov::point_t &p1, const nikonov::point_t &p2)
  {
    return (p1.x == p2.x) && (p1.y == p2.y);
  }
}
