#ifndef HEADER_H
#define HEADER_H

#include <iostream> 
#include <cmath>
#include <stdexcept>
namespace asafov {
	double absError(double, std::size_t);
	double f(double, std::size_t, double);
	void table(double, double, double, std::size_t, double);
}
#endif