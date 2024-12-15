#include "additional-utilities.hpp"
#include <iostream>
#include <string>
#include <limits>
#include "shape.hpp"
#include "fabric.hpp"
#include "scale.hpp"
void nikonov::fillShapeCollection(Shape* collection[], size_t& cnt, size_t& noncorrect)
{
  std::string name = "";
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
    else
    {
      ++noncorrect;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    float* nums = nullptr;
    try
    {
      nums = new float[n];
    }
    catch(const std::bad_alloc& e)
    {
      std::cerr << e.what() << '\n';
      destoy(collection, cnt);
    }
    for (size_t i = 0; i < n; ++i)
    {
      std::cin >> nums[i];
    }
    if (!std::cin)
    {
      delete[] nums;
      ++noncorrect;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
void nikonov::destoy(Shape* collection[], size_t& cnt)
{
  for (size_t i = 0; i < cnt; ++i)
  {
    delete collection[i];
  }
  cnt = 0;
}
