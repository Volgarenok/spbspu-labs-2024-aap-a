#include <iostream>
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
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
  double sum_area = 0.0;
  while (!std::cin.eof() && std::cin >> figure)
  {
    if (figure == "SCALE")
    {
      break;
    }
    if (figure == "RECTANGLE")
    {
      try
      {
        shapes[num] = makeRectangle(std::cin);
        sum_area += shapes[num]->getArea();
        num++;
      }
      catch (std::logic_error&)
      {
        std::cerr << "Wrong shape" << "\n";
      }
      catch (std::bad_alloc&)
      {
        std::cerr << "Error" << "\n";
        clearShapes(shapes);
        return 1;
      }
    }
  }
  if (std::cin.eof() && figure != "SCALE")
  {
    std::cerr << "Error" << "\n";
    clearShapes(shapes);
    return 1;
  }
  double scale_x = 0.0, scale_y = 0.0;
  double koef = 0.0;
  std::cin >> scale_x >> scale_y >> koef;
  point_t scale_pos = { scale_x, scale_y };
  if (koef <= 0.0 || num == 0)
  {
    std::cerr << "Error" << "\n";
    clearShapes(shapes);
    return 1;
  }
  std::cout << sum_area << " ";
  outputFigures(shapes, std::cout) << "\n";
  sum_area = sum_area * koef * koef;
  std::cout << sum_area << " ";
  for (size_t i = 0; i < num; ++i)
  {
    point_t move_point = {};
    move_point.x = scale_pos.x + (shapes[i]->getFrameRect().pos.x - scale_pos.x) * koef;
    move_point.y = scale_pos.y + (shapes[i]->getFrameRect().pos.y - scale_pos.y) * koef;
    shapes[i]->move(move_point);
    shapes[i]->scale(koef);
  }
  outputFigures(shapes, std::cout) << "\n";
  clearShapes(shapes);
}
