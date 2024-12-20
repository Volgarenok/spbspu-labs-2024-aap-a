#include "createShape.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "diamond.hpp"
#include "outRes.hpp"

double shramko::getArea(Shape** shapes, size_t count)
{
  double area = 0.0;
  for (size_t i = 0; i < count; i ++)
  {
    area += shapes[i]->getArea();
  }
  return area;
}

void shramko::scaling(Shape** shapes, size_t count, point_t centre, double k)
{
  for (size_t i = 0; i < count; i++)
  {
    point_t centre = shapes[i]->getRectangleFrame().pos;
    shapes[i]->move(centre);
    point_t centreTwo = shapes[i]->getRectangleFrame().pos;

    double diffX = (centreTwo.x - centre.x) * k * - 1;
    double diffY = (centreTwo.y - centre.y) * k * - 1;

    shapes[i]->scale(k);
    shapes[i]->move(diffX, diffY);
  }
}

int shramko::createShape(std::istream& in, std::ostream& err, std::ostream& out, Shape** shapes)
{
  std::string str;
  size_t count = 0;
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
          in >> bottom.x;
          in >> bottom.y;
          in >> top.x;
          in >> top.y;
          shapes[count] = new Rectangle{bottom, top};
          count++;
        }
        catch (const std::invalid_argument& e)
        {
          err << e.what << '\n';
        }
      }
      else if (str == "TRIANGLE")
      {
        try
        {
          point_t One, Two, Three;
          in >> One.x;
          in >> One.y;
          in >> Two.x;
          in >> Two.y;
          in >> Three.x;
          in >> Three.y;
          shapes[count] = new Triangle{One, Two, Three};
          count++;
        }
        catch (const std::invalid_argument& e)
        {
          err << e.what << '\n';
        }
      }
      else if (str == "DIAMOND")
      {
        try
        {
          point_t One, Two, Three;
          in >> One.x;
          in >> One.y;
          in >> Two.x;
          in >> Two.y;
          in >> Three.x;
          in >> Three.y;
          shapes[count] = new Diamond{One, Two, Three};
          count++;
        }
        catch (const std::invalid_argument& e)
        {
          err << e.what << '\n';
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
        in >> goCentre.x;
        in >> goCentre.y;
        in >> k;

        try
        {
          outRes(out, shapes, count);
          scaling(shapes, count, goCentre, k);
          outRes(out, shapes, count);
        }
        catch (const std::invalid_argument& e)
        {
          err << e.what() << '\n';
          clear(shapes, count);
          return -1;
        }
      }
    }
  }
  catch (const std::bad_alloc& e)
  {
    err << e.what() << '\n';
    clear(shapes, count);
    return -1;
  }
  catch (const std::logic_error& e)
  {
    err << e.what() << '\n';
    clear(shapes, count);
    return -1;
  }

  if (!isScaled)
  {
    clear(shapes, count);
    return -1;
  }

  return count;
}

void shramko::clear(Shape** shapes, size_t count)
{
  for (size_t i = 0; i < count; i++)
  {
    delete shapes[i];
  }
}
