#include <iostream>
#include <stdexcept>
#include <string>
#include <iomanip>
#include <cstddef>
#include "shape.h"
#include "base-types.h"
#include "rectangle.h"
#include "makeObjects.h"
#include "countFinalResults.h"
#include "scale.h"

int main()
{
  const size_t capacity = 10;
  finaev::Shape* shapes[capacity] = {};
  std::string str = "";
  size_t size = 0;
  double k;
  finaev::point_t scaleCenter;
  std::string coordinates = "";
  try
  {
    while (std::cin >> str)
    {
      if (size == capacity)
      {
        std::cerr << "Error. There is no scale!\n";
        return 1;
      }
      else if (str == "RECTANGLE")
      {
        finaev::Rectangle* a = finaev::makeRectangle(std::cin);
        shapes[size] = a;
        size++;
      }
      else if (std::cin.eof())
      {
        std::cerr << "the program is completed by eof, but scale not described\n";
        deleteShapes(shapes, size);
        return 1;
      }
      else if (str == "SCALE")
      {
        std::cin >> scaleCenter.x;
        std::cin >> scaleCenter.y;
        std::cin >> k;
        if (k <= 0)
        {
          std::cerr << "Uncorrect scale coefficient!";
	  return 1;
        }
        std::cout << std::setprecision(2) << finaev::getSumArea(shapes, size) << " ";
        finaev::printFrameRect(shapes, size);
        break;
      }
    }
    finaev::scale(shapes, size, scaleCenter, k);
    std::cout << std::setprecision(2) << finaev::getSumArea(shapes, size) << " ";
    finaev::printFrameRect(shapes, size);
    return 0;
  }
  catch (std::bad_alloc& e)
  {
    finaev::deleteShapes(shapes, size);
    return 1;
  }
}
