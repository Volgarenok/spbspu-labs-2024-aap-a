#include <iostream>
#include <iomanip>
#include <string>
#include "regular.hpp"
#include "ring.hpp"
#include "rectangle.hpp"
#include "figureactions.hpp"
#include "makeshapes.hpp"
#include "composite-shape.hpp"

using namespace tkach;

namespace
{
  void deleteShapesFromCompositeShape(CompositeShape& shapes_array)
  {
    for (size_t i = 0; i < shapes_array.size(); ++i)
    {
      delete shapes_array[i];
    }
  }
}
int main()
{
  CompositeShape shapes_array;
  std::string shape_name = "";
  bool incorrect_shape = false;
  double scale_coef = 0.0;
  point_t scale_point;
  while(!std::cin.eof() && shape_name != "SCALE")
  {
    std::cin >> shape_name;
    if (shape_name.empty())
    {
      continue;
    }
    try
    {
      Shape* shape = make_shape(std::cin, shape_name);
      if (shape != nullptr)
      {
        shapes_array.push_back(shape);
      }
    }
    catch (const std::logic_error& e)
    {
      incorrect_shape = true;
    }
    catch (const std::exception& e)
    {
      deleteShapesFromCompositeShape(shapes_array);
      std::cerr << e.what();
      return 1;
    }
    if (shape_name == "SCALE")
    {
      std::cin >> scale_point.x >> scale_point.y;
      std::cin >> scale_coef;
      if (scale_coef <= 0)
      {
        deleteShapesFromCompositeShape(shapes_array);
        std::cerr << "Error: scale coefficent need to be bigger than 0\n";
        return 1;
      }
    }
  }
  if (std::cin.eof())
  {
    deleteShapesFromCompositeShape(shapes_array);
    std::cerr << "Error: not enough arguments\n";
    return 1;
  }
  if (incorrect_shape)
  {
    std::cerr << "Error with shapes discription\n";
  }
  if (shapes_array.size() == 0)
  {
    deleteShapesFromCompositeShape(shapes_array);
    std::cerr << "Zero correct shapes\n";
    return 1;
  }
  std::cout << std::fixed << std::setprecision(1);
  try
  {
    std::cout << shapes_array.getArea() << " ";
    printAllFrameRectsFromCompShape(std::cout, shapes_array) << "\n";
    doUnsaveIsoScaleCompShape(shapes_array, scale_coef, scale_point);
    std::cout << shapes_array.getArea() << " ";
    printAllFrameRectsFromCompShape(std::cout, shapes_array) << "\n";
  }
  catch (const std::exception& e)
  {
    deleteShapesFromCompositeShape(shapes_array);
    std::cerr << e.what();
    return 1;
  }
  deleteShapesFromCompositeShape(shapes_array);
  return 0;
}
