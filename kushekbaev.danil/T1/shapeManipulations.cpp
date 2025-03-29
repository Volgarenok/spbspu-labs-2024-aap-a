#include "shapeManipulations.hpp"

void kushekbaev::output(std::ostream& out, CompositeShape& compShape, const point_t& scalePoint, double scaleCoeff)
{
  outputSum(out, compShape);
  outputPoints(out, compShape);
  out << "\n";
  scaleNoCheck(compShape, scalePoint, scaleCoeff);
  outputSum(out, compShape);
  outputPoints(out, compShape);
  out << "\n";
}

void kushekbaev::outputSum(std::ostream& out, const CompositeShape& compShape)
{
  double sum = 0;
  for (size_t i = 0; i < compShape.size(); i++)
  {
    sum += compShape[i]->getArea();
  }
  out << sum;
}

void kushekbaev::outputPoints(std::ostream& out, const CompositeShape& compShape)
{
  for (size_t i = 0; i < compShape.size(); i++)
  {
    rectangle_t rec = compShape[i]->getFrameRect();
    double x1 = rec.pos.x - (rec.width / 2);
    double y1 = rec.pos.y - (rec.height / 2);
    double x2 = rec.pos.x + (rec.width / 2);
    double y2 = rec.pos.y + (rec.height / 2);
    out << " " << x1 << " " << y1 << " " << x2 << " " << y2;
  }
}

void kushekbaev::scaleToPoint(Shape* object, const point_t& t, double scaleCoeff)
{
  point_t centr_rec1 = object->getFrameRect().pos;
  object->move(t);
  point_t centr_rec2 = object->getFrameRect().pos;
  double x = centr_rec2.x - centr_rec1.x;
  double y = centr_rec2.y - centr_rec1.y;
  object->scale(scaleCoeff);
  object->move(-(x * scaleCoeff), -(y * scaleCoeff));
}

void kushekbaev::scaleNoCheck(CompositeShape& compShape, const point_t& scalePoint, double scaleCoeff)
{
  for (size_t i = 0; i < compShape.size(); i++)
  {
    scaleToPoint(compShape[i], scalePoint, scaleCoeff);
  }
}

void kushekbaev::scaleCheck(CompositeShape& compShape, const point_t& scalePoint, double scaleCoeff)
{
  if (scaleCoeff <= 0)
  {
    throw std::logic_error("Incorrect scale");
  }
  scaleNoCheck(compShape, scalePoint, scaleCoeff);
}
