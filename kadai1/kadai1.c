#include <stdio.h>
#include <math.h>

double integration_func(double x);
double trapezoidal_rule(double a, double b, int N);

int main (void){
    int x = 3;
    int N = 1;
    
    for (; N <= 512; N *= 2){
    double result = trapezoidal_rule(0.0, M_PI / 6, N);
    printf("分割数N = %d\n計算結果 = %f\n計算誤差 = %f\n\n", N, result, fabs(0.549306144 - result));
    }
    return 0;
}

//積分される関数
double integration_func (double x){
    double result = 1.0 / cos(x);
    return result;
}

//台形公式
//積分範囲:a -> b
//分割数N
double trapezoidal_rule (double a,double b, int N){
    double h = (b - a) / N;

    double y_0 = integration_func(a);
    double y_n = integration_func(b);
    double tmp = a;
    double y_j = 0.0;
    double res_tmp = 0.0;

    for (int i = 0; i < N-1; i++){
        tmp = tmp + h;
        y_j = integration_func(tmp);
        res_tmp += y_j;
    }
    
    res_tmp *= 2.0;

    double result = (h / 2.0) * (y_0 + res_tmp + y_n);

    return result;
}