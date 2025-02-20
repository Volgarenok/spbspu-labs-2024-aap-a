#include <iostream>
#include <iomanip>
#include "shapemaking.hpp"
#include "shape.hpp"
#include "base-types.hpp"
#include "concave.hpp"
#include "rectangle.hpp"
#include "complexquad.hpp"
#include "tools.hpp"


int main()
{
  ivanova::Shape* shapes[10000] = {};
  std::string input = "";
  size_t size = 0;
  double k = 0.0;
  ivanova::point_t scaleCenter = {0, 0};
  std::string coordinates = "";
  bool isCorrect = false;
  bool isScale = false;

  try
  {
    while (std::cin >> input)
    {
      try
      {
        if (input == "RECTANGLE")
        {
          shapes[size] = ivanova::createRectangle(std::cin);
          size++;
        }
        else if (input == "COMPLEXQUAD")
        {
          shapes[size] = ivanova::createComplexquad(std::cin);
          size++;
        }
        else if (input == "CONCAVE")
        {
          shapes[size] = ivanova::createConcave(std::cin);
          size++;
        }
        else if (input == "DIAMOND")
        {
          shapes[size] = ivanova::createDiamond(std::cin);
          size++;
        }
        else if (input == "SCALE")
        {
          double x, y;
          std::cin >> x >> y;
          if (k <= 0)
          {
            std::cerr << "Incorrect scale coefficient!" << '\n';
            return 1;
          }
        scaleCenter = {x, y};
        ivanova::scale(shapes, size, scaleCenter, k);
        isScale = true;
        }
      }
      catch (std::bad_alloc & e)
      {
        std::cerr << "Out of memory" << "\n";
        ivanova::deleteShapes(shapes, size);
        return 1;
      }
    }
    if (std::cin.eof())
    {
      ivanova::deleteShapes(shapes, size);
      std::cerr << "EOF" << '\n';
      return 1;
    }
    if (!isScale)
    {
      std::cerr << "Incorrect scale!" << '\n';
      ivanova::deleteShapes(shapes, size);
      return 1;
    }
    if (isCorrect)
    {
      std::cerr << "Input has uncorrects figures!\n";
    }
    if (size == 0)
    {
      std::cerr << "No figure was entered!" << '\n';
      return 1;
    }
    std::cout << std::fixed;
    std::cout << std::setprecision(1);
    std::cout << ivanova::getSumArea(shapes, size);
    ivanova::printFrameRect(shapes, size);
    ivanova::scale(shapes, size, scaleCenter, k);
    std::cout << ivanova::getSumArea(shapes, size);
    ivanova::printFrameRect(shapes, size);
    ivanova::deleteShapes(shapes, size);
    return 0;
  }
  catch (std::logic_error& e)
  {
    ivanova::deleteShapes(shapes, size);
    return 1;
  }
}
