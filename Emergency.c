#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{

    int nNode, nPath, source, dest, *team;
    scanf("%d %d %d %d", &nNode, &nPath, &source, &dest);
    team = (int *)malloc(nNode * sizeof(int));
    for (size_t i = 0; i < nNode; i++)
    {
        scanf("%d", team + i);
    }
    int dist[nNode][nNode] ;
    for (size_t i = 0; i < nNode; i++)
    {
        for (size_t j = 0; j < nNode; j++)
        {
            if(i==j) dist[i][j]=0;
            else dist[i][j]=INT_MAX;
        }
        
    }
    
    int s,t,l;
    for (size_t i = 0; i < nPath; i++)
    {
        scanf("%d %d %d",&s,&t,&l);
        dist[s][t]=l;
    }

    return 0;
}