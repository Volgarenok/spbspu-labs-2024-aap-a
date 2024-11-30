#ifndef STRCONVERSION_H
#define STRCONVERSION_H
#include <istream>
namespace lanovenko
{
  char* inputStr(std::istream& in, const char stop);
  char* transformationStr(char* str);
}
#endif
