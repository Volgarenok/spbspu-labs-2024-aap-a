#include <cmath>
#include <stdexcept>

double arcsinTaylor(double x, size_t n, double error) {
    if (n > 10) throw std::invalid_argument("Maximum iterations exceeded");
    double sum = 0;
    double element_summirovania = 0;
    double p1 = 0;
    double p2 = 0;
    for (size_t i = 0; i < n; ++i) {
	long int factorial = 1;
	long int factorial2 = 1;
	if (i == 0){
	    factorial = 0;
	    factorial2 = 0;
	}
	else if (i == 1){
	    factorial = i;
	    factorial2 = 2;
	}
	else{
	    for (size_t j = 1; j <= i; ++j){
                factorial *= j;
	    }
	    for (size_t j = 1; j <= (2 * i); ++j){
                factorial2 *= j;
            }
	} 
        p1 = (pow(-1, i) * factorial2) / (pow(2, (2 * i)) * factorial * factorial);
        p2 = pow(x, (2 * i + 1)) / (2 * n + 1);
	element_summirovania = p1 * p2;
	sum += element_summirovania;
        if (fabs(element_summirovania) < error) break;
    }
    return sum;
}

double arctanTaylor(double x, size_t n, double error) {
    if (n > 10) throw std::invalid_argument("Maximum iterations exceeded");
    double sum = 0;
    double element_summirovania = 0;
    for (size_t i = 0; i < n; ++i) {
	element_summirovania = pow(x, (2 * i + 1)) / (2 * i + 1);
	sum += element_summirovania;
        if (fabs(element_summirovania) < error) break;
    }
    return sum;
}
