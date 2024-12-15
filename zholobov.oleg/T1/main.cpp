#include <iostream>
#include <string>

#include "shape.hpp"
#include "shapes_utils.hpp"

int main()
{
  constexpr size_t max_shapes = 1000;
  zholobov::Shape* shapes[max_shapes];
  size_t shape_cnt = 0;
  std::string shape_name;
  bool is_scale_processed = false;
  while (std::cin >> shape_name) {
    try {
      if (shape_name == "RECTANGLE") {
        shapes[shape_cnt++] = zholobov::create_rectangle(std::cin);
      } else if (shape_name == "SQUARE") {
        shapes[shape_cnt++] = zholobov::create_square(std::cin);
      } else if (shape_name == "PARALLELOGRAM") {
        shapes[shape_cnt++] = zholobov::create_parallelogram(std::cin);
      } else if (shape_name == "SCALE") {
        if (shape_cnt == 0) {
          std::cerr << "There are no shapes to scale\n";
          std::exit(1);
        }
        is_scale_processed = true;
        double x = 0.0;
        double y = 0.0;
        double scale_factor = 0.0;
        std::cin >> x >> y >> scale_factor;
        if (!std::cin || scale_factor <= 0) {
          std::cerr << "Error in SCALE paramaters\n";
          std::exit(1);
        }
        zholobov::process_scale(shapes, shape_cnt, {x, y}, scale_factor);
      } else {
        std::cerr << "Unknown shape (" << shape_name << ")\n";
      }
    } catch (const std::runtime_error& e) {
      std::cerr << e.what() << "\n";
      zholobov::delete_shapes(shapes, shape_cnt);
      std::exit(1);
    } catch (const std::invalid_argument& e) {
      std::cerr << e.what() << "\n";
    }
  }

  if (!is_scale_processed) {
      std::cerr << "SCALE command not found\n";
      zholobov::delete_shapes(shapes, shape_cnt);
      std::exit(1);
  }

  zholobov::delete_shapes(shapes, shape_cnt);
  return 0;
}
