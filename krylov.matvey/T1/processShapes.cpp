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
  krylov::getArray(in, arr, k);
  krylov::Rectangle* rect = new krylov::Rectangle({arr[0], arr[1]}, {arr[2], arr[3]});
  return rect;
}

krylov::Triangle* krylov::makeTriangle(std::istream &in)
{
  constexpr size_t k = 6;
  double arr[k] = {};
  krylov::getArray(in, arr, k);
  krylov::Triangle* triangle = new krylov::Triangle({arr[0], arr[1]}, {arr[2], arr[3]}, {arr[4], arr[5]});
  return triangle;
}

krylov::Complexquad* krylov::makeComplexquad(std::istream &in)
{
  constexpr size_t k = 8;
  double arr[k] = {};
  krylov::getArray(in, arr, k);
  krylov::Complexquad* cq = new krylov::Complexquad({arr[0], arr[1]}, {arr[2], arr[3]}, {arr[4], arr[5]}, {arr[6], arr[7]});
  return cq;
}

krylov::Ring* krylov::makeRing(std::istream &in)
{
  constexpr size_t k = 4;
  double arr[k] = {};
  krylov::getArray(in, arr, k);
  krylov::Ring* ring = new krylov::Ring({arr[0], arr[1]}, arr[2], arr[3]);
  return ring;
}

krylov::Shape* krylov::makeShape(std::string str, std::istream& in)
{
  krylov::Shape* figure = nullptr;
  try
  {
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
  }
  catch (const std::exception& e)
  {
    throw;
  }
  return figure;
}

void krylov::deleteShapes(krylov::Shape** shapes, const size_t shapeCount)
{
  for (size_t i = 0; i < shapeCount; ++i)
  {
    if (shapes[i] != nullptr)
    {
      delete shapes[i];
    }
  }
}

void krylov::printAreaAndFrameCoords(Shape** shapes, const size_t shapeCount, const double totalArea)
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
