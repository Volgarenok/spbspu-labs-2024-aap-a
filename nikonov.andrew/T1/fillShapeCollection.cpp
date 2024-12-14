#include "fillShapeCollection.hpp"
#include <iostream>
#include <string>
#include "shape.hpp"
#include "fabric.hpp"
#include "scale.hpp"
void nikonov::fillShapeCollection(Shape* collection[], size_t cnt, size_t noncorrect)
{
  std::string name = " ";
  size_t n = 0;
  while (std::cin >> name && name != "SCALE")
  {
    if (name == "RECTANGLE")
    {
      n = 4;
    }
    else if (name == "TRIANGLE" || name == "DIAMOND")
    {
      n = 6;
    }
    float* nums = new float[n];
    for (size_t i = 0; i < n; ++i)
    {
      std::cin >> nums[i];
    }
    if (!std::cin)
    {
      delete[] nums;
      std::cin.clear();
      ++noncorrect;
      continue;
    }
    nikonov::Shape* newElem = nikonov::make_shape(name, nums);
    if (newElem != nullptr)
    {
      collection[cnt] = newElem;
      ++cnt;
    }
    else 
    {
      ++noncorrect;
    }
    delete[] nums;
  }
}