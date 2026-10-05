#include <stdio.h>

int graph[10][10];
int visited[10];
int n;

void DFS(int v)
{
    int i;

    printf("%d ", v);
    visited[v] = 1;

    for(i = 0; i < n; i++)
    {
        if(graph[v][i] == 1 && visited[i] == 0)
            DFS(i);
    }
}

int main()
{
    int e, u, v, i;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    for(i = 0; i < e; i++)
    {
        printf("Enter edge: ");
        scanf("%d %d", &u, &v);

        graph[u][v] = 1;
    }

    printf("\nAdjacency List:\n");

    for(i = 0; i < n; i++)
    {
        int j;

        printf("%d -> ", i);

        for(j = 0; j < n; j++)
        {
            if(graph[i][j] == 1)
                printf("%d ", j);
        }

        printf("\n");
    }

    for(i = 0; i < n; i++)
        visited[i] = 0;

    printf("\nDFS: ");
    DFS(0);

    return 0;
}