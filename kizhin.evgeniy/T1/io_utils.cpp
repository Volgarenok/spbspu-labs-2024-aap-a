#include "io_utils.hpp"
#include <iomanip>
#include <ostream>
#include "shape_utils.hpp"

namespace kizhin {
  char* parseInputWord(std::istream&);
  double* parseInputParams(std::istream&);
  void resizeBuffer(double** buffer, size_t& capacity);
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
