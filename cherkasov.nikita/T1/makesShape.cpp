#include "makesShape.hpp"
#include <stdexcept>
#include <algorithm>

cherkasov::Rectangle* cherkasov::getRectangle(std::istream& input)
{
  double x1 = 0.0, y1 = 0.0;
  double x2 = 0.0, y2 = 0.0;
  input >> x1 >> y1 >> x2 >> y2;
  if (!input || x1 >= x2 || y1 >= y2)
  {
    throw std::invalid_argument("no input coordinate");
  }
  return new Rectangle(x1, y1, x2, y2);
}
cherkasov::Square* cherkasov::getSquare(std::istream& input)
{
  double x = 0.0, y = 0.0, length = 0.0;
  input >> x >> y >> length;
  if (!input || length <= 0)
  {
    throw std::invalid_argument("no input coordinate");
  }
  return new Square(x, y, length);
}
cherkasov::Parallelogram* cherkasov::getParallelogram(std::istream& input)
{
  double x1 = 0.0;
  double y1 = 0.0;
  double x2 = 0.0;
  double y2 = 0.0;
  double x3 = 0.0;
  double y3 = 0.0;
  input >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  if (!input || (x1 == x3 && y2 == y3) || (x2 == x3 && y1 == y3))
  {
    throw std::invalid_argument("no correct coordinat the parallelogram");
  }
  if (!(y1 == y2 || y1 == y3 || y2 == y3))
  {
    throw std::invalid_argument("sides of the parallelogram must parallel the x");
  }
  return new Parallelogram(x1, y1, x2, y2, x3, y3);
}
cherkasov::Diamond* cherkasov::getDiamond(std::istream& input)
{
  double x1 = 0.0;
  double y1 = 0.0;
  double x2 = 0.0;
  double y2 = 0.0;
  double x3 = 0.0;
  double y3 = 0.0;
  input >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  if (!input || ((x1 == x2 && y1 == y2) && (x1 == x3 && y1 == y3)))
  {
    throw std::invalid_argument("no input coordinat");
  }
  if ((x1 == x2 && y1 == y2) || (x1 == x3 && y1 == y3) || (x2 == x3 && y2 == y3))
  {
    throw std::invalid_argument("the vertices don't have to be equa");
  }
  return new Diamond(x1, y1, x2, y2, x3, y3);
}

