#include <iomanip>
#include "figureactions.hpp"
#include "makeshapes.hpp"
#include "composite-shape.hpp"
#include "shape.hpp"
#include "base-types.hpp"

namespace
{
  void deleteShapesFromCompositeShape(tkach::CompositeShape& shapes_array)
  {
    for (size_t i = 0; i < shapes_array.size(); ++i)
    {
      delete shapes_array[i];
    }
  }

  tkach::point_t getFrameRectLeftPoint(const tkach::rectangle_t& frame_rect)
  {
    tkach::point_t left_point = frame_rect.pos;
    tkach::addToPoint(left_point, (-1) * frame_rect.width / 2.0, (-1) * frame_rect.height / 2.0);
    return left_point;
  }

  tkach::point_t getFrameRectRightPoint(const tkach::rectangle_t& frame_rect)
  {
    tkach::point_t right_point = frame_rect.pos;
    tkach::addToPoint(right_point, frame_rect.width / 2.0, frame_rect.height / 2.0);
    return right_point;
  }

  std::ostream& printAllFrameRectsFromCompShape(std::ostream& out, const tkach::CompositeShape& shape_array)
  {
    tkach::rectangle_t frame_rect = shape_array[0]->getFrameRect();
    tkach::point_t left_bot_point = getFrameRectLeftPoint(frame_rect);
    tkach::point_t right_top_point = getFrameRectRightPoint(frame_rect);
    out << left_bot_point.x << " " << left_bot_point.y << " " << right_top_point.x << " " << right_top_point.y;
    for (size_t i = 1; i < shape_array.size(); ++i)
    {
      frame_rect = shape_array[i]->getFrameRect();
      left_bot_point = getFrameRectLeftPoint(frame_rect);
      right_top_point = getFrameRectRightPoint(frame_rect);
      out << " " << left_bot_point.x << " " << left_bot_point.y << " " << right_top_point.x << " " << right_top_point.y;
    }
    return out;
  }
}

int main()
{
  using namespace tkach;
  CompositeShape shapes_array;
  std::string shape_name;
  bool incorrect_shape = false;
  double scale_coef = 0.0;
  double scale_point_x = 0.0, scale_point_y = 0.0;
  while(!std::cin.eof() && shape_name != "SCALE")
  {
    std::cin >> shape_name;
    if (shape_name.empty())
    {
      continue;
    }
    if (shape_name == "SCALE")
    {
      std::cin >> scale_point_x >> scale_point_y;
      std::cin >> scale_coef;
      continue;
    }
    Shape* shape = nullptr;
    try
    {
      shape = makeShape(std::cin, shape_name);
      if (shape != nullptr)
      {
        shapes_array.pushBack(shape);
      }
      else
      {
        incorrect_shape = true;
      }
    }
    catch (const std::logic_error&)
    {
      continue;
    }
    catch (const std::exception& e)
    {
      delete shape;
      deleteShapesFromCompositeShape(shapes_array);
      std::cerr << e.what();
      return 1;
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
  if (shapes_array.empty())
  {
    std::cerr << "Zero correct shapes\n";
    return 1;
  }
  point_t scale_point = {scale_point_x, scale_point_y};
  std::cout << std::fixed << std::setprecision(1);
  try
  {
    std::cout << shapes_array.getArea() << " ";
    printAllFrameRectsFromCompShape(std::cout, shapes_array) << "\n";
    doSafeIsoScaleCompShape(shapes_array, scale_coef, scale_point);
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
