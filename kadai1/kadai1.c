#include <stdio.h>
#include <math.h>
#define N 32

double integration_func(double x);
double trapezoidal_rule(double a, double b);

int main (void){
    int x = 3;
    double result = trapezoidal_rule(0.0, M_PI / 6);
    printf("%f\n", result);
    return 0;
}


double integration_func (double x){
    double result = 1.0 / cos(x);
    return result;
}
double trapezoidal_rule (double a,double b){
    double h = (b - a) / N;

    double y0 = integration_func(a);
    double Yn = integration_func(b);
    double tmp = a;
    double Yj = 0.0;
    double res_tmp = 0.0;

    for (int i = 0; i < N-1; i++){
        tmp = tmp + h;
        Yj = integration_func(tmp);
        res_tmp += Yj;
    }
    
    res_tmp *= 2.0;

    double result = (h / 2.0) * (y0 + res_tmp + Yn);

    return result;
}