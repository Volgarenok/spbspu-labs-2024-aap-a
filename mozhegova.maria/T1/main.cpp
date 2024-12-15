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
    {}
    else if (isScale)
    {}
    delete[] str;
  }
}