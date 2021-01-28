#include <stdio.h>

double fabs(double a);
int getInput(int *count, double coefs[]);
int main()
{
    int count_1, count_2, maxExp_1, maxExp_2, maxExp_Out, count = 0, ori;
    double coef_1[1001] = {0}, coef_2[1001] = {0}, coef_Out[2002] = {0};
    maxExp_1 = getInput(&count_1, coef_1);
    maxExp_2 = getInput(&count_2, coef_2);
    for (int i = 0; i <= maxExp_1; i++)
    {
        for (int j = 0; j <= maxExp_2; j++)
        {
            coef_Out[i + j] += coef_1[i] * coef_2[j];
        }
    }
    maxExp_Out = maxExp_1 + maxExp_2;
    for (int i = maxExp_Out; i >=0;i--){
        if(fabs(coef_Out[i])>1e-6){
            count++;
        }
    }
    printf("%d",count);

    for (int i = maxExp_Out; i >=0;i--){
        if(fabs(coef_Out[i])>1e-6){
            printf(" %d %.1f",i,coef_Out[i]);
        }
    }



        return 0;
}
int getInput(int *count, double coefs[])
{
    int max = 0, exp;
    scanf("%d", count);
    for (int i = 0; i < *count; i++)
    {
        scanf("%d", &exp);
        scanf("%lf", coefs + exp);
        if (exp > max)
            max = exp;
    }
    return max;
}

double fabs(double a){
    return a>0?a:-a;
}