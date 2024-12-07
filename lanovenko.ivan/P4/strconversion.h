#ifndef STRCONVERSION_H
#define STRCONVERSION_H
#include <istream>
namespace lanovenko
{
  char* inputstring(std::istream& in, const char stop);
  char* transformationstr(char* str);
}
#endif
