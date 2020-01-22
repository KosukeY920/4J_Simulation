#include <stdio.h>
#include <math.h>

double diff_equa_1 (double);
double diff_equa_2 (double);
double diff_equa_3 (double);
double diff_equa_4 (double);
double heun_method (double, double, double, double, double, double, int, double);

const double q = 1.0;
const double m = 1.0;
double B = 10.0;


int main (void){
    double t = 0.0;
    double x = 0.1;
    double y = 0.0;
    double v_x = 0.0;
    double v_y = 0.1;
    double v_0 = pow(v_x, 2.0) + pow(v_y, 2.0);

    double dt = 0.005;
    int step = 500;
    
    printf ("i, t, x, y, v_x, v_y\n");
    printf ("0, %f, %f, %f, %f, %f\n", t, x, y, v_x, v_y);
    heun_method(t, x, y, v_x, v_y, dt, step, v_0);
}


//微分方程式
//式(2)
// v_y' = (q / m) * B * v_y
double diff_equa_1 (double v_y){
    double result = (q / m) * B * v_y;
    return result;
}


//微分方程式
//式(2)
// x' = v_x
double diff_equa_2 (double v_x){
    double result = v_x;
    return result;
}

//微分方程式
//式(3)
// v_y' = -(q / m) * B * v_x
double diff_equa_3 (double v_x){
    double result = -(q / m) * B * v_x;
    return result;
}

//微分方程式
//式(3)
//y' = v_y
double diff_equa_4 (double v_y){
    double result = v_y;
    return result;
}

//ホイン法
double heun_method (double t, double x, double y, double v_x,double v_y, double dt, int step, double v_0){
    double old_t = t;
    double old_x = x;
    double old_y = y;
    double old_v_y = v_y;
    double old_v_x = v_x;
    
    for(int i = 0; i < step; i++){
        double new_t = old_t + dt;
        double k1_eq1 = (dt * diff_equa_1(old_v_y));
        double k2_eq1 = (dt * diff_equa_1(old_v_y + k1_eq1));
        double k1_eq2 = (dt * diff_equa_2(old_v_y));
        double k2_eq2 = (dt * diff_equa_2(old_v_y + k1_eq2));

        double k1_eq3 = (dt * diff_equa_3(old_v_x));
        double k2_eq3 = (dt * diff_equa_3(old_v_x + k1_eq3));
        double k1_eq4 = (dt * diff_equa_4(old_v_y));
        double k2_eq4 = (dt * diff_equa_4(old_v_y + k1_eq4));

        double new_x = old_x + (0.5 * (k1_eq2 + k2_eq2));
        double new_y = old_y + (0.5 * (k1_eq4 + k2_eq4));
        double new_v_x = old_v_x + (0.5 * (k1_eq1 + k2_eq1));
        double new_v_y = old_v_y + (0.5 * (k1_eq3 + k2_eq3));

        old_t = new_t;
        old_x = new_x;
        old_y = new_y;
        old_v_x = new_v_x;
        old_v_y = new_v_y;

        //printf("%d, %f, %f, %f, %f, %f\n", i + 1, old_t, old_x, old_y, old_v_x, old_v_y);

        double v_n = pow(new_v_x, 2.0) + pow(new_v_y, 2.0);
        printf("誤差:%f\n", (v_n - v_0) / v_0);
    }

    return 0;
}
