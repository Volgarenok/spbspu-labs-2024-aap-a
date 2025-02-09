#include "shapeFactory.hpp"
#include "rectangle.hpp"
#include "square.hpp"
#include "parallelogram.hpp"
#include "diamond.hpp"
#include "makesShape.hpp"
namespace cherkasov
{
  Shape* ShapeFactory::createShape(std::string& inputCommand, std::istream& input)
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
  Shape* ShapeFactory::getRectangle(std::istream& input)
  {
    return new Rectangle(input);
  }
  Shape* ShapeFactory::getSquare(std::istream& input)
  {
    return new Square(input);
  }
  Shape* ShapeFactory::getParallelogram(std::istream& input)
  {
    return new Parallelogram(input);
  }
  Shape* ShapeFactory::getDiamond(std::istream& input)
  {
    return new Diamond(input);
  }
}
