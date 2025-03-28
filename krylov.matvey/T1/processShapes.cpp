#include "processShapes.hpp"
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "rectangle.hpp"
#include "ring.hpp"
#include "triangle.hpp"
#include "complexquad.hpp"

void krylov::getArray(std::istream &in, double *array, const size_t k)
{
  for (size_t i = 0; i < k; ++i)
  {
    in >> array[i];
  }
}

krylov::Rectangle* krylov::makeRectangle(std::istream &in)
{
  constexpr size_t k = 4;
  double arr[k] = {};
  getArray(in, arr, k);
  Rectangle* rect = new Rectangle({arr[0], arr[1]}, {arr[2], arr[3]});
  return rect;
}

krylov::Triangle* krylov::makeTriangle(std::istream &in)
{
  constexpr size_t k = 6;
  double arr[k] = {};
  getArray(in, arr, k);
  Triangle* triangle = new Triangle({arr[0], arr[1]}, {arr[2], arr[3]}, {arr[4], arr[5]});
  return triangle;
}

krylov::Complexquad* krylov::makeComplexquad(std::istream &in)
{
  constexpr size_t k = 8;
  double arr[k] = {};
  getArray(in, arr, k);
  Complexquad* cq = new Complexquad({arr[0], arr[1]}, {arr[2], arr[3]}, {arr[4], arr[5]}, {arr[6], arr[7]});
  return cq;
}

krylov::Ring* krylov::makeRing(std::istream &in)
{
  constexpr size_t k = 4;
  double arr[k] = {};
  getArray(in, arr, k);
  Ring* ring = new Ring({arr[0], arr[1]}, arr[2], arr[3]);
  return ring;
}

void krylov::isoScale(std::istream &in, Shape** shapes, const size_t shapeCount)
{
  constexpr size_t k = 3;
  double arr[k] = {};
  getArray(in, arr, k);
  point_t scaleCenter = {arr[0], arr[1]};
  for (size_t i = 0; i < shapeCount; ++i)
  {
    rectangle_t frameBefore = shapes[i]->getFrameRect();
    shapes[i]->move(scaleCenter);
    shapes[i]->scale(arr[2]);
    rectangle_t frameAfter = shapes[i]->getFrameRect();
    shapes[i]->move((frameBefore.pos.x - frameAfter.pos.x) * arr[2], (frameBefore.pos.y - frameAfter.pos.y) * arr[2]);
  }
}

void krylov::printInfoAboutShapes(const Shape* const* shapes, const size_t shapeCount)
{
  double totalArea = 0.0;
  for (size_t i = 0; i < shapeCount; ++i)
  {
    totalArea += shapes[i]->getArea();
  }
  printAreaAndFrameCoords(shapes, shapeCount, totalArea);
  std::cout << '\n';
}

krylov::Shape* krylov::makeShape(std::string str, std::istream& in)
{
  Shape* figure = nullptr;
  if (str == "RECTANGLE")
  {
    figure = makeRectangle(in);
  }
  else if (str == "TRIANGLE")
  {
    figure = makeTriangle(in);
  }
  else if (str == "COMPLEXQUAD")
  {
    figure = makeComplexquad(in);
  }
  else if (str == "RING")
  {
    figure = makeRing(in);
  }
  else
  {
    throw std::logic_error("Unknown figure");
  }
  return figure;
}

void krylov::deleteShapes(Shape** shapes, const size_t shapeCount)
{
  for (size_t i = 0; i < shapeCount; ++i)
  {
    if (shapes[i] != nullptr)
    {
      delete shapes[i];
    }
  }
}

void krylov::printAreaAndFrameCoords(const Shape* const* shapes, const size_t shapeCount, const double totalArea)
{
  std::cout << std::fixed << std::setprecision(1) << totalArea << ' ';
  for (size_t i = 0; i < shapeCount - 1; ++i)
  {
    rectangle_t frame = shapes[i]->getFrameRect();
    std::cout << frame.pos.x - frame.width / 2 << ' ';
    std::cout << frame.pos.y - frame.height / 2 << ' ';
    std::cout << frame.pos.x + frame.width / 2 << ' ';
    std::cout << frame.pos.y + frame.height / 2 << ' ';
  }
  rectangle_t frame = shapes[shapeCount - 1]->getFrameRect();
  std::cout << frame.pos.x - frame.width / 2 << ' ';
  std::cout << frame.pos.y - frame.height / 2 << ' ';
  std::cout << frame.pos.x + frame.width / 2 << ' ';
  std::cout << frame.pos.y + frame.height / 2;
}
