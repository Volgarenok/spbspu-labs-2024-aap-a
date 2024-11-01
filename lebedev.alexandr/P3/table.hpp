#ifndef TABLE_HPP
#define TABLE_HPP
#include <fstream>

bool isNumbers(char* t);
std::istream& inputTable(std::istream& inputFile, int* arr, size_t size);
void outputTable(std::ostream& outputFile, int* arr, size_t m);
#endif
