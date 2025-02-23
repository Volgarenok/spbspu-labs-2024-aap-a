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

double bocharov::getAllArea(const Shape * const * shapes, size_t shapeCount)
{
  double allArea = 0.0;
  for (size_t i = 0; i < shapeCount; i++)
  {
    allArea += shapes[i]->getArea();
  }
  return allArea;
}

void bocharov::scaling(Shape ** shapes, size_t shapeCount, point_t center, double ratio)
{
  try
  {
    for (size_t i = 0; i < shapeCount; i++)
    {
      point_t cneter = shapes[i]->getFrameRect().pos;
      shapes[i]->move(center);
      point_t center2 = shapes[i]->getFrameRect().pos;
      double diffenceX = (center2.x - cneter.x) * ratio * - 1;
      double diffenceY = (center2.y - cneter.y) * ratio * - 1;
      shapes[i]->scaleCheck(ratio);
      shapes[i]->move(diffenceX, diffenceY);
    }
  }
  catch (const std::invalid_argument &)
  {
    throw std::invalid_argument("under zero ratio with scale");
  }
}

std::size_t bocharov::getShapeInfo(std::istream & input, std::ostream & error, std::ostream & output, Shape ** shapes)
{
  std::string inpStr;
  std::size_t shapesCount = 0;
  point_t scale;
  double ratio = 0;
  bool scaled = false;
  while (input >> inpStr)
  {
    try
    {
      if (inpStr == "RECTANGLE")
      {
        constexpr size_t quantity = 2;
        point_t arrPoint[quantity] = {};
        createPoint(input, quantity, arrPoint);
        shapes[shapesCount] = new Rectangle{arrPoint[0], arrPoint[1]};
        shapesCount++;
      }
      else if (inpStr == "TRIANGLE")
      {
        constexpr size_t quantity = 3;
        point_t arrPoint[quantity] = {};
        createPoint(input, quantity, arrPoint);
        shapes[shapesCount] = new Triangle{arrPoint[0], arrPoint[1], arrPoint[2]};
        shapesCount++;
      }
      else if (inpStr == "PARALLELOGRAM")
      {
        constexpr size_t quantity = 3;
        point_t arrPoint[quantity] = {};
        createPoint(input, quantity, arrPoint);
        shapes[shapesCount] = new Parallelogram{arrPoint[0], arrPoint[1], arrPoint[2]};
        shapesCount++;
      }
      else if (inpStr == "CONCAVE")
      {
        constexpr size_t quantity = 4;
        point_t arrPoint[quantity] = {};
        createPoint(input, quantity, arrPoint);
        shapes[shapesCount] = new Concave{arrPoint[0], arrPoint[1], arrPoint[2], arrPoint[3]};
        shapesCount++;
      }
      else if (inpStr == "SCALE")
      {
        scaled = true;
        break;
      }
    }
    catch (const std::invalid_argument & e)
    {
      error << e.what() << '\n';
    }
  }
  if (!scaled)
  {
    clear(shapes, shapesCount);
    throw std::logic_error("Not entered Scale");
  }
  if (shapesCount == 0)
  {
    error << "No shapes for scale\n";
    return 0;
  }
  input >> scale.x;
  input >> scale.y;
  input >> ratio;
  try
  {
    outputRes(output, shapes, shapesCount);
    output << '\n';
    scaling(shapes, shapesCount, scale, ratio);
    outputRes(output, shapes, shapesCount);
    output << '\n';
  }
  catch (const std::invalid_argument & e)
  {
    clear(shapes, shapesCount);
    return 0;
  }
  return shapesCount;
}

void bocharov::clear(Shape ** shapes, size_t shapeCount)
{
  for (size_t i = 0; i < shapeCount; i++)
  {
    delete shapes[i];
  }
}
