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
  char * line = nullptr;
  bool was_error = false;
  bool was_scale = false;
  savintsev::CompositeShape figure(4);
  double params[8] = {};
  while (!was_scale)
  {
    delete[] line;
    line = savintsev::inputNewlineTerminatedStr(std::cin);
    if (line == nullptr)
    {
      std::cerr << "ERROR: Memory collapse\n";
      return 2;
    }
    if (std::cin.eof())
    {
      delete[] line;
      std::cerr << "ERROR: EOF is not implemented\n";
      return 2;
    }
    if (line[0] == '\0')
    {
      continue;
    }
    char * type = std::strtok(line, " ");
    savintsev::Shape * createdShape = nullptr;
    try
    {
      if (!std::strcmp(type, "RECTANGLE") || !std::strcmp(type, "COMPLEXQUAD") || !std::strcmp(type, "CONCAVE"))
      {
        readDescription(params);
        createdShape = savintsev::createShape(line, params);
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
      savintsev::point_t scalePoint = {params[0], params[1]};
      double scaleRatio = params[2];
      if (scaleRatio <= 0)
      {
        continue;
      }
      if (figure.empty())
      {
        delete[] line;
        std::cerr << "ERROR: No shapes\n";
        return 2;
      }
      savintsev::printAreaAndBorder(std::cout, figure);
      figure.unsafeScaleRelativeTo(scaleRatio, scalePoint);
      savintsev::printAreaAndBorder(std::cout, figure);
      delete[] line;
      was_scale = true;
    }
  }
  if (was_error)
  {
    std::cerr << "WARNING: Some shapes were ignored because they were described incorrectly\n";
  }
}
