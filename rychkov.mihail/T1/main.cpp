#include <iostream>
#include <memf.hpp>
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
    rychkov::Shape* temp = rychkov::getShape(command, std::cin);
    if (!temp)
    {
      allIsValid = false;
      std::cin.ignore();
      free(rychkov::getline(std::cin));
    }
    else
    {
      try
      {
        shapes = rychkov::composition::push_back(shapes, used, allocated, temp);
      }
      catch (...)
      {
        temp->~Shape();
        free(temp);
        free(command);
        rychkov::composition::deallocate(shapes, used);
        return 2;
      }
    }
    free(command);
  }
  rychkov::composition::deallocate(shapes, used);
  if (!allIsValid)
  {
    std::cerr << "some of figures have errors in input description\n";
  }
  return std::cin.fail();
}
