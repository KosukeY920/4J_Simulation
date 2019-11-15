#include <stdio.h>
#include <math.h>

double diff_equa_1 (double);
double diff_equa_2 (double, double);
double euler_method (double x, double y_1, double y_2, double h, int step);

double new_x = 0.0;
double new_y_1 = 0.0;
double new_y_2 = 0.0;
int main (void){
    double x = 0.0;
    double y_1 = 4.0;
    double y_2 = 6.0;
    double h = 0.5;
    int step = 4;
    
    printf ("i, x, y_1, y_2\n");
    printf ("0, %f, %f, %f\n", x, y_1, y_2);
    euler_method(x, y_1, y_2, h, step);
}

//微分方程式
//式1
double diff_equa_1 (double y_1){
    double result = -0.5 * y_1;
    return result;
}

//微分方程式
//式2
double diff_equa_2 (double y_1, double y_2){
    double result = 4 - 0.3 * y_2 - 0.1 * y_1;
    return result;
}

//オイラーの公式
double euler_method (double x, double y_1, double y_2, double h, int step){
    double old_x = x;
    double old_y_1 = y_1;
    double old_y_2 = y_2;
    
    for(int i = 0; i < step; i++){

        new_x = old_x + h;
        new_y_1 = old_y_1 + (h * diff_equa_1(old_y_1));
        new_y_2 = old_y_2 + (h * diff_equa_2(old_y_1, old_y_2));
        old_x = new_x;
        old_y_1 = new_y_1;
        old_y_2 = new_y_2;
        printf("%d, %f, %f, %f\n", i + 1, new_x, new_y_1, new_y_2);
    }

    return 0;
}