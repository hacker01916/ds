#include <stdio.h>

int main()
{
    int cost[10][10], dist[10], visit[10] = {0};
    int n, source, i, j, count;
    int min, u;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    printf("Enter source vertex: ");
    scanf("%d", &source);

    // Initial distance
    for(i = 0; i < n; i++)
        dist[i] = cost[source][i];

    dist[source] = 0;
    visit[source] = 1;

    for(count = 1; count < n; count++)
    {
        min = 999;

        for(i = 0; i < n; i++)
        {
            if(visit[i] == 0 && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }
        }

        visit[u] = 1;

        for(j = 0; j < n; j++)
        {
            if(visit[j] == 0 &&
               dist[u] + cost[u][j] < dist[j])
            {
                dist[j] = dist[u] + cost[u][j];
            }
        }
    }

    printf("\nShortest Distance from %d:\n", source);

    for(i = 0; i < n; i++)
        printf("To %d = %d\n", i, dist[i]);

    return 0;
}