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
  Shape* createShape(const std::string& command, std::istream& input)
  {
    if (command == "RECTANGLE")
    {
      return cherkasov::getRectangle(input);
    }
    else if (command == "SQUARE")
    {
      return cherkasov::getSquare(input);
    }
    else if (command == "PARALLELOGRAM")
    {
      return cherkasov::getParallelogram(input);
    }
    else if (command == "DIAMOND")
    {
      return cherkasov::getDiamond(input);
    }
    else
    {
      return nullptr;
    }
  }
}
