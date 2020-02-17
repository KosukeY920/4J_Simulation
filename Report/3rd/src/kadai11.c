#include<stdio.h>
#include<math.h>

void gauss(void);
void print_eq(void);

double result[4];
double eq[4][5] = {
    {1, 2, 1, 5, 20.5},
    {8, 1, 3, 1, 14.5},
    {1, 7, 1, 1, 18.5},
    {1, 1, 6, 1, 9.0}
};

int main(void)
{
    gauss();
    printf("\n結果\n");
    for(int i = 0; i < 4; i++)
        printf("x[%d] = %f\n", i + 1, result[i]);
        
    return (0);
}

void gauss(void)
{
    //前進削除
    for(int k = 0; k < 3; k++)
    {
        print_eq();
        printf("\n第%d列の掃き出し\n", k + 1);
        for(int i = k + 1; i < 4; i++)
        {
            double m = eq[i][k] / eq[k][k];
            for(int j = k; j < 5; j++)
            {
                eq[i][j] -= (eq[k][j] * m);
            }
        }
    }

    print_eq();

    //後退代入
    for(int i = 0; i < 4; i++)
    {
        result[i] = eq[i][4];
    }

    for(int i = 3; i >= 0; i--)
    {
        for(int j = i + 1; j <= 3; j++)
        {
            result[i] -= eq[i][j] * result[j];
        }

        result[i] /= eq[i][i];
    }
}

//二次元配列の内容を表示
void print_eq(void)
{
     for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            printf("%f ", eq[i][j]);
        }
        printf("\n");
    }
}