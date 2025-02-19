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
        compShape[i]->scaleEverything(**compShape, scalePoint, scaleCoeff);
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

  void outputCoord(std::ostream& out, CompositeShape** compShape)
  {
    if (compShape && *compShape)
    {
      CompositeShape* compShapePtr = *compShape;
      size_t shapeCounter = compShapePtr->size();
      for (size_t i = 0; i < shapeCounter; ++i)
      {
        if (compShapePtr->at(i))
        {
          rectangle_t rect = compShapePtr->at(i)->getFrameRect();
          double leftDownX = rect.pos.x - rect.width / 2;
          double leftDownY = rect.pos.y - rect.height / 2;
          double rightUpX = rect.pos.x + rect.width / 2;
          double rightUpY = rect.pos.y + rect.height / 2;
          out << " " << leftDownX << " " << leftDownY << " " << rightUpX << " " << rightUpY;
        }
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

  void printFrameCoordinates(std::ostream& out, const CompositeShape* compShape)
  {
    if (compShape && compShape->size() > 0)
    {
      for (size_t i = 0; i < compShape->size(); ++i)
      {
        rectangle_t frame = compShape->at(i)->getFrameRect();
        double leftx = frame.pos.x - frame.width / 2.0;
        double lefty = frame.pos.y - frame.height / 2.0;
        double rightx = frame.pos.x + frame.width / 2.0;
        double righty = frame.pos.y + frame.height / 2.0;
        out << leftx << " " << lefty << " " << rightx << " " << righty;
        if (i < compShape->size() - 1)
        {
          out << " ";
        }
      }
    }
  }
}
