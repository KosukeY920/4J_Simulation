#include <stdio.h>
#include <math.h>

double diff_equa_1 (double, double);
double diff_equa_2 (double);
double heun_method (double t, double I, double Q,double dt, int step);

double R = 0.0;
double C = 0.3;
double L = 10.0;

int main (void){
    double t = 0.0;
    double Q = 10.0;
    double I = 0.0;

    double dt = 0.01;
    int step = 2000;
    
    printf ("i, t, I, Q\n");
    printf ("0, %f, %f, %f\n", t, I, Q);
    heun_method(t, I, Q, dt, step);
}


//微分方程式
//式1
// I' = (-R * I - (Q / C)) / L
double diff_equa_1 (double Q, double I){
    double result = ((-R * I) -(Q / C)) / L ;
    return result;
}


//微分方程式
//式2
// Q' = I
double diff_equa_2 (double I){
    double result = I;
    return result;
}

//ホイン法
double heun_method (double t, double I, double Q, double dt, int step){
    double old_t = t;
    double old_Q = Q;
    double old_I = I;
    

    for(int i = 0; i < step; i++){
        double new_t = old_t + dt;
        double k1_eq1 = (dt * diff_equa_1(old_Q, old_I));
        double k2_eq1 = (dt * diff_equa_1(old_Q + dt, old_I + k1_eq1));
        double k1_eq2 = (dt * diff_equa_2(old_I));
        double k2_eq2 = (dt * diff_equa_2(old_I + k1_eq2));

        double new_I = old_I + (0.5 * (k1_eq1 + k2_eq1));
        double new_Q = old_Q + (0.5 * (k1_eq2 + k2_eq2));
        old_t = new_t;
        old_I = new_I;
        old_Q = new_Q;
        printf("%d, %f, %f, %f\n", i + 1, old_t, old_I, old_Q);
    }

    return 0;
}
