#include <sys/time.h>
#include <stdio.h>
#include <math.h>

#define STEP 100
#define SAMPLE_CNT 10

int main(void){
    double ave_xN;
    double pow2_xN;
    double bunsan = 0;
    for(int k = 0; k < 10; k++){
    for(int j = 0; j < SAMPLE_CNT; j++){
        int xN = 0;

        for(int i = 0; i < STEP; i++){    
            struct timeval miri;
            gettimeofday(&miri, NULL);
            srand(miri.tv_usec);
            int a = rand() % 2;
            if(a == 1){
                xN++;
            }else{
                xN--;
            }
            
            
        }
        //printf("%d\n", xN);

        ave_xN += xN;
        pow2_xN += xN * xN;
    }

    ave_xN /= STEP;
    pow2_xN /= STEP;

    bunsan += pow2_xN - pow(ave_xN, 2.0);
    }

//    printf("ave_x(N):%f\n", ave_xN);
    bunsan /= STEP;
    printf("bunsan:%f\n", bunsan);
    return 0;
}
