#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 10000

typedef struct record
{
    int maxTeam;
    int minCost;
    int numOfminCost;
} record;

int main()
{
    int nNode, nPath, source, dest, visitCount;
    scanf("%d %d %d %d", &nNode, &nPath, &source, &dest);
    int visited[nNode];
    int team[nNode];
    int maxTeam[nNode];
    int numOfPath[nNode];
    // visited = (int *)malloc(nNode * sizeof(int));
    // team = (int *)malloc(nNode * sizeof(int));
    // maxTeam = (int *)malloc(nNode * sizeof(int));
    // 读入各节点的救援人数，初始化节点未访问
    for (size_t i = 0; i < nNode; i++)
    {
        visited[i] = 0;
        scanf("%d", team + i);
        maxTeam[i]=team[i];
    }
    int dist[nNode][nNode];
    for (size_t i = 0; i < nNode; i++)
    {
        for (size_t j = 0; j < nNode; j++)
        {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = MAX;
        }
    }
    int s, t, l;
    for (size_t i = 0; i < nPath; i++)
    {
        scanf("%d %d %d", &s, &t, &l);
        dist[s][t] = l;
    }

    // visited[source] = 1;
    record *result = (record *)malloc(sizeof(record));
    result->maxTeam = 0;
    result->minCost = MAX;
    result->numOfminCost = 0;

    for (int j = 0; j < nNode; j++)
    {
        int minN = MAX;
        int minI = -1;
        for (int i = 0; i < nNode; i++)
        {
            if (visited[i] != 1 && dist[source][i] < minN)
            {
                minI = i;
                minN=dist[source][i];
            }
        }
        if (minI == -1)
            break;
        visited[minI] = 1;
        for (int i = 0; i < nNode; i++)
        {
            if(i==minI) continue;
            int potential = dist[source][minI] + dist[minI][i];
            int oldVal = dist[source][i];
            if (potential <= oldVal)
            {
                dist[source][i] = potential;        
                int temp = maxTeam[i];
                if (maxTeam[minI] + team[i] > maxTeam[i])
                {
                    maxTeam[i] = maxTeam[minI] + team[i];
                }

                if (i == dest)
                {
                    if (potential < result->minCost)
                    {
                        result->minCost = potential;
                        // result->maxTeam = team[minI] + team[i] * (minI == i ? 0 : 1);
                        result->numOfminCost = 1;
                    }
                    else
                    {
                        result->numOfminCost+=1;
                    }
                    result->maxTeam = maxTeam[i];
                }

                
            }
        }
    }
    printf("%d %d\n",result->numOfminCost,result->maxTeam);
    return 0;
}