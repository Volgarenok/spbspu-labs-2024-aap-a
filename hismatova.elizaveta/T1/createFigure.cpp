#include "createFigure.hpp"
#include <iostream>
#include <stdexcept>

namespace hismatova
{
  void readPoints(std::istream& in, double* points, int size)
  {
    for (int i = 0; i < size; ++i)
    {
      if (!(in >> points[i]))
      {
        throw std::invalid_argument("Invalid input for points");
      }
    }
  }
}
hismatova::Rectangle* hismatova::createRectangle(std::istream& in)
{
  double coordinates[4];
  readPoints(in, coordinates, 4);
  Rectangle* rectangle_ = new Rectangle(
    { coordinates[0], coordinates[1] },
    { coordinates[2], coordinates[3] }
  );
  return rectangle_;
}
hismatova::Triangle* hismatova::createTriangle(std::istream& in)
{
  double coordinates[6];
  readPoints(in, coordinates, 6);
  Triangle* triangle_ = new Triangle(
    { coordinates[0], coordinates[1] },
    { coordinates[2], coordinates[3] },
    { coordinates[4], coordinates[5] }
  );
  return triangle_;
}
hismatova::Concave* hismatova::createConcave(std::istream& in)
{
  double coordinates[8];
  readPoints(in, coordinates, 8);
  Concave* concave_ = new Concave(
    { coordinates[0], coordinates[1] },
    { coordinates[2], coordinates[3] },
    { coordinates[4], coordinates[5] },
    { coordinates[6], coordinates[7] }
  );
  return concave_;
}
