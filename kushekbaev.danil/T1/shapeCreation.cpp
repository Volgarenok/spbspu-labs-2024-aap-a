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
      in >> arr[i];
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
    return new Concave({arr[0], arr[1]}, {arr[2], arr[3]}, {arr[4], arr[5]}, {arr[6], arr[7]});
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

  void createShape(std::istream& in, Shape** capacity, size_t& shapeCounter, point_t& scalePoint, double& scaleCoeff)
  {
    bool scale_inputed = false;
    try
    {
      std::string shapeName;
      while (in >> shapeName)
      {
        if (shapeName == "RECTANGLE")
        {
          capacity[shapeCounter++] = kushekbaev::makeRectangle(in);
        }
          else if (shapeName == "CONCAVE")
        {
          capacity[shapeCounter++] = kushekbaev::makeConcave(in);
        }
        else if (shapeName == "PARALLELOGRAM")
        {
          capacity[shapeCounter++] = kushekbaev::makeParallelogram(in);
        }
        else if (shapeName == "DIAMOND")
        {
          capacity[shapeCounter++] = kushekbaev::makeDiamond(in);
        }
        else if (shapeName == "SCALE")
        {
          try
          {
            scalePoint = kushekbaev::makeScale(in);
            in >> scaleCoeff;
          }
          catch (const std::logic_error&)
          {
            throw std::logic_error("ERROR: Incorrect scale coefficient\n");
          }
          scale_inputed = true;
          break;
        }
      }
    }
    catch (const std::invalid_argument&)
    {
      throw std::invalid_argument("Some of ined shapes were incorrectly inputed\n");
    }
    catch (const std::bad_alloc&)
    {
      std::cerr << "ERROR: Bad allocation\n";
      kushekbaev::clearMemory(capacity, shapeCounter);
    }

    if (!scale_inputed)
    {
      throw std::logic_error("ERROR: there was no scale\n");
    }
    if (shapeCounter == 0)
    {
      throw std::runtime_error("Shapeless input\n");
    }
  }
}
