#ifndef FUNCS_H
#define FUNCS_H

namespace demehin
{
  const char* hasLetter(const char* str);
  const char* hasNumber(const char* str);
  const char* hasUInt(const char* str);
  const char* hasIdent(const char* str);
  const char* hasTerm(const char* str);
  const char* isExpr(const char* str);
  const char* hasMultipl(const char* str);
  const char* hasExpr(const char* str);
  const char* hasMultiplAndTerm(const char* str);
  const char* hasTermPlusExpr(const char* str);
  const char* hasTermMinusExpr(const char* str);
}
#endif

