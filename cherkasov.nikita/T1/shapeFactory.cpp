#include "shapeFactory.hpp"
#include "makesShape.hpp"
#include "rectangle.hpp"
#include "square.hpp"
#include "parallelogram.hpp"
#include "diamond.hpp"
#include <iostream>
#include <stdexcept>

cherkasov::Shape* createShape(const std::string& command, std::istream& input)
{
  try
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
  }
  catch (const std::invalid_argument&)
  {
    std::cerr << "invalid input encountered\n";
  }
  return nullptr;
}

