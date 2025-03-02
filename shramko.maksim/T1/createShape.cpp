#include "createShape.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "diamond.hpp"
#include "outRes.hpp"

double shramko::getEveryArea(Shape** shape, size_t count)
{
  double everyArea = 0.0;
  for (size_t i = 0; i < count; i++)
  {
    everyArea += shape[i]->getArea();
  }
  return everyArea;
}

void shramko::scaling(Shape** shape, size_t count, point_t centre, double k)
{
  for (size_t i = 0; i < count; i++)
  {
    point_t center = shape[i]->getFrameRect().pos;
    shape[i]->move(centre);
    point_t centreTwo = shape[i]->getFrameRect().pos;

    double diffX = (centreTwo.x - center.x) * k * - 1;
    double diffY = (centreTwo.y - center.y) * k * - 1;

    shape[i]->scale(k);
    shape[i]->move(diffX, diffY);
  }
}

int shramko::createShape(std::istream& in, std::ostream& err, std::ostream& out, Shape** shape)
{
  std::string str;
  int count = 0;
  bool isScaled = false;

  try
  {
    while (in >> str)
    {
      if (str == "RECTANGLE")
      {
        try
        {
          point_t top, bottom;
          in >> bottom.x >> bottom.y >> top.x >> top.y;
          shape[count] = new Rectangle{bottom, top};
          count++;
        }
        catch (const std::invalid_argument& e)
        {
          err << e.what() << '\n';
        }
      }
      else if (str == "TRIANGLE")
      {
        try
        {
          point_t one, two, three;
          in >> one.x >> one.y;
          in >> two.x >> two.y;
          in >> three.x >> three.y;
          shape[count] = new Triangle{one, two, three};
          count++;
        }
        catch (const std::invalid_argument& e)
        {
          err << e.what() << '\n';
        }
      }
      else if (str == "DIAMOND")
      {
        try
        {
          point_t one, two, three;
          in >> one.x >> one.y;
          in >> two.x >> two.y;
          in >> three.x >> three.y;
          shape[count] = new Diamond{one, two, three};
          count++;
        }
        catch (const std::invalid_argument& e)
        {
          err << e.what() << '\n';
        }
      }
      else if (str == "SCALE")
      {
        isScaled = true;
        if (count == 0)
        {
          err << "Nothing to scale\n";
          return -1;
        }

        point_t goCentre;
        double k;
        in >> goCentre.x >> goCentre.y >> k;

        try
        {
          scaling(shape, count, goCentre, k);
        }
        catch (const std::invalid_argument& e)
        {
          err << e.what() << '\n';
          destroy(shape, count);
          return -1;
        }
      }
    }
  }
  catch (const std::runtime_error& e)
  {
    err << e.what() << '\n';
    destroy(shape, count);
    return -1;
  }

  if (isScaled)
  {
    outRes(out, shape, count);
  }

  destroy(shape, count);
  return count;
}

void shramko::destroy(Shape** shape, size_t count)
{
  for (size_t i = 0; i < count; i++)
  {
    delete shape[i];
  }
}
