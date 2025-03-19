#ifndef INPUT_CHECKS_H
#define INPUT_CHECKS_H

#include <string>
#include <fstream>

namespace kalmbah {

bool isNumber(const std::string& str);
bool isInputFileEmpty(std::ifstream& inputFile);
bool isValidMatrixSize(int rows, int cols);
bool isValidMatrixElement(int value);

}

#endif
