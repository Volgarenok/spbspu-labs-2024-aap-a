#include "io_utils.hpp"
#include <cstring>
#include <iomanip>
#include <ostream>
#include "shape_utils.hpp"

namespace kizhin {
  char* parseInputWord(std::istream&);
  double* parseInputParams(std::istream&);
  void resizeBuffer(double** buffer, size_t& capacity);
  void resetPointers(char**, double**);
  void throwIfNotScaleOrSize(bool isScaleCommand, size_t shapesSize);
  void copy(const double*, const double*, double*);
  void copy(const char*, const char*, char*);
}

std::ostream& kizhin::outputShapesInfo(std::ostream& os, const Shape* const* shapes, size_t size)
{
  os << std::fixed << std::setprecision(1);
  os << computeTotalArea(shapes, size);
  for (const Shape* const* i = shapes; i != shapes + size; ++i) {
    outputShapeFrame(os << ' ', *i);
  }
  return os;
}

std::ostream& kizhin::outputShapeFrame(std::ostream& os, const Shape* shape)
{
  rectangle_t frame = shape->getFrameRect();
  const double x1 = frame.pos.x - frame.width / 2;
  const double x2 = frame.pos.x + frame.width / 2;
  const double y1 = frame.pos.y - frame.height / 2;
  const double y2 = frame.pos.y + frame.height / 2;
  return os << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2;
}

std::ostream& kizhin::outputShapeError(std::ostream& os, const char* name, const double* params)
{
  os << "Error: Invalid Shape Constructor Values: " << name;
  os << std::fixed << std::setprecision(1);
  for (const double* i = params + 1; i != params + 1 + static_cast< size_t >(params[0]); ++i) {
    os << ' ' << *i;
  }
  return os;
}

double* kizhin::processInput(std::istream& is, std::ostream& errs, size_t& size, Shape** shapes)
{
  bool isScaleCommand = false;
  char* currentName = nullptr;
  double* currentParams = nullptr;
  size = 0;
  try {
    while (is && !isScaleCommand) {
      parseInputString(is, &currentName, &currentParams);
      if (currentName && std::strcmp(currentName, "SCALE") == 0) {
        isScaleCommand = true;
      } else {
        Shape* currentShape = createShape(currentName, currentParams);
        if (currentShape) {
          shapes[size++] = currentShape;
        } else {
          outputShapeError(errs, currentName, currentParams) << '\n';
        }
        resetPointers(&currentName, &currentParams);
      }
    }
    throwIfNotScaleOrSize(isScaleCommand, size);
  } catch (...) {
    resetPointers(&currentName, &currentParams);
    throw;
  }
  delete[] currentName;
  return currentParams;
}

void kizhin::parseInputString(std::istream& is, char** nameOut, double** paramsOut)
{
  char* shapeName = parseInputWord(is);
  double* shapeParams = nullptr;
  try {
    shapeParams = parseInputParams(is);
  } catch (...) {
    delete[] shapeName;
    throw;
  }
  *nameOut = shapeName;
  *paramsOut = shapeParams;
}

char* kizhin::parseInputWord(std::istream& is)
{
  std::string shapeName;
  if (!(is >> shapeName)) {
    return nullptr;
  }
  char* shapeNameCStr = new char[shapeName.size() + 1];
  copy(shapeName.begin(), shapeName.end(), shapeNameCStr);
  shapeNameCStr[shapeName.size()] = '\0';
  return shapeNameCStr;
}

double* kizhin::parseInputParams(std::istream& is)
{
  size_t paramsCapacity = 16;
  double* params = new double[paramsCapacity];
  params[0] = 0;
  while (is >> params[static_cast< size_t >(1 + params[0])]) {
    ++params[0];
    if (paramsCapacity == params[0] + 1) {
      resizeBuffer(&params, paramsCapacity);
    }
  }
  if (!is && !is.eof()) {
    is.clear();
  }
  return params;
}

void kizhin::resizeBuffer(double** buffer, size_t& capacity)
{
  capacity *= 2;
  double* tempBuffer = nullptr;
  try {
    tempBuffer = new double[capacity];
  } catch (const std::bad_alloc&) {
    delete[] *buffer;
    *buffer = nullptr;
    throw;
  }
  copy(*buffer, *buffer + capacity / 2, tempBuffer);
  delete[] *buffer;
  *buffer = tempBuffer;
}

void kizhin::resetPointers(char** ptr1, double** ptr2)
{
  delete[] *ptr1;
  delete[] *ptr2;
  *ptr1 = nullptr;
  *ptr2 = nullptr;
}

void kizhin::throwIfNotScaleOrSize(bool isScaleCommand, size_t shapesSize)
{
  if (!isScaleCommand) {
    throw std::logic_error("Error: no 'SCALE' command\n");
  } else if (!shapesSize) {
    throw std::logic_error("Error: no shapes to perform 'SCALE' command\n");
  }
}

void kizhin::copy(const double* first, const double* last, double* result)
{
  for (; first != last; ++first, ++result) {
    *result = *first;
  }
}

void kizhin::copy(const char* first, const char* last, char* result)
{
  for (; first != last; ++first, ++result) {
    *result = *first;
  }
}

