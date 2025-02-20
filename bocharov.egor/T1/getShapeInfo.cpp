#include "getShapeInfo.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "parallelogram.hpp"
#include "concave.hpp"
#include "outputRes.hpp"

void createPoint(std::istream & input, size_t size, bocharov::point_t * arr)
{
  double coordX = 0;
  double coordY = 0;
  for (size_t i = 0; i < size; ++i)
  {
    input >> coordX >> coordY;
    arr[i] = {coordX, coordY};
  }
}

double bocharov::getAllArea(const Shape * const * myShapes, size_t shapeCount)
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
    throw std::invalid_argument("under zero ratio with scale");
  }
}

std::size_t bocharov::getShapeInfo(std::istream & input, std::ostream & error, std::ostream & output, Shape ** myShapes)
{
  std::string inpStr;
  std::size_t shapesCount = 0;
  bool scaled = false;
  auto handleError = [&](const std::invalid_argument & e)
  {
    error << e.what() << '\n';
  };
  while (input >> inpStr)
  {
    try
    {
      if (inpStr == "RECTANGLE")
      {
        constexpr size_t quantity = 2;
        point_t arrPoint[quantity] = {};
        createPoint(input, quantity, arrPoint);
        myShapes[shapesCount] = new Rectangle{arrPoint[0], arrPoint[1]};
        shapesCount++;
      }
      else if (inpStr == "TRIANGLE")
      {
        constexpr size_t quantity = 3;
        point_t arrPoint[quantity] = {};
        createPoint(input, quantity, arrPoint);
        myShapes[shapesCount] = new Triangle{arrPoint[0], arrPoint[1], arrPoint[2]};
        shapesCount++;
      }
      else if (inpStr == "PARALLELOGRAM")
      {
        constexpr size_t quantity = 3;
        point_t arrPoint[quantity] = {};
        createPoint(input, quantity, arrPoint);
        myShapes[shapesCount] = new Parallelogram{arrPoint[0], arrPoint[1], arrPoint[2]};
        shapesCount++;
      }
      else if (inpStr == "CONCAVE")
      {
        constexpr size_t quantity = 4;
        point_t arrPoint[quantity] = {};
        createPoint(input, quantity, arrPoint);
        myShapes[shapesCount] = new Concave{arrPoint[0], arrPoint[1], arrPoint[2], arrPoint[3]};
        shapesCount++;
      }
    }
    catch (const std::invalid_argument & e)
    {
      handleError(e);
    }
  }
  if (inpStr == "SCALE")
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
      output << '\n';
      scaling(myShapes, shapesCount, toCenter, ratio);
      outputRes(output, myShapes, shapesCount);
      output << '\n';
    }
    catch (const std::invalid_argument & e)
    {
      clear(myShapes, shapesCount);
      return 0;
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
