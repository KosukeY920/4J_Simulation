#include <stdio.h>
#include <math.h>

double diff_equa (double x, double y);
double euler_rule (double x, double y, double h, int step);

double new_x = 0;
double new_y = 0;
int main (void){
    double x = 0.0;
    double y = 0.5;
    double h = 0.5;
    int step = 3;

    euler_rule(x, y, h, step);
    printf ("x0 = %f, y0 = %f\n", x, y);
    printf ("x1 = %f, y1 = %f\n", new_x, new_y);

}

//微分方程式
double diff_equa (double x, double y){
    double result = y / (1.0 + x);
    return result;
}

//オイラーの公式
double euler_rule (double x, double y, double h, int step){
    double old_x = x;
    double old_y = y;
    
    for(int i = 0; i < step; i++){

        new_x = old_x + h;
        new_y = old_y + (h * diff_equa(old_x, old_y)); 
        old_x = new_x;
        old_y = new_y;
        //printf("%f, %f\n", new_x, new_y);
    }
    
    double result = new_y;
    return result;
}