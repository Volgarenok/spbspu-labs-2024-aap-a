#include <strinput.hpp>
#include <cstring>

int main()
{
  char * str = nullptr;
  mozhegova::Shape * shapes[1000] = {};
  size_t count = 0;
  bool flag = false;
  double scaleCoef = 0.0;
  mozhegova::point_t scaleCenter = {0.0, 0.0};
  while (!std::cin.eof())
  {
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
  if (flag)
  {
    std::cerr << "There is an incorrect shape\n";
  }
}