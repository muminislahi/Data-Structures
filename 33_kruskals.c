#include <stdio.h>
#include <stdlib.h>

struct edge
{
    int src;
    int dest;
    int wt; /* wt = weight */
};

int find_parent(int v, int parent[])
{
    if(parent[v] == v)
    {
        return v;
    }

    return find_parent(parent[v], parent);
}

void union_set(int a, int b, int parent[])
{
    int pa = find_parent(a, parent);
    int pb = find_parent(b, parent);

    parent[pb] = pa;
}

int main()
{
    int n; /* n = number_of_vertices */
    int e; /* e = number_of_edges */
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of directed edges: ");
    scanf("%d", &e);

    struct edge edges[e];

    printf("Enter edges (src dest wt):\n");
    for(i = 0; i < e; i++)
    {
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].wt);
    }

    /* Sort edges by weight */
    for(i = 0; i < e - 1; i++)
    {
        for(j = 0; j < e - i - 1; j++)
        {
            if(edges[j].wt > edges[j + 1].wt)
            {
                struct edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    int parent[n];
    for(i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    int total_cost = 0;
    int edges_selected = 0;

    printf("\nEdges selected:\n");

    for(i = 0; i < e && edges_selected < n - 1; i++)
    {
        int u = edges[i].src;
        int v = edges[i].dest;

        int pu = find_parent(u, parent);
        int pv = find_parent(v, parent);

        if(pu != pv)
        {
            printf("%d -> %d (wt %d)\n", u, v, edges[i].wt);
            union_set(u, v, parent);
            total_cost += edges[i].wt;
            edges_selected++;
        }
    }

    printf("\nTotal cost = %d\n", total_cost);

    return 0;
}
