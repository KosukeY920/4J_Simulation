#include <stdio.h>
#include <math.h>

double diff_equa_1 (double, double);
double diff_equa_2 (double);
double euler_method (double t, double y, double v, double h, int step);

double new_t = 0.0;
double new_y = 0.0;
double new_v = 0.0;
double m = 1.0;
double k = 2.0;
double l = 0.0;


int main (void){
    double t = 0.0;
    double y = 10.0;
    double v = 0.0;
    double h = 0.01;
    int step = 500;
    
    printf ("i, t, y, v\n");
    printf ("0, %f, %f, %f\n", t, y, v);
    euler_method(t, y, v, h, step);
}

//微分方程式
//式1
//v' = -k * y - l * v
double diff_equa_1 (double y, double v){
    double result = (-k * y) - (l * v);
    return result;
}

//微分方程式
//式2
//y' = v
double diff_equa_2 (double v){
    double result = v;
    return result;
}

//オイラーの公式
double euler_method (double t, double y, double v, double h, int step){
    double old_t = t;
    double old_y = y;
    double old_v = v;
    
    for(int i = 0; i < step; i++){

        new_t = old_t + h;
        new_v = old_v + (h * diff_equa_1(old_y, old_v));
        new_y = old_y + (h * diff_equa_2(old_v));
        old_t = new_t;
        old_y = new_y;
        old_v = new_v;
        printf("%d, %f, %f, %f\n", i + 1, new_t, new_y, new_v);
    }

    return 0;
}