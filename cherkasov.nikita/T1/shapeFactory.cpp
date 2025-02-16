#include "shapeFactory.hpp"
#include "makesShape.hpp"
#include "rectangle.hpp"
#include "square.hpp"
#include "parallelogram.hpp"
#include "diamond.hpp"
#include <iostream>
#include <stdexcept>

namespace cherkasov
{
  Shape* createShape(const std::string& inputCommand, std::istream& input)
  {
    if (inputCommand == "RECTANGLE")
    {
      return cherkasov::getRectangle(input);
    }
    else if (inputCommand == "SQUARE")
    {
      return cherkasov::getSquare(input);
    }
    else if (inputCommand == "PARALLELOGRAM")
    {
      return cherkasov::getParallelogram(input);
    }
    else if (inputCommand == "DIAMOND")
    {
      return cherkasov::getDiamond(input);
    }
    else
    {
      return nullptr;
    }
  }
}
