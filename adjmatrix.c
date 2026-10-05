#include <stdio.h>

int main()
{
    int graph[20][20];
    int vertices, edges;
    int i, j, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    /* Initialize matrix */
    for(i = 0; i < vertices; i++)
    {
        for(j = 0; j < vertices; j++)
        {
            graph[i][j] = 0;
        }
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (source destination):\n");

    for(i = 0; i < edges; i++)
    {
        scanf("%d %d", &u, &v);

        graph[u][v] = 1;
        graph[v][u] = 1;   /* For undirected graph */
    }

    printf("\nAdjacency Matrix:\n");

    for(i = 0; i < vertices; i++)
    {
        for(j = 0; j < vertices; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}