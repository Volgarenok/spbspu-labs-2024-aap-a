#include <iostream>
#include <iomanip>
#include "createFigure.hpp"

namespace hismatova
{
  void deleteFigures(shape** figures, size_t size)
  {
    for (size_t i = 0; i < size; i++)
    {
      delete figures[i];
    }
  }
  void results(shape** figures, size_t count)
  {
    double sum = 0;
    for (size_t i = 0; i < count; i++)
    {
      if (figures[i])
      {
        sum = sum + figures[i]->getArea();
      }
    }
    std::cout << std::fixed << std::setprecision(1) << sum;
    for (size_t i = 0; i < count; i++)
    {
      if (figures[i])
      {
        rectangle_t FrameRect = figures[i]->getFrameRect();
        std::cout << " " << FrameRect.pos.x - FrameRect.width / 2 << " " << FrameRect.pos.y - FrameRect.height / 2 << " ";
        std::cout << FrameRect.pos.x + FrameRect.width / 2 << " " << FrameRect.pos.y + FrameRect.height / 2;
      }
    }
    std::cout << "\n";
  }
}
int main()
{
  size_t count = 0;
  bool errors = false;
  bool scales = false;
  hismatova::shape* figures[10000];
  std::string nameFigure;
  while(std::cin >> nameFigure)
  {
    if (nameFigure == "RECTANGLE")
    {
      try
      {
        figures[count] = hismatova::createRectangle(std::cin);
        count++;
      }
      catch (const std::invalid_argument&)
      {
        errors = true;
      }
      catch (const std::bad_alloc&)
      {
        std::cerr << "out of memory\n";
        hismatova::deleteFigures(figures, count);
        return 1;
      }
    }
    else if (nameFigure == "TRIANGLE")
    {
      try
      {
        figures[count] = hismatova::createTriangle(std::cin);
        count++;
      }
      catch (const std::invalid_argument&)
      {
        errors = true;
      }
      catch (const std::bad_alloc&)
      {
        std::cerr << "out of memory\n";
        hismatova::deleteFigures(figures, count);
        return 1;
      }
    }
    else if (nameFigure == "CONCAVE")
    {
      try
      {
        figures[count] = hismatova::createConcave(std::cin);
        count++;
      }
      catch (const std::invalid_argument&)
      {
        errors = true;
      }
      catch (const std::bad_alloc&)
      {
        std::cerr << "out of memory\n";
        hismatova::deleteFigures(figures, count);
        return 1;
      }
    }
    else if (nameFigure == "SCALE")
    {
     if (count == 0)
     {
       std::cerr << "there is no figures";
       hismatova::deleteFigures(figures, count);
       return 1;
     }
     double x = 0, y = 0;
     hismatova::point_t point_;
     std::cin >> x >> y;
     point_.x = x;
     point_.y = y;
     double index = 0;
     std::cin >> index;
     if (index <= 0)
     {
       std::cerr << "index must be positive\n";
       hismatova::deleteFigures(figures, count);
       return 1;
     }
     scales = true;
     hismatova::results(figures, count);
     for (size_t i = 0; i < count; i++)
     {
       hismatova::point_t pos = figures[i]->getFrameRect().pos;
       figures[i]->move(point_);
       hismatova::point_t pos2 = figures[i]->getFrameRect().pos;
       hismatova::point_t p2;
       p2.x = (pos2.x - pos.x) * index;
       p2.y = (pos2.y - pos.y) * index;
       figures[i]->scale(index);
       figures[i]->move(-1 * p2.x, -1 * p2.y);
     }
     hismatova::results(figures, count);
     break;
    }
  }
  if (!scales)
  {
    std::cerr << "incorrect input\n";
  }
  else if (errors)
  {
    std::cerr << "error in parametrs\n";
  }
  hismatova::deleteFigures(figures, count);
}
