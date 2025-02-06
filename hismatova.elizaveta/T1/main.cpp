#include <iostream>
#include <iomanip>
#include "createFigure.hpp"

namespace hismatova
{
  void deleteFigures(Shape** figures, size_t size)
  {
    for (size_t i = 0; i < size; i++)
    {
      delete figures[i];
    }
  }
  Shape* createFigure(const std::string& name, std::istream& in, bool& errors, bool& memory)
  {
    try
    {
      if (name == "RECTANGLE")
      {
        return createRectangle(in);
      }
      else if (name == "TRIANGLE")
      {
        return createTriangle(in);
      }
      else if (name == "CONCAVE")
      {
        return createConcave(in);
      }
    }
    catch (const std::invalid_argument&)
    {
      errors = true;
    }
    catch (const std::bad_alloc&)
    {
      std::cerr << "out of memory\n";
      memory = true;
    }
    return nullptr;
  }
  void results(std::ostream& out, const Shape* const* figures, size_t count)
  {
    double sum = 0.0;
    for (size_t i = 0; i < count; i++)
    {
      if (figures[i])
      {
        sum += figures[i]->getArea();
      }
    }
    out << std::fixed << std::setprecision(1) << sum;
    for (size_t i = 0; i < count; i++)
    {
      if (figures[i])
      {
        rectangle_t FrameRect = figures[i]->getFrameRect();
        out << " " << FrameRect.pos.x - FrameRect.width / 2.0 << " " << FrameRect.pos.y - FrameRect.height / 2.0 << " ";
        out << FrameRect.pos.x + FrameRect.width / 2.0 << " " << FrameRect.pos.y + FrameRect.height / 2.0;
      }
    }
    out << "\n";
  }
}

int main()
{
  using namespace hismatova;
  size_t count = 0;
  bool errors = false;
  bool scales = false;
  bool memory = false;
  Shape* figures[10000];
  std::string nameFigure;
  while (std::cin >> nameFigure && nameFigure != "SCALE")
  {
    Shape* figure = createFigure(nameFigure, std::cin, errors, memory);
    if (memory)
    {
      deleteFigures(figures, count);
      return 1;
    }
    if (figure)
    {
      figures[count++] = figure;
    }
  }
  if (nameFigure == "SCALE")
  {
    if (count == 0)
    {
      std::cerr << "there is no figures\n";
      deleteFigures(figures, count);
      return 1;
    }
    double x = 0, y = 0;
    point_t point_;
    std::cin >> x >> y;
    if (x == 0 && y == 0)
    {
      std::cerr << "incorrect point\n";
      errors = true;
    }
    point_.x = x;
    point_.y = y;
    double index = 0;
    std::cin >> index;
    if (index <= 0)
    {
      std::cerr << "index must be positive\n";
      deleteFigures(figures, count);
      return 1;
    }
    scales = true;
    results(std::cout, figures, count);
    for (size_t i = 0; i < count; i++)
    {
      point_t pos = figures[i]->getFrameRect().pos;
      figures[i]->move(point_);
      point_t pos2 = figures[i]->getFrameRect().pos;
      point_t p2;
      p2.x = (pos2.x - pos.x) * index;
      p2.y = (pos2.y - pos.y) * index;
      figures[i]->scale(index);
      figures[i]->move(-1 * p2.x, -1 * p2.y);
    }
    results(std::cout, figures, count);
    deleteFigures(figures, count);
    return 0;
  }
  if (!scales)
  {
    std::cerr << "incorrect input\n";
    deleteFigures(figures, count);
    return 1;
  }
  if (errors)
  {
    std::cerr << "error in parameters\n";
  }
  deleteFigures(figures, count);
}
