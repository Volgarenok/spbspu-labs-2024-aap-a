#include "shapeFactory.hpp"
#include "rectangle.hpp"
#include "square.hpp"
#include "parallelogram.hpp"
#include "diamond.hpp"

cherkasov::Shape* ShapeFactory::createShape(const std::string& shapeType, std::istream& input)
{
  if (shapeType == "RECTANGLE")
  {
    return getRectangle(input);
  }
  else if (shapeType == "SQUARE")
  {
    return getSquare(input);
  }
  else if (shapeType == "PARALLELOGRAM")
  {
    return getParallelogram(input);
  }
  else if (shapeType == "DIAMOND")
  {
    return getDiamond(input);
  }
  return nullptr;
}

