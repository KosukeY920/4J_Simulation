#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define STEP 500

int main(void){
    srand((unsigned int)time(NULL));

    printf("x, y\n");
            
    for(int j = 0; j < 200; j++){
        int xN = 0;
        int yN = 0;

        for(int i = 0; i < STEP; i++){    
            int a = rand() % 4;

            if(a == 0){
                xN++;
            }else if(a == 1){
                xN--;
            }else if(a == 2){
                yN++;
            }else if(a == 3){
                yN--;
            }
        }
        printf("%d, %d\n", xN, yN);
    }

    return 0;
}
