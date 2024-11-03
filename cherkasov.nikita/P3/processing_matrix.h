#ifndef MATRIX_PROCESSING_H
#define MATRIX_PROCESSING_H
#include <string>

namespace cherkasov
{
void processFixedSizeArray(const std::string& inputFile, const std::string& outputFile);
void processDynamicMatrix(const std::string& inputFile, const std::string& outputFile);
}
#endif
