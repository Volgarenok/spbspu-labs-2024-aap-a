#include "shapeManipulations.hpp"

namespace kushekbaev
{
  double getTotalArea(size_t shapeCounter, CompositeShape** compShape)
  {
    double total = 0;
    for (size_t i = 0; i < shapeCounter; i++)
    {
      if (compShape[i])
      {
        total += compShape[i] -> getArea();
      }
    }
    return total;
  }

  void scaleAll(size_t shapeCounter, point_t scalePoint, double scaleCoeff, CompositeShape** compShape)
  {
    for (size_t i = 0; i < shapeCounter; i++)
    {
      if (compShape[i])
      {
        compShape[i]->scaleEverything(scalePoint, scaleCoeff);
      }
    }
  }

  void scaleSafe(size_t shapeCounter, point_t scalePoint, double scaleCoeff, CompositeShape** compShape)
  {
    if (scaleCoeff <= 0)
    {
      throw std::logic_error("Scale coeffitient must be greater than zero\n");
    }
    scaleAll(shapeCounter, scalePoint, scaleCoeff, compShape);
  }

  void outputCoord(size_t shapeCounter, std::ostream& output, CompositeShape** compShape)
  {
    for (size_t i = 0; i < shapeCounter; ++i)
    {
      if (compShape[i])
      {
        rectangle_t rect = compShape[i]->getFrameRect();
        double leftDownX = rect.pos.x - rect.width / 2;
        double leftDownY = rect.pos.y - rect.height / 2;
        double rightUpX = rect.pos.x + rect.width / 2;
        double rightUpY = rect.pos.y + rect.height / 2;
        output << " " << leftDownX << " " << leftDownY << " " << rightUpX << " " << rightUpY;
      }
    }
  }

  void clearMemory(size_t shapeCounter, CompositeShape** compShape)
  {
    for (size_t i = 0; i < shapeCounter; ++i)
    {
      delete compShape[i];
    }
  }
}
