#include <iostream>
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "square.hpp"
#include "parallelogram.hpp"
#include "inputFigures.hpp"
#include "outputFigures.hpp"

void clearShapes(dirti::Shape** shapes)
{
  for (size_t i = 0; shapes[i] != nullptr; ++i)
  {
    delete shapes[i];
  }
}

int main()
{
  using namespace dirti;
  std::cout << std::fixed;
  std::cout.precision(1);
  Shape* shapes[10000] = {};
  std::string figure;
  size_t num = 0;
  bool areWrongShapes = false;
  while (!std::cin.eof() && std::cin >> figure && figure != "SCALE")
  {
    try
    {
      shapes[num] = makeShape(std::cin, figure);
      if (shapes[num] != nullptr)
      {
        num++;
      }
    }
    catch (const std::logic_error&)
    {
      areWrongShapes = true;
    }
    catch (const std::bad_alloc&)
    {
      std::cerr << "Error" << "\n";
      clearShapes(shapes);
      return 1;
    }
  }
  if ((std::cin.eof() && figure != "SCALE") || num == 0)
  {
    std::cerr << "Error" << "\n";
    clearShapes(shapes);
    return 1;
  }
  double scale_x = 0.0, scale_y = 0.0;
  double koef = 0.0;
  std::cin >> scale_x >> scale_y >> koef;
  point_t scale_pos = { scale_x, scale_y };
  double sum_area = 0.0;
  for (size_t i = 0; i < num; ++i)
  {
    sum_area += shapes[i]->getArea();
  }
  std::cout << sum_area << " ";
  outputFigures(shapes, std::cout) << "\n";
  try
  {
    for (size_t i = 0; i < num; ++i)
    {
      double mv_x = scale_pos.x + (shapes[i]->getFrameRect().pos.x - scale_pos.x) * koef;
      double mv_y = scale_pos.y + (shapes[i]->getFrameRect().pos.y - scale_pos.y) * koef;
      point_t move_point = {mv_x, mv_y};
      shapes[i]->scale(koef);
      shapes[i]->move(move_point);
    }
  }
  catch (const std::invalid_argument&)
  {
    std::cerr << "Error" << "\n";
    clearShapes(shapes);
    return 1;
  }
  if (areWrongShapes)
  {
    std::cerr << "There are wrong descriptions for figures" << "\n";
  }
  sum_area = sum_area * koef * koef;
  std::cout << sum_area << " ";
  outputFigures(shapes, std::cout) << "\n";
  clearShapes(shapes);
}
