#include "makesShape.hpp"
#include <iostream>
#include <stdexcept>
#include <algorithm>

namespace cherkasov
{
  point_t readPoint(std::istream& input)
  {
    double x = 0.0;
    double y = 0.0;
    input >> x >> y;
    if (!input)
    {
      throw std::invalid_argument("no input coordinate");
    }
    point_t point = { x, y };
    return point;
  }
  void readPoints(point_t* vertex, size_t size, std::istream& input)
  {
    for (size_t i = 0; i < size; i++)
    {
      vertex[i] = readPoint(input);
    }
  }
  Rectangle* getRectangle(std::istream& input)
  {
    point_t left = readPoint(input);
    point_t right = readPoint(input);
    Rectangle* rectangle = new Rectangle(left, right);
    return rectangle;
  }
  Square* getSquare(std::istream& input)
  {
    point_t left = readPoint(input);
    double length = 0.0;
    input >> length;
    Square* square = new Square(left, length);
    return square;
  }
  Parallelogram* getParallelogram(std::istream& input)
  {
    point_t vertex[3];
    readPoints(vertex, 3, input);
    Parallelogram* parallelogram = new Parallelogram(vertex[0], vertex[1], vertex[2]);
    return parallelogram;
  }
  Diamond* getDiamond(std::istream& input)
  {
    point_t vertex[3];
    readPoints(vertex, 3, input);
    Diamond* diamond = new Diamond(vertex[0], vertex[1], vertex[2]);
    return diamond;
  }
  Shape* createShape(const std::string& inputCommand, std::istream& input)
  {
    if (inputCommand == "RECTANGLE")
    {
      return getRectangle(input);
    }
    else if (inputCommand == "SQUARE")
    {
      return getSquare(input);
    }
    else if (inputCommand == "PARALLELOGRAM")
    {
      return getParallelogram(input);
    }
    else if (inputCommand == "DIAMOND")
    {
      return getDiamond(input);
    }
    else
    {
      throw std::invalid_argument("incorrect shape");
    }
  }
}
