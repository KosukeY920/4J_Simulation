#include<stdio.h>
#include<math.h>

int main(void)
{
    double eq[3][4] = {{5, -4, 6, 8},
                       {7, -6, 10, 14}, 
                       {4, 9, 7, 74}};
    
    //配列内容表示
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            printf("%.0f ", eq[i][j]);
        }
        printf("\n");
    }
    printf("\n前進消去開始\n第一列の掃き出し\n");
    
    for(int i = 1; i < 3; i++)
    {   
        double a_i0 = eq[i][0];
        double a_00 = eq[0][0];
        for(int j = 0; j < 4; j++)
        {
            double m = eq[0][j] * (a_i0 / a_00);
            eq[i][j] -= m;
        }
    }

    //配列内容表示
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            printf("%.0f ", eq[i][j]);
        }
        printf("\n");
    }

    printf("\n第二列の掃き出し\n");
    for(int i = 2; i < 3; i++)
    {
        double a_i0 = eq[i][1];
        double a_11 = eq[1][1];

        for(int j = 1; j < 4; j++)
        {
            double m = eq[1][j] * (a_i0 / a_11);
            eq[i][j] -= m;
        }
    }

    //配列内容表示
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            printf("%.0f ", eq[i][j]);
        }
        printf("\n");
    }

    printf("\n後退代入開始\n");

    double result[3] = {eq[0][3], eq[1][3], eq[2][3]};

    for(int i = 2; i >= 0; i--)
    {
        for(int j = i + 1; j <= 2; j++)
        {
            result[i] -= eq[i][j] * result[j];
        }

        result[i] /= eq[i][i];
    }
    
    printf("結果\n");
    for(int i = 0; i < 3; i++)
        printf("result[%d] = %.0f\n", i, result[i]);

    return (0);
}