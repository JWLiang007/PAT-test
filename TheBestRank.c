#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char ID[7];
    int grade[4];
}info;

int main() {
    int n , m , subjC[101],subjM[101],subjE[101],subjA[101];
    scanf("%d %d",&n,&m);
    info *col = (info*)malloc(n*sizeof(info));
    for(int i=0;i<n;i++){
        scanf("%s %d %d %d",
              col[i].ID,col[i].grade,col[i].grade+1,col[i].grade+2);
        col[i].grade[3]=(col[i].grade[0]+col[i].grade[1]+col[i].grade[2])/3;
    }
    return 0;
}
