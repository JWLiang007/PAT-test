#include <stdio.h>


int main(){
    // definition
    int numOfInput,maxSum,maxS,maxT,curS,curT,curSum;
    // getInput
    scanf("%d",&numOfInput);
    int input[numOfInput];
    for(int i = 0;i<numOfInput;i++){
        scanf("%d",input+i);
    }
    // initiate
    maxSum = -1;
    maxS = 0;
    maxT = numOfInput -1 ;
    curS = curT = curSum = 0;
    while(curT < numOfInput){
        curSum += input[curT];
        if (curSum < 0){
            curS =  curT + 1;
            curSum =0;
        }else if(curSum > maxSum){
            maxT = curT;
            if(maxS != curS){
                maxS = curS;
            }
            maxSum = curSum;
        }
        
        curT += 1;
    }
    
    if(maxSum < 0) maxSum =0;
    printf("%d %d %d",maxSum,input[maxS],input[maxT]);
    return 0;
}