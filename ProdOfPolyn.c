#include <stdio.h>

int getInput(int *count, double coefs[]);
int main()
{
    int count_1, count_2, maxExp_1, maxExp_2,maxExp_Out;
    double coef_1[1001] = {0}, coef_2[1001] = {0}, coef_Out[2002] = {0};
    maxExp_1 = getInput(&count_1, coef_1);
    maxExp_2 = getInput(&count_2, coef_2);
    for (int i = 0; i <= maxExp_1; i++)
    {
        for (int j = 0; j <= maxExp_2; j++)
        {
            coef_Out[i+j]+=coef_1[i]*coef_2[j];
        }
    }
    maxExp_Out = maxExp_1*maxExp_2;
    
    

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