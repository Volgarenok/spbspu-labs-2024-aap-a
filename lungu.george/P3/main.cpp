#include <iostream>
#include <fstream>
#include <vector>
#include "spiral_decrement.h"
#include "savetofile.h"
#include "count_columns.h"
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
        if (inFile.eof()) {
            throw std::runtime_error("Input file is empty!");
        }

        int** matrix = nullptr;

        if (num == 1) {
            const int fixedRows = 5;
            const int fixedCols = 5;
            if (rows > fixedRows || cols > fixedCols) {
                throw std::invalid_argument("For num = 1, rows and cols must be less than or equal to 5.");
            }

            matrix = new int*[fixedRows];
            for (int i = 0; i < fixedRows; ++i) {
                matrix[i] = new int[fixedCols]{0};
            }

            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    matrix[i][j] = (i * cols) + j + 1;
                }
            }

        } else if (num == 2) {
            matrix = new int*[rows];
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
        } else {
            throw std::invalid_argument("Invalid value for num. Use 1 for fixed array or 2 for dynamic array.");
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

        for (int i = 0; i < (num == 1 ? 5 : rows); ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
