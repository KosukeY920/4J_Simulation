#include <stdio.h>
#include <math.h>

double integration_func_double(double x);
double simpson_rule_double(double a, double b, int N);

float integration_func_float(float x);
float simpson_rule_float(float a, float b, int N);


int main (void){
    int N = 50;
    
    printf("double\n刻み幅, 計算結果, 誤差\n");
    for(;N >= 2; N -= 2){
    double result_d = simpson_rule_double(0.0, M_PI / 2, N);
    printf("%d,%lf,%lf,\n", N, result_d, fabs(1.0-result_d));
    }

    N = 50;
    printf("\nfloat\n刻み幅, 計算結果, 誤差\n");
    for(;N >= 2; N -= 2){
    float result_f = simpson_rule_float(0.0, M_PI / 2, N);
    printf("%d,%f,%f,\n", N, result_f, fabsf(1.0-result_f));
    }
    return 0;
}

//積分される関数
//double
double integration_func_double (double x){
    double result = sin(x);
    return result;
}

//シンプソンの公式
//double
double simpson_rule_double (double a,double b, int N){
    double h = (b - a) / N;

    double y0 = integration_func_double(a);
    double Yn = integration_func_double(b);
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
        Y_odd = integration_func_double(tmp_odd);
        odd_res_tmp += Y_odd;
    }

    for (int i = 2; i < N; i += 2){
        tmp_even = tmp_even + 2 * h;
        Y_even = integration_func_double(tmp_even);
        even_res_tmp += Y_even;
    }
    
    odd_res_tmp *= 4.0;
    even_res_tmp *= 2.0;

    double result = (h / 3.0) * (y0 + odd_res_tmp  + even_res_tmp + Yn);

    return result;
}

//積分される関数
//float
float integration_func_float (float x){
    float result = sin(x);
    return result;
}

//シンプソンの公式
//float
float simpson_rule_float (float a,float b, int N){
    float h = (b - a) / N;

    float y0 = integration_func_float(a);
    float Yn = integration_func_float(b);
    //奇数
    float tmp_odd = a - h;
    float Y_odd = 0.0;
    float odd_res_tmp = 0.0;
    //偶数
    float tmp_even = a;
    float Y_even = 0.0;
    float even_res_tmp = 0.0;

    for (int i = 1; i < N; i += 2){
        tmp_odd = tmp_odd + 2 * h;
        Y_odd = integration_func_float(tmp_odd);
        odd_res_tmp += Y_odd;
    }

    for (int i = 2; i < N; i += 2){
        tmp_even = tmp_even + 2 * h;
        Y_even = integration_func_float(tmp_even);
        even_res_tmp += Y_even;
    }
    
    odd_res_tmp *= 4.0;
    even_res_tmp *= 2.0;

    float result = (h / 3.0) * (y0 + odd_res_tmp  + even_res_tmp + Yn);

    return result;
}