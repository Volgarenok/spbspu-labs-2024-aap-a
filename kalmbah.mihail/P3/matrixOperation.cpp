#include "matrixOperation.hpp"
#include <stdexcept>

namespace kalmbah
{
  std::istream& inputMtx(std::istream& in, int* mtx, size_t columns, size_t rows)
  {
    for (size_t i = 0; i < columns * rows; ++i)
    {
      if (!(in >> mtx[i]))
      {
        throw std::runtime_error("Input error");
      }
    }
    return in;
  }

  void mirrorHorizontal(const int* src, int* dest, size_t columns, size_t rows)
  {
    for (size_t i = 0; i < rows; ++i)
    {
      for (size_t j = 0; j < columns; ++j)
      {
        dest[i * columns + j] = src[(rows - 1 - i) * columns + j];
      }
    }
  }

  void mirrorVertical(const int* src, int* dest, size_t columns, size_t rows)
  {
    for (size_t i = 0; i < rows; ++i)
    {
      for (size_t j = 0; j < columns; ++j)
      {
        dest[i * columns + j] = src[i * columns + (columns - 1 - j)];
      }
    }
  }

  void mirrorCorner(const int* src, int* dest, size_t columns, size_t rows)
  {
    int* temp = new int[columns * rows]{};
    mirrorHorizontal(src, temp, columns, rows);
    mirrorVertical(temp, dest, columns, rows);
    delete[] temp;
  }

  void combineMatrices(const int* original, int* result, size_t columns, size_t rows)
  {
    const size_t newCols = columns * 2;

    for (size_t i = 0; i < rows; ++i)
    {
      for (size_t j = 0; j < columns; ++j)
      {
        result[i * newCols + j] = original[i * columns + j];
      }
    }

    int* vertical = new int[columns * rows]{};
    mirrorVertical(original, vertical, columns, rows);
    for (size_t i = 0; i < rows; ++i)
    {
      for (size_t j = 0; j < columns; ++j)
      {
        result[i * newCols + (columns + j)] = vertical[i * columns + j];
      }
    }
    delete[] vertical;

    int* horizontal = new int[columns * rows]{};
    mirrorHorizontal(original, horizontal, columns, rows);
    for (size_t i = 0; i < rows; ++i)
    {
      for (size_t j = 0; j < columns; ++j)
      {
        result[(rows + i) * newCols + j] = horizontal[i * columns + j];
      }
    }
    delete[] horizontal;

    int* corner = new int[columns * rows]{};
    mirrorCorner(original, corner, columns, rows);
    for (size_t i = 0; i < rows; ++i)
    {
      for (size_t j = 0; j < columns; ++j)
      {
        result[(rows + i) * newCols + (columns + j)] = corner[i * columns + j];
      }
    }
    delete[] corner;
  }

  void outputMtx(std::ostream& out, const int* mtx, size_t columns, size_t rows)
  {
    out << columns << " " << rows;
    for (size_t i = 0; i < rows; ++i)
    {
      for (size_t j = 0; j < columns; ++j)
      {
        out << " " << mtx[i * columns + j];
      }
    }
    out << "\n";
  }
}
