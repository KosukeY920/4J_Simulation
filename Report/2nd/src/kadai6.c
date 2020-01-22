#include <stdio.h>
#include <math.h>

double diff_equa_1 (double, double);
double diff_equa_2 (double, double);
double euler_method (double x, double y_1, double y_2, double h, int step);

double a = 1.0;
double b = 1.0;
double c = 1.0;
double d = 1.0;

double new_x = 0.0;
double new_y_1 = 0.0;
double new_y_2 = 0.0;
int main (void){
    double x = 0.0;
    double y_1 = 10.0;
    double y_2 = 10.0;
    double h = 0.1;
    int step = 1;
    
    printf ("i, x, y_1, y_2\n");
    printf ("0, %f, %f, %f\n", x, y_1, y_2);
    euler_method(x, y_1, y_2, h, step);
}

//微分方程式
//式1
//dy_1 / dx = ay_1 - cy_1y_2
double diff_equa_1 (double y_1, double y_2){
    double result = a * y_1 - c * y_1 * y_2;
    return result;
}

//微分方程式
//式2
//dy_2 / dx = -by_2 + dy_1y_2
double diff_equa_2 (double y_1, double y_2){
    double result = -b * y_2 + d * y_1 * y_2;
    return result;
}

//オイラーの公式
double euler_method (double x, double y_1, double y_2, double h, int step){
    double old_x = x;
    double old_y_1 = y_1;
    double old_y_2 = y_2;
    
    for(int i = 0; i < step; i++){

        new_x = old_x + h;
        new_y_1 = old_y_1 + (h * diff_equa_1(old_y_1, old_y_2));
        new_y_2 = old_y_2 + (h * diff_equa_2(old_y_1, old_y_2));
        old_x = new_x;
        old_y_1 = new_y_1;
        old_y_2 = new_y_2;
        printf("%d, %f, %f, %f\n", i + 1, new_x, new_y_1, new_y_2);
    }

    return 0;
}