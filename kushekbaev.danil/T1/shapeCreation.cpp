#include "shapeCreation.hpp"
#include <iomanip>
#include "shapeBreeding.hpp"
#include "shapeManipulations.hpp"

namespace
{
  double readDoubleInput(const size_t size, double *arr, std::istream& input)
  {
    for (size_t i = 0; i < size; i++)
    {
      input >> arr[i];
    }
    return *arr;
  }
}

namespace kushekbaev
{
  Rectangle* makeRectangle(std::istream& input)
  {
    const size_t size = 4;
    double arr[size];
    readDoubleInput(4, arr, input);
    return new Rectangle({ arr[0], arr[1] }, { arr[2], arr[3] });
  }

  Concave* makeConcave(std::istream& input)
  {
    point_t first { 0, 0 };
    point_t second { 0, 0 };
    point_t third { 0, 0 };
    point_t last { 0, 0 };
    input >> first.x >> first.y >> second.x >> second.y >> third.x >> third.y >> last.x >> last.y;
    return new Concave({ first, second, third, last });
  }

  Parallelogram* makeParallelogram(std::istream& input)
  {
    point_t first { 0, 0 };
    point_t second { 0, 0 };
    point_t third { 0, 0 };
    input >> first.x >> first.y >> second.x >> second.y >> third.x >> third.y;
    return new Parallelogram({ first, second, third });
  }

  Diamond* makeDiamond(std::istream& input)
  {
    point_t first { 0, 0 };
    point_t second { 0, 0 };
    point_t third { 0, 0 };
    input >> first.x >> first.y >> second.x >> second.y >> third.x >> third.y;
    return new Diamond({ first, second, third });
  }

  void createShape(std::istream& input, Shape** capacity, size_t& shapeCounter, point_t& scalePoint, double& scaleCoeff)
  {
    bool scale_inputed = false;
    try
    {
      std::string shapeName;
      while (input >> shapeName)
      {
        if (shapeName == "RECTANGLE")
        {
          capacity[shapeCounter++] = kushekbaev::makeRectangle(input);
        }
          else if (shapeName == "CONCAVE")
        {
          capacity[shapeCounter++] = kushekbaev::makeConcave(input);
        }
        else if (shapeName == "PARALLELOGRAM")
        {
          capacity[shapeCounter++] = kushekbaev::makeParallelogram(input);
        }
        else if (shapeName == "DIAMOND")
        {
          capacity[shapeCounter++] = kushekbaev::makeDiamond(input);
        }
        else if (shapeName == "SCALE")
        {
          try
          {
            scalePoint = kushekbaev::makeScale(input);
            input >> scaleCoeff;
          }
          catch (const std::out_of_range&)
          {
            throw std::out_of_range("ERROR: Incorrect scale coefficient\n");
          }
          scale_inputed = true;
          break;
        }
      }
    }
    catch (const std::invalid_argument&)
    {
      throw std::invalid_argument("Some of inputed shapes were incorrectly inputed\n");
    }
    catch (const std::bad_alloc&)
    {
      std::cerr << "ERROR: Bad allocation\n";
      kushekbaev::clearMemory(capacity, shapeCounter);
    }

    if (!scale_inputed)
    {
      throw std::out_of_range("ERROR: there was no scale\n");
    }
    if (shapeCounter == 0)
    {
      throw std::runtime_error("Shapeless input\n");
    }
  }
}
