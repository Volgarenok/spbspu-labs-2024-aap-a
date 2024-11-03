#include <iostream>
#include <fstream>
#include "savetofile.h"
namespace lungu {

void saveToFile(int** matrix, int rows, int cols, const std::string& outputFileName) {
    std::ofstream outFile(outputFileName);
    if (!outFile) {
        std::cerr << "Error during file unpacking!" << std::endl;
        return;
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            outFile << matrix[i][j] << " ";
        }
        outFile << std::endl;
    }
    outFile.close();
}

}
