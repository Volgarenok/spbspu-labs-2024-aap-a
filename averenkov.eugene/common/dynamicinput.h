#ifndef DYNAMICINPUT_H
#define DYNAMICINPUT_H
#include <istream>
namespace averenkov
{
  char* arrayresize(const char* str, char* new_str);
  char* stringInput(std::istream& in);
}
#endif
