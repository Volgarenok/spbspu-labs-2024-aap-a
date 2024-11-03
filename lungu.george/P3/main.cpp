#include <iostream>
#include <fstream>
#include <vector>
#include "spiral_decrement.h"
#include "savetofile.h"
int main(int argc, char* argv[]) {
    try {
        if (argc != 4) {
            throw std::invalid_argument("Using: " + std::string(argv[0]) + " num input output");
        }
        const int num = std::stoi(argv[1]);
        const std::string inputFileName = argv[2];
        const std::string outputFileName = argv[3];
        std::ifstream inFile(inputFileName);
        if (!inFile) {
            throw std::runtime_error("Error during file unpacking!");
        }
        int rows, cols;
        inFile >> rows >> cols;
        int** matrix = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            matrix[i] = new int[cols];
        }
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (!(inFile >> matrix[i][j])) {
                    throw std::runtime_error("Error during matrix reading!");
                }
            }
        }
        inFile.close();
        lungu::spiralDecrement(matrix, rows, cols);
        lungu::saveToFile(matrix, rows, cols, outputFileName);
        for (int i = 0; i < rows; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    } catch (const std::exception& e) {
        std::cerr << "Error" << "/n";
        return 1;
    }
    return 0;
}

