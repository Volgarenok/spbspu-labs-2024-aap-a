#include <iostream>
#include <iomanip>
#include <string>
#include "regular.hpp"
#include "shape.hpp"
#include "ring.hpp"
#include "rectangle.hpp"

namespace
{
  void deleteShapes(tkach::Shape** shape_array, size_t counter_of_shapes)
  {
      for(size_t i = 0; i < counter_of_shapes; ++i)
      {
        delete[] shape_array[i];
      }
  }
  double getTotalArea(tkach::Shape** shape_array, size_t counter_of_shapes)
  {
    double sum = 0;
    for(size_t i = 0; i < counter_of_shapes; ++i)
    {
      sum += shape_array[i]->getArea();
    }
    return sum;
  }

  void printCoordinatesOfFrameRect(tkach::Shape** shape_array, size_t counter_of_shapes)
  {
    for(size_t i = 0; i < counter_of_shapes; ++i)
    {
      tkach::rectangle_t frame_rect = shape_array[i]->getFrameRect();
      tkach::point_t left_bot_point, right_top_point;
      left_bot_point.x = frame_rect.pos.x - frame_rect.width / 2.0;
      left_bot_point.y = frame_rect.pos.y - frame_rect.height / 2.0;
      right_top_point.x = frame_rect.pos.x + frame_rect.width / 2.0;
      right_top_point.y = frame_rect.pos.y + frame_rect.height / 2.0;
      std::cout << left_bot_point.x << " " << left_bot_point.y << " " << right_top_point.x << " " << right_top_point.y;
    }
  }

  void doIsotropicScale(tkach::Shape** shape_array, size_t counter_of_shapes, double scale_coef, tkach::point_t scale_point)
  {
    for(size_t i = 0; i < counter_of_shapes; ++i)
    {
      tkach::point_t init_point = shape_array[i]->getFrameRect().pos;
      shape_array[i]->move(scale_point);
      tkach::point_t scaled_point = shape_array[i]->getFrameRect().pos;
      shape_array[i]->scale(scale_coef);
      double scaled_dx = (scaled_point.x - init_point.x) * scale_coef;
      double scaled_dy = (scaled_point.y - init_point.y) * scale_coef;
      shape_array[i]->move(-1 * scaled_dx, -1 * scaled_dy);
    }
  }
}
int main()
{
  tkach::point_t scale_point;
  double scale_coef = 0.0;
  tkach::Shape* shapes_array[10000] = {0};
  std::string shape_name = "";
  bool incorrect_shape = false;
  size_t counter_of_shapes = 0;
  while(true)
  {
    std::cin >> shape_name;
    if (std::cin.eof())
    {
      deleteShapes(shapes_array, counter_of_shapes);
      std::cerr << "Error: not enough arguments\n";
      return 1;
    }
    if (shape_name.empty())
    {
      continue;
    }
    if (shape_name == "RECTANGLE")
    {
      double left_bot_point_x = 0, left_bot_point_y = 0;
      double right_top_point_x = 0, right_top_point_y = 0;
      std::cin >> left_bot_point_x >> left_bot_point_y >> right_top_point_x >> right_top_point_y;
      try
      {
        shapes_array[counter_of_shapes++] = new tkach::Rectangle({left_bot_point_x, left_bot_point_y}, {right_top_point_x, right_top_point_y});
      }
      catch(const std::bad_alloc& e)
      {
        deleteShapes(shapes_array, counter_of_shapes);
        std::cerr << "Not enough memory\n";
        return 1;
      }
      catch (const std::logic_error& e)
      {
        incorrect_shape = true;
      }
    }
    else if (shape_name == "RING")
    {
      double center_x = 0, center_y = 0;
      double outer_radius = 0, inner_radius = 0;
      std::cin >> center_x >> center_y >> outer_radius >> inner_radius;
      try
      {
        shapes_array[counter_of_shapes++] = new tkach::Ring({center_x, center_y}, outer_radius, inner_radius);
      }
      catch(const std::bad_alloc& e)
      {
        deleteShapes(shapes_array, counter_of_shapes);
        std::cerr << "Not enough memory\n";
        return 1;
      }
      catch (const std::logic_error& e)
      {
        incorrect_shape = true;
      }
    }
    else if (shape_name == "REGULAR")
    {
      tkach::point_t point1, point2, point3;
      std::cin >> point1.x >> point1.y;
      std::cin >> point2.x >> point2.y;
      std::cin >> point3.x >> point3.y;
      try
      {
        shapes_array[counter_of_shapes++] = new tkach::Regular(point1, point2, point3);
      }
      catch(const std::bad_alloc& e)
      {
        deleteShapes(shapes_array, counter_of_shapes);
        std::cerr << "Not enough memory\n";
        return 1;
      }
      catch (const std::logic_error& e)
      {
        incorrect_shape = true;
      }
    }
    else if (shape_name == "SCALE")
    {
      std::cin >> scale_point.x >> scale_point.y;
      std::cin >> scale_coef;
      if (scale_coef <= 0)
      {
        deleteShapes(shapes_array, counter_of_shapes);
        std::cerr << "Error: sacle coefficent need to be bigger than 0\n";
        return 1;
      }
      break;
    }
  }
  if (incorrect_shape)
  {
    std::cerr << "Error with shapes discription\n";
  }
  std::cout << std::fixed << std::setprecision(1);
  std::cout << getTotalArea(shapes_array, counter_of_shapes) << "\n";
  printCoordinatesOfFrameRect(shapes_array, counter_of_shapes);
  std::cout << "\n";
  doIsotropicScale(shapes_array, counter_of_shapes, scale_coef, scale_point);
  std::cout << getTotalArea(shapes_array, counter_of_shapes) << "\n";
  printCoordinatesOfFrameRect(shapes_array, counter_of_shapes);
  std::cout << "\n";
  deleteShapes(shapes_array, counter_of_shapes);
  return 0;
}
