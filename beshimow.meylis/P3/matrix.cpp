#include "matrix.hpp"

namespace beshimow {
    std::istream& input(std::istream& inputFile, int* arr, size_t m) {
        for (size_t i = 0; i < m * m; ++i) {
            inputFile >> arr[i];
        }
        return inputFile; // Возвращаем поток для возможной цепочки вызовов
    }

    bool lwrTriMtx(const int* arr, size_t m) {
        bool flag = true;
        for (size_t i = 0; i < m; ++i) {
            for (size_t j = i + 1; j < m; ++j) {
                if (arr[i * m + j] != 0) {
                    flag = false;
                    break;
                }
            }
        }
        return flag; // Возвращаем результат проверки
    }
}
