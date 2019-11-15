#include <stdio.h>
#include <math.h>

double diff_equa (double t, double u);
double euler_rule (double t, double u, double h, int step);

double new_t = 0;
double new_u = 0;
int main (void){
    double t = 0.0;
    double u = 1.0;
    double h = 0.05;
    int step = 30;

    printf("i, t, u\n");
    euler_rule(t, u, h, step);
    
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