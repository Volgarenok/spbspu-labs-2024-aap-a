#include "additional-utilities.hpp"
#include <limits>
#include <iomanip>
#include <cmath>
#include "fabric.hpp"
void nikonov::fillShapeCollection(std::istream &input, std::ostream &out, CompositeShape &collection)
{
  std::string name = "";
  while (input >> name && name != "SCALE")
  {
    Shape *newElem = nullptr;
    try
    {
      newElem = make_shape(input, name);
      collection.push_back(newElem);
    }
    catch (const std::logic_error &e)
    {
      out << e.what() << '\n';
    }
    catch (const std::runtime_error &e)
    {
      input.clear();
      input.ignore(std::numeric_limits< std::streamsize >::max(), '\n');
    }
  }
}
void nikonov::destroy(Shape **collection, size_t cnt)
{
  for (size_t i = 0; i < cnt; ++i)
  {
    delete collection[i];
  }
}
void nikonov::ispScale(Shape &shp, double x, double y, double k)
{
  point_t s({ x, y });
  point_t origCenter = shp.getFrameRect().pos;
  shp.move(s);
  point_t newCenter = shp.getFrameRect().pos;
  double diffX = newCenter.x - origCenter.x;
  double diffY = newCenter.y - origCenter.y;
  shp.scale(k);
  shp.move(diffX * k * (-1), diffY * k * (-1));
}
void nikonov::scaleCollection(CompositeShape &collection, double x, double y, double k)
{
  if (k <= 0)
  {
    throw std::logic_error("ERROR: noncorrect scale parameters");
  }
  for (size_t i = 0; i < collection.size(); ++i)
  {
    ispScale(*collection[i], x, y, k);
  }
}
void nikonov::outputCollection(std::ostream &out, CompositeShape &collection)
{
  out << std::fixed << std::setprecision(1);
  double summArea = collection.getArea();
  out << summArea;
  for (size_t i = 0; i < collection.size(); ++i)
  {
    rectangle_t tempRect = collection[i]->getFrameRect();
    out << " " << tempRect.pos.x - tempRect.width / 2;
    out << " " << tempRect.pos.y - tempRect.height / 2;
    out << " " << tempRect.pos.x + tempRect.width / 2;
    out << " " << tempRect.pos.y + tempRect.height / 2;
  }
  out << '\n';
}
void nikonov::processCollection(std::istream &input, std::ostream &out, CompositeShape &collection)
{
  if (collection.size() == 0)
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
  outputCollection(out, collection);
  scaleCollection(collection, x, y, k);
  outputCollection(out, collection);
}
double nikonov::getSegmentLength(const point_t &a, const point_t &b)
{
  return std::sqrt(std::pow(b.x - a.x, 2) + std::pow(b.y - a.y, 2));
}
void nikonov::scalePoint(point_t &pt, point_t &center, double k)
{
  pt.x = center.x + (pt.x - center.x) * k;
  pt.y = center.y + (pt.y - center.y) * k;
}
