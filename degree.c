#include <stdio.h>
#include <stdlib.h>

struct node
{
    int vertex;
    struct node *next;
};

int main()
{
    struct node *adj[20];
    int indegree[20] = {0};
    int outdegree[20] = {0};
    int vertices, edges;
    int i, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    for(i = 0; i < vertices; i++)
        adj[i] = NULL;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (source destination):\n");

    for(i = 0; i < edges; i++)
    {
        scanf("%d %d", &u, &v);

        struct node *newnode;
        newnode = (struct node*)malloc(sizeof(struct node));

        newnode->vertex = v;
        newnode->next = adj[u];
        adj[u] = newnode;

        outdegree[u]++;
        indegree[v]++;
    }

    /* Display adjacency list */
    printf("\nAdjacency List:\n");

    for(i = 0; i < vertices; i++)
    {
        struct node *temp = adj[i];

        printf("%d -> ", i);

        while(temp != NULL)
        {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }

        printf("\n");
    }

    /* Display degrees */
    printf("\nVertex\tIndegree\tOutdegree\tTotal Degree\n");

    for(i = 0; i < vertices; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\n",
               i,
               indegree[i],
               outdegree[i],
               indegree[i] + outdegree[i]);
    }

    return 0;
}