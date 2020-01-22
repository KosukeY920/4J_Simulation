#include <stdio.h>
#include <math.h>

double diff_equa_1 (double, double);
double diff_equa_2 (double);
double diff_equa_3 (double, double);
double diff_equa_4 (double);
double diff_equa_5 (double, double);
double diff_equa_6 (double);
double heun_method (double, double, double, double, double, double, double, double, int);

const double q = 1.0;
const double m = 1.0;
const double B = 1.0;
const double E = 1.0;


int main (void){
    double t = 0.0;
    double x = 0.1;
    double y = 0.0;
    double z = 0.0;
    double v_x = 0.0;
    double v_y = 0.1;
    double v_z = 0.0;

    double dt = 0.05;
    int step = 10;
    
    //printf ("i, t, x, y, v_x, v_y\n");
    //printf ("0 %f %f %f %f %f %f %f\n", t, x, y, z, v_x, v_y, v_z);
   // printf("x, y, z\n");
    printf("%f %f %f\n", x, y, z);
    heun_method(t, x, y, z, v_x, v_y, v_z, dt, step);
}


//微分方程式
//式(x)
// v_y' = (q / m) * (x + v_y * B)
double diff_equa_1 (double x, double v_y){
    double result = (q / m) * (x + v_y * B);
    return result;
}


//微分方程式
//式(x)
// x' = v_x
double diff_equa_2 (double v_x){
    double result = v_x;
    return result;
}

//微分方程式
//式(y)
// v_y' = (q / m) * (y - v_x * B)
double diff_equa_3 (double y, double v_x){
    double result = (q / m) * (y - v_x * B);
    return result;
}

//微分方程式
//式(y)
//y' = v_y
double diff_equa_4 (double v_y){
    double result = v_y;
    return result;
}

//微分方程式
//式(z)
// v_z' = (q / m) * z
double diff_equa_5 (double z, double v_z){
    double result = (q / m) * z;
    return result;
}

//微分方程式
//式(z)
//z' = v_z
double diff_equa_6 (double v_z){
    double result = v_z;
    return result;
}



//ホイン法
double heun_method (double t, double x, double y, double z, double v_x,double v_y,double v_z, double dt, int step){
    double old_t = t;
    double old_x = x;
    double old_y = y;
    double old_z = z;
    double old_v_y = v_y;
    double old_v_x = v_x;
    double old_v_z = v_z;
    
    for(int i = 0; i < step; i++){
        double new_t = old_t + dt;
        double k1_eq1 = (dt * diff_equa_1(old_x, old_v_y));
        double k2_eq1 = (dt * diff_equa_1(old_x + dt, old_v_y + k1_eq1));
        double k1_eq2 = (dt * diff_equa_2(old_v_y));
        double k2_eq2 = (dt * diff_equa_2(old_v_y + k1_eq2));

        double k1_eq3 = (dt * diff_equa_3(old_y,old_v_x));
        double k2_eq3 = (dt * diff_equa_3(old_y + dt, old_v_x + k1_eq3));
        double k1_eq4 = (dt * diff_equa_4(old_v_y));
        double k2_eq4 = (dt * diff_equa_4(old_v_y + k1_eq4));

        double k1_eq5 = (dt * diff_equa_5(old_z, old_v_z));
        double k2_eq5 = (dt * diff_equa_5(old_z + dt, old_v_z + k1_eq5));
        double k1_eq6 = (dt * diff_equa_6(old_v_z));
        double k2_eq6 = (dt * diff_equa_6(old_v_z + k1_eq6));

        double new_x = old_x + (0.5 * (k1_eq2 + k2_eq2));
        double new_y = old_y + (0.5 * (k1_eq4 + k2_eq4));
        double new_z = old_z + (0.5 * (k1_eq6 + k2_eq6));
        double new_v_x = old_v_x + (0.5 * (k1_eq1 + k2_eq1));
        double new_v_y = old_v_y + (0.5 * (k1_eq3 + k2_eq3));
        double new_v_z = old_v_z + (0.5 * (k1_eq5 + k2_eq5));

        old_t = new_t;
        old_x = new_x;
        old_y = new_y;
        old_z = new_z;
        old_v_x = new_v_x;
        old_v_y = new_v_y;
        old_v_z = new_v_z;

        printf("%f %f %f\n", old_x, old_y, old_z);
        //printf("%d %f %f %f %f %f %f %f\n", i + 1, old_t, old_x, old_y, old_z, old_v_x, old_v_y, old_v_z);

    }

    return 0;
}
