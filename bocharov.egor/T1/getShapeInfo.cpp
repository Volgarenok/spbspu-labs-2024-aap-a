#include "getShapeInfo.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "parallelogram.hpp"
#include "concave.hpp"
#include "outputRes.hpp"

double bocharov::getAllArea(Shape ** myShapes, size_t shapeCount)
{
  double allArea = 0.0;
  for (size_t i = 0; i < shapeCount; i++)
  {
    allArea += myShapes[i]->getArea();
  }
  return allArea;
}

void bocharov::scaling(Shape ** myShapes, size_t shapeCount, point_t center, double ratio)
{
  try
  {
    for (size_t i = 0; i < shapeCount; i++)
    {
      point_t cneter = myShapes[i]->getFrameRect().pos;
      myShapes[i]->move(center);
      point_t center2 = myShapes[i]->getFrameRect().pos;
      double diffenceX = (center2.x - cneter.x) * ratio * - 1;
      double diffenceY = (center2.y - cneter.y) * ratio * - 1;
      myShapes[i]->scaleCheck(ratio);
      myShapes[i]->move(diffenceX, diffenceY);
    }
  }
  catch (const std::invalid_argument &)
  {
    throw std::invalid_argument("under zero ratio with scale\n");
  }
}

std::size_t bocharov::getShapeInfo(std::istream & input, std::ostream & error, std::ostream & output, Shape ** myShapes)
{
  std::string myStr;
  std::size_t shapesCount = 0;
  bool scaled = false;
  auto handleError = [&](const std::invalid_argument & e)
  {
    error << e.what() << '\n';
  };
  while (input >> myStr)
  {
    try
    {
      if (myStr == "RECTANGLE")
      {
        point_t down, up;
        input >> down.x;
        input >> down.y;
        input >> up.x;
        input >> up.y;
        myShapes[shapesCount] = new Rectangle{down, up};
        shapesCount++;
      }
      else if (myStr == "TRIANGLE")
      {
        point_t a, b, c;
        input >> a.x;
        input >> a.y;
        input >> b.x;
        input >> b.y;
        input >> c.x;
        input >> c.y;
        myShapes[shapesCount] =  new Triangle{a, b, c};
        shapesCount++;
      }
      else if (myStr == "PARALLELOGRAM")
      {
        point_t a, b, c;
        input >> a.x;
        input >> a.y;
        input >> b.x;
        input >> b.y;
        input >> c.x;
        input >> c.y;
        bool correct_parallelogram = ((a.y == b.y) && (a.y != c.y)) || ((b.y == c.y) && (a.y != b.y));
        if (!correct_parallelogram)
        {
          throw std::invalid_argument("Error in PARALLELOGRAM parameters");
        }
        myShapes[shapesCount] =  new Parallelogram{a, b, c};
        shapesCount++;
      }
      else if (myStr == "CONCAVE")
      {
        point_t a, b, c, d;
        input >> a.x;
        input >> a.y;
        input >> b.x;
        input >> b.y;
        input >> c.x;
        input >> c.y;
        input >> d.x;
        input >> d.y;
        myShapes[shapesCount] =  new Concave{a, b, c, d};
        shapesCount++;
      }
      else if (myStr == "SCALE")
      {
        scaled = true;
        if (shapesCount == 0)
        {
          error << "No shapes for scale\n";
          return 0;
        }
        point_t toCenter;
        double ratio;
        input >> toCenter.x;
        input >> toCenter.y;
        input >> ratio;
        try
        {
          outputRes(output, myShapes, shapesCount);
          scaling(myShapes, shapesCount, toCenter, ratio);
          outputRes(output, myShapes, shapesCount);
        }
        catch (const std::invalid_argument & e)
        {
          clear(myShapes, shapesCount);
          return 0;
        }
      }
    }
    catch (const std::invalid_argument & e)
    {
      handleError(e);
    }
  }
  if (!scaled)
  {
    clear(myShapes, shapesCount);
    return 0;
  }
  return shapesCount;
}
void bocharov::clear(Shape ** myshape, size_t shapeCount)
{
  for (size_t i = 0; i < shapeCount; i++)
  {
    delete myshape[i];
  }
}
