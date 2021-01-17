#include <stdio.h>
#include <stdlib.h>

#define MAXNODES 101

struct Node
{
    int numOfChild;
    int *children;
    int level;
}nodes[MAXNODES];


int main(){
    int n, m, parentNo, numOfChild,*children;
    scanf("%d %d", &n, &m);
    if(n==0)
        return 0;
    if(m==0){
        printf("%d",n);
        return 0;
    }
    for(int i = 0; i < MAXNODES; i++){
        nodes[i].numOfChild=0;
    }
    for (int i = 0; i < m ;i++){
        scanf("%d %d", &parentNo, &numOfChild);
        struct Node *parentNode = nodes+parentNo;
        parentNode->numOfChild = numOfChild;
        children = parentNode->children=(int *)malloc(numOfChild*sizeof(int));
        for (int j = 0; j < numOfChild; j++){
            scanf("%d",children+j);
        }
    }
    
    int queue[MAXNODES],s=0,t=0,result[MAXNODES] = {0},maxLevel=0;
    nodes[1].level=0;
    queue[t++]=1;
    struct Node *pNode, *cNode=NULL;
    while(s != t){
        pNode = nodes+queue[s++];
        int childIndex;
        for(int i = 0; i < pNode->numOfChild; i++){
            childIndex = pNode->children[i];
            cNode = nodes + childIndex;
            cNode->level = pNode->level+1;
            if(cNode->numOfChild ==0)
                result[cNode->level]++;
            else{
                queue[t++]=childIndex;
            }
        }
        if (cNode && cNode->level > maxLevel) 
            maxLevel = cNode->level;
    }
    for (int i = 0; i < maxLevel;i++)
        printf("%d ",result[i]);
    printf("%d",result[maxLevel]);
    return 0;
}