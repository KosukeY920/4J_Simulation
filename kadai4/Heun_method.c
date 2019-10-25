#include <stdio.h>
#include <math.h>

double diff_equa (double x, double y);
double heun_method (double x, double y, double h, int step);

double calculated_x = 0.0;
double calculated_y = 0.0;

int main (void) {
    double x = 0.0;
    double y = 0.5;
    double h = 0.5;
    int step = 1;

    heun_method(x, y, h, step);
    printf ("x0 = %f, y0 = %f\n", x, y);
    printf ("x1 = %f, y1 = %f\n", calculated_x, calculated_y);

}

//微分方程式
double diff_equa (double x, double y){
    double result = 2.0 * y / (1.0 + x);
    return result;
}

//ホイン法
double heun_method (double x, double y, double h, int step){
    double x_i = x;
    double y_i = y;

    for(int i = 0; i < step; i++){
        double x_i1 = x_i + h;
        double k1 = (h * diff_equa(x_i, y_i));
        double k2 = (h * diff_equa(x_i + h, y_i + k1));

        double y_i1 = y_i + (0.5 * (k1 + k2));
        x_i = x_i1;
        y_i = y_i1;
    }
    calculated_x = x_i;
    calculated_y = y_i;

    return 0;
}