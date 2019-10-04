#include <stdio.h>
#include <math.h>
#define N 8

double integration_func(double x);
double simpson_rule(double a, double b);

int main (void){
    double result = simpson_rule(0.0, M_PI / 2);
    printf("%f\n", result);
    return 0;
}


double integration_func (double x){
    double result = sin(x);
    return result;
}
double simpson_rule (double a,double b){
    double h = (b - a) / N;

    double y0 = integration_func(a);
    double Yn = integration_func(b);
    //奇数
    double tmp_odd = a - h;
    double Y_odd = 0.0;
    double odd_res_tmp = 0.0;
    //偶数
    double tmp_even = a;
    double Y_even = 0.0;
    double even_res_tmp = 0.0;

    for (int i = 1; i < N; i += 2){
        tmp_odd = tmp_odd + 2 * h;
        Y_odd = integration_func(tmp_odd);
        odd_res_tmp += Y_odd;
    }

    for (int i = 2; i < N; i += 2){
        tmp_even = tmp_even + 2 * h;
        Y_even = integration_func(tmp_even);
        even_res_tmp += Y_even;
    }
    
    odd_res_tmp *= 4.0;
    even_res_tmp *= 2.0;

    double result = (h / 3.0) * (y0 + odd_res_tmp  + even_res_tmp + Yn);

    return result;
}