#include<stdio.h>
#include<math.h>

void print_eq(void);
void pivoting(int);

double eq[3][4] = {
    {-2, 2, 0, 0},
    {3, -3, 1, 1}, 
    {2, 1, 6, 9}
    };

int main(void)
{
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
        printf("result[%d] = %.0f\n", i, result[i]);

    
    return (0);
}


//二次元配列の内容を表示
void print_eq(void)
{
     for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 4; j++)
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