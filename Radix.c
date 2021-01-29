#include <stdio.h>

long long calDecm(char digit[],int radix);
int getDecm(char c);
int main()
{
    char digit1[10],digit2[10],*fir,*sec;
    int flag,radix;
    long long num1;
    scanf("%s %s %d %d",digit1,digit2,&flag,&radix);
    if(flag==1){
        fir = digit1;
        sec = digit2;
    }else{
        fir = digit2;
        sec = digit1;
    }
    num1=flag==1?calDecm(digit1,radix):calDecm(digit2,radix);
    int s=2,t=35,mid;
    while (s<=t)
    {
        mid = (s+t)/2;
        if(num1==calDecm(sec,mid)) {
            break;
        }else if(num1<calDecm(sec,mid)){
            t = mid - 1 ; 
        }else{
            s= mid + 1;
        }
    }

    if(s<=t){
        printf("%d",mid);
    }else{
        printf("%s","Impossible");
    }
    
    return 0;
}

long long  calDecm(char digit[],int radix){
	int result = 0;
	for(int i =0;digit[i]!='\0';i++){
		result=result*radix+getDecm(digit[i]);
	}
    return result;
}
int  getDecm(char c){
	if(c>='0'&&c<='9'){
		return c-'0';
	}else if(c>='a'&&c<='z'){
		return 10 + c -'a';
	}
}