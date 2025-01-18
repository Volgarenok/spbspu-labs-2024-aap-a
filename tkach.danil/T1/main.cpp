#include <iostream>
#include <iomanip>
#include <string>
#include "regular.hpp"
#include "ring.hpp"
#include "rectangle.hpp"
#include "figureactions.hpp"
#include "makeshapes.hpp"
#include "composite-shape.hpp"

namespace
{
  void deleteShapesFromCompositeShape(tkach::CompositeShape& shapes_array)
  {
    for (size_t i = 0; i < shapes_array.size(); ++i)
    {
      delete shapes_array[i];
    }
  }

  tkach::point_t setFrameRectLeftPoint(const tkach::rectangle_t& frame_rect)
  {
    return {frame_rect.pos.x - frame_rect.width / 2.0, frame_rect.pos.y - frame_rect.height / 2.0};
  }

  tkach::point_t setFrameRectRightPoint(const tkach::rectangle_t& frame_rect)
  {
    return {frame_rect.pos.x + frame_rect.width / 2.0, frame_rect.pos.y + frame_rect.height / 2.0};
  }

  void setFrameRectPoints(const tkach::rectangle_t& frame_rect, tkach::point_t& left_bot_point, tkach::point_t& right_top_point)
  {
    left_bot_point = setFrameRectLeftPoint(frame_rect);
    right_top_point = setFrameRectRightPoint(frame_rect);
  }

  template< typename Container >
  std::ostream& printFrameRects(std::ostream& Out, const Container& Shapes, const size_t Size)
  {
    tkach::rectangle_t frame_rect = Shapes[0]->getFrameRect();
    tkach::point_t left_bot_point = setFrameRectLeftPoint(frame_rect);
    tkach::point_t right_top_point = setFrameRectRightPoint(frame_rect);
    Out << left_bot_point.x << " " << left_bot_point.y << " " << right_top_point.x << " " << right_top_point.y;
    for (size_t i = 1; i < Size; ++i)
    {
      frame_rect = Shapes[i]->getFrameRect();
      setFrameRectPoints(frame_rect, left_bot_point, right_top_point);
      Out << " " << left_bot_point.x << " " << left_bot_point.y << " " << right_top_point.x << " " << right_top_point.y;
    }
    return Out;
  }

  std::ostream& printAllFrameRectsFromCompShape(std::ostream& out, const tkach::CompositeShape& shape_array)
  {
    return printFrameRects(out, shape_array, shape_array.size());
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
    try
    {
      Shape* shape = make_shape(std::cin, shape_name);
      if (shape != nullptr)
      {
        shapes_array.push_back(shape);
      }
    }
    catch (const std::logic_error&)
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
      std::cin >> scale_point_x >> scale_point_y;
      std::cin >> scale_coef;
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
    std::cerr << "Zero correct shapes\n";
    return 1;
  }
  point_t scale_point = {scale_point_x, scale_point_y};
  std::cout << std::fixed << std::setprecision(1);
  try
  {
    std::cout << shapes_array.getArea() << " ";
    printAllFrameRectsFromCompShape(std::cout, shapes_array) << "\n";
    doSaveIsoScaleCompShape(shapes_array, scale_coef, scale_point);
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
