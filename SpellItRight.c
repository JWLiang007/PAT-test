#include <stdio.h>
#include <stdlib.h>

void printResult(int,int);
char *numEnum[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"}; 
int main(){

    int sum = 0;
    char c ; 
    while( (c = getchar()) != '\n'){
        sum += (c - '0');
    }
    
    printResult(sum,1);
    return 0;
}

void printResult(int sum,int first){
    int divisor = sum %10;
    if(sum/10 > 0){
        printResult(sum/10,0);
    }

    printf("%s",numEnum[divisor]);
    if(first==0)
        printf("%c",' ');
}