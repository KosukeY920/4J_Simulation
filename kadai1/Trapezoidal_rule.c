#include <stdio.h>
#include <math.h>
#define N 1

double integration_func(double x);
double trapezoidal_rule(double x0, double x1);

int main (void){
    int x = 3;
    double result = trapezoidal_rule(0, 1);
    printf("%f\n", result);
    return 0;
}


double integration_func (double x){
    double result = 4 / (1 + pow(x, 2));
    return result;
}
double trapezoidal_rule (double x0,double x1){
    double h = (x1 - x0) / N;

    double y0 = integration_func(x0);
    double y1 = integration_func(x1);

    double result = (h / 2) * (y0 + y1);

    return result;
}