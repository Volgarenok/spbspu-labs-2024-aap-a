#include<iostream>

int main()
{
  size_t capacity = 5;
  char* line = reinterpret_cast<char*>(malloc(sizeof(char) * (capacity)));
  if (line == nullptr)
  {
    std::cerr << "Memory was not allocated\n";
    return 1;
  }
}
