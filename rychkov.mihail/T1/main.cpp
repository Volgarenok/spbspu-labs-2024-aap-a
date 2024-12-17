#include <iostream>
#include <iomanip>

#include <string_input.hpp>
#include <string_comparison.hpp>

#include "shapes_input.hpp"
#include "shape_scale.hpp"
#include "composition.hpp"

namespace rychkov
{
  std::ostream& printRectangle(std::ostream& out, rychkov::rectangle_t rect);
  std::ostream& printCompositionFrames(std::ostream& out, rychkov::Shape** shapes, size_t size);
}

int main()
{
  std::cout << std::fixed << std::setprecision(1);
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
      bool inputHasError = false;
      if (std::cin >> scaleCenter.x >> scaleCenter.y >> coef)
      {
        if (!allIsValid)
        {
          std::cerr << "some of figures have errors in input description\n";
        }
        if (used == 0)
        {
          std::cerr << "there are no valid shapes in input\n";
          inputHasError = true;
        }
        if (coef <= 0)
        {
          std::cerr << "scale coefficient is non-positive\n";
          inputHasError = true;
        }
        if (!inputHasError)
        {
          rychkov::printCompositionFrames(std::cout, shapes, used) << '\n';
          rychkov::scale(shapes, used, coef, scaleCenter);
          rychkov::printCompositionFrames(std::cout, shapes, used) << '\n';
        }
      }
      free(command);
      rychkov::composition::deallocate(shapes, used);
      return !std::cin.good() || inputHasError;
    }

    bool isUnknown = false;
    rychkov::Shape* temp = rychkov::getShape(command, std::cin, isUnknown);
    if (isUnknown)
    {
      free(rychkov::getline(std::cin));
    }
    else if (!temp)
    {
      allIsValid = false;
      std::cin.clear();
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
    command = nullptr;
  }
  free(command);
  rychkov::composition::deallocate(shapes, used);
  return std::cin.fail() ? 2 : 1;
}

std::ostream& rychkov::printRectangle(std::ostream& out, rychkov::rectangle_t rect)
{
  out << rect.pos.x - rect.width / 2;
  out << ' ' << rect.pos.y - rect.height / 2;
  out << ' ' << rect.pos.x + rect.width / 2;
  out << ' ' << rect.pos.y + rect.height / 2;
  return out;
}
std::ostream& rychkov::printCompositionFrames(std::ostream& out, rychkov::Shape** shapes, size_t size)
{
  out << rychkov::composition::getArea(shapes, size);
  for (size_t i = 0; i < size; i++)
  {
    printRectangle(out << ' ', shapes[i]->getFrameRect());
  }
  return out;
}
