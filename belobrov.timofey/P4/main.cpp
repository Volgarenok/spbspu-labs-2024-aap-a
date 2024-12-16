#include <iostream>

int main() {
  char* line = belobrov::inputLine(std::cin);
  if (line == nullptr) {
    std::cerr << "Memory allocation error!\n";
    return 1;
  }

  if (line[0] == '\0') {
    std::cerr << "Line is empty!\n";
    free(line);
    return 1;
  }
}
