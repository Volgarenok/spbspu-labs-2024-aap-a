#include "shapeCreation.hpp"
#include <iomanip>
#include "shapeBreeding.hpp"
#include "shapeManipulations.hpp"

namespace
{
  double readDoubleInput(const size_t size, double *arr, std::istream& in)
  {
    for (size_t i = 0; i < size; i++)
    {
      if (!(in >> arr[i]))
      {
        throw std::invalid_argument("Invalid input data\n");
      }
    }
    return *arr;
  }
}

namespace kushekbaev
{
  Rectangle* makeRectangle(std::istream& in)
  {
    const size_t size = 4;
    double arr[size];
    readDoubleInput(size, arr, in);
    return new Rectangle({ arr[0], arr[1] }, { arr[2], arr[3] });
  }

  Concave* makeConcave(std::istream& in)
  {
    const size_t size = 8;
    double arr[size];
    readDoubleInput(size, arr, in);
    return new Concave({ arr[0], arr[1] }, { arr[2], arr[3] }, { arr[4], arr[5] }, { arr[6], arr[7] });
  }

  Parallelogram* makeParallelogram(std::istream& in)
  {
    const size_t size = 6;
    double arr[size];
    readDoubleInput(size, arr, in);
    point_t first { arr[0], arr[1] };
    point_t second { arr[2], arr[3] };
    point_t third { arr[4], arr[5] };
    return new Parallelogram({ first, second, third });
  }

  Diamond* makeDiamond(std::istream& in)
  {
    const size_t size = 6;
    double arr[size];
    readDoubleInput(size, arr, in);
    point_t first { arr[0], arr[1] };
    point_t second { arr[2], arr[3] };
    point_t third { arr[4], arr[5] };
    return new Diamond({ first, second, third });
  }

  void createShape(std::istream& in, CompositeShape& compShape, std::string shapeName)
  {
    Shape* shape = nullptr;

    if (shapeName == "RECTANGLE")
    {
      shape = makeRectangle(in);
    }
    else if (shapeName == "CONCAVE")
    {
      shape = makeConcave(in);
    }
    else if (shapeName == "PARALLELOGRAM")
    {
      shape = makeParallelogram(in);
    }
    else if (shapeName == "DIAMOND")
    {
      shape = makeDiamond(in);
    }
    else
    {
      throw std::logic_error("Unsupported shape type\n");
    }
    if (shapeName != "SCALE")
    {
      try
      {
        compShape.push_back(shape);
      }
      catch (const std::bad_alloc& e)
      {
        delete shape;
        throw;
      }
    }
  }
}
