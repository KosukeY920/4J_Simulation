#include <stdio.h>
#include <math.h>

double diff_equa_1 (double, double);
double diff_equa_2 (double);
double heun_method (double, double, double, double, int);

double qB_m = 2.0;

int main (void){
    double t = 0.0;
    double x = 0.0;
    double v = 1.0;

    double dt = 0.01;
    int step = 1;
    
    printf ("i, t, x, v\n");
    printf ("0, %f, %f, %f\n", t, x, v);
    heun_method(t, x, v, dt, step);
}


//微分方程式
//式1
// v' = (qB / m) * v
double diff_equa_1 (double x, double v){
    double result = qB_m * v;
    return result;
}


//微分方程式
//式2
// x' = v
double diff_equa_2 (double v){
    double result = v;
    return result;
}

//ホイン法
double heun_method (double t, double x, double v, double dt, int step){
    double old_t = t;
    double old_x = x;
    double old_v = v;
    
    for(int i = 0; i < step; i++){
        double new_t = old_t + dt;
        double k1_eq1 = (dt * diff_equa_1(old_x, old_v));
        double k2_eq1 = (dt * diff_equa_1(old_x + dt, old_v + k1_eq1));
        double k1_eq2 = (dt * diff_equa_2(old_v));
        double k2_eq2 = (dt * diff_equa_2(old_v + k1_eq2));

        double new_v = old_v + (0.5 * (k1_eq1 + k2_eq1));
        double new_x = old_x + (0.5 * (k1_eq2 + k2_eq2));
        old_t = new_t;
        old_v = new_v;
        old_x = new_x;
        printf("%d, %f, %f, %f\n", i + 1, old_t, old_v, old_x);
    }

    return 0;
}
