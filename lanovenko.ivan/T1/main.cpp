#include <iostream>
#include <cstring>
#include "strinput.h"
#include "shape.hpp"
#include "string_manipulations.hpp"
#include "delete_shape.hpp"
#include "scale_functions.hpp"

int main()
{
  using namespace lanovenko;
  bool scale = false;
  bool errors = false;
  size_t res = 0;
  Shape* shapeArray[10000] = { nullptr };
  while (scale != true)
  {
    if (std::cin.eof())
    {
      deleteShape(shapeArray, res);
      std::cerr << "Wrong input!\n";
      return 1;
    }
    Shape* currentFigure = nullptr;
    const char* cStr = nullptr;
    try
    {
      cStr = input_string(std::cin, '\n');
    }
    catch (const std::bad_alloc& e)
    {
      deleteShape(shapeArray, res);
      std::cerr << e.what() << "\n";
      return 1;
    }
    if (std::strstr(cStr, "SCALE") == nullptr)
    {
      try
      {
        currentFigure = parseShape(cStr);
        shapeArray[res++] = currentFigure;
        delete[] cStr;
      }
      catch (const std::bad_alloc& e)
      {
        deleteShape(shapeArray, res);
        delete[] cStr;
        std::cerr << "Out of memmory!\n";
        return 1;
      }
      catch (const std::invalid_argument& e)
      {
        delete[] cStr;
        errors = true;
      }
      catch (const std::logic_error& e)
      {
        delete[] cStr;
        continue;
      }
     }
    else
    {
      scale = true;
      double scaleParametrs[3];
      try
      {
        parseScale(scaleParametrs, cStr);
        scaleShapes(shapeArray, scaleParametrs, std::cout, res);
        delete[] cStr;
      }
      catch (const std::invalid_argument& e)
      {
        deleteShape(shapeArray, res);
        delete[] cStr;
        std::cerr << e.what() << "\n";
        return 1;
      }
    }
  }
  if (errors == true)
  {
    std::cerr << "Some figures are incorrectly described!\n";
  }
  deleteShape(shapeArray, res);
}
