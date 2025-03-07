#include "createShape.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "diamond.hpp"
#include "outRes.hpp"

double shramko::getEveryArea(Shape** shape, size_t count)
{
  double everyArea = 0.0;
  for (size_t i = 0; i < count; ++i)
  {
    if (shape[i])
    {
      everyArea += shape[i]->getArea();
    }
  }
  return everyArea;
}

void shramko::scaling(Shape** shape, size_t count, point_t centre, double k)
{
  for (size_t i = 0; i < count; i++)
  {
    if (!shape[i])
    {
      continue;
    }

    point_t center = shape[i]->getFrameRect().pos;
    shape[i]->move(centre);
    point_t centreTwo = shape[i]->getFrameRect().pos;

    double diffX = (centreTwo.x - center.x) * k * -1;
    double diffY = (centreTwo.y - center.y) * k * -1;

    shape[i]->scale(k);
    shape[i]->move(diffX, diffY);
  }
}

int shramko::createShape(std::istream& in, std::ostream& err, std::ostream& out, Shape** shape)
{

  constexpr size_t MAX_SHAPES = 10000;
  int count = 0;
  bool isScaled = false;

  try
  {
    std::string str;
    while (in >> str && count < MAX_SHAPES)
    {
      if (str == "RECTANGLE")
      {
        point_t top, bottom;
        if (!(in >> bottom.x >> bottom.y >> top.x >> top.y))
        {
          err << "Invalid rectangle input\n";
          destroy(shape, count);
          return -1;
        }
        shape[count++] = new Rectangle{bottom, top};
      }
      else if (str == "TRIANGLE")
      {
        point_t one, two, three;
        if (!(in >> one.x >> one.y >> two.x >> two.y >> three.x >> three.y))
        {
          err << "Invalid triangle input\n";
          destroy(shape, count);
          return -1;
        }
        shape[count++] = new Triangle{one, two, three};
      }
      else if (str == "DIAMOND")
      {
        point_t one, two, three;
        if (!(in >> one.x >> one.y >> two.x >> two.y >> three.x >> three.y))
        {
          err << "Invalid diamond input\n";
          destroy(shape, count);
          return -1;
        }
        shape[count++] = new Diamond{one, two, three};
      }
      else if (str == "SCALE")
      {
        isScaled = true;
        point_t goCentre;
        double k;
        if (count == 0)
        {
          err << "Nothing to scale\n";
          destroy(shape, count);
          return -1;
        }
        if (!(in >> goCentre.x >> goCentre.y >> k))
        {
          err << "Invalid scale parameters\n";
          destroy(shape, count);
          return -1;
        }
        scaling(shape, count, goCentre, k);
      }
    }
  }
  catch (const std::invalid_argument& e)
  {
    err << e.what() << '\n';
    destroy(shape, count);
    return 1;
  }

  if (!isScaled)
  {
    destroy(shape, count);
    return -1;
  }
  return 0;
}

void shramko::destroy(Shape** shape, size_t count)
{
  if (!shape || count == 0)
  {
    return;
  }

  for (size_t i = 0; i < count; ++i)
  {
    if (shape[i] != nullptr)
    {
      delete shape[i];
      shape[i] = nullptr;
    }
  }
}
