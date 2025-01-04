#include <cstddef>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include "actionShapes.hpp"
#include "composite-shape.hpp"
#include "makeShapes.hpp"
#include "shape.hpp"
int main()
{
  kiselev::Shape* shape = nullptr;
  constexpr size_t capacity = 100;
  kiselev::CompositeShape compShp(capacity);
  std::string titleShape;
  bool isIncorrectShape = false;
  kiselev::point_t scale;
  double ratio = 0;
  try
  {
    while (std::cin >> titleShape)
    {
      if (std::cin.eof())
      {
        std::cerr << "The input ended with eof\n";
        return 1;
      }
      try
      {
        if (titleShape == "RECTANGLE")
        {
          shape = kiselev::make_rectangle(std::cin);
          compShp.push_back(shape);
        }
        else if (titleShape == "DIAMOND")
        {
          shape = kiselev::make_diamond(std::cin);
          compShp.push_back(shape);
        }
        else if (titleShape == "COMPLEXQUAD")
        {
          shape = kiselev::make_complexquad(std::cin);
          compShp.push_back(shape);
        }
        else if (titleShape == "SCALE")
        {
          scale = kiselev::make_scale(std::cin);
          std::cin >> ratio;
          if (ratio <= 0)
          {
            std::cerr << "Incorrect ratio\n";
            return 1;
          }
          break;
        }
      }
      catch (std::invalid_argument& e)
      {
        isIncorrectShape = true;
      }
    }
    if (isIncorrectShape)
    {
      std::cerr << "There was an error in the description of the scale\n";
    }
    if (compShp.empty())
    {
      std::cerr << "The scales were not passed\n";
      return 1;
    }
    if (ratio == 0)
    {
        std::cerr << "Not entered SCALE\n";
        return 1;
    }
    std::cout << std::fixed << std::setprecision(1) << compShp.getArea();
    kiselev::printCoordinatesRect(std::cout, compShp);
    compShp.scale(ratio, scale);
    std::cout << compShp.getArea();
    kiselev::printCoordinatesRect(std::cout, compShp);
    return 0;
  }
  catch (const std::out_of_range& e)
  {
    std::cerr << e.what();
    return 1;
  }
  catch (const std::logic_error& e)
  {
    std::cerr << e.what();
    return 1;
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Memory was not allocated\n";
    return 1;
  }
}
