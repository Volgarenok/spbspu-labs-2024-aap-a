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

        // Открытие входного файла
        std::ifstream inFile(inputFileName);
        if (!inFile) {
            throw std::runtime_error("Error during file unpacking!");
        }

        int rows, cols;
        inFile >> rows >> cols;

        // Создание массива в зависимости от значения num
        int** matrix = nullptr;

        if (num == 1) {
            // Фиксированный массив
            const int fixedRows = rows; // Пример фиксированного размера
            const int fixedCols = cols; // Пример фиксированного размера
            matrix = new int*[fixedRows];
            for (int i = 0; i < fixedRows; ++i) {
                matrix[i] = new int[fixedCols];
            }

            // Инициализация фиксированного массива (можно изменить по необходимости)
            for (int i = 0; i < fixedRows; ++i) {
                for (int j = 0; j < fixedCols; ++j) {
                    matrix[i][j] = (i * fixedCols) + j + 1; // Просто пример
                }
            }

            rows = fixedRows;
            cols = fixedCols;

        } else if (num == 2) {
            // Динамический массив
            matrix = new int*[rows];
            for (int i = 0; i < rows; ++i) {
                matrix[i] = new int[cols];
            }

            // Чтение матрицы из файла
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

        // Обработка матрицы
        lungu::spiralDecrement(matrix, rows, cols);
        
        // Подсчет столбцов без подряд идущих одинаковых элементов
        int count = lungu::countColumnsWithoutConsecutiveDuplicates(matrix, rows, cols);

        // Сохранение результата в файл
        lungu::saveToFile(matrix, rows, cols, outputFileName);

        // Запись количества столбцов в тот же файл
        std::ofstream outFile(outputFileName, std::ios_base::app); // Открываем файл для добавления
        if (outFile) {
            outFile << "Количество столбцов без подряд идущих одинаковых элементов: " << count << std::endl;
            outFile.close();
        } else {
            throw std::runtime_error("Error during file writing!");
        }

        // Освобождение памяти
        for (int i = 0; i < rows; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}


