#include "additional-utilities.hpp"
#include <iostream>
#include <string>
#include <limits>
#include "shape.hpp"
#include "fabric.hpp"
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
void nikonov::ispScale(Shape* shp, float x, float y, float k)
{
  point_t S(x, y);
  point_t origCenter = shp->getFrameRect().pos_;
  shp->move(S);
  point_t newCenter = shp->getFrameRect().pos_;
  float diffX = newCenter.x_ - origCenter.x_;
  float diffY = newCenter.y_ - origCenter.y_;
  shp->scale(k);
  shp->move(diffX * k * (-1), diffY * k * (-1));
}
bool nikonov::processCollection(Shape* collection[], size_t cnt)
{
  float x = 0.0, y = 0.0;
  float k = 0.0;
  std::cin >> x >> y >> k;
  if (!std::cin || k <= 0) {
    std::cerr << "ERROR: noncorrect scale parameters\n";
    nikonov::destoy(collection, cnt);
    return 1;
  }
  float s1 = 0.0, s2 = 0.0;
  for (size_t i = 0; i < cnt; ++i)
  {
    s1 += collection[i]->getArea();
  }
  for (size_t i = 0; i < cnt; ++i)
  {
    std::cout << s1 << ' ';
    nikonov::rectangle_t tempRect = collection[i]->getFrameRect();
    std::cout << tempRect.pos_.x_ - tempRect.width_ / 2 << " ";
    std::cout << tempRect.pos_.y_ - tempRect.height_ / 2 << " ";
    std::cout << tempRect.pos_.x_ + tempRect.width_ / 2 << " ";
    std::cout << tempRect.pos_.y_ + tempRect.height_ / 2 << '\n';
  }
  for (size_t i = 0; i < cnt; ++i)
  {
    nikonov::ispScale(collection[i], x, y, k);
    s2 += collection[i]->getArea();
  }
  for (size_t i = 0; i < cnt; ++i)
  {
    std::cout << s2 << ' ';
    nikonov::rectangle_t tempRect = collection[i]->getFrameRect();
    std::cout << tempRect.pos_.x_ - tempRect.width_ / 2 << " ";
    std::cout << tempRect.pos_.y_ - tempRect.height_ / 2 << " ";
    std::cout << tempRect.pos_.x_ + tempRect.width_ / 2 << " ";
    std::cout << tempRect.pos_.y_ + tempRect.height_ / 2 << '\n';
  }
  return 0;
}
