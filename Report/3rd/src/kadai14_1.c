#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define SAMPLE_CNT 10
#define DATA_NUM 10

void print_eq(void);
void pivoting(int);

double data[2][10] = {0.0};
double eq[3][4] = {0.0};

int main(void){
    double ave_xN = 0;
    double pow2_xN = 0;
    double bunsan = 0;
    double sum_xy = 0, sum_x = 0, sum_y = 0, sum_x_pow2 = 0;
    double a = 0, b = 0;
    const int STEP = 500;

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

        //分散の平均
        bunsan /= SAMPLE_CNT;
        printf("%d, %f\n", STEP * N, bunsan);
        data[0][N - 1] = STEP * N;
        data[1][N - 1] = bunsan;

        sum_xy += STEP * N * bunsan;
        sum_x += STEP * N;
        sum_y += bunsan;
        sum_x_pow2 += pow(STEP * N, 2);
    }

    a = (10 * sum_xy - sum_x * sum_y) / (10 * sum_x_pow2 - pow(sum_x, 2));
    b = (sum_x_pow2 * sum_y - sum_xy * sum_x) / (10 * sum_x_pow2 - pow(sum_x, 2));

    printf("一次近似\na = %f\nb = %f\n\n", a, b);


    eq[0][0] = DATA_NUM;
    for(int i = 0; i < DATA_NUM; i++)
    {
        eq[0][1] += data[0][i];
        eq[0][2] += pow(data[0][i], 2.0);
        eq[0][3] += data[1][i];
        eq[1][0] += data[0][i];
        eq[1][1] += pow(data[0][i], 2.0);
        eq[1][2] += pow(data[0][i], 3.0);
        eq[1][3] += data[0][i] * data[1][i];
        eq[2][0] += pow(data[0][i], 2.0);
        eq[2][1] += pow(data[0][i], 3.0);
        eq[2][2] += pow(data[0][i], 4.0);
        eq[2][3] += pow(data[0][i], 2.0) * data[1][i];
    }

    //前進削除
    for(int k = 0; k < 2; k++)
    {
        print_eq();
        printf("\n第%d列の掃き出し\n", k + 1);

        for(int i = k + 1; i < 3; i++)
        {
            pivoting(k);
            double m = eq[i][k] / eq[k][k];
            for(int j = k; j < 4; j++)
            {
                eq[i][j] -= (eq[k][j] * m);
            }
        }
    }

    print_eq();

    //後退代入

    double result[3] = {eq[0][3], eq[1][3], eq[2][3]};

    for(int i = 2; i >= 0; i--)
    {
        for(int j = i + 1; j <= 2; j++)
        {
            result[i] -= eq[i][j] * result[j];
        }

        result[i] /= eq[i][i];
    }
    
    printf("\n二次近似\n");
    for(int i = 0; i < 3; i++)
        printf("x^%d = %f\n", i, result[i]);

    return 0;
}



//二次元配列の内容を表示
void print_eq(void)
{
     for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            printf("%f ", eq[i][j]);
        }
        printf("\n");
    }
}

//ピボット選択
void pivoting(int k)
{
    if(eq[k][k] == 0.0)
    {
        printf("a_kkが0のためピボット選択を実行します。\n");
        //最大値検索
        int max_i;
        for(int i = k; i <= (2 - k); i++)
        {
            double tmp = eq[i][k];
            if(tmp < eq[i + 1][k])
            {
                tmp = eq[i + 1][k];
                max_i = i + 1;
            }
        }

        //列交換
        for(int i = 0; i < 4; i++)
        {
            double tmp = eq[k][i];
            eq[k][i] = eq[max_i][i];
            eq[max_i][i] = tmp;
        }
    }
}