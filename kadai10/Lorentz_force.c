#include <stdio.h>
#include <math.h>

double diff_equa_1 (double);
double diff_equa_2 (double);
double euler_method (double t, double y, double v, double h, int step);
double heun_method (double t, double I, double Q,double dt, int step);

double new_t = 0.0;
double new_y = 0.0;
double new_v = 0.0;

double R = 1.0;
double C = 0.3;
double L = 10.0;
double Q_0 = 10.0;

double calculated_t = 0.0;
double calculated_I = 0.0;

int main (void){
    double t = 0.0;
    double Q = Q_0;
    double I = 0.0;

    double dt = 0.025;
    int step = 4;
    
    printf ("i, t, Q, I\n");
    printf ("0, %f, %f, %f\n", t, Q, I);
    heun_method(t, I, Q, dt, step);
}

//微分方程式
//式1
//dv/dt = (qB/m) * v
//v' = 2 * v
double diff_equa_1 (double v){
    double result = 2 * v;
    return result;
}

//微分方程式
//式2
//dx/dt = v
//x' = v
double diff_equa_2 (double v){
    double result = v;
    return result;
}

//オイラーの公式
/*double euler_method (double t, double y, double v, double h, int step){
    double old_t = t;
    double old_y = y;
    double old_v = v;
    
    for(int i = 0; i < step; i++){

        new_t = old_t + h;
        new_y = old_y + (h * diff_equa_1(k, l, old_y, old_v));
        new_v = old_v + (h * diff_equa_2(old_v));
        old_t = new_t;
        old_y = new_y;
        old_v = new_v;
        printf("%d, %f, %f, %f\n", i + 1, new_t, new_y, new_v);
    }

    return 0;
}*/

//ホイン法
double heun_method (double t, double I, double Q, double dt, int step){
    double t_i = t;
    double I_i = I;
    

    for(int i = 0; i < step; i++){
        double t_i1 = t_i + dt;
        double k1 = (dt * diff_equa_1(R, Q, I_i, C, L));
        double k2 = (dt * diff_equa_1(R, Q + dt, I_i + k1, C, L));

        double I_i1 = I_i + (0.5 * (k1 + k2));
        t_i = t_i1;
        I_i = I_i1;
        printf("%d, %f, %f, %f\n", i + 1, new_t, new_y, new_v);
    }
    calculated_t = t_i;
    calculated_I = I_i;

    return 0;
}