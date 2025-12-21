#include <stdio.h>
#include <stdlib.h>

struct adj_node
{
    int vertex;
    int wt; /* wt = weight */
    struct adj_node *next;
};

struct adj_node *create_node(int v, int wt)
{
    struct adj_node *new_node = (struct adj_node *) malloc(sizeof(struct adj_node));

    new_node->vertex = v;
    new_node->wt = wt;
    new_node->next = NULL;

    return new_node;
}

void add_edge(struct adj_node *adj_list[], int src, int dest, int wt)
{
    struct adj_node *new_node = create_node(dest, wt);

    if(adj_list[src] == NULL)
    {
        adj_list[src] = new_node;
    }
    else
    {
        struct adj_node *temp = adj_list[src];

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = new_node;
    }
}

int main()
{
    int n; /* n = number_of_vertices */
    int e; /* e = number_of_edges */
    int i;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    struct adj_node *adj_list[n];

    for(i = 0; i < n; i++)
    {
        adj_list[i] = NULL;
    }

    printf("Enter number of directed edges: ");
    scanf("%d", &e);

    printf("Enter edges (src dest wt):\n");
    for(i = 0; i < e; i++)
    {
        int s, d, w;
        scanf("%d %d %d", &s, &d, &w);
        add_edge(adj_list, s, d, w);
    }

    int src_vertex;

    printf("Enter source vertex: ");
    scanf("%d", &src_vertex);

    int dist[n];
    int visited[n];

    for(i = 0; i < n; i++)
    {
        dist[i] = 999999;
        visited[i] = 0;
    }

    dist[src_vertex] = 0;

    for(i = 0; i < n - 1; i++)
    {
        int min_dist = 999999;
        int u = -1;

        int j;

        for(j = 0; j < n; j++)
        {
            if(!visited[j] && dist[j] < min_dist)
            {
                min_dist = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        struct adj_node *temp = adj_list[u];

        while(temp != NULL)
        {
            if(!visited[temp->vertex] && dist[u] + temp->wt < dist[temp->vertex])
            {
                dist[temp->vertex] = dist[u] + temp->wt;
            }

            temp = temp->next;
        }
    }

    printf("\nShortest distances from %d:\n", src_vertex);
    for(i = 0; i < n; i++)
    {
        printf("%d -> %d : %d\n", src_vertex, i, dist[i]);
    }

    return 0;
}
