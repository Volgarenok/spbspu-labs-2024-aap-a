#include <iostream>
#include <stdexcept>
#include <string>
#include <iomanip>
#include <cstddef>
#include "shape.hpp"
#include "base-types.hpp"
#include "rectangle.hpp"
#include "makeObjects.hpp"
#include "countFinalResults.hpp"
#include "scale.hpp"

int main()
{
  const size_t capacity = 10000;
  finaev::Shape* shapes[capacity] = {};
  std::string str = "";
  size_t size = 0;
  double k = 0.0;
  finaev::point_t scaleCenter = {0, 0};
  std::string coordinates = "";
  bool isCorrect = false;
  bool isScale = false;
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
        try
        {
          shapes[size] = finaev::makeRectangle(std::cin);
          if (shapes[size] == nullptr)
          {
            isCorrect = true;
          }
          size++;
        }
        catch(std::bad_alloc & e)
        {
          finaev::deleteShapes(shapes, size);
          std::cerr << "Error alloc" << "\n";
          return 1;
        }
      }
      else if (str == "SQUARE")
      {
        try
        {
          shapes[size] = finaev::makeSquare(std::cin);
          if (shapes[size] == nullptr)
          {
            isCorrect = true;
          }
          size++;
        }
        catch(std::bad_alloc & e)
        {
          finaev::deleteShapes(shapes, size);
          std::cerr << "Error alloc" << "\n";
          return 1;
        }
      }
      else if (std::cin.eof())
      {
        deleteShapes(shapes, size);
        std::cerr << "the program is completed by eof, but scale not described\n";
        return 1;
      }
      else if (str == "SCALE")
      {
        isScale = true;
        std::cin >> scaleCenter.x;
        std::cin >> scaleCenter.y;
        std::cin >> k;
        if (k <= 0)
        {
          std::cerr << "Uncorrect scale coefficient!\n";
          finaev::deleteShapes(shapes, size);
          return 1;
        }
        break;
      }
    }
    if (!isScale)
    {
      std::cerr << "no scale!\n";
      finaev::deleteShapes(shapes, size);
      return 1;
    }
    if (isCorrect)
    {
      std::cerr << "Input has uncorrects figures!\n";
    }
    if (size == 0)
    {
      std::cerr << "No figures!\n";
      return 1;
    }
    std::cout << std::fixed << std::setprecision(1) << finaev::getSumArea(shapes, size);
    finaev::printFrameRect(shapes, size);
    std::cout << "\n";
    finaev::scale(shapes, size, scaleCenter, k);
    std::cout << std::fixed << std::setprecision(1) << finaev::getSumArea(shapes, size);
    finaev::printFrameRect(shapes, size);
    std::cout << "\n";
    finaev::deleteShapes(shapes, size);
    return 0;
  }
  catch (std::logic_error& e)
  {
    finaev::deleteShapes(shapes, size);
    return 1;
  }
}
