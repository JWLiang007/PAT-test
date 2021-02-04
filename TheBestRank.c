#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 101

typedef struct info
{
    char ID[7];
    int grade[4];
    struct info *next;
} info;

typedef enum subj
{
    C=0,
    M,
    E,
    A
};

char symbol[] ={'C','M','E','A'};

void subjSort(int (*subj)[SIZE])
{
    int rank,cnt;
    for (int i = 0; i < 4; i++)
    {
        rank = 0;
        for (int j = SIZE-1; j >= 0; j--)
        {
            if (subj[i][j] != 0)
            {
                cnt = subj[i][j];
                subj[i][j] = rank+1;
                rank += cnt;
            }
        }
    }
}


int main()
{
    int n, m, gradeC, gradeM, gradeE, gradeA;
    int subj[4][SIZE] = {{0}};
    // int subjC[101]={0}, subjM[101]={0}, subjE[101]={0}, subjA[101]={0};
    char id[7];
    scanf("%d %d", &n, &m);
    // info *col = (info *)malloc(n * sizeof(info));
    info *list = (info *)malloc(sizeof(info)), *std;
    list->next=NULL;
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %d %d", id, &gradeC, &gradeM, &gradeE);
        gradeA = (gradeC + gradeM + gradeE + 1) / 3;
        std = (info *)malloc(sizeof(info));
        strcpy(std->ID, id);
        std->grade[C]=gradeC;
        std->grade[M]=gradeM;
        std->grade[E]=gradeE;
        std->grade[A]=gradeA;
        std->next=list->next;
        list->next = std;
        // strcpy(col[i].ID, id);
        // col->grade[C] = gradeC;
        // col->grade[M] = gradeM;
        // col->grade[E] = gradeE;
        // col->grade[A] = gradeA;
        subj[C][gradeC] += 1;
        subj[M][gradeM] += 1;
        subj[E][gradeE] += 1;
        subj[A][gradeA] += 1;
    }
    subjSort(subj);
    for(int i = 0; i< m;i++){
        scanf("%s",id);
        info *p=list,*q;
        int min=2*SIZE,idx;
        while(p->next!=NULL){
            q = p->next;
            if(strcmp(q->ID,id)==0){
                // min = subj[0][*(q->grade)];
                for(int j = 3,count = 0; count < 4; count++,j = (j+1)%4){
                    if(subj[j][*(q->grade+j)] < min ){
                        min = subj[j][*(q->grade+j)];
                        idx=j;
                    }
                }
                printf("%d %c\n",min,symbol[idx]);
                break;
            }
            p=p->next;
        }
        if(p->next==NULL && n>0){
            printf("%s\n","N/A");
        }else{
            // p->next = q->next;
            // free(q);
        }
    }
    

    return 0;
}
