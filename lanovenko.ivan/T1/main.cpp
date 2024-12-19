#include <iostream>
#include <iomanip>
#include <cstring>
#include "input_string.hpp"
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "traingle.hpp"
#include "input_shape.hpp"
#include "string_manipulation.hpp"

using namespace lanovenko;

int main()
{
  constexpr size_t maxcapasity = 1000;
  char* str = nullptr;
  size_t shapeNumber = 0;
  Shape* shapeArray[maxcapasity] = { nullptr };
  bool errors = false;
  bool scale_was_met = false;

  while (!scale_was_met)
  {
    if (!std::cin.good())
    {
      std::cerr << "Wrong input!\n";
      for (size_t i = 0; i < shapeNumber; i++)
      {
        delete shapeArray[i];
      }
      return 1;
    }

    try
    {
      str = inputStr(std::cin);
    }
    catch (const std::logic_error& e)
    {
      std::cerr << e.what() << "\n";
      delete[] str;
      for (size_t i = 0; i < shapeNumber; i++)
      {
        delete shapeArray[i];
      }
      return 2;
    }
    constexpr size_t shapes_count = 4;
    const char* shape_names[shapes_count] = { "RECTANGLE", "TRIANGLE", "DIAMOND", "SCALE"};
    try
    {
      for (size_t i = 0; i < shapes_count; i++)
      {
        size_t name_size = std::strlen(shape_names[i]);
        if (std::strncmp(shape_names[i], str, name_size) == 0)
        {
          if (i == 0)
          {
            Shape* shape = inputRectangle(str);
            if (shape != nullptr)
            {
              shapeArray[shapeNumber++] = shape;
            }
          }
          if (i == 1)
          {
            Shape* shape = inputTriangle(str);
            if (shape != nullptr)
            {
              shapeArray[shapeNumber++] = shape;
            }
          }
          if (i == 2)
          {
            Shape* shape = inputDiamond(str);
            if (shape != nullptr)
            {
              shapeArray[shapeNumber++] = shpae;
            }
          }
          if (i == 3)
          {
            scale_was_met = true;
            scaleCommand(str, shapeArray, shapeNumber, std::cout);
          }
        }
      }
    }
    catch (const std::invalid_argument& e)
    {
      errors = true;
    }
    catch (const std::logic_error& e)
    {
      std::cerr << e.what() << "\n";
      delete[] str;
      for (size_t i = 0; i < shapeNumber; i++)
      {
        delete shapeArray[i];
      }
      return 1;
    }
    delete[] str;
  }
  if (errors)
  {
    std::cerr << "Some names are incorrect!\n";
  }
  for (size_t i = 0; i < shapeNumber; i++)
  {
    delete shapeArray[i];
  }
}
