#include <strinput.hpp>
#include <cstring>
#include "shape.hpp"
#include "rectangle.hpp"
#include "diamond.hpp"
#include "polygon.hpp"
#include "shapeManipulator.hpp"

int main()
{
  mozhegova::Shape * shapes[1000] = {};
  size_t count = 0;
  bool flag = false;
  double scaleCoef = 0.0;
  mozhegova::point_t scaleCenter = {0.0, 0.0};
  while (true)
  {
    if (std::cin.eof())
    {
      std::cerr << "Incorrect scale\n";
      mozhegova::destroy(shapes, count);
      return 1;
    }
    char * str = nullptr;
    try
    {
      str = mozhegova::inputString(std::cin, '\n');
    }
    catch (const std::exception& e)
    {
      std::cerr << "Out of memory\n";
      return 1;
    }
    if (str[0] == '\0')
    {
      delete[] str;
      continue;
    }

    double * num = nullptr;
    size_t len = 0;
    char * tok = std::strtok(str, " ");
    bool isRectangle = std::strcmp(tok, "RECTANGLE") == 0;
    bool isDiamond = std::strcmp(tok, "DIAMOND") == 0;
    bool isPolygon = std::strcmp(tok, "POLYGON") == 0;
    bool isScale = std::strcmp(tok, "SCALE") == 0;

    if (isRectangle)
    {
      len = 4;
      try
      {
        num = mozhegova::getNum(tok, len);
      }
      catch (const std::exception& e)
      {
        std::cerr << "Out of memory\n";
        delete[] str;
        mozhegova::destroy(shapes, count);
        return 1;
      }
      mozhegova::point_t lowLef = {num[0], num[1]};
      mozhegova::point_t uppRig = {num[2], num[3]};
      if (lowLef.x >= uppRig.x || lowLef.y >= uppRig.y)
      {
        flag = true;
        delete[] str;
        delete[] num;
        continue;
      }
      mozhegova::Rectangle * rect = new mozhegova::Rectangle(lowLef, uppRig);
      shapes[count++] = rect;
      delete[] num;
    }
    else if (isDiamond)
    {
      len = 6;
      try
      {
        num = mozhegova::getNum(tok, len);
      }
      catch (const std::exception& e)
      {
        std::cerr << "Out of memory\n";
        delete[] str;
        mozhegova::destroy(shapes, count);
        return 1;
      }
      mozhegova::point_t p1 = {num[0], num[1]};
      mozhegova::point_t p2 = {num[2], num[3]};
      mozhegova::point_t p3 = {num[4], num[5]};
      try
      {
        mozhegova::Diamond * diam = new mozhegova::Diamond(p1, p2, p3);
        shapes[count++] = diam;
        delete[] num;
      }
      catch(const std::exception& e)
      {
        flag = true;
        delete[] str;
        delete[] num;
        continue;
      }
    }
    else if (isPolygon)
    {
      try
      {
        num = mozhegova::getNum(tok, len);
      }
      catch (const std::exception& e)
      {
        std::cerr << "Out of memory\n";
        delete[] str;
        mozhegova::destroy(shapes, count);
        return 1;
      }
      if (len < 6)
      {
        flag = true;
        delete[] str;
        delete[] num;
        continue;
      }
      mozhegova::point_t * numPoint = nullptr;
      try
      {
        numPoint = new mozhegova::point_t [len / 2];
      }
      catch (const std::exception& e)
      {
        std::cerr << "Out of memory\n";
        delete[] str;
        delete[] num;
        mozhegova::destroy(shapes, count);
        return 1;
      }
      for (size_t i = 0; i < len / 2; i++)
      {
        numPoint[i] = {num[i * 2], num[i * 2 + 1]};
      }
      for (size_t i = 0; i < (len - 1) / 2; i++)
      {
        for (size_t j = i + 1; j < len / 2; j++)
        {
          if (numPoint[i].x == numPoint[j].x && numPoint[i].y == numPoint[j].y)
          {
            flag = true;
          }
        }
      }
      if (flag)
      {
        delete[] str;
        delete[] num;
        continue;
      }
      mozhegova::Polygon * poly = new mozhegova::Polygon(len / 2, numPoint);
      shapes[count++] = poly;
      delete[] num;
      delete[] numPoint;
    }
    else if (isScale)
    {
      len = 3;
      try
      {
        num = mozhegova::getNum(tok, len);
      }
      catch (const std::exception& e)
      {
        std::cerr << "Out of memory\n";
        delete[] str;
        mozhegova::destroy(shapes, count);
        return 1;
      }
      scaleCenter = {num[0], num[1]};
      scaleCoef = num[2];
      delete[] str;
      delete[] num;
      break;
    }
    delete[] str;
  }
  if (scaleCoef <= 0)
  {
    std::cerr << "Incorrect scale\n";
    mozhegova::destroy(shapes, count);
    return 1;
  }
  if (count == 0)
  {
    std::cerr << "There are no shapes\n";
    return 1;
  }
  std::cout << std::fixed;
  std::cout.precision(1);
  std::cout << mozhegova::sumArea(shapes, count);
  mozhegova::printCoorRect(shapes, count);
  mozhegova::scaleShapes(shapes, count, scaleCenter, scaleCoef);
  std::cout << mozhegova::sumArea(shapes, count);
  mozhegova::printCoorRect(shapes, count);
  mozhegova::destroy(shapes, count);
  if (flag)
  {
    std::cerr << "There is an incorrect shape\n";
  }
}
