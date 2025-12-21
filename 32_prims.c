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

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (src dest wt):\n");
    for(i = 0; i < e; i++)
    {
        int s, d, w;
        scanf("%d %d %d", &s, &d, &w);
        add_edge(adj_list, s, d, w);
    }

    int visited[n];
    int min_cost = 0;

    for(i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    int start_vertex;

    printf("Enter starting vertex for Prim: ");
    scanf("%d", &start_vertex);

    visited[start_vertex] = 1;

    printf("\nSelected edges:\n");

    int edges_selected = 0;

    while(edges_selected < n - 1)
    {
        int min_wt = 999999;
        int u = -1, v = -1;

        for(i = 0; i < n; i++)
        {
            if(visited[i] == 1)
            {
                struct adj_node *temp = adj_list[i];

                while(temp != NULL)
                {
                    if(visited[temp->vertex] == 0 && temp->wt < min_wt)
                    {
                        min_wt = temp->wt;
                        u = i;
                        v = temp->vertex;
                    }

                    temp = temp->next;
                }
            }
        }

        if(v == -1)
        {
            break;
        }

        visited[v] = 1;
        edges_selected++;

        min_cost += min_wt;

        printf("%d -> %d (wt %d)\n", u, v, min_wt);
    }

    printf("\nTotal cost = %d\n", min_cost);

    return 0;
}
