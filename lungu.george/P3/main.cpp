#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include "spiral_decrement.h"
#include "savetofile.h"
#include "count_columns.h"

int main(int argc, char* argv[]) {
    int** matrix = nullptr;
    int rows = 0;
    int cols = 0;

    try {
        if (argc != 3) {
            throw std::invalid_argument("Using: " + std::string(argv[0]) + " input output");
        }

        const std::string inputFileName = argv[1];
        const std::string outputFileName = argv[2];

        std::ifstream inFile(inputFileName);
        if (!inFile) {
            throw std::runtime_error("Error during file unpacking!");
        }

        inFile >> rows >> cols;

        if (rows <= 0 || cols <= 0) {
            return 0;
        }

        matrix = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            matrix[i] = new int[cols];
        }

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (!(inFile >> matrix[i][j])) {
                    throw std::runtime_error("Not enough data");
                }
            }
        }

        inFile.close();

        lungu::spiralDecrement(matrix, rows, cols);
        int count = lungu::countColumnsWithoutConsecutiveDuplicates(matrix, rows, cols);

        lungu::saveToFile(matrix, rows, cols, outputFileName);

        std::ofstream outFile(outputFileName, std::ios_base::app);
        if (outFile) {
            outFile << count << std::endl;
            outFile.close();
        } else {
            throw std::runtime_error("Error during file writing!");
        }

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;

        if (matrix) {
            for (int i = 0; i < rows; ++i) {
                delete[] matrix[i];
            }
            delete[] matrix;
        }
        return 2;
    }
    if (matrix) {
        for (int i = 0; i < rows; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    return 0;
}

