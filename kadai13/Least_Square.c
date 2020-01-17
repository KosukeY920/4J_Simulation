#include<stdio.h>
#include<math.h>

void print_eq(void);
void pivoting(int);

#define DATA_NUM 4

double data[3][DATA_NUM] = {
    {1, 2, 3, 4},   //k
    {1, 2, 3, 4},   //x_k
    {0, 1, 2, 4}    //y_k
};

double eq[2][3] = {0.0};

int main(void)
{
    eq[0][0] = DATA_NUM;
    for(int i = 0; i < DATA_NUM; i++)
    {
        eq[0][1] += data[1][i];
        eq[0][2] += data[2][i];
        eq[1][0] = eq[0][1];
        eq[1][1] += pow(data[1][i], 2);
        eq[1][2] += data[1][i] * data[2][i];
    }

    //前進削除
    for(int k = 0; k < 1; k++)
    {
        print_eq();
        printf("\n第%d列の掃き出し\n", k + 1);

        for(int i = k + 1; i < 2; i++)
        {
            pivoting(k);
            double m = eq[i][k] / eq[k][k];
            for(int j = k; j < 3; j++)
            {
                eq[i][j] -= (eq[k][j] * m);
            }
        }
    }

    print_eq();

    //後退代入

    double result[2] = {eq[0][2], eq[1][2]};

    for(int i = 1; i >= 0; i--)
    {
        for(int j = i + 1; j <= 1; j++)
        {
            result[i] -= eq[i][j] * result[j];
        }

        result[i] /= eq[i][i];
    }
    
    printf("\n結果\n");
    printf("a, b = %f, %f\n", result[0], result[1]);
    
    return (0);
}


//二次元配列の内容を表示
void print_eq(void)
{
     for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("%.0f ", eq[i][j]);
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
        for(int i = k; i <= (1 - k); i++)
        {
            double tmp = eq[i][k];
            if(tmp < eq[i + 1][k])
            {
                tmp = eq[i + 1][k];
                max_i = i + 1;
            }
        }

        //列交換
        for(int i = 0; i < 3; i++)
        {
            double tmp = eq[k][i];
            eq[k][i] = eq[max_i][i];
            eq[max_i][i] = tmp;
        }
    }
}