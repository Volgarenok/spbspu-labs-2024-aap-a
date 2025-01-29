#include <iostream>
#include <cstring>
#include <cctype>

namespace beshimow {
    void excludeCharacters(const char* str1, const char* str2, char*& result) {
        // Определяем длину входной строки
        size_t len1 = std::strlen(str1);
        size_t len2 = std::strlen(str2);

        // Выделяем память для выходной строки (максимально возможная длина)
        result = new char[len1 + 1]; // +1 для нуль-терминатора
        if (!result) {
            std::cerr << "Ошибка выделения памяти" << std::endl;
            exit(1);
        }

        size_t resultIndex = 0;

        // Проходим по каждому символу входной строки
        for (size_t i = 0; i < len1; ++i) {
            bool shouldExclude = false;

            // Проверяем, есть ли символ в строке исключений
            for (size_t j = 0; j < len2; ++j) {
                if (str1[i] == str2[j]) {
                    shouldExclude = true;
                    break;
                }
            }

            // Если символ не нужно исключать, добавляем его в выходную строку
            if (!shouldExclude) {
                result[resultIndex++] = str1[i];
            }
        }

        // Завершаем выходную строку нуль-терминатором
        result[resultIndex] = '\0';
    }
}

int main() {
    // Считываем строку из стандартного ввода
    char* input = nullptr;
    std::cout << "Введите строку: ";
    std::string temp;
    std::getline(std::cin, temp);

    // Выделяем память для входной строки
    input = new char[temp.length() + 1];
    if (!input) {
        std::cerr << "Ошибка выделения памяти" << std::endl;
        return 1;
    }
    std::strcpy(input, temp.c_str());

    // Вторая строка, символы которой будут исключены
    const char* exclude = "abc";
    char* output = nullptr;

    // Вызываем функцию для исключения символов
    beshimow::excludeCharacters(input, exclude, output);

    // Выводим результат
    std::cout << output << std::endl;

    // Освобождаем выделенную память
    delete[] input;
    delete[] output;

    return 0; // Завершение программы с кодом возврата 0
}
