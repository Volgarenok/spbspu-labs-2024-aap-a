#include <iostream>
#include <iomanip>
#include <string>
#include "regular.hpp"
#include "ring.hpp"
#include "rectangle.hpp"
#include "figureactions.hpp"
#include "makeshapes.hpp"

int main()
{
  tkach::Shape* shapes_array[10000] = {};
  std::string shape_name = "";
  bool incorrect_shape = false;
  size_t counter_of_shapes = 0;
  double scale_coef = 0.0;
  tkach::point_t scale_point;
  while(!std::cin.eof())
  {
    std::cin >> shape_name;
    if (shape_name.empty())
    {
      continue;
    }
    try
    {
      shapes_array[counter_of_shapes] = tkach::make_shape(std::cin, shape_name);
      if (shapes_array[counter_of_shapes] != nullptr)
      {
        counter_of_shapes++;
      }
    }
    catch(const std::bad_alloc& e)
    {
      tkach::deleteShapes(shapes_array, counter_of_shapes);
      std::cerr << "Not enough memory\n";
      return 1;
    }
    catch (const std::logic_error& e)
    {
      incorrect_shape = true;
    }
    if (shape_name == "SCALE")
    {
      std::cin >> scale_point.x >> scale_point.y;
      std::cin >> scale_coef;
      if (scale_coef <= 0)
      {
        tkach::deleteShapes(shapes_array, counter_of_shapes);
        std::cerr << "Error: scale coefficent need to be bigger than 0\n";
        return 1;
      }
      break;
    }
  }
  if (std::cin.eof())
  {
    deleteShapes(shapes_array, counter_of_shapes);
    std::cerr << "Error: not enough arguments\n";
    return 1;
  }
  if (counter_of_shapes == 0)
  {
    tkach::deleteShapes(shapes_array, counter_of_shapes);
    std::cerr << "Zero shapes\n";
    return 1;
  }
  if (incorrect_shape)
  {
    std::cerr << "Error with shapes discription\n";
  }
  std::cout << std::fixed << std::setprecision(1);
  std::cout << tkach::getTotalArea(shapes_array, counter_of_shapes) << " ";
  tkach::printCoordinatesOfAllFrameRects(std::cout, shapes_array, counter_of_shapes);
  std::cout << "\n";
  tkach::doIsoScaleShapes(shapes_array, counter_of_shapes, scale_coef, scale_point);
  std::cout << tkach::getTotalArea(shapes_array, counter_of_shapes) << " ";
  tkach::printCoordinatesOfAllFrameRects(std::cout, shapes_array, counter_of_shapes);
  std::cout << "\n";
  tkach::deleteShapes(shapes_array, counter_of_shapes);
  return 0;
}
