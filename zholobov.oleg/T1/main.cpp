#include <iostream>
#include <string>

#include "composite-shape.hpp"
#include "shape.hpp"
#include "shapes_utils.hpp"

int main()
{
  zholobov::CompositeShape composite_shape;
  size_t shape_cnt = 0;
  std::string shape_name;
  bool is_scale_processed = false;
  while (std::cin >> shape_name) {
    try {
      zholobov::Shape* shape = zholobov::create_shape(shape_name, std::cin);
      if (shape != nullptr) {
        composite_shape.push_back(shape);
      } else if (shape_name == "SCALE") {
        if (shape_cnt == 0) {
          std::cerr << "There are no shapes to scale\n";
          return 1;
        }
        is_scale_processed = true;
        double x = 0.0;
        double y = 0.0;
        double scale_factor = 0.0;
        std::cin >> x >> y >> scale_factor;
        if (!std::cin) {
          std::cerr << "Error in SCALE paramaters\n";
          return 1;
        }
        composite_shape.print(std::cout);
        std::cout << "\n";
        composite_shape.scale_relative({x, y}, scale_factor);
        composite_shape.print(std::cout);
        std::cout << "\n";
      } else {
        std::cerr << "Unknown shape (" << shape_name << ")\n";
      }
    } catch (const std::logic_error& e) {
      std::cerr << e.what() << "\n";
    } catch (const std::exception& e) {
      std::cerr << e.what() << "\n";
      return 1;
    }
  }

  if (!is_scale_processed) {
    std::cerr << "SCALE command not found\n";
    return 1;
  }

  return 0;
}
