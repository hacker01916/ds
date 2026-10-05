#include <stdio.h>

int main()
{
    int a[10][10], indegree[10] = {0};
    int n, i, j, count = 0, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    // Find indegree
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            if(a[j][i] == 1)
                indegree[i]++;

    printf("Topological Order: ");

    while(count < n)
    {
        v = -1;

        for(i = 0; i < n; i++)
        {
            if(indegree[i] == 0)
            {
                v = i;
                break;
            }
        }

        if(v == -1)
        {
            printf("\nTopological sorting not possible");
            return 0;
        }

        printf("%d ", v);
        indegree[v] = -1;
        count++;

        for(j = 0; j < n; j++)
        {
            if(a[v][j] == 1)
                indegree[j]--;
        }
    }

    return 0;
}