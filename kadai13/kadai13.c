#include<stdio.h>
#include<math.h>

void print_eq(void);
void pivoting(int);

#define DATA_NUM 7

double data[3][DATA_NUM] = {
    {1, 2, 3, 4, 5, 6, 7},   //i
    {0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6},   //x_i
    {0.000, 0.034, 0.138, 0.282, 0.479, 0.724, 1.120}    //y_i
};

double eq[3][4] = {0.0};

int main(void)
{
    eq[0][0] = DATA_NUM;
    for(int i = 0; i < DATA_NUM; i++)
    {
        eq[0][1] += data[1][i];
        eq[0][2] += pow(data[1][i], 2.0);
        eq[0][3] += data[2][i];
        eq[1][0] += data[1][i];
        eq[1][1] += pow(data[1][i], 2.0);
        eq[1][2] += pow(data[1][i], 3.0);
        eq[1][3] += data[1][i] * data[2][i];
        eq[2][0] += pow(data[1][i], 2.0);
        eq[2][1] += pow(data[1][i], 3.0);
        eq[2][2] += pow(data[1][i], 4.0);
        eq[2][3] += pow(data[1][i], 2.0) * data[2][i];
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
    
    printf("\n結果\n");
    for(int i = 0; i < 3; i++)
        printf("x^%d = %f\n", i, result[i]);
    
    return (0);
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