#include <stdio.h>

int main()
{
    int cost[10][10], visited[10] = {0};
    int n, i, j, edges = 0;
    int min, u, v, total = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    visited[0] = 1;

    printf("\nEdges in MST:\n");

    while(edges < n - 1)
    {
        min = 999;

        for(i = 0; i < n; i++)
        {
            if(visited[i])
            {
                for(j = 0; j < n; j++)
                {
                    if(!visited[j] && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        printf("%d - %d = %d\n", u, v, min);

        total = total + min;
        visited[v] = 1;
        edges++;
    }

    printf("Minimum Cost = %d", total);

    return 0;
}