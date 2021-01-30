#include <stdio.h>
#include <string.h>
#include <limits.h>

int getDigFrmChar(char c)
{
    int res;
    if (c >= '0' && c <= '9')
    {
        res = c - '0';
    }
    else
    {
        res = c - 'a' + 10;
    }
    return res;
}

long long calDecm(char dig[], long long radix)
{
    long long res = 0;
    int n;
    for (int i = 0; dig[i] != '\0'; i++)
    {
        n = getDigFrmChar(dig[i]);
        if ((LLONG_MAX - n) / radix < res) /* overflow */
            return -1;
        res = res * radix + n;
    }
    return res;
}

long long binsearch(char *s, long long n, long long rmin, long long rmax)
{
    long long r, m, ans = -1;
    while (rmax >= rmin)
    {
        r = rmin + (rmax - rmin) / 2; 
        if ((m = calDecm(s, r)) > n || m == -1)
            rmax = r - 1;
        else if (m < n)
            rmin = r + 1;
        else
        {
            ans = r;
            rmax = r - 1;
        }
    }
    return ans;
}

int minradix(char *s)
{ 
    int temp,ans=0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        temp = getDigFrmChar(s[i]);
        if (temp > ans)
        {
            ans = temp;
        }
    }
    return (ans + 1);

}

int main()
{

    int flag;
    long long radix, num1;
    char digit1[11], digit2[11], *fir, *sec;
    scanf("%s %s %d %lld", digit1, digit2, &flag, &radix);
    if (flag == 1)
    {
        fir = digit1;
        sec = digit2;
    }
    else if (flag == 2)
    {
        fir = digit2;
        sec = digit1;
    }
    num1 = calDecm(fir, radix);

    long long s = minradix(sec);
    long long t = num1 + 1;


    long long r = binsearch(sec, num1, s, t);
    if (r != -1)
        printf("%lld", r);
    else
        printf("Impossible");


    return 0;
}