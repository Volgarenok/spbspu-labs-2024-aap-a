#include "stringManip.h"

namespace aleksandrov
{
  std::string getWord(const std::string str, size_t numberOfWord)
  {
    size_t strSize = str.size();
    if (!strSize)
    {
      return "";
    }
    size_t wordStart = 0;
    size_t wordIndex = 0;
    for (size_t i = 0; i <= strSize; ++i)
    {
      if (str[i] == ' ' || i == strSize)
      {
        if (wordStart < i)
        {
          if (wordIndex == numberOfWord - 1)
          {
            return str.substr(wordStart, i - wordStart);
          }
          ++wordIndex;
        }
        wordStart = i + 1;
      }
    }
    return "";
  }

  std::string getShapeParams(const std::string str, size_t& count)
  {
    std::string params;
    std::string param = getWord(str, count + 2);
    while (param != "")
    {
      if (!count)
      {
        params += param;
      }
      else
      {
        params += " " + param;
      }
      ++count;
      param = getWord(str, count + 2);
    }
    return params;
  }

  std::string getScaleParams(const std::string str, double& x, double& y, double& k)
  {
    std::string param1 = getWord(str, 2);
    std::string param2 = getWord(str, 3);
    std::string param3 = getWord(str, 4);
    bool continues = getWord(str, 5) != "";
    if (param1 == "" || param2 == "" || param3 == "" || continues)
    {
      return "";
    }
    x = std::stod(param1);
    y = std::stod(param2);
    k = std::stod(param3);
    return "something not empty";
  }
}

