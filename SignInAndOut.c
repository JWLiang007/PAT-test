#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[16];
    int signIn;
    int singOut;
} RECORD;

int cvtTime(char oriTime[]);

int main()
{
    int numOfRecord;
    scanf("%d", &numOfRecord);
    RECORD records[numOfRecord];
    for (int i = 0; i < numOfRecord; i++)
    {
        char name[16], oriIn[16], oriOut[16];
        scanf("%s %s %s", name, oriIn, oriOut);
        strcpy(records[i].name,name);
        records[i].signIn = cvtTime(oriIn);
        records[i].singOut = cvtTime(oriOut); 
    }

    int firstIndex = 0, lastIndex = 0;
    for ( int i = 1; i < numOfRecord ; i++){
        if(records[i].signIn<records[firstIndex].signIn){
            firstIndex = i;
        }
        if(records[i].singOut>records[lastIndex].singOut){
            lastIndex = i;
        }
    }
    printf("%s %s",records[firstIndex].name,records[lastIndex].name);
    return 0;
}

int cvtTime(char oriTime[])
{
    int result = 0;
    for (int i = 0; oriTime[i] != '\0'; i++)
    {
        if(oriTime[i]!=':'){
            result = result * 10 + oriTime[i] - '0';
        }else{
            result = result * 60;
        }
    }
    return result;
}