#include <iostream>
#include <string>
#include "shape.hpp"
#include "fabric.hpp"
int main()
{
  std::string name = " ";
  nikonov::Shape* shapeCollection[10000] = { nullptr };
  size_t n = 0, cnt = 0, noncorrect = 0;
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
      shapeCollection[cnt] = newElem;
      ++cnt;
    }
    delete[] nums;
  }
  for (size_t i = 0; i < cnt; ++i)
  {
    delete shapeCollection[i];
  }
}
