#include <stdio.h>
#include <math.h>
#define N 32

double integration_func(double x);
double simpson_rule(double a, double b);

int main (void){
    double result = simpson_rule(0.0, 1.0);
    printf("%f\n", result);
    return 0;
}


double integration_func (double x){
    double result = 4.0 / (1.0 + x * x);
    return result;
}
double simpson_rule (double a,double b){
    double h = (b - a) / N;

    double y0 = integration_func(a);
    double Yn = integration_func(b);
    double tmp_kisu = a;
    double Y_kisu = 0.0;
    double kisu_res_tmp = 0.0;
    double tmp_gusu = a;
    double Y_gusu = 0.0;
    double gusu_res_tmp = 0.0;

    for (int i = 1; i < N-1; i += 2){
        tmp = tmp + h;
        Yj = integration_func(tmp);
        res_tmp += Yj;
    }

    for (int i = 2; i < N - 2; i += 2){

    }
    
    res_tmp *= 2.0;

    double result = (h / 2.0) * (y0 + res_tmp + Yn);

    return result;
}