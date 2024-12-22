#include "InputHandler.h"
#include "rectangle.h"
#include "square.h"
#include "parallelogram.h"
#include "diamond.h"
#include <iostream>
cherkasov::Shape* parseShapeInput(const std::string& inputCommand, bool& invalidInput)
{
  if (inputCommand == "RECTANGLE")
  {
    double x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    if (x1 >= x2 || y1 >= y2)
    {
      invalidInput = true;
    }
    return new cherkasov::Rectangle(x1, y1, x2, y2);
  }
  else if (inputCommand == "SQUARE")
  {
    double x1, y1, length;
    std::cin >> x1 >> y1 >> length;
    if (length <= 0)
    {
      invalidInput = true;
    }
    return new cherkasov::Square(x1, y1, length);
  }
  else if (inputCommand == "PARALLELOGRAM")
  {
    double x1, y1, x2, y2, x3, y3;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    if ((x1 == x2 && y1 == y2) || (x1 == x3 && y1 == y3))
    {
      invalidInput = true;
    }
    return new cherkasov::Parallelogram(x1, y1, x2, y2, x3, y3);
  }
  else if (inputCommand == "DIAMOND")
  {
    double x1, y1, x2, y2, x3, y3;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    if ((x1 == x2 && y1 == y2) || (x1 == x3 && y1 == y3))
    {
      invalidInput = true;
    }
    return new cherkasov::Diamond(x1, y1, x2, y2, x3, y3);
  }
  invalidInput = true;
  return nullptr;
}

