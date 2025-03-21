#include <iostream>
#include <iomanip>
#include <limits>
#include "shapemaking.hpp"
#include "shape.hpp"
#include "base-types.hpp"
#include "concave.hpp"
#include "rectangle.hpp"
#include "complexquad.hpp"
#include "tools.hpp"


int main()
{
  ivanova::Shape* shapes[1000] = {};
  std::string input = "";
  size_t size = 0;
  double k = 0.0;
  ivanova::point_t scaleCenter = {0, 0};
  std::string coordinates = "";
  bool isScale = false;

  try
  {
    while (std::cin >> input)
    {
      if (input.empty())
      {
        continue;
      }
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
          std::cin >> x >> y >> k;
          if (k <= 0)
          {
            std::cerr << "Incorrect scale coefficient!" << '\n';
            ivanova::deleteShapes(shapes, size);
            return 1;
          }
        scaleCenter = {x, y};
        isScale = true;
        }
        else
        {
          std::cerr << "Unknown command: " << input << '\n';
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }
      }
      catch (std::bad_alloc & e)
      {
        std::cerr << "Out of memory" << "\n";
        ivanova::deleteShapes(shapes, size);
        return 1;
      }
      catch (const std::invalid_argument& e)
      {
        std::cerr << "Incorrect shape size" << '\n';
      }
    }
    if (!isScale)
    {
      std::cerr << "Incorrect scale!" << '\n';
      ivanova::deleteShapes(shapes, size);
      return 1;
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
    try
    {
      ivanova::scale(shapes, size, scaleCenter, k);
    }
    catch(const std::invalid_argument& e)
    {
      std::cerr << "Incorrect scale!" << '\n';
      ivanova::deleteShapes(shapes, size);
      return 1;
    }
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
