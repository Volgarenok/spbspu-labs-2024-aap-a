#include "additional-utilities.hpp"
#include <iostream>
#include <limits>
#include <iomanip>
#include <dynamicArray.hpp>
#include "shape.hpp"
#include "fabric.hpp"
void nikonov::fillShapeCollection(Shape* collection[], size_t& cnt, size_t& noncorrect)
{
  std::string name = "";
  size_t n = 0;
  while (std::cin >> name && name != "SCALE")
  {
    if (name[0] == '\n')
    {
      continue;
    }
    else if (name == "RECTANGLE")
    {
      n = 4;
    }
    else if (name == "TRIANGLE" || name == "DIAMOND")
    {
      n = 6;
    }
    else
    {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    }
    double * nums = nullptr;
    try
    {
      nums = new double [n];
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
void nikonov::ispScale(Shape* shp, double  x, double  y, double  k)
{
  point_t S(x, y);
  point_t origCenter = shp->getFrameRect().pos;
  shp->move(S);
  point_t newCenter = shp->getFrameRect().pos;
  double  diffX = newCenter.x - origCenter.x;
  double  diffY = newCenter.y - origCenter.y;
  shp->scale(k);
  shp->move(diffX * k * (-1), diffY * k * (-1));
}
bool nikonov::processCollection(Shape* collection[], size_t cnt)
{
  if (cnt == 0)
  {
    std::cerr << "ERROR: nothing to scale\n";
    return 1;
  }
  double  x = 0.0, y = 0.0;
  double  k = 0.0;
  std::cin >> x >> y >> k;
  if ((!std::cin && !std::cin.eof()) || k <= 0) {
    std::cerr << "ERROR: noncorrect scale parameters\n";
    nikonov::destoy(collection, cnt);
    return 1;
  }
  double  s1 = 0.0, s2 = 0.0;
  std::cout << std::fixed << std::setprecision(1);
  for (size_t i = 0; i < cnt; ++i)
  {
    s1 += collection[i]->getArea();
  }
  std::cout << s1;
  for (size_t i = 0; i < cnt; ++i)
  {
    nikonov::rectangle_t tempRect = collection[i]->getFrameRect();
    std::cout << " " << tempRect.pos.x - tempRect.width / 2;
    std::cout << " " << tempRect.pos.y - tempRect.height / 2;
    std::cout << " " << tempRect.pos.x + tempRect.width / 2;
    std::cout << " " << tempRect.pos.y + tempRect.height / 2;
  }
  std::cout << '\n';
  for (size_t i = 0; i < cnt; ++i)
  {
    nikonov::ispScale(collection[i], x, y, k);
    s2 += collection[i]->getArea();
  }
  std::cout << s2;
  for (size_t i = 0; i < cnt; ++i)
  {
    nikonov::rectangle_t tempRect = collection[i]->getFrameRect();
    std::cout << " " << tempRect.pos.x - tempRect.width / 2;
    std::cout << " " << tempRect.pos.y - tempRect.height / 2;
    std::cout << " " << tempRect.pos.x + tempRect.width / 2;
    std::cout << " " << tempRect.pos.y + tempRect.height / 2;
  }
  std::cout << '\n';
  return 0;
}
