#ifndef FUNC_H
#define FUNC_H
namespace asafov {
	double absError(double x, size_t k);
	double expNegPow2x(double x, size_t k, double error);
	void table(double left, double right, double step, size_t numberMax, double error);
}
#endif
