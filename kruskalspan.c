#include <stdio.h>

struct edge
{
    int u, v, w;
};

int find(int parent[], int x)
{
    while(parent[x] != x)
        x = parent[x];

    return x;
}

int main()
{
    struct edge e[20], temp;
    int parent[10];
    int n, m, i, j;
    int count = 0, total = 0;
    int a, b;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter edges (u v weight):\n");

    for(i = 0; i < m; i++)
        scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);

    // Sort edges by weight
    for(i = 0; i < m - 1; i++)
    {
        for(j = i + 1; j < m; j++)
        {
            if(e[i].w > e[j].w)
            {
                temp = e[i];
                e[i] = e[j];
                e[j] = temp;
            }
        }
    }

    // Initialize parent
    for(i = 0; i < n; i++)
        parent[i] = i;

    printf("\nEdges in MST:\n");

    for(i = 0; i < m && count < n - 1; i++)
    {
        a = find(parent, e[i].u);
        b = find(parent, e[i].v);

        if(a != b)
        {
            printf("%d - %d = %d\n",
                   e[i].u, e[i].v, e[i].w);

            total = total + e[i].w;
            parent[a] = b;
            count++;
        }
    }

    printf("Minimum Cost = %d", total);

    return 0;
}