#include <iostream>
#include <iomanip>
#include <cstring>
#include <newlineterminatedstr.h>
#include "composite-shape.hpp"
#include "rectangle.hpp"
#include "concave.hpp"
#include "complexquad.hpp"

namespace
{
  void readDblfromDesc(double * numbers, size_t amt);
  void printSumAreaAndBorders(std::ostream & out, savintsev::CompositeShape & rhs);

  void readDblfromDesc(double * numbers, size_t amt)
  {
    char * token = nullptr;
    for (size_t i = 0; i < amt; ++i)
    {
      token = std::strtok(nullptr, " ");
      if (!token)
      {
        break;
      }
      numbers[i] = std::atof(token);
    }
  }

  void printSumAreaAndBorders(std::ostream & out, savintsev::CompositeShape & rhs)
  {
    out << std::fixed << std::setprecision(1) << rhs.getArea();
    for (size_t i = 0; i < rhs.size(); ++i)
    {
      savintsev::rectangle_t rect = rhs[i]->getFrameRect();
      savintsev::point_t lowLeft = {rect.pos.x - rect.width / 2, rect.pos.y - rect.height / 2};
      savintsev::point_t upRight = {rect.pos.x + rect.width / 2, rect.pos.y + rect.height / 2};
      out << ' ' << lowLeft.x << ' ' << lowLeft.y << ' ' << upRight.x << ' ' << upRight.y;
    }
    out << '\n';
  }
}

int main()
{
  char * line = nullptr;
  bool was_error = false;
  bool was_scale = false;
  savintsev::CompositeShape figure(4);
  savintsev::point_t scalePoint = {0, 0};
  double scaleRatio = 0.0;
  int result = 0;
  while (!was_scale)
  {
    delete[] line;
    line = savintsev::inputNewlineTerminatedStr(std::cin);
    if (line == nullptr)
    {
      std::cerr << "ERROR: Memory full\n";
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
    char * token = std::strtok(line, " ");
    try
    {
      if (!std::strcmp(token, "RECTANGLE"))
      {
        double nums[4] = {0.0, 0.0, 0.0, 0.0};
        readDblfromDesc(nums, 4);
        savintsev::Rectangle * Rect = nullptr;
        Rect = new savintsev::Rectangle({nums[0], nums[1]}, {nums[2], nums[3]});
        figure.push_back(Rect);
      }
      if (!std::strcmp(token, "CONCAVE"))
      {
        double n[8] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
        readDblfromDesc(n, 8);
        savintsev::Concave * Conc = nullptr;
        Conc = new savintsev::Concave({n[0], n[1]}, {n[2], n[3]}, {n[4], n[5]}, {n[6], n[7]});
        figure.push_back(Conc);
      }
      if (!std::strcmp(token, "COMPLEXQUAD"))
      {
        double n[8] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
        readDblfromDesc(n, 8);
        savintsev::Complexquad * Comp = nullptr;
        Comp = new savintsev::Complexquad({n[0], n[1]}, {n[2], n[3]}, {n[4], n[5]}, {n[6], n[7]});
        figure.push_back(Comp);
      }
    }
    catch (const std::invalid_argument & e)
    {
      was_error = true;
      continue;
    }
    if (!std::strcmp(token, "SCALE"))
    {
      double numbers[3] = {0.0, 0.0, 0.0};
      readDblfromDesc(numbers, 3);
      if (numbers[2] <= 0)
      {
        continue;
      }
      scalePoint = {numbers[0], numbers[1]};
      scaleRatio = numbers[2];
      if (figure.empty())
      {
        delete[] line;
        std::cerr << "ERROR: No shapes\n";
        return 2;
      }
      printSumAreaAndBorders(std::cout, figure);
      figure.scaleRelativeTo(scaleRatio, scalePoint);
      printSumAreaAndBorders(std::cout, figure);
      delete[] line;
      was_scale = true;
    }
  }
  if (was_error)
  {
    std::cerr << "WARNING: Some shapes were ignored because they were described incorrectly\n";
  }
}
