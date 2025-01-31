#ifndef NEWLINETERMINATEDSTR_H
#define NEWLINETERMINATEDSTR_H
#include <iostream>

namespace savintsev
{
  char * inputNewlineTerminatedStr(std::istream & in);
  char * createEnlargedCopiedStr(const char * old, size_t m);
}

#endif
