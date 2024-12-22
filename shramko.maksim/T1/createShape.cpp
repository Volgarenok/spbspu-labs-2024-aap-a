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
    point_t center = shape[i]->getRectFrame().pos;
    shape[i]->move(centre);
    point_t centreTwo = shape[i]->getRectFrame().pos;

    double diffX = (centreTwo.x - center.x) * k * - 1;
    double diffY = (centreTwo.y - center.y) * k * - 1;

    shape[i]->scale(k);
    shape[i]->move(diffX, diffY);
  }
}

int shramko::createShape(std::istream& in, std::ostream& err, std::ostream& out, Shape** shape)
{
  std::string stri;
  int count = 0;
  bool isScaled = false;
  try
  {
    while (in >> stri)
    {
      if (stri == "RECTANGLE")
      {
        try
        {
          point_t top, bottom;
          in >> bottom.x;
          in >> bottom.y;
          in >> top.x;
          in >> top.y;
          shape[count] = new Rectangle{bottom, top};
          count++;
        }
        catch (const std::invalid_argument& e)
        {
          err << e.what << '\n';
        }
      }
      else if (stri == "TRIANGLE")
      {
        try
        {
          point_t one, two, three;
          in >> one.x;
          in >> one.y;
          in >> two.x;
          in >> two.y;
          in >> three.x;
          in >> three.y;
          shape[count] = new Triangle{one, two, three};
          count++;
        }
        catch (const std::invalid_argument& e)
        {
          err << e.what << '\n';
        }
      }
      else if (stri == "DIAMOND")
      {
        try
        {
          point_t one, two, three;
          in >> one.x;
          in >> one.y;
          in >> two.x;
          in >> two.y;
          in >> three.x;
          in >> three.y;
          shape[count] = new Diamond{one, two, three};
          count++;
        }
        catch (const std::invalid_argument& e)
        {
          err << e.what << '\n';
        }
      }
      else if (stri == "SCALE")
      {
        isScaled = true;
        if (count == 0)
        {
          err << "Nothing to scale\n";
          return -1;
        }

        point_t goCentre;
        double k;
        in >> goCentre.x;
        in >> goCentre.y;
        in >> k;

        try
        {
          outRes(out, shape, count);
          scaling(shape, count, goCentre, k);
          outRes(out, shape, count);
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
  catch (const std::bad_alloc& e)
  {
    err << e.what() << '\n';
    destroy(shape, count);
    return -1;
  }
  catch (const std::logic_error& e)
  {
    err << e.what() << '\n';
    destroy(shape, count);
    return -1;
  }

  if (!isScaled)
  {
    destroy(shape, count);
    return -1;
  }

  return count;
}

void shramko::clear(Shape** shape, size_t count)
{
  for (size_t i = 0; i < count; i++)
  {
    delete shape[i];
  }
}
