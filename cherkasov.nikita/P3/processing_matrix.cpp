#include "processing_matrix.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

void cherkasov::processFixedMatrix(const std::string & inputFile, const std::string & outputFile)
{
  std::ifstream inFile(inputFile);
  if (!inFile)
  {
    std::cerr << "Error: Cannot open input file." << "\n";
    exit(2);
  }
  int rows, cols;
  inFile >> rows >> cols;
  if (rows * cols > 10000)
  {
  std::cerr << "Error: Matrix size exceeds 10000 elements." << "\n";
  exit(2);
  }
  int matrix[10000];
  for (int i = 0; i < rows * cols; ++i)
  {
    inFile >> matrix[i];
  }
  inFile.close();
  int count = 0;
  for (int d = 1; d < rows; ++d)
  {
    bool hasZero = false;
    for (int i = 0; i < rows - d; ++i)
    {
      if (matrix[i * cols + (i + d)] == 0)
      {
        hasZero = true;
        break;
      }
  }
    if (!hasZero)
    {
      count++;
    }
  }
  std::ofstream outFile(outputFile);
  if (!outFile)
  {
  std::cerr << "Error: Cannot open output file." << "\n";
  exit(2);
  }
  outFile << count << "\n";
  outFile.close();
  }
void cherkasov::processDynamicMatrix(const std::string& inputFile, const std::string& outputFile)
{
  std::ifstream inFile(inputFile);
  if (!inFile)
  {
    std::cerr << "Error: Cannot open input file." << "\n";
    exit(2);
  }
  int rows, cols;
  inFile >> rows >> cols;
  int* matrix = new int[rows * cols];
  for (int i = 0; i < rows * cols; ++i)
  {
    inFile >> matrix[i];
  }
    inFile.close();
    int count = 0;
    for (int d = 1; d < rows; ++d)
    {
    bool hasZero = false;
    for (int i = 0; i < rows - d; ++i)
    {
      if (matrix[i * cols + (i + d)] == 0)
      {
        hasZero = true;
        break;
      }
    }
      if (!hasZero)
      {
        count++;
      }
    }
    std::ofstream outFile(outputFile);
    if (!outFile)
    {
      std::cerr << "Error: Cannot open output file." << "\n";
      exit(2);
    }
      outFile << count << "\n";
      outFile.close();
      delete[] matrix;
}
