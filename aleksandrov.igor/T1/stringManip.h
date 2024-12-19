#ifndef STRINGMANIP_H
#define STRINGMANIP_H

#include <string>

namespace aleksandrov
{
  std::string getWord(const std::string str, size_t numberOfWord);
  std::string getShapeParams(const std::string str, size_t& count);
  std::string getScaleParams(const std::string str, double& x, double& y, double& k);
}

#endif

