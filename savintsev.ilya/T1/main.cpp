#include <iostream>
#include <cstring>
#include <newlineterminatedstr.h>
#include "composite-shape.hpp"
#include "shape-utils.hpp"

namespace
{
  void readDescription(double * numbers)
  {
    char * token = std::strtok(nullptr, " ");
    size_t i = 0;
    while (token)
    {
      numbers[i++] = std::atof(token);
      token = std::strtok(nullptr, " ");
    }
  }
}

int main()
{
  using namespace savintsev;
  char * line = nullptr;
  bool was_error = false;
  bool was_scale = false;
  CompositeShape figure(4);
  double params[8] = {};
  point_t scalePoint = {};
  double scaleRatio = 0;
  while (!was_scale && !std::cin.eof())
  {
    delete[] line;
    line = inputNewlineTerminatedStr(std::cin);
    if (line == nullptr)
    {
      std::cerr << "ERROR: Memory collapse\n";
      return 2;
    }
    if (line[0] == '\0')
    {
      continue;
    }
    char * type = std::strtok(line, " ");
    Shape * createdShape = nullptr;
    try
    {
      if (!std::strcmp(type, "RECTANGLE") || !std::strcmp(type, "COMPLEXQUAD") || !std::strcmp(type, "CONCAVE"))
      {
        readDescription(params);
        createdShape = createShape(line, params);
        figure.push_back(createdShape);
      }
    }
    catch (const std::invalid_argument & e)
    {
      was_error = true;
      continue;
    }
    catch (const std::bad_alloc & e)
    {
      delete[] line;
      delete createdShape;
      std::cerr << "ERROR: Memory collapse\n";
      return 2;
    }
    if (!std::strcmp(type, "SCALE"))
    {
      readDescription(params);
      scalePoint = {params[0], params[1]};
      scaleRatio = params[2];
      if (scaleRatio <= 0)
      {
        continue;
      }
      was_scale = true;
    }
  }
  delete[] line;
  if (figure.empty())
  {
    std::cerr << "ERROR: No shapes\n";
    return 2;
  }
  if (std::cin.eof())
  {
    std::cerr << "ERROR: EOF is not implemented\n";
    return 2;
  }
  printAreaAndBorder(std::cout, figure);
  figure.unsafeScaleRelativeTo(scaleRatio, scalePoint);
  printAreaAndBorder(std::cout, figure);
  if (was_error)
  {
    std::cerr << "WARNING: Some shapes were ignored because they were described incorrectly\n";
  }
}
