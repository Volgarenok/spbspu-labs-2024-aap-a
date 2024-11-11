#include <iostream>
#include <fstream>
#include <vector>
#include "spiral_decrement.h"
#include "savetofile.h"
#include "count_columns.h"
#include "cleanup.h"

int main(int argc, char* argv[]) {
    int** matrix = nullptr;
    int rows = 0;
    int cols = 0;
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

        if (inFile.eof() || (rows == 0 || cols == 0)) {
            std::ofstream outFile(outputFileName);
            if (outFile) {
                outFile << "0 0" << std::endl;
            }
            return 0;
        }

        if (num == 2 && inFile.peek() == EOF) {
            std::ofstream outFile(outputFileName);
            if (outFile) {
            }
            return 0;
        }

        if (num == 1) {
            static const int fixedRows = 5;
            static const int fixedCols = 5;

            if (rows > fixedRows || cols > fixedCols) {
                throw std::runtime_error("Not enough data" +
                    std::to_string(fixedRows) + "x" + std::to_string(fixedCols));
            }

            matrix = new int*[fixedRows];
            for (int i = 0; i < fixedRows; ++i) {
                matrix[i] = new int[fixedCols];
            }

            for (int i = 0; i < fixedRows; ++i) {
                for (int j = 0; j < fixedCols; ++j) {
                    matrix[i][j] = (i * fixedCols) + j + 1;
                }
            }

            rows = fixedRows;
            cols = fixedCols;

        } else if (num == 2) {
            matrix = new int*[rows];
            for (int i = 0; i < rows; ++i) {
                matrix[i] = new int[cols];
            }

            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    if (!(inFile >> matrix[i][j])) {
                        throw std::runtime_error("Not enough data for dynamic array");
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
        } else {
            throw std::runtime_error("Error during file writing!");
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    lungu::cleanup(matrix, rows);

    return 0;
}

