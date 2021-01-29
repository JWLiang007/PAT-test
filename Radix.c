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
    int n ;
    for (int i = 0; dig[i] != '\0'; i++)
    {
        n = getDigFrmChar(dig[i]);
        if((LLONG_MAX - n) / radix < res) /* overflow */
            return -1;
        res = res * radix + n;

    }
    return res;

}

long long binsearch(char *s, long long n, long long rmin, long long rmax)
{
    long long r, m;
    while(rmax >= rmin)
    {
        r = rmin + (rmax - rmin) / 2; /* avoid (rmin + rmax) overflow */
        if((m = calDecm(s, r)) > n || m == -1)
            rmax = r - 1;
        else if(m < n)
            rmin = r + 1;
        else
            return r;
    }
    return -1;
}

int minradix(char *s)
{   /* Simply the largest digit in the number plus 1 */
    char r;
    for(r = '0'; *s; s++)
        if(*s > r)
            r = *s;
    return getDigFrmChar(r) + 1;
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
    else if(flag == 2)
    {
        fir = digit2;
        sec = digit1;
    }
    num1 = calDecm(fir, radix);
    // int s = 0, temp;
    long long s = minradix(sec);     
    long long t = LLONG_MAX;
    // for (int i = 0; sec[i] != '\0'; i++)
    // {
    //     temp = getDigFrmChar(sec[i]);
    //     if (temp > s)
    //     {
    //         s = temp;
    //     }
    // }
    // s = s + 1;

    if(strlen(sec) == 1){
        if(num1 == (s - 1)) printf("%d",s);
        else printf("%s","Impossible");
    }else 
    {
        long long r = binsearch(sec,num1,s,t) ;
        if(r != -1)       printf("%lld", r);
        else                    printf("Impossible");
    }
    


    return 0;
}