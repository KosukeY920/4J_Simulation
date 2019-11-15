#include <stdio.h>
#include <math.h>

double diff_equa (double t, double u);
double euler_rule (double t, double u, double h, int step);
double heun_method (double t, double u, double h, int step);
double RK_method (double t, double u, double h, int step);


double calculated_t = 0.0;
double calculated_u = 0.0;
int main (void){
    double t = 0.0;
    double u = 1.0;
    double h = 0.025;
    int step = 40;


    printf("i, t, u\n");
    euler_rule(t, u, h, step);
    printf("i, t, u\n");
    heun_method(t, u, h, step);
    printf("i, t, u\n");
    RK_method(t, u, h, step);
    
    //printf ("t0 = %f, u0 = %f\n", t, u);
   // printf ("t1 = %f, u1 = %f\n", new_t, new_u);

}

//微分方程式
double diff_equa (double t, double u){
    double result = u;
    return result;
}

//オイラーの公式
double euler_rule (double t, double u, double h, int step){
    double old_t = t;
    double old_u = u;
    double new_t = 0;
    double new_u = 0;
    for(int i = 0; i < step; i++){

        new_t = old_t + h;
        new_u = old_u + (h * diff_equa(old_t, old_u)); 
        old_t = new_t;
        old_u = new_u;
        printf("%d, %f, %f\n", i + 1, new_t, new_u);
    }
    
    
    double result = new_u;
    return result;
}

//ホイン法
double heun_method (double t, double u, double h, int step){
    double t_i = t;
    double u_i = u;

    for(int i = 0; i < step; i++){
        double t_i1 = t_i + h;
        double k1 = (h * diff_equa(t_i, u_i));
        double k2 = (h * diff_equa(t_i + h, u_i + k1));

        double u_i1 = u_i + (0.5 * (k1 + k2));
        t_i = t_i1;
        u_i = u_i1;
        printf("%d, %f, %f\n", i + 1, t_i, u_i);
    }
    calculated_t = t_i;
    calculated_u = u_i;

    return 0;
}

//ルンゲ・クッタ法
double RK_method (double t, double u, double h, int step){
    double t_i = t;
    double u_i = u;

    for(int i = 0; i < step; i++){
        double t_i1 = t_i + h;
        double k1 = h * diff_equa(t_i, u_i);
        double k2 = h * diff_equa((t_i + h * 0.5), (u_i + k1 * 0.5));
        double k3 = h * diff_equa((t_i + h * 0.5), (u_i + k2 * 0.5));
        double k4 = h * diff_equa((t_i + h), (u_i + k3));

        double u_i1 = u_i + ((k1 + 2 * k2 + 2 * k3 + k4) / 6);
        t_i = t_i1;
        u_i = u_i1;
        printf("%d, %f, %f\n", i + 1, t_i, u_i);
    }
    calculated_t = t_i;
    calculated_u = u_i;

    return 0;
}