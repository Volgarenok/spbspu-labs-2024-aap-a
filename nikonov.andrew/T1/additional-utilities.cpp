#include "additional-utilities.hpp"
#include <limits>
#include <iomanip>
#include "shape.hpp"
#include "fabric.hpp"
void nikonov::fillShapeCollection(std::istream &input, Shape **collection, size_t &cnt, size_t &noncorrect)
{
  std::string name = "";
  size_t n = 0;
  constexpr size_t rectangleParametersNum = 4;
  constexpr size_t triangleOrDiamondParametersNum = 6;
  size_t maxNum = std::max(rectangleParametersNum, triangleOrDiamondParametersNum);
  double *nums = new double[maxNum];
  while (input >> name && name != "SCALE")
  {
    if (name[0] == '\n')
    {
      continue;
    }
    else if (name == "RECTANGLE")
    {
      n = rectangleParametersNum;
    }
    else if (name == "TRIANGLE" || name == "DIAMOND")
    {
      n = triangleOrDiamondParametersNum;
    }
    else
    {
      input.clear();
      input.ignore(std::numeric_limits< std::streamsize >::max(), '\n');
      continue;
    }
    for (size_t i = 0; i < n; ++i)
    {
      input >> nums[i];
    }
    if (!input)
    {
      ++noncorrect;
      input.clear();
      input.ignore(std::numeric_limits< std::streamsize >::max(), '\n');
      continue;
    }
    Shape *newElem = make_shape(name, nums);
    if (newElem != nullptr)
    {
      collection[cnt] = newElem;
      ++cnt;
    }
    else
    {
      ++noncorrect;
    }
  }
  delete []nums;
}
void nikonov::destoy(Shape **collection, size_t cnt)
{
  for (size_t i = 0; i < cnt; ++i)
  {
    delete collection[i];
  }
}
void nikonov::ispScale(Shape *shp, double x, double y, double k)
{
  point_t S({ x, y });
  point_t origCenter = shp->getFrameRect().pos;
  shp->move(S);
  point_t newCenter = shp->getFrameRect().pos;
  double diffX = newCenter.x - origCenter.x;
  double diffY = newCenter.y - origCenter.y;
  shp->scale(k);
  shp->move(diffX * k * (-1), diffY * k * (-1));
}
double nikonov::getCollectionArea(Shape **collection, size_t cnt)
{
  double summ = 0.0;
  for (size_t i = 0; i < cnt; ++i)
  {
    summ += collection[i]->getArea();
  }
  return summ;
}
void nikonov::scaleCollection(Shape **collection, size_t cnt, double x, double y, double k)
{
  if (k <= 0)
  {
    throw std::logic_error("ERROR: noncorrect scale parameters");
  }
  for (size_t i = 0; i < cnt; ++i)
  {
    ispScale(collection[i], x, y, k);
  }
}
void nikonov::outputCollection(std::ostream &out, Shape **collection, size_t cnt)
{
  out << std::fixed << std::setprecision(1);
  double summArea = getCollectionArea(collection, cnt);
  out << summArea;
  for (size_t i = 0; i < cnt; ++i)
  {
    rectangle_t tempRect = collection[i]->getFrameRect();
    out << " " << tempRect.pos.x - tempRect.width / 2;
    out << " " << tempRect.pos.y - tempRect.height / 2;
    out << " " << tempRect.pos.x + tempRect.width / 2;
    out << " " << tempRect.pos.y + tempRect.height / 2;
  }
  out << '\n';
}
void nikonov::processCollection(std::istream &input, std::ostream &out, Shape **collection, size_t cnt)
{
  if (cnt == 0)
  {
    throw std::logic_error("ERROR: nothing to scale");
  }
  double x = 0.0;
  double y = 0.0;
  double k = 0.0;
  input >> x >> y >> k;
  if (!input || k <= 0)
  {
    throw std::logic_error("ERROR: noncorrect scale parameters");
  }
  outputCollection(out, collection, cnt);
  scaleCollection(collection, cnt, x, y, k);
  outputCollection(out, collection, cnt);
}
