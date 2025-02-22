#include <cmath>

double arcsinTaylor(double x, size_t n, double error) {
    if (n > 10) throw invalid_argument("Maximum iterations exceeded");
    double sum = 0;
    double term = 0;
    double term1 = 0;
    double term2 = 0;
    for (size_t i = 0; i < n; ++i) {
	int factorial = 1;
	int factorial2 = 1;
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
        term1 = (pow(-1, i) * factorial2) / (pow(2, (2 * i)) * factorial * factorial);
        term2 = pow(x, (2 * i + 1)) / (2 * n + 1);
	term = term1 * term2;
	sum += term;
        if (fabs(term) < error) break;
    }
    return sum;
}
