#ifndef EXC_SND_HPP
#define EXC_SND_HPP

<<<<<<< HEAD
namespace zholobov {
=======
#include <istream>

namespace zholobov {
  char* read_string(std::istream& input);
>>>>>>> parent of f7ab4f9b (Revert "Merge branch 'dribas.sergey/P6' into dribas.sergey/P4")
  char* exc_snd(char* dst, const char* src, const char* excl_chars);
}

#endif
