#include <stdio.h>
#include <stdlib.h>

int main()
{

    int nNode, nPath, source, dest, *team;
    scanf("%d %d %d %d", &nNode, &nPath, &source, &dest);
    team = (int *)malloc(nNode * sizeof(int));
    for (size_t i = 0; i < nNode; i++)
    {
        scanf("%d", team + i);
    }
    int dist[nNode][nNode];
    int s,t,l;
    for (size_t i = 0; i < nPath; i++)
    {
        scanf("%d %d %d",&s,&t,&l);
        
    }

    return 0;
}