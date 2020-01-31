#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


//#define STEP 500
#define SAMPLE_CNT 10

int main(void){
    double ave_xN = 0;
    double pow2_xN = 0;
    double bunsan = 0;
    double sum_xy = 0, sum_x = 0, sum_y = 0, sum_x_pow2 = 0;
    double a = 0, b = 0;
    const int STEP = 500;

    struct timeval miri;
    gettimeofday(&miri, NULL);
    srand((unsigned int)time(NULL));

    printf("STEP, bunsan\n");
    for(int N = 1; N <= 10; N++){

    
        for(int k = 0; k < 10; k++){
            double sum_xN = 0, sum_pow2_xN = 0;
            for(int j = 0; j < SAMPLE_CNT; j++){
                int xN = 0;

                for(int i = 0; i < STEP * N; i++){    
            
                    int a = rand() % 2;
                    if(a == 1){
                        xN++;
                    }else{
                        xN--;
                    }
                }

                //位置の和
                sum_xN += xN;
                //位置の2乗の和
                sum_pow2_xN += xN * xN;

                
                
            }
            //位置の平均
            ave_xN += sum_xN / SAMPLE_CNT;
            //位置の2乗の平均
            pow2_xN += sum_pow2_xN / SAMPLE_CNT;
    
    
            //分散の和
            bunsan += (pow2_xN - pow(ave_xN, 2.0));
        }

//    printf("ave_x(N):%f\n", ave_xN);
        //分散の平均
        bunsan /= SAMPLE_CNT;
        printf("%d, %f\n", STEP * N, bunsan);

        sum_xy += STEP * N * bunsan;
        sum_x += STEP * N;
        sum_y += bunsan;
        sum_x_pow2 += pow(STEP * N, 2);
    }

    a = (10 * sum_xy - sum_x * sum_y) / (10 * sum_x_pow2 - pow(sum_x, 2));
    b = (sum_x_pow2 * sum_y - sum_xy * sum_x) / (10 * sum_x_pow2 - pow(sum_x, 2));

    printf("a = %f\nb = %f\n", a, b);

    return 0;
}
