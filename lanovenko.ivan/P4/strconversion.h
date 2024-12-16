#ifndef STRCONVERSION_H
#define STRCONVERSION_H
#include <istream>
namespace lanovenko
{
  char* inputStr(std::istream& in, char stop);
  void transformationStr(const char* str, char* missing);
}
#endif
