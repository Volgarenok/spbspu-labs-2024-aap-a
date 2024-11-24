#include "CheckRealNumber.hpp"

char * zakirov::compare_literals(char * line, char literal){
	  if (!line)
  	{
    	return line;
  	}
		return (* line == literal) ? (line + 1) : nullptr;
}

