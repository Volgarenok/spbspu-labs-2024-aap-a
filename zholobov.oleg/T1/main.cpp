#include <iostream>
#include <string>

#include <common_utils.hpp>
#include "composite-shape.hpp"
#include "shape.hpp"
#include "shapes_utils.hpp"

int main()
{
  zholobov::CompositeShape composite_shape;
  std::string shape_name;
  bool is_scale_command = false;
  try {
    while (std::cin >> shape_name) {
      zholobov::Shape* shape = nullptr;
      try {
        shape = zholobov::create_shape(shape_name, std::cin);
        composite_shape.push_back(shape);
      } catch (const std::out_of_range& e) {
        delete shape;
        throw;
      } catch (const std::invalid_argument& e) {
        if (shape_name == "SCALE") {
          is_scale_command = true;
          break;
        }
        std::cerr << e.what() << "\n";
      }
    }

    if (is_scale_command) {
      if (composite_shape.empty()) {
        std::cerr << "There are no shapes to scale\n";
        return 1;
      }
      double params[3];
      zholobov::read_array(params, 3, std::cin);
      if (!std::cin) {
        std::cerr << "Error reading SCALE paramaters\n";
        return 1;
      }
      composite_shape.print(std::cout);
      std::cout << "\n";
      composite_shape.scale_relative({params[0], params[1]}, params[2]);
      composite_shape.print(std::cout);
      std::cout << "\n";
    } else {
      std::cerr << "SCALE command not found\n";
      return 1;
    }
  } catch (const std::exception& e) {
    std::cerr << e.what() << "\n";
    return 1;
  }

  return 0;
}
