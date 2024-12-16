#include <iostream>
#include <string_input.hpp>
#include <string_comparison.hpp>

#include "shapes_input.hpp"
#include "shape_scale.hpp"
#include "composition.hpp"

int main()
{
  size_t allocated = 8;
  size_t used = 0;
  rychkov::Shape** shapes = rychkov::composition::allocate(allocated);
  if (!shapes)
  {
    return 2;
  }

  bool allIsValid = true;
  char* command = nullptr;
  while ((command = rychkov::getline(std::cin, ' ')) && (std::cin.good()))
  {
    if (rychkov::cmpEnd(command, "SCALE") == 0)
    {
      rychkov::point_t scaleCenter{0, 0};
      double coef = 1;
      if (std::cin >> scaleCenter.x >> scaleCenter.y >> coef)
      {
        std::cout << rychkov::composition::getArea(shapes, used);
        for (size_t i = 0; i < used; i++)
        {
          rychkov::rectangle_t temp = shapes[i]->getFrameRect();
          std::cout << ' ' << temp.pos.x - temp.width / 2;
          std::cout << ' ' << temp.pos.y - temp.height / 2;
          std::cout << ' ' << temp.pos.x + temp.width / 2;
          std::cout << ' ' << temp.pos.y + temp.height / 2;
        }
        std::cout << '\n';
        rychkov::scale(shapes, used, coef, scaleCenter);
      }
      free(command);
      rychkov::composition::deallocate(shapes, used);
      return std::cin.fail() || std::cin.eof();
    }
    rychkov::Shape* temp = rychkov::getShape(command, std::cin);
    if (!temp)
    {
      allIsValid = false;
      std::cin.ignore();
      free(rychkov::getline(std::cin));
    }
    else
    {
      rychkov::Shape** tempShapes = rychkov::composition::push_back(shapes, used, allocated, temp);
      if (!tempShapes)
      {
        temp->~Shape();
        free(temp);
        free(command);
        rychkov::composition::deallocate(shapes, used);
        return 2;
      }
      shapes = tempShapes;
    }
    free(command);
  }
  rychkov::composition::deallocate(shapes, used);
  if (!allIsValid)
  {
    std::cerr << "some of figures have errors in input description\n";
  }
  return std::cin.fail() ? 2 : 1;
}
